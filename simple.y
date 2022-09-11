/*
 * CS250
 *
 * simple.y: simple parser for the simple "C" language
 * 
 * (C) Copyright Gustavo Rodriguez-Rivera grr@purdue.edu
 *
 * IMPORTANT: Do not post in Github or other public repository
 */

%token	<string_val> WORD

%token 	NOTOKEN LPARENT RPARENT LBRACE RBRACE LCURLY RCURLY COMA SEMICOLON EQUAL STRING_CONST LONG LONGSTAR VOID CHARSTAR CHARSTARSTAR INTEGER_CONST AMPERSAND OROR ANDAND EQUALEQUAL NOTEQUAL LESS GREAT LESSEQUAL GREATEQUAL PLUS MINUS TIMES DIVIDE PERCENT IF ELSE WHILE DO FOR CONTINUE BREAK RETURN

%union	{
		char *string_val;
		int nargs;
		int my_nlabel;
	}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
int yyerror(const char * s);

extern int line_number;
const char * input_file;
char * asm_file;
FILE * fasm;

#define MAX_ARGS 5
int nargs;
char * args_table[MAX_ARGS];

#define MAX_LOCALS 16
int nlocals = 0;
char * local_vars_table[MAX_LOCALS];

int local_vars_type[MAX_LOCALS];


#define MAX_GLOBALS 100
int nglobals = 0;
char * global_vars_table[MAX_GLOBALS];

int global_vars_type[MAX_GLOBALS];

#define MAX_STRINGS 100
int nstrings = 0;
char * string_table[MAX_STRINGS];

char *regStk[]={ "rbx", "r10", "r13", "r14", "r15"};
char *regStkByte[] = { "bl", "r10b", "r13b", "r14b", "r15b"};
char nregStk = sizeof(regStk)/sizeof(char*);

char *regArgs[]={ "rdi", "rsi", "rdx", "rcx", "r8", "r9"};
char nregArgs = sizeof(regArgs)/sizeof(char*);

#define MAX_NESTED_LOOPS 10
int loopStack[MAX_NESTED_LOOPS];
int loopTop = 0;

int top = 0;

int nargs =0;
 
int nlabel = 0;

int currentVarType;

int jumpLabelCounter = 0; 

int ifLabelCounter = 0;

void creatLocalVar(int var_type, char *word) {  // record the created local varible and its type
	local_vars_table[nlocals]=word;
  	local_vars_type[nlocals]=var_type;

  	nlocals++;
}

int getLocalVarIndex(char *word) {	//find the index of the input local variable (which can be use to push and pop in regStk)
	 for (int i=0; i<nlocals;i++) {
		 if (strcmp(local_vars_table[i], word) == 0) {
			 return i;
		 }
	 }
	 return -1;  // ret -1 for not found
}

void creatGlobalVar(int var_type, char *word) {  // record the created global varible and its type
  	global_vars_table[nglobals]=word;
  	global_vars_type[nglobals]=var_type;

  	nglobals++;
}

int getGlobalVarIndex(char *word) {  //find the index of the input global variable (which can be use to push and pop in regStk)
	 for (int i=0; i<nglobals;i++) {
		 if (strcmp(global_vars_table[i], word) == 0) {
			 return i;
		 }
	 }
	 return -1; // ret -1 for not found
}

%}

%%

goal:	
		program;

program :
        function_or_var_list;

function_or_var_list:
        function_or_var_list function
        | function_or_var_list global_var
        | /*empty */
	;

function:
    var_type WORD 
         {
		 fprintf(fasm, "\t.text\n");
		 fprintf(fasm, ".globl %s\n", $2);
		 fprintf(fasm, "%s:\n", $2);

		 fprintf(fasm, "# Save registers\n");
		 fprintf(fasm, "\tpushq %%rbp\n");
		 fprintf(fasm, "\tmovq %%rsp, %%rbp\n");
		 fprintf(fasm, "\tsubq $%d,%%rsp\n", 8*MAX_LOCALS); // Reserve space for args locals

		 fprintf(fasm, "\tpushq %%rbx\n");
		 fprintf(fasm, "\tpushq %%r10\n");
		 fprintf(fasm, "\tpushq %%r13\n");
		 fprintf(fasm, "\tpushq %%r14\n");
		 fprintf(fasm, "\tpushq %%r15\n");

		 nlocals = 0;
		 top = 0; 
		 // set local counter 0 in this func call, then pass arg as loc after LPARENT arguments RPARENT
	 }
	 LPARENT arguments RPARENT 
         {

		 for (int i=0; i<nlocals; i++) {
		     fprintf(fasm, "\tmovq %%%s,-%d(%%rbp)\n", regArgs[i], (i+1)*8 );
		 }

         }
	 compound_statement
         {
		  // Restore space in stack for local vars
		 fprintf(fasm, "# Restore registers\n");
		 fprintf(fasm, "\tpopq %%r15\n");
		 fprintf(fasm, "\tpopq %%r14\n");
		 fprintf(fasm, "\tpopq %%r13\n");
		 fprintf(fasm, "\tpopq %%r10\n");
		 fprintf(fasm, "\tpopq %%rbx\n");
		 fprintf(fasm, "\tleave\n");
		 fprintf(fasm, "\tret\n");
         }
	;



arg_list:
         arg
         | arg_list COMA arg
	 ;

arguments:
         arg_list
	 | /*empty*/
	 ;

arg: var_type WORD{
	
	creatLocalVar(currentVarType, $<string_val>2);
	
};

global_var: 
	var_type global_var_list SEMICOLON;

global_var_list: WORD {									
	fprintf(fasm,".data\n");
	fprintf(fasm, ".comm %s, 8\n", $<string_val>1);
	creatGlobalVar(currentVarType, $<string_val>1);
    }

	| global_var_list COMA WORD {
	fprintf(fasm, ".comm %s, 8\n", $<string_val>3);
	creatGlobalVar(currentVarType, $<string_val>3);
	};

var_type: 	// record the latest type by new created global or local variable
		CHARSTAR {currentVarType = 0;} 
		| CHARSTARSTAR {currentVarType = 1;}
		| LONG {currentVarType = 2;}
		| LONGSTAR {currentVarType = 3;}
		| VOID {currentVarType = 4;};

assignment:
    WORD EQUAL expression {				// [A-Za-z][A-Za-z0-9]* = some expression  (global/local variable assiginment)
        char * id = $<string_val>1;
        int i = getLocalVarIndex(id);
                 
        if (i == -1) { // not found  (its glob)

            fprintf(fasm, "\tmovq %%%s, %s\n", regStk[top-1], id);

        }else {

            fprintf(fasm, "\tmovq %%%s, -%d(%%rbp)\n", regStk[top-1], (i+1)*8 ); //  adress of this element
        }
        top--;
	}

	| WORD LBRACE expression RBRACE EQUAL expression {	// [A-Za-z][A-Za-z0-9]* [some expression] (array)
 	    char * id = $<string_val>1;
		int i = getLocalVarIndex(id);
		int j = getGlobalVarIndex(id);
		int type;
		
		if (i == -1) { // it is not local var  (its glob)

			type = global_vars_type[j];

        }else {

            type = local_vars_type[i];

        }
		 
		if(type == 0) { // it is character array, which has 1 byte length each

			fprintf(fasm, "\timulq $1, %%%s\n", regStk[top-2]);

		} else {  // it is not character array(others), which has 8 byte length each

			fprintf(fasm, "\timulq $8, %%%s\n", regStk[top-2]);

		}
		 
		if (i == -1) { // push global var location to word

			top++; // we use another reg to store base address
			fprintf(fasm, "\tmovq %s, %%%s\n", id, regStk[top-1]);
			
		}

		else { // push local var location to word

			top++;
			fprintf(fasm, "\tmovq -%d(%%rbp), %%%s\n", (i+1)*8, regStk[top-1]);
			
		}

		fprintf(fasm, "\taddq %%%s, %%%s\n", regStk[top-1], regStk[top-3]);
		fprintf(fasm, "\tmovq %%%s, (%%%s)\n", regStk[top-2], regStk[top-3]);
		top-=3;

	};

call :
         WORD LPARENT  call_arguments RPARENT {
		 char * funcName = $<string_val>1;
		 int nargs = $<nargs>3;
		 int i;
		 fprintf(fasm,"     # func=%s nargs=%d\n", funcName, nargs);
     		 fprintf(fasm,"     # Move values from reg stack to reg args\n");
		 for (i=nargs-1; i>=0; i--) {
			top--;
			fprintf(fasm, "\tmovq %%%s, %%%s\n",
			  regStk[top], regArgs[i]);
		 }
		 if (!strcmp(funcName, "printf")) {
			 // printf has a variable number of arguments
			 // and it need the following
			 fprintf(fasm, "\tmovl    $0, %%eax\n");
		 }
		 fprintf(fasm, "\tcall %s\n", funcName);
		 fprintf(fasm, "\tmovq %%rax, %%%s\n", regStk[top]);
		 top++;
         }
      ;

call_arg_list:
         expression {
		$<nargs>$=1;
	 }
         | call_arg_list COMA expression {
		$<nargs>$++;
	 }

	 ;

call_arguments:
         call_arg_list { $<nargs>$=$<nargs>1; }
	 | /*empty*/ { $<nargs>$=0;}
	 ;

expression :
         logical_or_expr
	 ;

logical_or_expr:
          logical_and_expr

	 | logical_or_expr OROR logical_and_expr{  // stand for "||" computation
		fprintf(fasm, "\torq %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		//comput the result and push result in the second slot, and pop 1st one
		top--;
	 }
	 ;

logical_and_expr:
         equality_expr

	 | logical_and_expr ANDAND equality_expr{  // stand for "&&" compute
		fprintf(fasm, "\tandq %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		//similar to the OROR above
		top--;
	 }
	 ;

equality_expr:
         relational_expr
	 | equality_expr EQUALEQUAL relational_expr {
	 
		// a == b
		fprintf(fasm, "\tcmp %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		fprintf(fasm, "\tjne nequal_%d\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $1, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tjmp end_%d\n", jumpLabelCounter);

		fprintf(fasm, "\tnequal_%d:\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $0, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tend_%d:\n", jumpLabelCounter);
		
		jumpLabelCounter++;
		top--;
		
	 }
	 | equality_expr NOTEQUAL relational_expr {
	 
		// a != b
		fprintf(fasm, "\tcmp %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		fprintf(fasm, "\tje equal_%d\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $1, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tjmp end_%d\n", jumpLabelCounter);

		fprintf(fasm, "\tequal_%d:\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $0, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tend_%d:\n", jumpLabelCounter);
		
		jumpLabelCounter++;
		top--;
		
	 }
	 ;

relational_expr:
         additive_expr
	 | relational_expr LESS additive_expr {

		// a < b
		fprintf(fasm, "\tcmp %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		fprintf(fasm, "\tjge greatequal_%d\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $1, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tjmp end_%d\n", jumpLabelCounter);

		fprintf(fasm, "\tgreatequal_%d:\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $0, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tend_%d:\n", jumpLabelCounter);
		
		jumpLabelCounter++;
		top--;
	}
	 | relational_expr GREAT additive_expr {
		
		// a > b
		fprintf(fasm, "\tcmp %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		fprintf(fasm, "\tjle lessequal_%d\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $1, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tjmp end_%d\n", jumpLabelCounter);

		fprintf(fasm, "\tlessequal_%d:\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $0, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tend_%d:\n", jumpLabelCounter);
		
		jumpLabelCounter++;
		top--;
	}
	 | relational_expr LESSEQUAL additive_expr {
		
		// a <= b
		fprintf(fasm, "\tcmp %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		fprintf(fasm, "\tjg great_%d\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $1, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tjmp end_%d\n", jumpLabelCounter);

		fprintf(fasm, "\tgreat_%d:\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $0, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tend_%d:\n", jumpLabelCounter);
		
		jumpLabelCounter++;
		top--;
	}
	 | relational_expr GREATEQUAL additive_expr {
		
		// a >= b
		fprintf(fasm, "\tcmp %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		fprintf(fasm, "\tjl less_%d\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $1, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tjmp end_%d\n", jumpLabelCounter);

		fprintf(fasm, "\tless_%d:\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $0, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tend_%d:\n", jumpLabelCounter);
		
		jumpLabelCounter++;
		top--;
	}
	 ;

additive_expr:
          multiplicative_expr
	  | additive_expr PLUS multiplicative_expr { // add two expressions and save results to the second reg in stk

		if (top<nregStk) {
			fprintf(fasm, "\taddq %%%s,%%%s\n", regStk[top-1], regStk[top-2]);
			top--;
		}
	  }
	  | additive_expr MINUS multiplicative_expr { // similar to the one above

		if (top<nregStk) {
			fprintf(fasm, "\tsubq %%%s,%%%s\n", regStk[top-1], regStk[top-2]);
			top--;
		}
	  }
	  ;

multiplicative_expr:
          primary_expr
	  | multiplicative_expr TIMES primary_expr {
		if (top<nregStk) {
			fprintf(fasm, "\timulq %%%s,%%%s\n", regStk[top-1], regStk[top-2]);
			top--;
		}
      }
	  | multiplicative_expr DIVIDE primary_expr { // similar to the one above divide
		if (top<nregStk) {
			fprintf(fasm, "\tmovq $0, %%rdx\n");
			fprintf(fasm, "\tmovq %%%s, %%rax\n", regStk[top-2]);
			fprintf(fasm, "\tdivq %%%s\n", regStk[top-1]);
			fprintf(fasm, "\tmovq %%rax, %%%s\n", regStk[top-2]);
			top--;
		}
      }
	  | multiplicative_expr PERCENT primary_expr { // the remainder from percent results saved to rdx
		if (top<nregStk) {
			fprintf(fasm, "\tmovq $0, %%rdx\n");
			fprintf(fasm, "\tmovq %%%s, %%rax\n", regStk[top-2]);
			fprintf(fasm, "\tdivq %%%s\n", regStk[top-1]);
			fprintf(fasm, "\tmovq %%rdx, %%%s\n", regStk[top-2]);
			top--;
		}
      }
	  ;

primary_expr:
	  STRING_CONST {
		  // Add string to string table.
		  // String table will be produced later
		  string_table[nstrings]=$<string_val>1;
		  fprintf(fasm, "\t#top=%d\n", top);
		  fprintf(fasm, "\n\t# push string %s top=%d\n",
			  $<string_val>1, top);
		  if (top<nregStk) {
		  	fprintf(fasm, "\tmovq $string%d, %%%s\n", 
				nstrings, regStk[top]);
			//fprintf(fasm, "\tmovq $%s,%%%s\n", 
				//$<string_val>1, regStk[top]);
			top++;
		  }
		  nstrings++;
	  }
      | call
	  | WORD {
		 
 	     char * id = $<string_val>1;
		 int i = getLocalVarIndex(id);
		 top++;
		 if (i>=0) { // local found

			 fprintf(fasm, "\tmovq -%d(%%rbp), %%%s\n", (i+1)*8, regStk[top-1] );
			 
		 }
		 else {  // Global var

			 fprintf(fasm, "\tmovq %s, %%%s\n", id, regStk[top-1]);
		
		 }
	  }
	  | WORD LBRACE expression RBRACE {
  		 // Lookup local var
 	     char * id = $<string_val>1;
		 int i = getLocalVarIndex(id);
		 int j = getGlobalVarIndex(id);
		 int type;

		 if (i == -1) { // it is not local var  (its glob)

			type = global_vars_type[j];

        }else {

            type = local_vars_type[i];

        }

		//multiply and add stack for adresss
		 
		if(type == 0) { // it is character array, which has 1 byte length each

			fprintf(fasm, "\timulq $1, %%%s\n", regStk[top-1]);

		} else {  // it is not character array(others), which has 8 byte length each

			fprintf(fasm, "\timulq $8, %%%s\n", regStk[top-1]);

		}
 
		 	 
		 if (i == -1) { // global
			 
			 top++;
			 fprintf(fasm, "\tmovq %s, %%%s\n", id, regStk[top-1]);

		 }else { // local
			 
			 top++;
			 fprintf(fasm, "\tmovq -%d(%%rbp), %%%s\n", (i+1)*8, regStk[top-1]);

		 }
		 
		 fprintf(fasm, "\taddq %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		 
		 fprintf(fasm, "\tmovq %%%s, %%%s\n", regStk[top-2], regStk[top-1]); //dereferencing
		 fprintf(fasm, "\tmovq (%%%s), %%%s\n", regStk[top-1], regStk[top-2]);
		 top--;
		 
		 if(type == 0) // take only first byte (bc its char arr)
		 {

		 	fprintf(fasm, "\tmovb %%%s, %%r9b\n", regStkByte[top-1]);
		 	fprintf(fasm, "\tmovq $0, %%%s\n", regStk[top-1]);
		 	fprintf(fasm, "\tmovb %%r9b, %%%s\n", regStkByte[top-1]);

		 }
	  }

	  | AMPERSAND WORD {
 	     char * id = $<string_val>2;
		 int i = getLocalVarIndex(id);
		 top++;
		 if (i>=0) { //local

			 fprintf(fasm, "\tleaq -%d(%%rbp), %%%s\n", (i+1)*8, regStk[top-1]);
			
		 }
		 else { //global

			 fprintf(fasm, "\tleaq %s, %%%s\n", id, regStk[top-1]);

		 }
		 
	  }
	  | INTEGER_CONST {
		  fprintf(fasm, "\n\t# push %s\n", $<string_val>1);
		  if (top<nregStk) {
			fprintf(fasm, "\tmovq $%s,%%%s\n", 
				$<string_val>1, regStk[top]);
			top++;
		  }
	  }
	  | LPARENT expression RPARENT
	  ;

compound_statement:
	 LCURLY statement_list RCURLY
	 ;

statement_list:
         statement_list statement
	 | /*empty*/
	 ;

local_var:
        var_type local_var_list SEMICOLON;

local_var_list: 
	WORD {
			creatLocalVar(currentVarType, $<string_val>1);
    }
    | local_var_list COMA WORD {
		creatLocalVar(currentVarType, $<string_val>3);
	}
    ;

statement:
         assignment SEMICOLON
	 | call SEMICOLON {
		top = 0;
	 }
	 | local_var
	 | compound_statement
	 | IF LPARENT expression RPARENT {
			/*

			if (xxx) {

				statements
				jmp: ifEnd_#:

			}
			lbl: else_#:
			else {

				statements

			}

			lbl: ifEnd_#: (skip else)

			*/

			ifLabelCounter++;
			fprintf(fasm, "\tcmpq $0, %%%s\n", regStk[top-1]);
			fprintf(fasm, "\tje else_%d\n", ifLabelCounter);
			
			top--;
			
		}	 
		statement {
			fprintf(fasm, "\tjmp ifEnd_%d\n", ifLabelCounter);
			fprintf(fasm, "\telse_%d:\n", ifLabelCounter);
		}
		else_optional {
			fprintf(fasm, "\tifEnd_%d:\n", ifLabelCounter);
		 }
	 | WHILE LPARENT {
		// act 1
		loopStack[loopTop] = nlabel;
		loopTop++;
		nlabel++;
		fprintf(fasm, "\n\t# Begin WHILE loop\n");
		fprintf(fasm, "loop_start_%d:\n", loopStack[loopTop-1]);
		fprintf(fasm, "loop_continue_%d:\n", loopStack[loopTop-1]);
	    }
        expression RPARENT {
		// act2
		fprintf(fasm, "\tcmpq $0, %%%s\n", regStk[top-1]);
		fprintf(fasm, "\tje loop_end_%d\n", loopStack[loopTop-1]);
		top--;
         }
         statement {
		// act3
		fprintf(fasm, "\tjmp loop_start_%d\n", loopStack[loopTop-1]);
		fprintf(fasm, "loop_end_%d:\n", loopStack[loopTop-1]);
		loopTop--;
	 }
	 | DO {
		loopStack[loopTop] = nlabel;
		loopTop++;
		nlabel++;
		fprintf(fasm, "loop_start_%d:\n", loopStack[loopTop-1]);
		fprintf(fasm, "loop_continue_%d:\n", loopStack[loopTop-1]);
	 }
	 	statement{}
		
		WHILE LPARENT expression {
		fprintf(fasm, "\tcmpq $0, %%%s\n", regStk[top-1]);
		fprintf(fasm, "\tjne loop_start_%d\n", loopStack[loopTop-1]);
		top--;
	 }
	 RPARENT SEMICOLON {
		fprintf(fasm, "loop_end_%d:\n", loopStack[loopTop-1]);
		loopTop--;
	 }
	 | FOR LPARENT assignment SEMICOLON {
		loopStack[loopTop] = nlabel;
		loopTop++;
		nlabel++;
		fprintf(fasm, "loop_start_%d:\n", loopStack[loopTop-1]);
	 }
	 expression SEMICOLON {
		fprintf(fasm, "\tcmpq $0, %%%s\n", regStk[top-1]);
		fprintf(fasm, "\tjne loop_body_start_%d\n", loopStack[loopTop-1]);
		fprintf(fasm, "\tje loop_end_%d\n", loopStack[loopTop-1]);
		top--;

		fprintf(fasm, "\tloop_assignment_%d:\n", loopStack[loopTop-1]);
		fprintf(fasm, "loop_continue_%d:\n", loopStack[loopTop-1]);
	 }
	 assignment RPARENT{
		fprintf(fasm, "\tjmp loop_start_%d\n", loopStack[loopTop-1]); 
		fprintf(fasm, "\tloop_body_start_%d:\n", loopStack[loopTop-1]);
	 }
	 statement {
		fprintf(fasm, "\tjmp loop_assignment_%d\n", loopStack[loopTop-1]);
		fprintf(fasm, "loop_end_%d:\n", loopStack[loopTop-1]);
		loopTop--;
	}
	 | jump_statement
	 ;

else_optional:
         ELSE  statement 
	 | /* empty */ 
         ;

jump_statement:
     CONTINUE SEMICOLON {
		//CONTINUE in lopps
		fprintf(fasm, "\tjmp loop_continue_%d\n", loopStack[loopTop-1]);
	 }
	 | BREAK SEMICOLON {
		//BREAK in loops
		fprintf(fasm, "\tjmp loop_end_%d\n", loopStack[loopTop-1]);
	 }
	 | RETURN expression SEMICOLON {
		 fprintf(fasm, "\tmovq %%rbx, %%rax\n");
		 top = 0;
		 
		  // Restore space in stack for local vars
		 fprintf(fasm, "# Restore registers\n");
		 fprintf(fasm, "\tpopq %%r15\n");
		 fprintf(fasm, "\tpopq %%r14\n");
		 fprintf(fasm, "\tpopq %%r13\n");
		 fprintf(fasm, "\tpopq %%r10\n");
		 fprintf(fasm, "\tpopq %%rbx\n");
		 fprintf(fasm, "\tleave\n");
		 fprintf(fasm, "\tret\n");
	 }
	 ;

%%

void yyset_in (FILE *  in_str );

int
yyerror(const char * s)
{
	fprintf(stderr,"%s:%d: %s\n", input_file, line_number, s);
}


int
main(int argc, char **argv)
{
	printf("-------------WARNING: You need to implement global and local vars ------\n");
	printf("------------- or you may get problems with top------\n");
	
	// Make sure there are enough arguments
	if (argc <2) {
		fprintf(stderr, "Usage: simple file\n");
		exit(1);
	}

	// Get file name
	input_file = strdup(argv[1]);

	int len = strlen(input_file);
	if (len < 2 || input_file[len-2]!='.' || input_file[len-1]!='c') {
		fprintf(stderr, "Error: file extension is not .c\n");
		exit(1);
	}

	// Get assembly file name
	asm_file = strdup(input_file);
	asm_file[len-1]='s';

	// Open file to compile
	FILE * f = fopen(input_file, "r");
	if (f==NULL) {
		fprintf(stderr, "Cannot open file %s\n", input_file);
		perror("fopen");
		exit(1);
	}

	// Create assembly file
	fasm = fopen(asm_file, "w");
	if (fasm==NULL) {
		fprintf(stderr, "Cannot open file %s\n", asm_file);
		perror("fopen");
		exit(1);
	}

	// Uncomment for debugging
	//fasm = stderr;

	// Create compilation file
	// 
	yyset_in(f);
	yyparse();

	// Generate string table
	int i;
	for (i = 0; i<nstrings; i++) {
		fprintf(fasm, "string%d:\n", i);
		fprintf(fasm, "\t.string %s\n\n", string_table[i]);
	}

	fclose(f);
	fclose(fasm);

	return 0;
}

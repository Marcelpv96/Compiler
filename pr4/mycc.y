/* TO BE COMPLETED */

%{

#include "lex.yy.h"
#include "global.h"

#define MAXFUN 100
#define MAXFLD 100

static struct ClassFile cf;

/* stacks of symbol tables and offsets, depth is just 2 in C (global/local) */
static Table *tblptr[2];
static int offset[2];

/* stack pointers (index into tblptr[] and offset[]) */
static int tblsp = -1;
static int offsp = -1;

/* stack operations */
#define top_tblptr	(tblptr[tblsp])
#define top_offset	(offset[offsp])
#define push_tblptr(t)	(tblptr[++tblsp] = t)
#define push_offset(n)	(offset[++offsp] = n)
#define pop_tblptr	(tblsp--)
#define pop_offset	(offsp--)

/* flag to indicate we are compiling main's body (to differentiate 'return') */
static int is_in_main = 0;

%}

/* declare YYSTYPE attribute types of tokens and nonterminals */
%union
{ Symbol *sym;  /* token value yylval.sym is the symbol table entry of an ID */
  unsigned num; /* token value yylval.num is the value of an int constant */
  float flt;    /* token value yylval.flt is the value of a float constant */
  char *str;    /* token value yylval.str is the value of a string constant */
  unsigned loc; /* location of instruction to backpatch */
  Type typ;	/* type descriptor */
}

/* declare ID token and its attribute type */
%token <sym> ID

/* Declare INT tokens (8 bit, 16 bit, 32 bit) and their attribute type 'num' */
%token <num> INT8 INT16 INT32

/* Declare FLT token for literal floats */
%token <flt> FLT

/* Declare STR token for literal strings */
%token <str> STR

/* declare tokens for keywords */
/* Note: install_id() returns Symbol* for keywords and identifiers */
%token <sym> BREAK CHAR DO ELSE FLOAT FOR IF INT MAIN RETURN VOID WHILE

/* declare operator tokens */
%right '=' PA NA TA DA MA AA XA OA LA RA
%left OR
%left AN
%left '|'
%left '^'
%left '&'
%left EQ NE LE '<' GE '>'
%left LS RS
%left '+' '-'
%left '*' '/' '%'
%right '!' '~'
%left PP NN
%left '.' AR

/* Declare attribute types for marker nonterminals, such as K L M and N */
/* TODO: TO BE COMPLETED WITH ADDITIONAL NONMARKERS AS NECESSARY */
%type <loc> K L M N

%type <typ> type list args

%type <num> ptr

%%

prog	: Mprog exts	{ addwidth(top_tblptr, top_offset);
			  pop_tblptr;
			  pop_offset;
			}
	;

Mprog	: /* empty */	{ push_tblptr(mktable(NULL));
			  push_offset(0);
			}
	;

exts	: exts func
	| exts decl
	| /* empty */
	;

func	: MAIN '(' ')' Mmain block
			{ // need a temporary table pointer
			  Table *table;
			  // the type of main is a JVM type descriptor
			  Type type = mkfun("[Ljava/lang/String;", "V");
			  // emit the epilogue part of main()
			  emit3(getstatic, constant_pool_add_Fieldref(&cf, "java/lang/System", "out", "Ljava/io/PrintStream;"));
			  emit(iload_2);
			  emit3(invokevirtual, constant_pool_add_Methodref(&cf, "java/io/PrintStream", "println", "(I)V"));
			  emit(return_);
			  // method has public access and is static
			  cf.methods[cf.method_count].access = (enum access_flags)(ACC_PUBLIC | ACC_STATIC);
			  // method name is "main"
			  cf.methods[cf.method_count].name = "main";
			  // method descriptor of "void main(String[] arg)"
			  cf.methods[cf.method_count].descriptor = type;
			  // local variables
			  cf.methods[cf.method_count].max_locals = top_offset;
			  // max operand stack size of this method
			  cf.methods[cf.method_count].max_stack = 100;
			  // length of bytecode is in the emitter's pc variable
			  cf.methods[cf.method_count].code_length = pc;
			  // must copy code to make it persistent
			  cf.methods[cf.method_count].code = copy_code();
			  if (!cf.methods[cf.method_count].code)
				error("Out of memory");
			  // advance to next method to store in method array
			  cf.method_count++;
			  if (cf.method_count > MAXFUN)
			  	error("Max number of functions exceeded");
			  // add width information to table
			  addwidth(top_tblptr, top_offset);
			  // need this table of locals for enterproc
			  table = top_tblptr;
			  // exit the local scope by popping
			  pop_tblptr;
			  pop_offset;
			  // enter the function in the global table
			  enterproc(top_tblptr, $1, type, table);
			}
	| type ptr ID '(' Margs args ')' block
			{ /* TASK 3: TO BE COMPLETED */
                Table *table;
  			  // the type of function is gived by $1, args by $6
                Type type = mkfun($6, $1);
                // method has public access and is static
                cf.methods[cf.method_count].access = (enum access_flags)(ACC_PUBLIC | ACC_STATIC);
                cf.methods[cf.method_count].name = $3->lexptr;
                cf.methods[cf.method_count].descriptor = type;
                // local variables
                cf.methods[cf.method_count].max_locals = top_offset;
                // max operand stack size of this method
                cf.methods[cf.method_count].max_stack = 100;
                // length of bytecode is in the emitter's pc variable
                cf.methods[cf.method_count].code_length = pc;
                // must copy code to make it persistent
                cf.methods[cf.method_count].code = copy_code();
                if (!cf.methods[cf.method_count].code)
                  error("Out of memory");
                // advance to next method to store in method array
                cf.method_count++;
                if (cf.method_count > MAXFUN)
                  error("Max number of functions exceeded");
                // add width information to table
                addwidth(top_tblptr, top_offset);
                // need this table of locals for enterproc
                table = top_tblptr;
                // exit the local scope by popping
                pop_tblptr;
                pop_offset;
                // enter the function in the global table
                enterproc(top_tblptr, $3, type, table);
			}
	;

Mmain	:		{ int label1, label2;
			  Table *table;
			  // create new table for local scope of main()
			  table = mktable(top_tblptr);
			  // push it to create new scope
			  push_tblptr(table);
			  // for main(), we must start with offset 3 in the local variables of the frame
			  push_offset(3);
			  // init code block to store stmts
			  init_code();
			  // emit the prologue part of main()
			  emit(aload_0);
			  emit(arraylength);
			  emit2(newarray, T_INT);
			  emit(astore_1);
			  emit(iconst_0);
			  emit(istore_2);
			  label1 = pc;
			  emit(iload_2);
			  emit(aload_0);
			  emit(arraylength);
			  label2 = pc;
			  emit3(if_icmpge, PAD);
			  emit(aload_1);
			  emit(iload_2);
			  emit(aload_0);
			  emit(iload_2);
			  emit(aaload);
			  emit3(invokestatic, constant_pool_add_Methodref(&cf, "java/lang/Integer", "parseInt", "(Ljava/lang/String;)I"));
			  emit(iastore);
			  emit32(iinc, 2, 1);
			  emit3(goto_, label1 - pc);
			  backpatch(label2, pc - label2);
			  // global flag to indicate we're in main()
			  is_in_main = 1;
			}
	;

Margs	:		{ /* TASK 3: TO BE COMPLETED */
    // add code to create new table and push on tblptr and push offset 0
        Table * table = mktable(top_tblptr);
        push_tblptr(table);
        push_offset(0);
			  init_code();
			  is_in_main = 0;
			}
	;

block	: '{' decls stmts '}'
	;

decls	: decls decl
	| /* empty */
	;

decl	: list ';'
	;

type	: VOID		{ $$ = mkvoid(); }
	| INT		{ $$ = mkint(); }
	| FLOAT		{ $$ = mkfloat(); }
	| CHAR		{ $$ = mkchar(); }
	;

args	: args ',' type ptr ID
			{ if ($4 && ischar($3))
				enter(top_tblptr, $5, mkstr(), top_offset++);
			  else
				enter(top_tblptr, $5, $3, top_offset++);
			  $$ = mkpair($1, $3);
			}
	| type ptr ID	{ if ($2 && ischar($1))
				    enter(top_tblptr, $3, mkstr(), top_offset++);
			 else
				enter(top_tblptr, $3, $1, top_offset++);
			  $$ = $1;
			}
	;

list	: list ',' ptr ID
			{ if (top_tblptr->level == 0){
                    cf.fields[cf.field_count].access = ACC_STATIC;
                    cf.fields[cf.field_count].name = $4->lexptr;
                    cf.fields[cf.field_count].descriptor = $1;
                    cf.field_count++;
                    enter(top_tblptr, $4, $1, constant_pool_add_Fieldref(&cf, cf.name, $4->lexptr, $1));
              }else{
                  enter(top_tblptr, $4, $1, top_offset++);
			      $$ = $1;
              }
			}
	| type ptr ID	{
        if (top_tblptr->level == 0){
            cf.fields[cf.field_count].access = ACC_STATIC;
            cf.fields[cf.field_count].name = $3->lexptr;
            cf.fields[cf.field_count].descriptor = $1;
            cf.field_count++;
            enter(top_tblptr, $3, $1, constant_pool_add_Fieldref(&cf, cf.name, $3->lexptr, $1));
        }
	    else{
            enter(top_tblptr, $3, $1, top_offset++);
            $$ = $1;
        }
	}
	;

ptr	: /* empty */	{ $$ = 0; }
	| '*'		{ $$ = 1; }
	;

stmts   : stmts stmt
        | /* empty */
        ;

/* TASK 1: TO BE COMPLETED: */
stmt    : ';'
        | expr ';'      { emit(pop); }
        | IF '(' expr ')' M stmt
                        { backpatch($5, pc - $5); emit3(goto_, 3); }
        | IF '(' expr ')' M stmt ELSE N L stmt
                        { backpatch($5, $9 - $5); emit3(goto_, 3); backpatch($8, pc - $8);}
        | WHILE '(' L expr ')' M stmt N
                        { backpatch($6, pc - $6); backpatch($8, $3-$8); }
        | DO L  stmt WHILE '(' expr ')' M N ';'
                        { backpatch($8, pc - $8);  backpatch($9, $2-$9);}
        | FOR '(' expr ';' L expr M N ';'  L expr N ')' L stmt N
                        { backpatch($8, pc - $8); backpatch($8, $14 - $8); backpatch($16, $10-$16); backpatch($12, $5-$12  ); }
        | RETURN expr ';'
                        { if (is_in_main)
			  	                    emit(istore_2); /* TO BE COMPLETED */
			  else
			  	emit(ireturn);
			}
	| BREAK ';'	{ /* BREAK is optional to implement (see Pr3) */
			  error("break not implemented");
			}
        | '{' stmts '}'
        | error ';'     { yyerrok; }
        ;

exprs	: exprs ',' expr
	| expr
	;

/* TASK 1: TO BE COMPLETED (use pr3 code, then work on assign operators): */
expr    : ID   '=' expr {   int place;
                            Type type;
                            if (getlevel(top_tblptr, $1) == 0){
                                emit(dup);
                                emit3(putstatic, getplace(top_tblptr, $1));
                            }
                            if(getlevel(top_tblptr, $1) == 1){
                                place = getplace(top_tblptr, $1);
                                type = gettype(top_tblptr, $1);
                                if(isint(type)){emit(dup);emit2(istore, place);}
                                if(isfloat(type)){emit(dup);emit2(fstore, place);}
                            }
                        }
        | ID {int place;
              Type type;
              if (getlevel(top_tblptr, $1) == 0){
                  emit3(getstatic, getplace(top_tblptr, $1));
              }
              if(getlevel(top_tblptr, $1) == 1){
                  place = getplace(top_tblptr, $1);
                  type = gettype(top_tblptr, $1);
                  if(isint(type)){emit2(iload, place);}
                  if(isfloat(type)){emit2(fload, place);}
              }
        }
        | expr OR  expr { emit(ior);  }
        | expr AN  expr { emit(iand);  }
        | expr EQ  expr { emit3(if_icmpeq, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
        | expr NE  expr { emit3(if_icmpne, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
        | expr '<' expr { emit3(if_icmplt, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
        | expr '>' expr { emit3(if_icmpgt, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
        | expr LE  expr { emit3(if_icmple, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
        | expr GE  expr { emit3(if_icmpge, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
        | expr '+' expr { emit(iadd); }
        | expr '-' expr { emit(isub); }
        | expr '*' expr { emit(imul); }
        | expr '/' expr { emit(idiv); }
        | expr '%' expr { /* TODO: TO BE COMPLETED */ error("% operator not implemented"); }
        | '!' expr      { emit(ineg); }
        | '(' expr ')'
        | '$' INT8      { // check that we are in main()
			  if (is_in_main)
			  {	emit(aload_1);
			  	emit2(bipush, $2);
			  	emit(iaload);
			  }
			  else
			  	error("invalid use of $# in function");
			}
        | PP ID         {  emit(iadd); emit(iconst_1); }
        | NN ID         { emit(isub); emit(iconst_1); }
        | ID PP         { emit(iadd); emit(iconst_1); }
        | ID NN         { emit(isub); emit(iconst_1);}
        | ID            { emit2(iload,  getplace(top_tblptr, $1)); }
        | INT8          { emit2(bipush, $1); }
        | INT16         { emit3(sipush, $1); }
        | INT32         { emit2(ldc, constant_pool_add_Integer(&cf, $1)); }
	| FLT		{ emit2(ldc, constant_pool_add_Float(&cf, $1)); }
	| STR		{ emit2(ldc, constant_pool_add_String(&cf, constant_pool_add_Utf8(&cf, $1))); }
	| ID '(' exprs ')'{ emit3(invokestatic, constant_pool_add_Methodref(&cf, cf.name, $1->lexptr, gettype(top_tblptr, $1))); }
        ;

K       : /* empty */   { $$ = pc; emit3(ifne, 0); }
        ;

L       : /* empty */   { $$ = pc; }
        ;

M       : /* empty */   { $$ = pc;	/* location of inst. to backpatch */
			  emit3(ifeq, 0);
			}
        ;

N       : /* empty */   { $$ = pc;	/* location of inst. to backpatch */
			  emit3(goto_, 0);
			}
        ;

P       : /* empty */   { emit(pop); }
        ;

%%

int main(int argc, char **argv)
{
	// init the compiler
	init();

	// set up a new class file structure
	init_ClassFile(&cf);

	// class has public access
	cf.access = ACC_PUBLIC;

	// class name is "Code"
	cf.name = "Code";

	// field counter (incremented for each field we add)
	cf.field_count = 0;

	// method counter (incremented for each method we add)
	cf.method_count = 0;

	// allocate an array of MAXFLD fields
	cf.fields = (struct FieldInfo*)malloc(MAXFLD * sizeof(struct FieldInfo));

	// allocate an array of MAXFUN methods
	cf.methods = (struct MethodInfo*)malloc(MAXFUN * sizeof(struct MethodInfo));

	if (!cf.methods)
		error("Out of memory");

	if (argc > 1)
		if (!(yyin = fopen(argv[1], "r")))
			error("Cannot open file for reading");

	if (yyparse() || errnum > 0)
		error("Compilation errors: class file not saved");

	fprintf(stderr, "Compilation successful: saving %s.class\n", cf.name);

	// save class file
	save_classFile(&cf);

	return 0;
}

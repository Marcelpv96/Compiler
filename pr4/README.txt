
To test mycc, use:

csh test.sh

The tests are not exhaustive but gives a good indication of coverage.

The test codes test*.uc are most important, since they test specific features.

NOTES:

1. It will save you a lot of time if you implement a generic "emit operation"
   function for all 2-ary operations. Same for the assignment operations:

   expr    : ID   '=' expr { $$ = < emit assignment $1, &$3, nop, nop > }
           | ID   PA  expr { $$ = < emit assignment $1, &$3, iadd, fadd > }
	   | ...

           | expr LS  expr { $$ = < emit oper &$1, &$3, ishl, nop > } 
           | expr RS  expr { $$ = < emit oper &$1, &$3, ishr, nop > } 
           | expr '+' expr { $$ = < emit oper &$1, &$3, iadd, fadd > }

   your < emit assignment > function generates code using emit for integer and
   floating point (nop when no floating point equivalent exists).

2. To implement short-circuit evaluation, please use the material in the
   project description, the lecture notes, and textbook. Implement the
   relational operators by returning $$.type = NULL and set the $$.truelist and
   $$.falselist. This indicates that the "value" of the relational operaration
   is short-circuit. Therefore, when a short-circuit value is used as an
   integer value, you need to convert it. Write a "de-circuit" function that
   generates code when type == NULL to convert a short-circuit "value" to an
   integer 0 or 1. You can do the same for convering an integer to
   short-circuit code.

   For example:

        | RETURN expr ';'
                        { < de-circuit &$2 >;
                          ...

3. To implement backpatchlist() you can call the backpatch() operation from
   bytecode.c. Note that backpatch() uses a relative offset, not an absolute
   location, so you need to calculate the relative offset.

4. Implementing functions. The approach in the project description does not
   allow them to be recursive, since the function name is not added to the
   table before the function body is parsed.

   If you want recursion, redefine the production:

   func : head block
		{ ... }

   head : type ptr ID '(' Margs args ')'
		{ use enterproc() with table = NULL to add the function name
		  ...
		}

   The above approach can also use the 'ftype' as suggested in the project.

5. For type checking and coercion, it helps if you write function(s) that
   convert the topmost value of the stack to int/float and the second topmost
   value. This way, you can call the conversion fucntion(s) and they will
   convert the top values if needed. This is necessary to integer operations on
   floats. You may also want to write a function that determines the widest type
   of two operands, so "int + float" gives floating point fadd and the second
   topmost value is converted to float first using swap, i2f, swap by your
   conversion function.

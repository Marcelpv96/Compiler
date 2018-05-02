CC=c++
YACC=bison -y
#YACC=yacc
LEX=reflex/bin/reflex --bison
#LEX=flex
#LEX=lex
LIBS=reflex/lib/libreflex.a
COFLAGS=-g -O2
CWFLAGS=-Wall -Wextra
CIFLAGS=-I. -Ireflex/include
CMFLAGS=
CFLAGS=$(CWFLAGS) $(COFLAGS) $(CIFLAGS) $(CMFLAGS)
all:		mycc
mycc:		mycc.c bytecode.o error.o init.o javaclass.o lex.yy.cpp symbol.o
		$(CC) $(CFLAGS) -o mycc mycc.c bytecode.o error.o init.o javaclass.o lex.yy.cpp symbol.o $(LIBS)
mycc.c:		mycc.l mycc.y
		$(LEX) -+ --header-file=lex.yy.h mycc.l
		$(YACC) -o mycc.c -d -v mycc.y
.c.o:
		$(CC) $(CFLAGS) -c $<
.cpp.o:
		$(CC) $(CFLAGS) -c $<

.PHONY:		clean distclean
clean:
		-rm -f *.o
distclean:
		-rm -f mycc *.o mycc.h mycc.c lex.yy.h lex.yy.cpp mycc.output Code.class

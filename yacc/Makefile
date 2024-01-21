YFLAGS  = -dy

all: dropword mol

dropword: dropword.cc
	g++ dropword.cc -o dropword

mol: lexer.o parser.o 
	cc lexer.o parser.o -o mol

lexer.o: parser.o

clean:
	rm -f *.o y.tab.h mol dropword

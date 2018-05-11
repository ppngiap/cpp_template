all: factorial_ast factorial_gcc fibonacci_ast fibonacci_gcc mtuple_ast mtuple_gcc

factorial_ast: factorial.cpp
	clang++ -std=c++11 -Xclang -ast-print -fsyntax-only factorial.cpp > factorial.ast

factorial_gcc: factorial.cpp
	g++ -std=c++11 -save-temps -o factorial factorial.cpp

fibonacci_ast: fibonacci.cpp
	clang++ -std=c++11 -Xclang -ast-print -ftemplate-depth=10000 -fsyntax-only fibonacci.cpp > fibonacci.ast

fibonacci_gcc: fibonacci.cpp
	g++ -std=c++11 -save-temps -o fibonacci fibonacci.cpp

mtuple_ast: mtuple.cpp
	clang++ -std=c++11 -Xclang -ast-print -fsyntax-only mtuple.cpp > mtuple.ast

mtuple_gcc: mtuple.cpp
	g++ -std=c++11 -save-temps -o mtuple mtuple.cpp


clean:
	rm factorial
	rm fibonacci

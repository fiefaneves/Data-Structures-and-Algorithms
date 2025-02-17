.PHONY : test1 test2 test3 test4 clean

solver: solver.cpp 
	g++ solver.cpp -o solver

test1: solver 
	./solver < 1.in > saida.1
	diff 1.out saida.1

test2: solver 
	./solver < 2.in > saida.2
	diff 2.out saida.2

test3: solver 
	./solver < 3.in > saida.3
	diff 3.out saida.3

test4: solver 
	./solver < 4.in > saida.4
	diff 4.out saida.4

clean: 
	rm -f solver saida.*


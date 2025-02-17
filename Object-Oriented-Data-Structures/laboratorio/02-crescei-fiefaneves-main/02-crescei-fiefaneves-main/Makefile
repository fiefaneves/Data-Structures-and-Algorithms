.PHONY : clean sanity-test

sanity: sanity.cpp list.hpp
	g++ sanity.cpp -o sanity

sanity-check: sanity
	./sanity
	@echo "SANITY CHECK OK"

.PHONY : test1 test2 test3 test4 test5 clean

solver: solver.cpp  
	g++ solver.cpp -o solver

test1: solver 
	./solver < 1.in > saida.1
	diff 1.out saida.1
	@echo "TEST 1 OK"

test2: solver 
	./solver < 2.in > saida.2
	diff 2.out saida.2
	@echo "TEST 2 OK"

test3: solver 
	./solver < 3.in > saida.3
	diff 3.out saida.3
	@echo "TEST 3 OK"

test4: solver 
	./solver < 4.in > saida.4
	diff 4.out saida.4
	@echo "TEST 4 OK"

test5: solver 
	./solver < 5.in > saida.5
	diff 5.out saida.5
	@echo "TEST 5 OK"

clean: 
	rm -f sanity solver saida.*


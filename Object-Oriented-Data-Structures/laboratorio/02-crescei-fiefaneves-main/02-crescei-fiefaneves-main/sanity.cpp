

//////////////////////////////////////////////////////////
// ATENCAO:                                             //
// NAO MODIFIQUE ESTE ARQUIVO                           //
// Este programa serve para testar a conformidade com   // 
// as instrucoes de implementacao do problema.          //
// Modifique os demais codigos-fonte de forma que estes // 
// testes funcionem corretamente.                       //
//////////////////////////////////////////////////////////



#include <cassert>
#include <iostream>

#include "list.hpp"

using namespace std;

template <typename T>
void testLinkedList(T min, T max)
{
	int n = 0;
	assert(min <= max);
	for (T cur = min; cur < max; cur++, n++);
	int half = n / 2;

	List<T> *il = new LinkedList<T>();

	T cur = min;
	for (int i = 0; i < half; i++) {
		il->append(cur);
		cur++;
	}
	cur = max;
	for (int i = n; i >= half; i--) {
		il->insert(half, cur);
		cur--;
	}
	cur = min;
	for (int i = 0; i < n; i++) {
		T exp = (*il)[i];
		cout << exp << "\n";
		assert(exp == cur);
		cur++;
	}
	delete il;
}

void testStack()
{
	cout << "Testing stack: \n";
	SQ<int> sq1(STACK);
	int n = 201;
	for (int i = 0; i < n; i++) {
		sq1.push(i);
	}
	int half = n / 2;
	
	SQ<int>* sq2= sq1.split();
	
	assert(sq1.size() == half);
	assert(sq2->size() == n-half);

	for (int i = 0; i < half; i++ ) {
		int x = sq1.pop();
		cout << x << " ?= " << n-1-i << "\n";
		assert (x == n-1-i);
	}
	cout << "---\n";
	for (int i = half; i < n; i++ ) {
		int x = sq2->pop();
		cout << x << " ?= " << n-1-i << "\n";
		assert (x == n-1-i);
	}

	for (int i=0; i< half; i++) {
		sq2->push(i);
	}
	for (int i=half; i< n; i++) {
		sq1.push(i);
	}
	sq1.merge(sq2);
	for (int i = 0; i < n; i++) {
		int x = sq1.pop();
		cout << x << " ?= " << n-1-i << "\n";
		assert (x == n-1-i);
	}
	assert(sq1.size() == 0);
	assert(sq2->size() == 0);
	delete sq2;
}


void testQueue()
{
	cout << "Testing queue: \n";
	SQ<int> sq1(QUEUE);
	int n = 201;
	for (int i = 0; i < n; i++) {
		sq1.push(i);
	}
	int half = n / 2;
	
	SQ<int>* sq2= sq1.split();
	
	assert(sq1.size() == half);
	assert(sq2->size() == n-half);

	for (int i = 0; i < half; i++ ) {
		int x = sq1.pop();
		cout << x << " ?= " << i << "\n";
		assert (x == i);
	}
	cout << "---\n";
	for (int i = half; i < n; i++ ) {
		int x = sq2->pop();
		cout << x << " ?= " << i << "\n";
		assert (x ==i);
	}

	for (int i=half; i< n; i++) {
		sq2->push(i);
	}
	for (int i=0; i< half; i++) {
		sq1.push(i);
	}
	sq1.merge(sq2);
	for (int i = 0; i < n; i++) {
		int x = sq1.pop();
		cout << x << " ?= " << i << "\n";
		assert (x == i);
	}
	assert(sq1.size() == 0);
	assert(sq2->size() == 0);
	delete sq2;
}


int main()
{
	int imin = 10;
	int imax = 30;
	testLinkedList(imin, imax);

	char cmin = '0';
	char cmax = 'Z';
	testLinkedList(cmin, cmax);

	double dmin = 27.0;
	double dmax = 48.0;
	testLinkedList(dmin, dmax);

	testStack();
	testQueue();
}

#include <bits/stdc++.h>
#include <cassert>
#include <iostream>

using namespace std;

class Stack
{
private:
	class Node
	{
	public:
		int element;
		Node* next;
		Node(int v, Node* n) : element(v), next(n) {}
		~Node() = default;
	};
	
	Node* top;
	int size;

public:
	Stack() : top(nullptr), size(0) {}
	~Stack() = default;
	
	void push(int v){
		top = new Node(v, top);
		size++;
	}

	int pop(){
		if (size == 0) return -1;
		int v = top->element;
		Node* n = top;
		top = top->next;
		delete n;
		size--;
		return v;
	}

	int len(){
		return size;
	}

	bool is_empty(){
		return size == 0;
	}

	void clear(){
		while (not is_empty()){
			pop();
		}
	}
	
};

class Deque
{
private:
	class Node
	{
	public:
		int element;
		Node* prev;
		Node* next;
		Node(int v, Node* p, Node* n) : element(v), prev(p), next(n) {}
		~Node() = default;
	};

	Node* front;
	Node* back;
	int size;

public:
	Deque() : front(nullptr), back(nullptr), size(0) {};
	~Deque() = default;

	void push_front(int v){
		if (size == 0){
			front = new Node(v, nullptr, nullptr);
			back = front;
		} else {
			front = new Node(v, nullptr, front);
			front->next->prev = front;
		}
		size++;
	}

	void push_back(int v){
		if (size == 0){
			back = new Node(v, nullptr, nullptr);
			front = back;
		} else {
			back = new Node(v, back, nullptr);
			back->prev->next = back;
		}
		size++;
	}

	int pop_front(){
		if (size == 0) return -1;
		int v = front->element;
		Node* n = front;
		front = front->next;
		if (front != nullptr) front->prev = nullptr;
		delete n;
		size--;
		return v;
	}

	int pop_back(){
		if (size == 0) return -1;
		int v = back->element;
		Node* n = back;
		back = back->prev;
		if (back != nullptr) back->next = nullptr;
		delete n;
		size--;
		return v;
	}

	int len(){
		return size;
	}

	bool is_empty(){
		return size == 0;
	}

	void clear(){
		while (not is_empty()){
			pop_front();
		}
	}

};

//E0 = entrada T0
//S0 = sáida do vagão de T0, se houver
//E1E = entrada T1 pela esquerda
//E1D = entrada T1 pela direita
//S1E = saída do vagão de T1 pela esquerda, se houver
//S1D = saída do vagão de T1 pela direita, se houver

int main()
{
	// freopen("1.in", "r", stdin);

	string op;
	int next_car = 0;
	Stack t0;
	Deque t1;
	while (cin >> op) {
		if (op == "E0"){
			t0.push(next_car);
			next_car++;
		} else if (op == "E1E"){
			t1.push_front(next_car);
			next_car++;
		} else if (op == "E1D"){
			t1.push_back(next_car);
			next_car++;
		} else if (op == "S0" and not t0.is_empty()){
			cout << t0.pop() << endl;
		} else if (op == "S1E" and not t1.is_empty()){
			cout << t1.pop_front() << endl;
		} else if (op == "S1D" and not t1.is_empty()){
			cout << t1.pop_back() << endl;
		}

		if (op == "FIM"){
			cout << t0.len() << endl;
			cout << t1.len() << endl;
			t0.clear();
			t1.clear();
			next_car = 0;
			cout << endl;
		}
	}

}
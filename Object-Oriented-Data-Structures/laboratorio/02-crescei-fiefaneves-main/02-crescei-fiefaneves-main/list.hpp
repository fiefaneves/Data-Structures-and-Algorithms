#pragma once

#include <cassert>
#include <iostream>
#include <bits/stdc++.h>


template <typename T>
class List
{
public:
	virtual ~List() {};
	int& size(){ // retorna o tamanho da lista
		return sz;
	}
	virtual T &operator[](int pos) = 0;  // retorna o elemento da posicao pos
	virtual void insert(int pos, T val) = 0; // insere val na posicao pos
	void append(T val){ // adiciona ao final
		insert(sz, val);
	}
	void prepend(T val){ // adiciona no inicio
		insert(0, val);
	}
	virtual T remove(int pos) = 0; // remove e retorna o elemento da posicao pos
protected:
	int sz{0}; // tamanho da lista
};

//
// Lista encadeada
//
template <typename T>
class LinkedList : public List<T>
{
	// Tipo no da lista encadeada
	struct Node {
        explicit Node() {};
		explicit Node(T v): val(v), next(nullptr) {}
		~Node() {
			//cout << "deleting " << val << endl;
		}
		T val;
		Node *next=nullptr;
	};

public:
	LinkedList(){head = new Node(); this->size() = 0;};
	~LinkedList(){
        Node *cur = head;
        while (cur != nullptr) {
            Node *next = cur->next;
            delete cur;
            cur = next;
        }
    }

	// metodos da interface List
	T &operator[](int pos) override{
		assert(pos <= this->size());
		return locate(pos)->next->val;
	}

	void insert(int pos, T val) override{
		assert(pos <= this->size());
        Node *cur = locate(pos);
        Node *new_node = new Node(val);
        new_node->next = cur->next;
        cur->next = new_node;
        this->size()++;
	}

	T remove(int pos) override{
		assert(pos < this->size());
		Node *cur = locate(pos);
		Node *to_die = cur->next;
		cur->next = to_die->next;
		T ret = to_die->val;
		delete to_die;
		this->size()--;
		return ret;
	}

	void clear(){
		Node *cur = head->next;
		while (cur != nullptr) {
			Node *next = cur->next;
			delete cur;
			cur = next;
		}
		head->next = nullptr;
		this->size() = 0;
	}

public:
	// Metodos adicionais

	// Concatena a lista other ao final desta lista
	/*Os elementos devem ser removidos de other
	mas a lista other nao deve ser destruida*/
	void merge(LinkedList<T> *other){
		Node *cur = head;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = other->head->next;
		this->size() += other->sz;
		other->head->next = nullptr;
		other->sz = 0;
	}

	// Divide a lista de duas metades.
	// Esta lista fica com os primeiros floor(n/2) elementos.
	// Os restantes elementos sao colocados numa nova lista
	// // retornada pelo metodo.

	LinkedList<T> *split(){
		LinkedList<T> *new_list = new LinkedList<T>();
		if (this->size() == 0){
			return new_list;
		} else if (this->size() == 1){
			new_list->head->next = head->next;
			head->next = nullptr;
			this->size() = 0;
			new_list->size() = 1;
			return new_list;
		}
		int mid = this->size() / 2;

		Node *cur = head;
		for (int i = 0; i < mid; i++) {
			cur = cur->next;
		}
		new_list->head->next = cur->next;
		cur->next = nullptr;
		new_list->size() = this->size() - mid;
		this->size() = mid;
		return new_list;
	}

private:
	Node *locate(int pos){ // localiza o no da posicao pos
        Node *cur = head;
        for(int i = 0; i < pos && cur->next != nullptr; i++){
            cur = cur->next;
        }
        return cur;
	}

	Node *head;
};

//
// Tipos de SQ
//
enum TYPE {
	STACK = 0, // Pilha
	QUEUE = 1  // FIla
};

//
// Classe para representar objetos que podem ser pilha ou fila
//
template <typename T>
class SQ
{
public:
	TYPE Type() const{ // retorna o tipo da SQ (vide enum TYPE)
		return type;
	}

	SQ(TYPE t): type(t) {} // recebe o tipo do SQ na construcao

	const T &peek(){ // retorna uma referencia para o elemento no topo/frente da pilha/fila
		if (type == STACK) {
			return list[0];
		} else {
			return list[0];
		}
	}

	void push(T val){ // empilha/enfileira
		if (type == QUEUE) {
			list.append(val);
		} else {
			list.prepend(val);
		}
	}

	T pop(){ // desempilha/desenfileira
		if (type == QUEUE && list.size() > 0) {
			return list.remove(0);
		} else if (type == STACK && list.size() > 0) {
			return list.remove(0);
		}
		return T();
	}

	void transform(){ // transforma de pilha para fila ou vice versa
		if (type == STACK) {
			type = QUEUE;
		} else {
			type = STACK;
		}
	}

	// Divide como no enunciado:
	// os primeiros floor(n/2) elementos permanecesm nesta SQ
	// e os demais sao retornados numa nova SQ
	SQ<T> *split(){
		LinkedList<T> *new_list = list.split();
		SQ<T> *new_sq = new SQ<T>(type);
		new_sq->list.merge(new_list);
		delete new_list;
		return new_sq;
	}

	// Combina como enunciado:
	// os elementos de other sao transferidos para esta SQ,
	// de forma que other fica vazia, mas nao eh destruida
	void merge(SQ<T> *other){
		if (type == other->Type()) {
			list.merge(&other->list);
		}
	}

	int size(){
		return list.size();
	}

	void clear(){
		list.clear();
	}

private:
	TYPE type; // tipo da SQ
	LinkedList<T> list; // lista que armazena os elementos
};
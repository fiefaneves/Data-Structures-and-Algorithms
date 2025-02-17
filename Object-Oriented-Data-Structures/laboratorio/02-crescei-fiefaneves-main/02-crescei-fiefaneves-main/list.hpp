#pragma once

#include <cassert>
#include <iostream>
#include <bits/stdc++.h>


// -----------------------------------------------------------------
// DECLARACOES DOS TAD
// -----------------------------------------------------------------

//
// Classe abstrata/Interface para listas
//
template <typename T>
class List
{
public:
	virtual ~List() {};
	int size() const; // retorna o tamanho da lista
	virtual T &operator[](int pos) = 0;  // retorna o elemento da posicao pos
	virtual void insert(int pos, T val) = 0; // insere val na posicao pos
	void append(T val); // adiciona ao final
	void prepend(T val); // adiciona no inicio
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
		explicit Node(T v, Node *nxt = nullptr): val{v}, next{nxt} { }
		explicit Node(Node *nxt = nullptr): next{nxt} { }
		~Node() {
			//cout << "deleting " << val << endl;
		}
		T val;
		Node *next=nullptr;
	};

public:
	// LinkedList();
	// ~LinkedList();

	LinkedList(){head = new Node(); this->sz = 0;};
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
		assert(pos < this->sz);
		return locate(pos)->next->val;
	}
	void insert(int pos, T val) override{
		assert(pos <= this->sz);
        Node *cur = locate(pos);
        Node *new_node = new Node(val);
        new_node->next = cur->next;
        cur->next = new_node;
        this->sz++;
	}
	T remove(int pos) override{
		assert(pos < this->sz);
		Node *cur = locate(pos);
		Node *to_die = cur->next;
		cur->next = to_die->next;
		T ret = to_die->val;
		delete to_die;
		this->sz--;
		return ret;
	}

public:
	// Metodos adicionais

	// Concatena a lista other ao final desta lista
	// Os elementos devem ser removidos de other
	// mas a lista other nao deve ser destruida
	void merge(LinkedList<T> *other){
		Node *cur = head;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = other->head->next;
		//this->sz += other->this->sz; //?
		this->sz += other->sz;
		other->head->next = nullptr;
		other->sz = 0;
	}

	// Divide a lista de duas metades.
	// Esta lista fica com os primeiros floor(n/2) elementos.
	// Os restantes elementos sao colocados numa nova lista
	// retornada pelo metodo.
	LinkedList<T> *split(){
		if (this->sz < 2) return nullptr;
		LinkedList<T> *new_list = new LinkedList<T>();
		
		int mid = this->sz / 2;
		Node *cur = head;
		for (int i = 0; i < mid; i++) {
			cur = cur->next;
		}

		new_list->head->next = cur->next;
		cur->next = nullptr;

		new_list->sz = this->sz - mid;
		this->sz = mid;
		return new_list;
	}

	int size() const{
		return this->sz;
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
	int size() const;{ // retorna o numero de elementos na SQ
		return list.size();
	}
	const T &peek(){ // retorna uma referencia para o elemento no topo/frente da pilha/fila
		if (type == STACK) {
			return list[list.size() - 1];
		} else {
			return list[0];
		}
	}
	void push(T val); // empilha/enfileira
	T pop(); // desempilha/desenfileira
	void transform(); // transforma de pilha para fila ou vice versa
	// Divide como no enunciado:
	// os primeiros floor(n/2) elementos permanecesm nesta SQ
	// e os demais sao retornados numa nova SQ
	SQ<T> *split();
	// Combina como enunciado:
	// os elementos de other sao transferidos para esta SQ,
	// de forma que other fica vazia, mas nao eh destruida
	void merge(SQ<T> *other);
private:
	TYPE type; // tipo da SQ
	LinkedList<T> list; // lista que armazena os elementos

	// ADD CODE HERE
	// Lembre da composicao
};

template <typename T>
int List<T>::size() const
{
	return this->sz;
}


// ADD CODE HERE
// Definicoes dos metodos


/*
template <typename T>
class SQ {
private:
    LinkedList<T> list;
    TYPE type;

public:
    SQ(TYPE t) : type(t) {}

    TYPE Type() const {
        return type;
    }

    int size() const {
        return list.size();
    }

    const T& peek() {
        if (type == STACK) {
            return list[list.size() - 1];
        } else {
            return list[0];
        }
    }

    void enqueue(T val) {
        if (type == QUEUE) {
            list.insert(list.size(), val);
        }
    }

    void dequeue() {
        if (type == QUEUE && list.size() > 0) {
            list.remove(0);
        }
    }

    void push(T val) {
        if (type == STACK) {
            list.insert(list.size(), val);
        }
    }

    void pop() {
        if (type == STACK && list.size() > 0) {
            list.remove(list.size() - 1);
        }
    }

    void split() {
        LinkedList<T>* newList = list.split();
        if (newList) {
            // Handle the new list as needed
        }
    }

    void merge(SQ<T>& other) {
        if (type == other.Type()) {
            list.merge(&other.list);
        }
    }

    void transform() {
        if (type == STACK) {
            type = QUEUE;
        } else {
            type = STACK;
        }
    }
};
*/
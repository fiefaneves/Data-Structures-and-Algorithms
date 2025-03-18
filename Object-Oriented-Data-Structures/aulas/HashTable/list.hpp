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

	T search(T val){
		Node *cur = head->next;
		while (cur != nullptr) {
			if (cur->val == val) {
				return cur->val;
			}
			cur = cur->next;
		}
		return T();
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
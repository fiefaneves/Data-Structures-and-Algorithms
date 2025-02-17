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
		~Node() {}

		// ADD CODE HERE
		// atributos
	};

public:
	LinkedList();
	~LinkedList();
	// metodos da interface List
	T &operator[](int pos) override;
	void insert(int pos, T val) override;
	T remove(int pos) override;

public:
	// Metodos adicionais

	// Concatena a lista other ao final desta lista
	// Os elementos devem ser removidos de other
	// mas a lista other nao deve ser destruida
	void merge(LinkedList<T> *other);

	// Divide a lista de duas metades.
	// Esta lista fica com os primeiros floor(n/2) elementos.
	// Os restantes elementos sao colocados numa nova lista
	// retornada pelo metodo.
	LinkedList<T> *split();

private:
	Node *locate(int pos); // localiza o no da posicao pos

	// ADD CODE HERE
	// atributos
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
	TYPE Type() const; // retorna o tipo da SQ (vide enum TYPE)
	SQ(TYPE t); // recebe o tipo do SQ na construcao
	int size() const; // retorna o numero de elementos na SQ
	const T &peek(); // retorna uma referencia para o elemento no topo/frente da pilha/fila
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

	// ADD CODE HERE
	// Lembre da composicao
};


// -----------------------------------------------------------------
// IMPLEMENTACOES DOS TAD
// -----------------------------------------------------------------


template <typename T>
int List<T>::size() const
{
	return this->sz;
}


// ADD CODE HERE
// Definicoes dos metodos

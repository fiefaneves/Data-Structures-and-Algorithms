#include <bits/stdc++.h>

using namespace std;

template <typename T>
class List
{
public:
	virtual ~List() {}
	int size(){
		return sz;
	};

	virtual T get(int pos) = 0;

	virtual void insert(int pos, T val) = 0;

	void append(T val){
		insert(size(), val);
	}

	void prepend(T val){
		insert(0, val);
	}

	virtual T remove(int pos) = 0;

protected:
	int sz{0};
};

template <typename T>
class LinkedList : public List<T>
{
	struct Node {
        Node() {};
		Node(T v,  Node *nxt = nullptr): val{v}, next{nxt} { }
		~Node(){
			//cout << "deleting " << val << endl;
		}
		T val;
		Node *next=nullptr;
	};

public:
	LinkedList(){head = new Node(); this->sz = 0;};
	~LinkedList(){
        Node *cur = head;
        while (cur != nullptr) {
            Node *next = cur->next;
            delete cur;
            cur = next;
        }
    }

	T get(int pos){
        assert(pos < this->sz);
        return locate(pos)->next->val;
    }

	void insert(int pos, T val){
        assert(pos <= this->sz);
        Node *cur = locate(pos);
        Node *new_node = new Node(val);
        new_node->next = cur->next;
        cur->next = new_node;
        this->sz++;
    }

	T remove(int pos){
        assert(pos < this->sz);
        Node *cur = locate(pos);
        Node *to_die = cur->next;
        cur->next = to_die->next;
        T ret = to_die->val;
        delete to_die;
        this->sz--;
        return ret;
    }

    void print(){
        for (int i = 0; i < this->sz; i++) {
            cout << (i?", ":"") << get(i);
        }
        cout << endl;
    }

private:
	Node *locate(int pos){
        Node *cur = head;
        for(int i = 0; i < pos && cur->next != nullptr; i++){
            cur = cur->next;
        }
        return cur;
    }
	Node *head;
};

/*
template <typename T>
class ArrayList : public List<T>
{
	static const int DEFAULT_CAPACITY = 1;
public:
	ArrayList(int initial_cap){
        cap = initial_cap;
        sz = 0;
        arr = new T[cap];
    }
	~ArrayList(){
        cout << "destucting arraylist" << endl;
	    delete[] arr;
    }

	T get(int pos){
		return arr[pos];
	}

	void insert(int pos, T val){
        check_and_double();
        pos = (pos > sz) ? sz : pos;
        for (int i = sz; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = val;
        sz++;
    }

	T remove(int pos){
        if (pos >= sz) {
            cout << "Out of bounds" << endl;
            exit(1);
        }
        T ret = arr[pos];
        for (int i = pos; i < sz - 1; i++) {
            arr[i] = arr[i + 1];
        }
        sz--;
        return ret;
    }

private:
	int cap;
	T *arr;
	void check_and_double(){
        if (sz < cap) return;
        cout << "Doubling" << endl;
        int new_cap = 2 * cap;
        T *new_arr = new T[new_cap];
        for (int i = 0; i < sz; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        cap = new_cap;
    }
};
*/

template <typename T> void printList(List<T> *list){
    for (int i = 0; i < list->size(); i++) {
        cout << (i?", ":"") << list->get(i);
    }
    cout << endl;
}

int main()
{
        // List of ints
	// LinkedList<int> list;
    // int n = 20;
    // for (int i = 0; i < n; i++) {
    //     list.append(i);
    // }
    // list.printList();

        // List of doubles
    LinkedList<double> doubleList;
    int n = 20;
    for (int i = 0; i < n; i++) {
        doubleList.append(i + 0.5);
    }
    printList(&doubleList);

        // List of chars
    LinkedList<char> charList;
    for (char c = 'a'; c <= 'z'; c++) {
        charList.append(c);
    }
    charList.print();

        // List of lists of chars
    List<List<char>*> *all = new LinkedList<List<char>*>();
    for (int i = 0; i < 10; i++) {
        all->append(new LinkedList<char>());
        for (int j = 0; j < 5; j++) {
            all->get(i)->append('a' + (5*i)+j);
        }
    }
    for (int i = 0; i < 10; i++) {
        printList(all->get(i));
    }
    for (int i = 0; i < 10; i++) {
        delete all->remove(0);
    }
    delete all;

	// int n = 1 << 4;
	// for (int i = 0; i < n; i++) {
	// 	list.append(2 * i);
	// }
	// int half = n / 2;
	// for (int i = 0; i < half; i++) {
	// 	list.remove(i);
	// }
	// for (int i = 0; i < half; i++) {
	// 	list.insert(2 * i, 4 * i);
	// }
    // list.printList();
}
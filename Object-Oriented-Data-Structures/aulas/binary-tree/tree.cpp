#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* left = nullptr;
    Node* right = nullptr;
    // Node<T>* left;
    // Node<T>* right;
};

template <typename T>

void printTree(Node<T>* root, int level=0) {
    if (root == nullptr) return; //caso base
    for (int i = 0; i < level; i++) {
        cout << "  ";
    }
    cout << root->data << endl;
    printTree(root->left, level + 1);
    printTree(root->right, level + 1);
    
}

using intNode = Node<int>;
using charNode = Node<char>;

int main() {
    charNode j{'J'};
    charNode h{'H'};
    charNode i{'I'};
    charNode d{'D'};
    charNode e{'E', /*left*/ &j};
    charNode f{'F', &h, /*right*/ &i};
    charNode g{'G'};
    charNode b{'B', &d, &e};
    charNode c{'C', &f, &g};
    charNode a{'A', &b, &c};

    printTree(&a, 0);
    return 0;
}
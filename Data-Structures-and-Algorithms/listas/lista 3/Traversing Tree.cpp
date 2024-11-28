#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct BSTNode{
    int key;
    int element;
    BSTNode *left;
    BSTNode *right; 
};

struct BST{
    BSTNode *root;
    int nodecount;
};

BSTNode *create_bstnode(int k, int e){
    BSTNode *n = new BSTNode;
    n->key = k;
    n->element = e;
    n->left = n->right = NULL;
    return n;
}

BST *create_bst(){
    BST *bst = new BST;
    bst->root = NULL;
    bst->nodecount = 0;
    return bst;
}

BSTNode *inserthelp(BSTNode *rt, int k, int e){
    if (rt == NULL){
        return create_bstnode(k,e);
    }
    if (rt->key > k){
        rt->left = inserthelp(rt->left, k, e);
    }
    else{
        rt->right = inserthelp(rt->right, k, e);
    }
    return rt;
}

void insert(BST *bst, int k, int e){
    bst->root = inserthelp(bst->root, k, e);
    bst->nodecount++;
}

void preorder(BSTNode *rt){
    if (rt != NULL){
        cout << ' ' << rt->element; 
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(BSTNode *rt){
    if (rt != NULL){
        inorder(rt->left);
        cout << ' ' << rt->element;
        inorder(rt->right);
    }
}

void postorder(BSTNode *rt){
    if (rt != NULL){
        postorder(rt->left);
        postorder(rt->right);
        cout << ' ' << rt->element;
    }
}

int main(){
    int n; cin >> n;
    int data;
    BST *bst = create_bst();
    for (int i = 0; i < n; i++){
        cin >> data;
        insert(bst, data, data);
    }
    cout << "Pre order :";
    preorder(bst->root);
    cout << '\n';
    cout << "In order  :";
    inorder(bst->root);
    cout << '\n';
    cout << "Post order:";
    postorder(bst->root);
}
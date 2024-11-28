#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct BSTNode{
    int key;
    int element;
    BSTNode *left; //left child
    BSTNode *right; //right child
};

struct BST{
    BSTNode *root;
    int nodecount; //number of elements
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

int findhelp(BSTNode *rt, int k){
    if (rt == NULL){
        return NULL;
    }
    if (rt->key > k){
        return findhelp(rt->left, k);
    }
    else if (rt->key == k){
        return rt->element;
    }
    else{
        return findhelp(rt->right, k);
    }
}

int find(BST *bst, int k){
    return findhelp(bst->root, k);
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

BSTNode *getmin(BSTNode *rt){
    if (rt->left == NULL){
        return rt;
    }
    return getmin(rt->left);
}

BSTNode *deletemin(BSTNode *rt){
    if (rt->left == NULL){
        return rt->right;
    }
    rt->left = deletemin(rt->left);
    return rt;
}

BSTNode *removehelp(BSTNode *rt, int k){
    if (rt == NULL){
        return NULL;
    }
    if (rt->key > k){
        rt->left = removehelp(rt->left, k);
    }
    else if (rt->key < k){
        rt->right = removehelp(rt->right, k);
    }
    else{
        if (rt->left == NULL){
            return rt->right;
        }
        else if (rt->right == NULL){
            return rt->left;
        }
        else{
            BSTNode *temp = getmin(rt->right);
            rt->element = temp->element;
            rt->key = temp->key;
            rt->right = deletemin(rt->right);
        }
    }
    return rt;
}

int remove(BST *bst, int k){
    int temp = findhelp(bst->root, k);
    if (temp != NULL){
        bst->root = removehelp(bst->root, k);
        bst->nodecount--;
    }
    return temp;
}

//traversals

void preorder(BSTNode *rt){
    if (rt != NULL){
        cout << rt->element << ' ';
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(BSTNode *rt){
    if (rt != NULL){
        inorder(rt->left);
        cout << rt->element << ' ';
        inorder(rt->right);
    }
}

void postorder(BSTNode *rt){
    if (rt != NULL){
        postorder(rt->left);
        postorder(rt->right);
        cout << rt->element;
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
    cout << "Pre order : ";
    preorder(bst->root);
    cout << '\n';
    cout << "In order  : ";
    inorder(bst->root);
    cout << '\n';
    cout << "Post order: ";
    postorder(bst->root);
    cout << '\n';
}
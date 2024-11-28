#include <bits/stdc++.h>

using namespace std;

struct BSTNode{
    int key;
    int element;
    int height;
    int count;
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
    n->height = -1;
    n->count = 1;
    n->left = n->right = NULL;
    return n;
}

BST *create_bst(){
    BST *bst = new BST;
    bst->root = NULL;
    bst->nodecount = 0;
    return bst;
}

int h(BSTNode *rt){
    if (rt == NULL){
        return -1;
    }
    return rt->height;
}

int getBalance (BSTNode *rt){
    if (rt == NULL){
        return 0;
    }
    return h(rt->left) - h(rt->right);
}

int getcount(BSTNode *rt){
    if (rt == NULL){
        return 0;
    }
    else{
        return rt->count;
    }
}

BSTNode *rightRotate(BSTNode *rt){
    BSTNode *l = rt->left;
    BSTNode *lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->count = 1 + getcount(rt->left) + getcount(rt->right);
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->count = 1 + getcount(l->left) + getcount(l->right);
    l->height = max(h(l->left), h(l->right)) + 1;
    return l;
}

BSTNode *leftRotate(BSTNode *rt){
    BSTNode *r = rt->right;
    BSTNode *rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->count = 1 + getcount(rt->left) + getcount(rt->right);
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->count = 1 + getcount(r->left) + getcount(r->right);
    r->height = max(h(r->left), h(r->right)) + 1;
    return r; 
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

    rt->count = 1 + getcount(rt->left) + getcount(rt->right);
    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);
    if(balance < -1 && k >= rt->right->key){
        return leftRotate(rt);
    }
    if(balance > 1 && k < rt->left->key){
        return rightRotate(rt);
    }
    if(balance > 1 && k >= rt->left->key){
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if(balance < -1 && k < rt->right->key){
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }
    return rt;
}

void insert(BST *bst, int k, int e){
    bst->root = inserthelp(bst->root, k, e);
    bst->nodecount++;
}

int findindexhelp(BSTNode *rt, int k){
    if (rt == NULL){
        return -1000000000;
    }
    if (rt->key > k){
        return findindexhelp(rt->left, k);
    }
    else if (rt->key == k){
        return 1 + getcount(rt->left);
    }
    else{
        return 1 + getcount(rt->left) + findindexhelp(rt->right, k);
    }
}

int findindex(BST *bst, int k){
    return findindexhelp(bst->root, k);
}

int main(){
    int n; cin >> n;
    int command;
    int data;
    BST *bst = create_bst();
    for (int i = 0; i < n; i++){
        cin >> command;
        if (command == 1){
            cin >> data;
            insert(bst, data, data);
        }
        else if(command == 2){
            cin >> data;
            int index = findindex(bst, data);
            if (index < 0){
                cout << "Data tidak ada" << '\n';
            }
            else{
                cout << index << '\n';
            }
        }
    }
}
#include<iostream>
using namespace std;

struct node{
    int k;
    int size;
    int count;
    node* left;
    node* right;
    node(int _k){
        k=_k;
        size=1;
        count=1;
    }
};

int size(node* t){
    if (t==NULL) return 0;
    return t->size;
}

node* insert(node* tree, int x){
    if (tree==NULL) return new node(x);
    if (x<tree->k){
        tree->left = insert(tree->left, x);
    }else if (x>tree->k){
        tree->right = insert(tree->right, x);
    }else{
        tree->count++;
    }
    tree->size=size(tree->left)+size(tree->right)+tree->count;
    return tree;
}

int _rank(node * tree, int x){
    // 不加这一句， 就会RE。 看来不知道什么数据，会找到树以外去了。
    if (tree==NULL) return 1;

    if (tree->k == x){
        return size(tree->left)+1;
    }
    if (tree->k<x){
        return size(tree->left)+tree->count + _rank(tree->right, x);
    }
    return _rank(tree->left, x);
}

int nth(node * tree, int n){
    if (n>=size(tree->left)+1 && n<=size(tree->left)+tree->count){
        return tree->k;
    }
    else if (size(tree->left)+tree->count<n){
        return nth(tree->right, n-size(tree->left)-tree->count);
    }
    else {
        return nth(tree->left, n);
    }
}

int prev(node * tree, int x){
    if (tree==NULL) return -2147483647;
    if (tree->k < x && (!tree->right || tree->right->k>=x)){
        return tree->k;
    }
    if (tree->k >= x){
        return prev(tree->left, x);
    }
    return prev(tree->right, x);
}


int next(node * tree, int x){
    if (tree==NULL) return 2147483647;
    if (tree->k > x && (!tree->left || tree->left->k<=x)){
        return tree->k;
    }
    if (tree->k <= x){
        return next(tree->right, x);
    }
    return next(tree->left,x);
}
node * tree=NULL;
int main(){
    int n;
    cin >> n;
    tree=insert(tree, 2147483647);
    tree=insert(tree, -2147483647);
    while(n--){
        int cmd, x;
        cin >> cmd>>x;
        switch (cmd){
            case 1: cout << _rank(tree, x)-1<<endl; break;
            case 2: cout << nth(tree, x+1) << endl; break;
            case 3: cout << nth(tree, _rank(tree, x)-1)<<endl;break;
            case 4: cout << nth(tree, _rank(tree, x+1))<<endl; break;
            case 5: tree=insert(tree, x);break;
        }
    }
}
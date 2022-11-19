#include <iostream>
#include <vector>


template <typename T> 
struct Tree{ 
    Tree *parent, *left, *right;
    T value;
};


template <typename T> 
using NodeVector = std::vector<Tree<T>*>;


// Costruisce un nuovo nodo, contenente value, senza figli o genitori
template <typename T>
Tree<T> *makeTree(T value){
    Tree<T> *t = new Tree<T>;
    t->value = value;
    return t;
}


// Inserisce il sottoalbero radicato treeToInsert come figlio sinistro di root
template <typename T>
void insertLeft(Tree<T> *root, Tree<T> *treeToInsert){
    root->left = treeToInsert;
    treeToInsert->parent = root;
}


// Inserisce il sottoalbero radicato treeToInsert come figlio destro di root
template <typename T>
void insertRight(Tree<T> *root, Tree<T> *treeToInsert){
    root->right = treeToInsert;
    treeToInsert->parent = root;
}


// Distrugge ricorsivamente questo albero
template <typename T>
void deleteTree(Tree<T> *tree){
    if(tree.left != NULL)
        deleteTree(tree.left);
    if(tree.right != NULL)
        deleteTree(tree.right);
    delete tree;
}


// Ruotare la testa di pi/2 radianti per leggerlo, da chiamare con uno 0 alla fine
template <typename T>
void printTree(Tree<T> *tree, int lv){
    if(tree->right != NULL)
        printTree(tree->right, lv+1);
    
    for(int i=0; i<lv; i++)
        std::cout << "\t";
    std::cout << tree->value << std::endl;

    if(tree->left != NULL)
        printTree(tree->left, lv+1);
}


// depth first search pre-order
template <typename T>
std::vector<Tree<T>*> preOrderDFS(Tree<T> *tree){
    std::vector<Tree<T>*> v;
    realpreOrderDFS(tree, &v);
    return v;
}

template <typename T>
void realpreOrderDFS(Tree<T> *tree, std::vector<Tree<T>*> *v){
    if(tree==NULL)
        return;
    v->push_back(tree);
    realpreOrderDFS(tree->left, v);
    realpreOrderDFS(tree->right, v);
}


// depth first search in-order
template <typename T>
std::vector<Tree<T>*> inOrderDFS(Tree<T> *tree){
    std::vector<Tree<T>*> v;
    realInOrderDFS(tree, &v);
    return v;
}

template <typename T>
void realInOrderDFS(Tree<T> *tree, std::vector<Tree<T>*> *v){
    if(tree==NULL)
        return;
    realInOrderDFS(tree->left, v);
    v->push_back(tree);
    realInOrderDFS(tree->right, v);
}


// depth first search post-order
template <typename T>
std::vector<Tree<T>*> postOrderDFS(Tree<T> *tree){
    std::vector<Tree<T>*> v;
    realPostOrderDFS(tree, &v);
    return v;
}

template <typename T>
void realPostOrderDFS(Tree<T> *tree, std::vector<Tree<T>*> *v){
    if(tree==NULL)
        return;
    realPostOrderDFS(tree->left, v);
    realPostOrderDFS(tree->right, v);
    v->push_back(tree);
}


// all three depth first search
template <typename T>
void dfs(Tree<T> *tree, std::vector<Tree<T>*> *preOrder, std::vector<Tree<T>*> *inOrder, std::vector<Tree<T>*> *postOrder){
    if(tree==NULL)
        return;

    preOrder->push_back(tree);
    dfs(tree->left, preOrder, inOrder, postOrder);
    inOrder->push_back(tree);
    dfs(tree->right, preOrder, inOrder, postOrder);
    postOrder->push_back(tree);
}


template <typename T>
void invert(Tree<T> *tree){
    Tree<T> *tmp = tree->left;
    tree->left = tree->right;
    tree->right = tmp;

    if(tree->left != NULL)
        invert(tree->left);
    if(tree->right != NULL)
        invert(tree->right);
}


int main(){
    Tree<float>* tree = makeTree<float>(3.1415926);
    insertLeft<float>(tree, makeTree<float>(2.71818));

    insertRight<float>(tree, makeTree<float>(1000.1));

    insertLeft<float>(tree->left, makeTree<float>(11111));
    insertRight<float>(tree->left, makeTree<float>(12345));

    // printTree(tree, 0);
    invert(tree);
    printTree(tree, 0);

    std::vector<Tree<float>*> v;
    v = preOrderDFS(tree);
    for(int i=0; i<5; i++){
        std::cout << v[i]->value << " ";
    }
    std::cout << std::endl;

    v = inOrderDFS(tree);
    for(int i=0; i<5; i++){
        std::cout << v[i]->value << " ";
    }
    std::cout << std::endl;

    v = postOrderDFS(tree);
    for(int i=0; i<5; i++){
        std::cout << v[i]->value << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;

    std::vector<Tree<float>*> v1, v2, v3;
    dfs(tree, &v1, &v2, &v3);
    for(int i=0; i<5; i++){
        std::cout << v1[i]->value << " ";
    }
    std::cout << std::endl;
    for(int i=0; i<5; i++){
        std::cout << v2[i]->value << " ";
    }
    std::cout << std::endl;
    for(int i=0; i<5; i++){
        std::cout << v3[i]->value << " ";
    }
    std::cout << std::endl;
}

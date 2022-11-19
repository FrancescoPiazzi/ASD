#include <vector>
#include <iostream>

template <typename T> 
struct Tree{ 
    Tree *parent, *left, *right;
    T value;
};


template <typename T>
Tree<T> *makeTree(T value);


template <typename T>
void insertLeft(Tree<T> *root, Tree<T> *treeToInsert);


template <typename T>
void insertRight(Tree<T> *root, Tree<T> *treeToInsert);


template <typename T>
void deleteTree(Tree<T> *tree);


template <typename T>
void printTree(Tree<T> *tree, int lv);


template <typename T>
void preOrderDFS(Tree<T> *tree, std::vector<Tree<T>*> *v);


template <typename T>
void inOrderDFS(Tree<T> *tree, std::vector<Tree<T>*> *v);


template <typename T>
void postOrderDFS(Tree<T> *tree, std::vector<Tree<T>*> *v);


template <typename T> 
void dfs(Tree<T> *tree, std::vector<Tree<T>*> *, std::vector<Tree<T>*> *, std::vector<Tree<T>*> *);


template <typename T>
void invert(Tree<T> *tree);
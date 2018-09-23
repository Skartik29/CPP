#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include <iostream>

class Node
{
private:
    int data;
    Node* left;
    Node* right;
public:
    Node(int d = 0);
    Node(const Node &from);
    ~Node();
    int GetData() const {return data;}
    Node* GetLeft() const {return left;}
    Node* GetRight() const {return right;}
    void SetLeft(Node* l) {left = l;}
    void SetRight(Node* r) {right = r;}
};

class BST
{
private:
    Node* root;
    void cpy_node(const Node* f, Node* s);
    void delete_nodes(Node*& f);
public:
    BST();
    BST(const BST &from);
    ~BST();
    Node* GetRoot() const {return root;}
    void InsertNode(int d);
    void DeleteNode(Node* n);
    //traversals
    void PreOrder(Node* r);
    void InOrder(Node* r);
    void PostOrder(Node* r);
    void PreOrderIter(Node* r);
    void InOrderIter(Node* r);
    void PostOrderIter(Node* r);
    void LevelOrderSameLines(Node* r);
    void LevelOrderDiffLines(Node* r);
    //search
    Node* Find(int value);
    //others
    Node* Parent(Node* n);
    Node* Predeccesor(Node* n);
    Node* Successor(Node* n);
    int Height(Node* r);
    bool IsBst(Node* r, int mn, int mx);
};

#endif // BINARYSEARCHTREE_H_INCLUDED

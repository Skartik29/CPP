#ifndef LINKEDLISTS_H_INCLUDED
#define LINKEDLISTS_H_INCLUDED

#include <iostream>

class SinglyLL
{
private:
    int data;
    SinglyLL *next;
public:
    SinglyLL(int d);
    SinglyLL(const SinglyLL &ptr);
    SinglyLL(const SinglyLL *ptr);
    SinglyLL *GetNext() const {return next;}
    ~SinglyLL();
    void SetNext(SinglyLL* ptr) {next = ptr;}
    int GetData() const {return data;}
};

class DoublyLL
{
private:
    int data;
    DoublyLL* l;
    DoublyLL* r;
public:
    DoublyLL(int d);
    DoublyLL(const DoublyLL& ptr);
    DoublyLL(const DoublyLL* ptr);
    ~DoublyLL();
    DoublyLL* GetLeft() const {return l;}
    DoublyLL* GetRight() const {return r;}
    void SetLeft(DoublyLL* left) {l = left;}
    void SetRight(DoublyLL* right) {r = right;}
    int GetData() const {return data;}
};

class List
{
private:
    SinglyLL* sll;
    DoublyLL* dll;
public:
    List();
    List(const List& ptr);
    //List(const List* ptr);
    ~List();
    SinglyLL* GetSll() const {return sll;}
    DoublyLL* GetDll() const {return dll;}
    //Insertions
    void SAddNode(int data);
    void DAddNode(int data);
    //Deletions
    void SDelNode(SinglyLL*& node);
    void DDelNode(DoublyLL*& node);
    //Search
    SinglyLL* SIsPresent(int data);
    DoublyLL* DIsPresent(int data);
    //Print
    void PrintList();
};


#endif // LINKEDLISTS_H_INCLUDED

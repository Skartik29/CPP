#include "LinkedLists.h"

SinglyLL::SinglyLL(int d)
{
    data = d;
    next = NULL;
}
SinglyLL::SinglyLL(const SinglyLL& ptr)
{
    data = ptr.GetData();
    next = NULL;
}
SinglyLL::SinglyLL(const SinglyLL* ptr)
{
    data = ptr->GetData();
    next = NULL;
}
SinglyLL::~SinglyLL()
{
    next = NULL;
}
DoublyLL::DoublyLL(int d)
{
    data = d;
    l = NULL;
    r = NULL;
}
DoublyLL::DoublyLL(const DoublyLL& ptr)
{
    data = ptr.GetData();
    l = NULL; r = NULL;
}
DoublyLL::DoublyLL(const DoublyLL* ptr)
{
    data = ptr->GetData();
    l = NULL; r = NULL;
}
DoublyLL::~DoublyLL()
{
    l = NULL;
    r = NULL;
}
List::List()
{
    sll = NULL; dll = NULL;
}
List::List(const List& ptr)
{
    if (ptr.GetSll())
    {
        SinglyLL* s = ptr.GetSll();
        sll = new SinglyLL(s->GetData());
        SinglyLL* ss = sll;
        s = s->GetNext();
        while (s)
        {
            SinglyLL *nnode = new SinglyLL(s->GetData());
            ss->SetNext(nnode);
            ss = nnode;
            s = s->GetNext();
        }
    }
    if (ptr.GetDll())
    {
        DoublyLL* d = ptr.GetDll();
        dll = new DoublyLL(d->GetData());
        DoublyLL* dd = dll;
        d = d->GetRight();
        while (d)
        {
            DoublyLL *nnode = new DoublyLL(d->GetData());
            dd->SetRight(nnode);
            nnode->SetLeft(dd);
            dd = nnode;
            d = d->GetRight();
        }
    }
}
List::~List()
{
    SinglyLL* ss = sll;
    while (ss)
    {
        SinglyLL* nnode = ss->GetNext();
        delete ss;
        ss = nnode;
    }
    DoublyLL* dd = dll;
    while (dd)
    {
        DoublyLL* nnode = dd->GetRight();
        delete dd;
        dd = nnode;
    }
}
//Insertions
void List::SAddNode(int d)
{
    SinglyLL* nnode = new SinglyLL(d);
    if (!sll) sll = nnode;
    else
    {
        SinglyLL* s = sll;
        while (s->GetNext())
            s = s->GetNext();
        s->SetNext(nnode);
    }
}
void List::DAddNode(int d)
{
    DoublyLL* nnode = new DoublyLL(d);
    if (!dll) dll = nnode;
    else
    {
        DoublyLL* d = dll;
        while (d->GetRight())
            d = d->GetRight();
        d->SetRight(nnode);
        nnode->SetLeft(d);
    }
}
//Deletions
void List::SDelNode(SinglyLL*& node)
{
    if (!node) return;
    SinglyLL* s = sll;
    SinglyLL* p = s;
    while (s && s != node)
    {
        p = s; s = s->GetNext();
    }
    if (!s) return;
    if (p == s)
    {
        sll = node->GetNext();
    }
    else
    {
        p->SetNext(node->GetNext());
    }
    node->SetNext(NULL);
    delete node;
}
void List::DDelNode(DoublyLL*& node)
{
    if (!node) return;
    DoublyLL* ln = node->GetLeft();
    DoublyLL* rn = node->GetRight();
    if (ln) ln->SetRight(rn);
    if (rn) rn->SetLeft(ln);
    node->SetLeft(NULL);
    node->SetRight(NULL);
    if (node == dll)
        dll = rn;
    delete node;
}
SinglyLL* List::SIsPresent(int data)
{
    SinglyLL* s = sll;
    while (s)
    {
        if (s->GetData() == data) return s;
        s = s->GetNext();
    }
    return NULL;
}
DoublyLL* List::DIsPresent(int data)
{
    DoublyLL* d = dll;
    while (d)
    {
        if (d->GetData() == data) return d;
        d = d->GetRight();
    }
    return NULL;
}
void List::PrintList()
{
    SinglyLL* s = sll;
    while (s)
    {
        std::cout<<s->GetData()<<" ";
        s = s->GetNext();
    }
    std::cout<<std::endl;
    DoublyLL* d = dll;
    while (d)
    {
        std::cout<<d->GetData()<<" ";
        d = d->GetRight();
    }
    std::cout<<std::endl;
}

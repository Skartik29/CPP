#include "BinarySearchTree.h"
#include <stack>
#include <queue>

Node::Node(int d)
{
    data = d;
    left = NULL;
    right = NULL;
}
Node::Node(const Node &from)
{
    data = from.GetData();
    left = NULL;
    right = NULL;
}
Node::~Node()
{
    data = -1;
}
BST::BST()
{
    root = NULL;
}
void BST::cpy_node(const Node* f, Node *s)
{
    if (!f || !s) return;
    if (f->GetLeft())
    {
        Node* l = new Node(f->GetLeft()->GetData());
        s->SetLeft(l);
    }
    if (f->GetRight())
    {
        Node* r = new Node(f->GetRight()->GetData());
        s->SetRight(r);
    }
    cpy_node(f->GetLeft(),s->GetLeft());
    cpy_node(f->GetRight(),s->GetRight());
}
BST::BST(const BST &from)
{
    Node* r = from.GetRoot();
    root = new Node(r->GetData());
    cpy_node(r,root);
}
void BST::delete_nodes(Node*& f)
{
    if (!f) return;
    Node* l = f->GetLeft();
    Node* r = f->GetRight();
    delete f;
    delete_nodes(l);
    delete_nodes(r);
}
BST::~BST()
{
    delete_nodes(root);
}
void BST::InsertNode(int d)
{
    Node* nnode = new Node(d);
    Node* t = root;
    Node* p = t;
    while (t)
    {
        p = t;
        if (t && t->GetData() > d) t= t->GetLeft();
        else t = t->GetRight();
    }
    if (p)
    {
        if (d < p->GetData()) p->SetLeft(nnode);
        else p->SetRight(nnode);
    } else root = nnode;
}
void BST::PreOrder(Node* r)
{
    if (!r) return;
    std::cout<<r->GetData()<<std::endl;
    PreOrder(r->GetLeft());
    PreOrder(r->GetRight());
}
void BST::InOrder(Node* r)
{
    if (!r) return;
    InOrder(r->GetLeft());
    std::cout<<r->GetData()<<std::endl;
    InOrder(r->GetRight());
}
void BST::PostOrder(Node* r)
{
    if (!r) return;
    PostOrder(r->GetLeft());
    PostOrder(r->GetRight());
    std::cout<<r->GetData()<<std::endl;
}
void BST::PreOrderIter(Node* r)
{
    if (!r) return;
    std::stack<Node*> s;
    s.push(r);
    while (!s.empty())
    {
        Node* t = s.top();
        s.pop();
        std::cout<<t->GetData();
        if (t->GetRight()) s.push(t->GetRight());
        if (t->GetLeft()) s.push(t->GetLeft());
    }
}
void BST::InOrderIter(Node* r)
{
    if (!r) return;
    std::stack<Node*> s;
    Node* curr = root;
    while (curr != NULL || s.empty() == false)
    {
        while (curr !=  NULL)
        {
            s.push(curr);
            curr = curr->GetLeft();
        }
        curr = s.top();
        s.pop();
        std::cout << curr->GetData() << " ";
        curr = curr->GetRight();
    }
}
void BST::PostOrderIter(Node* r)
{
    if (!r) return;
    std::stack<Node*> s1, s2;
    s1.push(r);
    Node* n;
    while (!s1.empty())
    {
        n = s1.top(); s1.pop();
        s2.push(n);
        if (n->GetLeft())
            s1.push(n->GetLeft());
        if (n->GetRight())
            s1.push(n->GetRight());
    }
    while (!s2.empty())
    {
        n = s2.top(); s2.pop();
        std::cout<<n->GetData()<<std::endl;
    }
}
void BST::LevelOrderSameLines(Node* r)
{
    if (!r) return;
    std::queue<Node*> q;
    q.push(r);
    while (!q.empty())
    {
        Node* t = q.front(); q.pop();
        std::cout<<t->GetData()<<" ";
        if (t->GetLeft()) q.push(t->GetLeft());
        if (t->GetRight()) q.push(t->GetRight());
    }
}
void BST::LevelOrderDiffLines(Node* r)
{
    if (!r) return;
    std::queue<Node*> q;
    q.push(r);
    while (1)
    {
        int ct = q.size();
        if (ct == 0) break;
        while (ct > 0)
        {
            Node* t = q.front();
            std::cout<<t->GetData()<<" ";
            q.pop();
            if (t->GetLeft()) q.push(t->GetLeft());
            if (t->GetRight()) q.push(t->GetRight());
            ct--;
        }
        std::cout<<std::endl;
    }
}
Node* BST::Parent(Node* n)
{
    if (n == root) return NULL;
    Node* t = root;
    while (t)
    {
        if (t->GetLeft() == n || t->GetRight() == n) return t;
        if (t->GetData() > n->GetData()) t = t->GetLeft();
        else t = t->GetRight();
    }
}
Node* BST::Predeccesor(Node* n)
{
    if (!n) return NULL;
    if (n->GetLeft())
    {
        Node* t = n->GetLeft();
        Node* p = t;
        while (t)
        {
            p = t;
            t = t->GetRight();
        }
        return p;
    }
    else
    {
        Node *t = Parent(n);
        while (t)
        {
            if (t->GetRight() == n) return t;
            else t = Parent(t);
        }
        return NULL;
    }
}
Node* BST::Successor(Node* n)
{
    if (!n) return NULL;
    if (n->GetRight())
    {
        Node* t = n->GetRight();
        Node* p = t;
        while (t)
        {
            p = t;
            t = t->GetLeft();
        }
        return p;
    }
    else
    {
        Node *t = Parent(n);
        while (t)
        {
            if (t->GetLeft() == n) return t;
            else t = Parent(t);
        }
        return NULL;
    }
}
Node* BST::Find(int value)
{
    Node* t = root;
    while (t)
    {
        if (t->GetData()  == value) return t;
        if (t->GetData() > value) t = t->GetLeft();
        else t = t->GetRight();
    }
    return NULL;
}
int BST::Height(Node* r)
{
    if (!r) return 0;
    int hl = Height(r->GetLeft());
    int hr = Height(r->GetRight());
    if (hl > hr) return 1 + hl;
    else return 1 + hr;
}
bool BST::IsBst(Node* r, int mn, int mx)
{
    if (!r) return true;
    if (r->GetData() > mx || r->GetData() < mn) return false;
    return IsBst(r->GetLeft(), mn, r->GetData()) && IsBst(r->GetRight(), r->GetData(), mx);
}

#include <iostream>
#include "LinkedLists.h"
#include "Stack.h"
#include "Queue.h"
#include "BinarySearchTree.h"
#include "Matrix.h"
#include "Graphs.h"
#include "Puzzles.h"
#include <climits>

using namespace std;

int main()
{
    /** Testing linked list
    List *lst = new List();
    lst->PrintList();
    lst->SAddNode(10);
    lst->SAddNode(11);
    lst->SAddNode(12);
    lst->PrintList();
    lst->DAddNode(13);
    lst->DAddNode(14);
    lst->DAddNode(15);
    lst->PrintList();
    SinglyLL* sl = lst->SIsPresent(12);
    DoublyLL* dl = lst->DIsPresent(15);
    lst->PrintList();
    lst->SDelNode(sl);
    lst->DDelNode(dl);
    lst->PrintList();
    delete lst; **/
    /** Testing stack
    Stck *s = new Stck();
    for (int i = 0; i < 100; ++i)
        s->Push(10);
    delete s; **/
    /** Testing queue
    Que* q = new Que();
    q->Deque();
    for (int i = 0; i < 3; ++i)
        q->Enqueue(i);
    q->Deque();
    q->Deque();
    q->Deque();
    q->Deque();
    delete q; **/
    /** Testing CQue
    CQue* cq = new CQue();
    cq->Deque();
    cq->Enqueue(0);
    cq->Enqueue(1);
    cq->Enqueue(2);
    cq->Enqueue(3);
    cq->Enqueue(4);
    cq->Enqueue(5);
    cq->Enqueue(6);
    cq->Deque();
    cq->Deque();
    delete cq; **/
    /**  Testing BST
    BST* tree = new BST();
    for (int i = 0; i < 10; ++i)
        tree->InsertNode(i);
    tree->LevelOrderDiffLines(tree->GetRoot());
    std::cout<<tree->Find(11)->GetData()<<std::endl;
    std::cout<<tree->IsBst(tree->GetRoot(), INT_MIN, INT_MAX); **/
    /**  Testing graphs
    GraphsAdjacency* graph = new GraphsAdjacency(9);
    for (int i = 1; i < 8; ++i)
        graph->AddEdge(i, i+1);
    graph->RemoveEdge(0,1);
    graph->DFS(1); **/

    ArrayPuzzles* ap = new ArrayPuzzles();
    ap->PrintArray();
    ap->ClockwiseRotation(3);
    ap->PrintArray();
    ap->AnticlockwiseRotation(9);
    ap->PrintArray();
    delete ap;

    return 0;
}

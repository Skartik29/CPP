#ifndef GRAPHS_H_INCLUDED
#define GRAPHS_H_INCLUDED

#include "Matrix.h"
#include <forward_list>
#include <vector>
#include <iostream>

class GraphsMatrix
{
private:
    Matrix<int>* matrix;
    int V;
public:
    GraphsMatrix(int V);
    GraphsMatrix(const GraphsMatrix& cpy);
    ~GraphsMatrix();
    Matrix<int>* GetMatrix() const {return matrix;}
    void AddEdge(int u, int v, int w);
    void RemoveEgde(int u, int v);
    bool IsEdge(int u, int v);
    void AddVertex(std::vector<int>& v);
    int GetV() const {return V;}
};

class GraphsAdjacency
{
private:
    int V;
    std::vector<std::forward_list<int> > adjacency;
    void DFSUtil(int s, bool visited[]);
public:
    GraphsAdjacency(int v);
    void AddEdge(int u, int v);
    void RemoveEdge(int u, int v);
    bool IsEdge(int u, int v);
    void AddVertex(std::forward_list<int> &l);
    void RemoveVertex(int v);
    //Search
    void BFS(int s);
    void DFS(int s);
};

#endif // GRAPHS_H_INCLUDED

#include "Graphs.h"
#include <algorithm>
#include <queue>

/**  Matrix implementation  **/
GraphsMatrix::GraphsMatrix(int V)
{
    matrix = new Matrix<int>(V,V);
    this->V = V;
}
GraphsMatrix::GraphsMatrix(const GraphsMatrix &cpy)
{
    matrix = new Matrix<int>(*(cpy.GetMatrix()));
    V = cpy.GetV();
}
GraphsMatrix::~GraphsMatrix()
{
    delete matrix;
}
void GraphsMatrix::AddEdge(int u, int v, int w)
{
    matrix->SetValue(u,v,w);
}
void GraphsMatrix::RemoveEgde(int u, int v)
{
    matrix->SetValue(u,v,0);
}
bool GraphsMatrix::IsEdge(int u, int v)
{
    return (*matrix)(u,v) ? true : false;
}
void GraphsMatrix::AddVertex(std::vector<int>& v)
{
    int ind = v.size() - 1;
    int x = matrix->GetX();
    int y = matrix->GetY();
    x += v.size();
    y += v.size();
    matrix->ResizeInner(x,y);
    int indd = matrix->GetX() * matrix->GetY();
    for (int i = ind; i >= 0; --i)
    {
        --indd;
        matrix->AddToVectorEnd(v[i], indd);
    }
    V++;
}
/**  Adjacency implementation  **/
GraphsAdjacency::GraphsAdjacency(int v)
{
    V = v;
    adjacency.resize(V);
}
void GraphsAdjacency::AddEdge(int u, int v)
{
    int uInd = u - 1, vInd = v - 1;
    adjacency[uInd].push_front(v);
    adjacency[vInd].push_front(u);
}
void GraphsAdjacency::RemoveEdge(int u, int v)
{
    int uInd = u - 1, vInd = v - 1;
    adjacency[uInd].remove(v);
    adjacency[vInd].remove(u);
}
bool GraphsAdjacency::IsEdge(int u, int v)
{
    int uInd = u - 1, vInd = v - 1;
    if (std::find(adjacency[uInd].begin(), adjacency[uInd].end(), v) != adjacency[uInd].end()) return true;
    else if (std::find(adjacency[vInd].begin(), adjacency[vInd].end(), u) != adjacency[vInd].end()) return true;
    else return false;
}
void GraphsAdjacency::AddVertex(std::forward_list<int>& l)
{
    adjacency.push_back(l);
    V++;
}
void GraphsAdjacency::RemoveVertex(int v)
{
    int vInd = v - 1;
    adjacency.erase(adjacency.begin()+vInd);
    V--;
}
void GraphsAdjacency::BFS(int s)
{
    int sInd = s - 1;
    bool *visited = new bool[V];
    for (int i = 0; i < V; ++i)
        visited[i] = false;
    std::queue<int> q;
    q.push(sInd);
    visited[sInd] = true;
    while (!q.empty())
    {
        int ind = q.front();
        std::cout<<ind<<" ";
        q.pop();
        std::forward_list<int> l = adjacency[ind];
        std::forward_list<int>::iterator it;
        for (it = l.begin(); it != l.end(); ++it)
        {
            if (!visited[*it])
            {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
    delete[] visited;
}
void GraphsAdjacency::DFSUtil(int s, bool visited[])
{
    visited[s] = true;
    std::cout<<s<<" ";
    std::forward_list<int> l = adjacency[s];
    std::forward_list<int>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
    {
        if (!visited[*it])
            DFSUtil(*it, visited);
    }
}
void GraphsAdjacency::DFS(int s)
{
    int sInd = s - 1;
    bool *visited = new bool[V];
    for (int i = 0; i < V; ++i)
        visited[i] = false;
    DFSUtil(sInd, visited);
}

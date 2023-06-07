#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define N 6
#define PVW pair<int,int> //pair of vertex and weight of edge connected to it

int** initializeGraph();
void primsMST(int graph[N][N], int n_vertices);
void printMST(int parent[], int graph[6][6], int root);

int main(){
    int graph[N][N] = {
            {0,3,0,0,0,1},
            {3,0,2,1,10,0},
            {0,2,0,3,0,5},
            {0,1,3,0,5,0},
            {0,10,0,5,0,4},
            {1,0,5,0,4,0}
    };
    primsMST(graph, N);
    return 0;
}

class CompareEdges{
    public:
        bool operator()(PVW below, PVW above){
            // return true if the node below has a lower weighted edge
            return(below.second > above.second);
        }
};

/// @param graph a connect and undirected graph
/// @return a minimum spanning tree
void primsMST(int graph[N][N], const int n_vertices){
    // set of vertices in MST;
    bool mstVertices[n_vertices];

    // initialize all vertices as not in the mst
    for(int i = 0; i < n_vertices; i++){
        mstVertices[i] = false;
    }
   
    // parent of vertices in sub-trees
    int parent[n_vertices];

    // priority queue of vertices and edge weights
    // Used to select the minimum safe edge
    priority_queue<PVW, vector<PVW>, CompareEdges> pq;

    // root with 0 as the root node
    int root = 0;
    parent[root] = -1;

    // edges from parent vertices to fringe vertices
    pq.push({root, 0});

    // go through all fringe vertices
    for(int i = 0; i < n_vertices - 1; i++){
        // get minimum edge connected to fringe vertex from a vertex in the tree
        PVW  minSafeEdge = pq.top();
        pq.pop();

        // add second to the mst vertices set
        int u = minSafeEdge.first;
        mstVertices[u] = true;

        // add edges of newly added vertex, which are not already in the mst
        for(int v = 0 ; v < n_vertices; v++){
            if(graph[u][v] && !mstVertices[v]){
                parent[v] = u;
                pq.push({v, graph[u][v]});
            }
        }
    }

    printMST(parent, graph, root);

}

void printMST(int parent[], int graph[6][6], int root)
{
    cout << "Edge \tWeight\n";
    for (int i = 0; i < N; i++)
        if(i != root)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}


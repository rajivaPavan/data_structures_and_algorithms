#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define N 6

int** initializeGraph();
void printGraph(int** graph, int n);
int** primsMST(int** graph, int n_vertices);
pair<int, int> minSafeEdge(vector<pair<int, int>> edges, bool mstSet[]);

int main(){
    int** graph = initializeGraph();
    int** mst = primsMST(graph, N);
    printGraph(mst, N);
    return 0;
}

/// @param graph a connect and undirected graph
/// @return a minimum spanning tree
int** primsMST(int** graph, const int n_vertices){
    // set of vertices in MST;
    bool mstVertices[n_vertices];
   
    // parent of vertices in sub-trees
    int parent[n_vertices];

    // start with 0 as the root node
    parent[0] = 0; 
    mstVertices[0] = true;

    // edges from parent vertices to fringe vertices
    vector<pair<int, int>> edges;

    // go through all fringe vertices
    for(int i = 0; i < n_vertices - 1; i++){
        // get minimum edge connected to fringe vertex from a vertex in the tree
        pair<int, int> edge = minSafeEdge(edges, mstVertices);
        
        // add first as the parent of the second
        parent[edge.second] = edge.first;

        // add second to the mst vertices set
        mstVertices[edge.second] = true;
    }
    
}

/// @brief Gets minimum edge connected to fringe vertex from a vertex in the tree
/// @param edges 
/// @param mstSet array of vertices in the mst
/// @return edge with minimum weight to be added to the mst. 
/// pair : first - mst vertex, second - fringe vertex to be added
pair<int, int> minSafeEdge(vector<pair<int, int>> edges, bool mstSet){

}

/// @brief prints the edges of the given graph
/// @param graph adjacency matrix
/// @param n number of vertices
void printGraph(int** graph, int n){
    cout << "The graph is a follows: " << endl;
    
}

/// @return a hard coded graph adjacency matrix of 6 x 6
int** initializeGraph(){
    int graph[N][N] = {
        {0,3,0,0,0,1},
        {3,0,2,1,10,0},
        {0,2,0,3,0,5},
        {0,1,3,0,5,0},
        {0,10,0,5,0,4},
        {1,0,5,0,4,0}
    };
    
    int** G = new int*[N];
    for(int i = 0; i < N; i++){
        G[i] = new int[N];
        for(int j = 0; j < N; j++)
            G[i][j] = graph[i][j];
    }
    
    return G;
}


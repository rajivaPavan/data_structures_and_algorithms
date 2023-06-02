#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define N 6

int** initializeGraph();
void printMST();
int** primsMST(int** graph);

int main(){
    int** graph = initializeGraph();
    primsMST(graph);
    
    return 0;
}

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

int** primsMST(int** graph){
    bool vertices[N];
    for (int i = 0; i < N; i++)
    {
        vertices[i] = false; // not in MST yet
    }

    int mst_weight = 0;

    // start with 0
    for (int i = 0; i < N; i++)
    {
        vertices[i] = true; // visit vertex
        // get neighbour with least edge
        int minEdgeNeighbour = -1;
        for(int j = 0; j < N; j++){
            if(vertices[j] == true)
                continue;
            
            if(j != i)
                continue;

            if((graph[i][j] > 0) && 
                 (minEdgeNeighbour > graph[i][j]))
            {
                minEdgeNeighbour = j; // closest vertex with respect to vertex i
            }
        }

        // if not already in MST
        if(vertices[minEdgeNeighbour] == false){
            vertices[minEdgeNeighbour] = true; // add neighbour to MST
            mst_weight += graph[i][minEdgeNeighbour]; // add mst weight to MST
        }

    }
    
    cout << "Weight of MST = " << mst_weight << endl;
}





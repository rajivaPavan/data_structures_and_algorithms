#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define PII pair<int, int>
#define INFINITY 9999999

// Number of nodes in the graph
#define N 6

class Compare {
public:
    bool operator()(PII below, PII above)
    {
        if(below.second < above.second)
            return true;
        return false;
    }
};

void dijkstra(int graph[N][N], int source, int* distance);

int main(){

    // adjacency matrix for the graph
    int graph[N][N] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0} 
    };

    for(int i = 0; i < 6; i++){
        // apply dijkstra's algorithm for each node as source
        int* distance = (int*)malloc(sizeof(int)*N);
        dijkstra(graph, i, distance);

        // print the distance of each node from the source
        cout << "Time to each city from city " << i << " is: " << endl;
        for(int j = 0; j < N; j++){
            if(j != i)
                cout << j << " : " << distance[j] << endl;
        }
        cout << endl;
    }

    return 0;
}

// Dijkstra's algorithm implementation
void dijkstra(int graph[N][N], int source, int* distance){
    priority_queue<PII, vector<PII>, Compare> pq;
    // initialize distance of all nodes to infinity
    for(int i = 0; i < N; i++){
        distance[i] = INFINITY;
    }

    // distance of source node from itself is 0
    distance[source] = 0;
    pq.push({source, distance[source]});

    while(!pq.empty()){
        PII min_dist_node = pq.top(); // visited edge
        int u = min_dist_node.first;
        pq.pop(); // remove the visited edge from the queue
        for(int v = 0; v < N; v++){ 
            // adjacent nodes of the visited edge
            if(graph[u][v] != 0){
                // relax the edge
                if(distance[v] > distance[u] + graph[u][v]){
                    distance[v] = distance[u] + graph[u][v];
                    pq.push({v, distance[v]});
                }
            }
        }
    }
}


 

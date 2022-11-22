/**
* @author Francesco Piazzi
* @brief visita iterativa, usa una coda per tenere traccia dei nodi da visitare
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    vector<int> neighbors;
    bool visited = false;
};

int neighbors(vector<Node> g, int start);

int main(){
    int N, M, S;    // nodi, archi, nodo partenza
    int n1, n2;

    ifstream input("input.txt");
    input >> N >> M >> S;

    vector<Node> graph(N);

    for(int i=0; i<M ; i++){
        input >> n1 >> n2;
        graph[n1].neighbors.push_back(n2);
    }

    ofstream output("output.txt");
    output << neighbors(graph, S);
    output.close();
}

int neighbors(vector<Node> g, int start){
    int neigh=0;

    queue<int> toVisit;
    toVisit.emplace(start);
    g[start].visited = true;

    while(!toVisit.empty()){
        int extracted = toVisit.front();
        toVisit.pop();

        for(int n : g[extracted].neighbors){
            if(!g[n].visited){
                toVisit.emplace(n);
                g[n].visited = true;
            }
        }
        neigh++;
    }
    return neigh;
}
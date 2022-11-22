/**
* @author Francesco Piazzi
* @brief visita ricorsiva, funziona ma usa troppa memoria
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// un nodo è rappresentato dal suo numero
// e dalla lista di numeri di nodi a cui è connesso
typedef pair<int, vector<int>> node;
typedef vector<node> graph;

int neighbors(graph g, vector<bool> &visited, int start);
void printGraph(graph g);
void printNode(node n);

int main(){
    int N, M, S;    // nodi, archi, nodo partenza
    int n1, n2;

    ifstream input("input.txt");
    input >> N >> M >> S;

    // -1 -> il nodo non è ancora stato trovato nel file
    graph g(M, make_pair(-1, vector<int>()));
    // vettore di supporto per evitare ricorsioni infinite
    vector<bool> visited(N, false);

    for(int i=0; i<M ; i++){
        input >> n1 >> n2;
        // il nodo 1 finisce nella cella 1, il 10 nella 10
        g.at(n1).first = n1;
        g.at(n1).second.push_back(n2);
    }

    input.close();

    ofstream output("output.txt");
    output << neighbors(g, visited, S) << endl;
    output.close();

    return 0;
}


int neighbors(graph g, vector<bool> &visited, int start){
    visited.at(start) = true;
    int neigh=0;

    for(int i : g.at(start).second){            // per ogni adiacente di start
        if(!visited.at(i)){                     // se non l'ho ancora visitato
            neigh+=neighbors(g, visited, i);    // conto i suoi adiacenti
        }
    }

    return neigh+1;
}


void printGraph(graph g){
    for(node n : g)
        if(n.first != -1)
            printNode(n);
    cout << endl;
}


void printNode(node n){
    cout << n.first << " -> ";
    for(int i : n.second){
        cout << i << ", ";
    }
    cout << endl;
}

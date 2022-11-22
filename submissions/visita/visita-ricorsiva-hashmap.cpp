/**
* @author Francesco Piazzi
* @brief visita ricorsiva, funziona ma usa troppa memoria, i valori sono memorizzati in un'hashmap
*/

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;


// un nodo è rappresentato dal suo numero
// e dalla lista di numeri di nodi a cui è connesso
typedef map<int, vector<int>> graph;

int neighbors(graph g, vector<bool> &visited, int start);


int main(){
    int N, M, S;    // nodi, archi, nodo partenza
    int n1, n2;

    ifstream input("input.txt");
    input >> N >> M >> S;

    // -1 -> il nodo non è ancora stato trovato nel file
    graph g;
    // vettore di supporto per evitare ricorsioni infinite
    vector<bool> visited(N, false);

    for(int i=0; i<M ; i++){
        input >> n1 >> n2;
        // il nodo 1 finisce nella cella 1, il 10 nella 10
        g[n1].push_back(n2);
    }

    input.close();

    ofstream output("output.txt");
    output << neighbors(g, visited, S) << endl;
    output.close();

    return 0;
}


int neighbors(graph g, vector<bool> &visited, int start){
    visited.at(start) = true;
    int neigh = 0;

    for(int i : g[start]){                      // per ogni adiacente di start
        if(!visited.at(i)){                     // se non l'ho ancora visitato
            neigh+=neighbors(g, visited, i);    // conto i suoi adiacenti
        }
    }

    return neigh+1;
}

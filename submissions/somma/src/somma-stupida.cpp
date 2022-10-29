/**
* @author Francesco Piazzi
* @brief somma stupida per capire cosa c'è da fare per contribuire alla repo senza avere git
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream input("input.txt");
    int a, b;
    input >> a >> b;
	input.close();
	
	int res = a;
	for(int i=0; i<b; i++){
		res++;
	}
	
	ofstream output("output.txt");
	output << res;
	output.close();
}

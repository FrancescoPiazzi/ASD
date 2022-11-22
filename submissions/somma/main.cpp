#include <fstream>

using namespace std;

int main(){
	int a, b;
	ifstream f("input.txt");
	ofstream g("output.txt");
	
	f >> a >> b;
	g << a+b;
	
	f.close();
	g.close();
}

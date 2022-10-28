#include <fstream>
#include <iostream>

using namespace std;

int main(){
	int a[1000000];
    
	ifstream f("input.txt");
	ofstream g("output.txt");
	
    int n;
    f >> n;

    for(int i=0; i<n; i++){
        f >> a[i];
    }

    int max1=0, max2=0;
    for(int i=0; i<n; i++){
        max1 = max(0, max1+a[i]);
        max2 = max(max1, max2);
    }

    g << max2;

	f.close();
	g.close();

    return 0;
}

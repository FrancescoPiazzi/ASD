#include <iostream>

const int N = 100000;
const long int M = 5000000000;

using namespace std;

int main(){
    srand(time(NULL));
    cout << N << endl;
    for(int i=0; i<N; i++){
        cout << rand()%M << " " << rand()%M << endl;
    }

    return 0;
}
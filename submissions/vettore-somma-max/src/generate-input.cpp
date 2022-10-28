#include <iostream>

const int N = 10;

using namespace std;

int main(){
    srand(time(NULL));
    cout << N << endl;
    for(int i=0; i<N; i++){
        cout << rand()%100-60 << " ";
    }

    return 0;
}
#include <iostream>

const int N = 10000000;

using namespace std;

int main(){
    srand(time(NULL));
    cout << N << endl;
    for(int i=0; i<N; i++){
        cout << rand()%10000 << " ";
    }

    return 0;
}
#include <iostream>

const int ROWS = 3;
const int COLS = 7;

using namespace std;

int main(){
    srand(time(NULL));
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            cout << rand()%100-60 << " ";
        }
        cout << endl;
    }

    return 0;
}
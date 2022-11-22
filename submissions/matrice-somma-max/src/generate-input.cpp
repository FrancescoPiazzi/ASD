#include <iostream>

const int ROWS = 500;
const int COLS = 500;

using namespace std;

int main(){
    srand(time(NULL));
    cout << ROWS << " " << COLS << endl;
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            cout << rand()%100-60 << " ";
        }
        cout << endl;
    }

    return 0;
}
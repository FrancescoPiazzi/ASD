#include <iostream>

using namespace std;

int main(){
    srand(time(NULL));
    cout << rand()%10000 << " " << rand()%10000;

    return 0;
}
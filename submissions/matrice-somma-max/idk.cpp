/**
 * @author Francesco Piazzi
 * @brief usa una matrice di somma cumulativa, non fa schifo ma non è chissà cosa
*/

#include <fstream>
#include <iostream>

using namespace std;

const int SIZE = 2000;

int maxMatrix(int **a, int **b,int, int);
int** cumulativeMatrix(int **a, int, int);
int getSum(int **m, int startX, int startY, int endX, int endY);
int maxVect(int *a, int n);

int main(){
	int **a = new int*[SIZE];
    for(int i=0; i<SIZE; i++)
        a[i] = new int[SIZE];
    int r, c;
    int mx;

	ifstream f("input.txt");
	ofstream g("output.txt");
	
    f >> r >> c;
    for(int i=0; i<r*c; i++)
        f >> a[i/c][i%c];
    f.close();

    int **cumulative = cumulativeMatrix(a, r, c);
    mx = maxMatrix(a, cumulative, r, c);
    g << mx;

    g.close();
    return 0;
}


int maxMatrix(int **a, int **b, int r, int c){
    int mx=0;

    for(int i=0; i<min(r, c); i++){
        // per righe: j è "l'altezza" della riga
        for(int j=i; j<c; j++){
            int max1=0;
            for(int k=i; k<r; i++){
                max1 = max(0, max1+getSum(b, i, i, j, k));
                mx = max(max1, mx);
                cout << i << "," << i << "  " << j << "," << k << "\t";
            }
            cout << endl;
        }

        // per colonne: j è "la larghezza" della colonna
        for(int j=i; j<r; j++){
            int max1=0;
            for(int k=i; k<c; i++){
                max1 = max(0, max1+getSum(b, i, i, k, j));
                mx = max(max1, mx);
                cout << i << "," << i << "  " << k << "," << j << "\t";
            }
            cout << endl;
        }
    }

    return mx;
}


// data una matrice di somme cumulative m, trova la somma della sottomatrice
int getSum(int **m, int startX, int startY, int endX, int endY){
    // se start ed end sono a zero non devo sottrarre nulla
    if(startX == 0 && startY == 0)
        return m[endX][endY];

    // se solo uno dei due è a 0 devo sottrarre solo l'altro
    if(startX == 0)
        return m[endX][endY] - m[endX][startY-1];
    if(startY == 0)
        return m[endX][endY] - m[startX-1][endY];

    // altrimenti mi tocca fare dei conti
    return m[endX][endY] - m[startX-1][endY] - m[endX][startY-1] + m[startX-1][startY-1];
}


// calcola la matrice di somma cumulativa
int** cumulativeMatrix(int **a, int r, int c){
    int** b = new int*[SIZE];
    for(int i=0; i<SIZE; i++)
        b[i] = new int[SIZE];

    b[0][0] = a[0][0];  // primo elemento

    for(int i=1; i<SIZE; i++){
        b[i][0] = b[i-1][0]+a[i][0];    // prima riga
        b[0][i] = b[0][i-1]+a[0][i];    // prima colonna
    }

    // il resto della matrice
    for(int i=1; i<r; i++)
        for(int j=1; j<c; j++)
            b[i][j] = a[i][j] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];

    return b;
}


int maxVect(int *a, int n){
    int max1=0, max2=0;
    for(int i=0; i<n; i++){
        max1 = max(0, max1+a[i]);
        max2 = max(max1, max2);
    }
    return max2;
}
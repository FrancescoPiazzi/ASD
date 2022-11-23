/**
 * @author Francesco Piazzi
 * @brief usa una matrice di somma cumulativa per colonne e l'algoritmo del massimo
*/

#include <fstream>
#include <iostream>

using namespace std;

const int SIZE = 2000;

int maxMatrix(int **cols,int, int);
int** cumulativeMatrixCols(int **a, int, int);
int getSumCol(int **m, int col, int start, int end);

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

    int** cumulative = cumulativeMatrixCols(a, r, c);
    mx = maxMatrix(cumulative, r, c);

    g << mx;
    g.close();
    return 0;
}


int maxMatrix(int **cols, int r, int c){
    int max1=0, max2=0;
    
    for(int start=0; start<r; start++){
        for(int end=start; end<r; end++){
            max1 = 0;
            for(int k=0; k<c; k++){
                max1 = max(0, max1+getSumCol(cols, k, start, end));
                max2 = max(max1, max2);
            }
        }
    }

    return max2;
}


// calcola la matrice di somma cumulativa per colonne
int** cumulativeMatrixCols(int **a, int r, int c){
    int** cols = new int*[SIZE];

    for(int i=0; i<SIZE; i++){
        cols[i] = new int[SIZE];
        cols[0][i] = a[0][i];
    }

    for(int i=1; i<r; i++)
        for(int j=0; j<c; j++)
            cols[i][j] = a[i][j] + cols[i-1][j];

    return cols;
}


int getSumCol(int **m, int col, int start, int end){
    return start==0 ? m[end][col] : m[end][col]-m[start-1][col];
}

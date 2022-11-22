/**
 * @author Francesco Piazzi
 * @brief usa una matrice di somma cumulativa, non fa schifo ma non è chissà cosa
*/

#include <fstream>
#include <iostream>

using namespace std;

const int SIZE = 2000;

void printMatrix(int **m, int, int);
void printMatrix(int **m, int, int, int, int);
void printVector(int v[], int);

int maxMatrix(int **a, int, int);
int maxVect(int a[], int);
int** cumulativeMatrix(int **a, int, int);
int getSum(int **m, int startX, int startY, int endX, int endY);

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

    mx = maxMatrix(cumulative, r, c);
    g << mx;

    
    g.close();

    return 0;
}


int maxMatrix(int **m, int r, int c){
    int mx=0;

    for(int startX=0; startX<r; startX++){
        for(int startY=0; startY<c; startY++){
            for(int endX=startX; endX<r; endX++){
                for(int endY=startY; endY<c; endY++){
                    mx = max(mx, getSum(m, startX, startY, endX, endY));
                    // cout << startX << "," << startY << "  " << endX << "," << endY << " -> " << getSum(m, startX, startY, endX, endY) << endl;
                }
            }
        }
    }

   // cout << getSum(m, 0, 1, 1, 2) << endl;

    return mx;
}

int getSum(int **m, int startX, int startY, int endX, int endY){
    // data una matrice di somme cumulative m, trova la somma della sottomatrice

    // se start ed end sono a zero non devo sottrarre nulla
    if(startX == 0 && startY == 0)
        return m[endX][endY];

    // se solo uno dei due è a 0 devo sottrarre solo l'altro
    if(startX == 0)
        return m[endX][endY] - m[endX][startY-1];
    if(startY == 0)
        return m[endX][endY] - m[startX-1][endY];

    // altrimenti mi tocca fare dei conti
    return m[endX][endY] - 
        m[startX-1][endY] - 
        m[endX][startY-1] + 
        m[startX-1][startY-1];
}

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
    for(int i=1; i<r; i++){
        for(int j=1; j<c; j++){
            b[i][j] = a[i][j] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];
        }
    }

    return b;
}

int maxVect(int a[], int size){
    int max1=0, max2=0;
    for(int i=0; i<size; i++){
        max1 = max(0, max1+a[i]);
        max2 = max(max1, max2);
    }
    return max2;
}


void printVector(int v[], int size){
    for(int i=0; i<size; i++)
        cout << v[i] << " ";
    cout << endl;
}


void printMatrix(int **m, int endX, int endY){
    printMatrix(m, 0, 0, endX, endY);
}


void printMatrix(int **m, int startX, int startY, int endX, int endY){
    for(int i=startX; i<endX; i++){
        for(int j=startY; j<endY; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

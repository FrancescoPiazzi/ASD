/**
 * @author Francesco Piazzi
 * @brief calcola la somma tutte le possibili sottomatrici e prende la maggiore, fa schifo
 * @bug ogni tanto va in segfault, non ho idea del motivo
 * @todo rimuovere funzioni inutilizzate
*/

#include <fstream>
#include <iostream>

using namespace std;

const int SIZE = 10;

void printMatrix(int m[][SIZE], int, int);
void printMatrix(int m[][SIZE], int, int, int, int);
void printVector(int v[], int);

int maxMatrix(int m[][SIZE], int, int);
int* srotola(int m[][SIZE], int, int, int, int, int res[]);
int maxVect(int a[], int);
int sumVector(int a[], int);

int main(){
	int a[SIZE][SIZE];
    int r, c;
    int mx=0;

	ifstream f("input.txt");
	ofstream g("output.txt");
	
    f >> r >> c;

    // lol
    if(r > SIZE)
        r = SIZE;
    if(c > SIZE)
        c = SIZE;

    for(int i=0; i<r*c; i++)
        f >> a[i/c][i%c];

    mx = maxMatrix(a, r, c);
    g << mx;

    return 0;
}


int maxMatrix(int m[][SIZE], int r, int c){
    int mx=0;

    for(int x1=0; x1<r; x1++){
        for(int y1=0; y1<c; y1++){
            for(int x2=x1; x2<c; x2++){
                for(int y2=y1; y2<c; y2++){
                    int matriceSrotolata[SIZE*SIZE];
                    srotola(m, x1, y1, x2, y2, matriceSrotolata);
                    int k=sumVector(matriceSrotolata, (x2-x1+1)*(y2-y1+1));
                    if(k>mx){
                        mx=k;
                    }
                }
            }
        }
    }

    return mx;
}

int maxVect(int a[], int size){
    int max1=0, max2=0;
    for(int i=0; i<size; i++){
        max1 = max(0, max1+a[i]);
        max2 = max(max1, max2);
    }
    return max2;
}


int sumVector(int a[], int size){
    int sum=0;
    for(int i=0; i<size; i++)
        sum += a[i];
    return sum;
}


// TODO: deve poter srotolare sia per righe che per colonne
int* srotola(int m[][SIZE], int startX, int startY, int endX, int endY, int res[]){
    int k=0;
    for(int i=startX; i<=endX; i++){
        for(int j=startY; j<=endY; j++){
            res[k] = m[i][j];
            k++;
        }
    }
    return res;
}


void printVector(int v[], int size){
    for(int i=0; i<size; i++)
        cout << v[i] << " ";
    cout << endl;
}


void printMatrix(int m[][SIZE], int endX, int endY){
    printMatrix(m, 0, 0, endX, endY);
}


void printMatrix(int m[][SIZE], int startX, int startY, int endX, int endY){
    for(int i=startX; i<endX; i++){
        for(int j=startY; j<endY; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * @author Francesco Piazzi
 * @brief mergesort, ma se ci sono solo 2 elementi da ordinare li ordino "a mano"
 * @todo spostare il codice che fa il merge in una funzione
*/

#include <iostream>
#include <fstream>

using namespace std;

void mergeSort(int[], int, int);
void bubbleSort(int[], int, int);

int main(){
    int N;
    int *a = new int[1000*1000*100];

    fstream f;
    f.open("input.txt", ios::in);
    f >> N;
    for(int i=0; i<N; i++)
        f >> a[i];
    f.close();

    mergeSort(a, 0, N);

    fstream g;
    g.open("output.txt", ios::out);
    for(int i=0; i<N; i++)
        g << a[i] << " ";
    g.close();
}

void mergeSort(int a[], int start, int end){
    if(end-start < 2){
        return;
    }

    if(end-start == 2){
        if(a[start] > a[end-1]){
            int tmp = a[start];
            a[start] = a[end-1];
            a[end-1] = tmp;
        }
        return;
    }

    int middle = (end-start)/2 + start;
    mergeSort(a, start, middle);
    mergeSort(a, middle, end);

    int *b = new int[end-start];
    int i;
    int i1=start, i2=middle;
    for(i=start; i1<middle && i2<end; i++){
        if(a[i1] < a[i2]){
            b[i-start] = a[i1];
            i1++;
        }
        else{
            b[i-start] = a[i2];
            i2++;
        }
    }

    // metto gli elementi rimasti di un array o di un altro
    if(i1 < middle){
        while(i1 < middle){
            b[i-start] = a[i1];
            i1++;
            i++;
        }
    }
    else{
        while(i2 < end){
            b[i-start] = a[i2];
            i2++;
            i++;
        }
    }

    for(int i=start; i<end; i++)
        a[i] = b[i-start];

    delete(b);
}

void bubbleSort(int a[], int start, int end){
    for(int i=start; i<end-1; i++){
        for(int j=start; j<end-i-1; j++){
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}
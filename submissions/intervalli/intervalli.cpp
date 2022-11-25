#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void mergeSort(vector<pair<int, int>> &a, int start, int end);


int main(){
    ifstream f("input.txt");
    ofstream g("output.txt");
    int n;
    f >> n;
    vector<pair<int, int>> intervals(n);
    for(int i=0; i<n; i++){
        f >> intervals[i].first;
        f >> intervals[i].second;
    }

    mergeSort(intervals, 0, n);

    int maxsize=-1;
    int i=0;
    int startLongest, endLongest;

    while(i<n-1){
        int end = i;
        int k;
        for(k=i+1; k<n && intervals[k].first <= intervals[end].second; k++)
            if(intervals[k].second > intervals[end].second)  // l'intervallo si allunga
                end = k;

        int lunghezza = intervals[k].first - intervals[end].second;
        // cout << "lunghezza: " << lunghezza << endl;
        if(lunghezza > maxsize){
            maxsize = lunghezza;
            startLongest = intervals[end].second;
            endLongest = intervals[k].first;
        }
        i = k;
    }

    if(maxsize == -1)
        g << 0;
    else
        g << startLongest << " " << endLongest;

    return 0;
}


void mergeSort(vector<pair<int, int>> &a, int start, int end){
    if(end-start < 2)
        return;

    int middle = (end-start)/2 + start;
    mergeSort(a, start, middle);
    mergeSort(a, middle, end);

    vector<pair<int, int>> b(end-start);
    int i;
    int i1=start, i2=middle;
    for(i=start; i1<middle && i2<end; i++){
        if(a[i1].first < a[i2].first){
            b[i-start] = a[i1];
            i1++;
        }
        else{
            b[i-start] = a[i2];
            i2++;
        }
    }

    // sistemo gli elementi rimasti dell'array in cui ne sono rimasti
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
}
#include <iostream>
#include "SortTestHelper.hpp"
using namespace std;

template<typename T>
void _merge(T arr[], int l, int mid, int r){
    T aux[r-l+1];

    // Before comparation we should copy arr
    for(int i=l; i <= r; i++){
        aux[i-l] = arr[i];
    }
    // Initialize pointers
    int i = l, j = mid+1;
    for(int k=l; k<=r; k++){
        
        // All left arr elements have been processed
        if(i > mid){
           arr[k] = aux[j-l];
           j++;
        }
        // All right arr elements have been processed
        else if(j > r){
            arr[k] = aux[i-l];
            i++;
        }

        else if(aux[i-l] < aux[j-l]){
            arr[k] = aux[i-l];
            i++;
        }

        else{
            arr[k] = aux[j-l];
            j++;
        }

    } 
}


template<typename T>
void _mergeSort(T arr[], int l, int r){
    
    if(l >= r){
        return;
    }

    int mid = l + (r-l)/2;
    _mergeSort(arr, l, mid);
    _mergeSort(arr, mid+1, r);
    _merge(arr, l, mid, r);

}


template<typename T>
void mergeSort(T arr[], int n){

    _mergeSort(arr, 0, n-1);
}

int main() {

    // test running time
    int N = 20000;
    int *arr = SortTestHelper::generateRandomArray(N,0,100000);
    SortTestHelper::testSort("Mergesort",mergeSort,arr,20000);
    delete[] arr;  //注意delete掉new的数组


    // test using int array
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    mergeSort( a, 10 );
    for( int i = 0 ; i < 10 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;

    // test using float array
    float b[4] = {4.4,3.3,2.2,1.1};
    mergeSort( b, 4 );
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<b[i]<<" ";
    cout<<endl;


    return 0;
}
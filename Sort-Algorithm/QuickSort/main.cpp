#include <iostream>
#include "SortTestHelper.hpp"
using namespace std;

template<typename T>
int partition(T arr[], int start, int end){
    
    int pivot = arr[start];
    int index = start;
    //arr[l+1....j] < v; arr[j+1...i) > v; j==index;
    for(int i = start+1; i <= end; i++){
        if(arr[i] < pivot){
            index++;
            swap(arr[index], arr[i]);
        }
    }

    swap(arr[start], arr[index]);


    return index;
}


template<typename T>
void _quickSort(T arr[], int start, int end){
    if(start >= end){
        return;
    }

    int p = partition(arr, start, end);
    _quickSort(arr, start, p-1);
    _quickSort(arr, p+1, end);
    
}


template<typename T>
void quickSort(T arr[], int n){

    _quickSort(arr, 0, n-1);
}

int main() {

    // test running time
    int N = 20000;
    int *arr = SortTestHelper::generateRandomArray(N,0,100000);
    SortTestHelper::testSort("Quicksort",quickSort,arr,20000);
    delete[] arr;  //注意delete掉new的array


    // test using int array
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    quickSort( a, 10 );
    for( int i = 0 ; i < 10 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;

    // test using float array
    float b[4] = {4.4,3.3,2.2,1.1};
    quickSort( b, 4 );
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<b[i]<<" ";
    cout<<endl;


    return 0;
}
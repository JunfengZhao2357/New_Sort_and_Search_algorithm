#include <iostream>
#include "SortTestHelper.hpp"
using namespace std;

template<typename T>
void insertionSort(T arr[], int n){

    for(int i = 1; i < n ; i ++){

        // compare elements from the back to the front
        for( int j = i ; j > 0 && arr[j] < arr[j-1] ; j -- )

            swap( arr[j-1], arr[j]);

    }
}

int main() {

    // test running time
    int N = 20000;
    int *arr = SortTestHelper::generateRandomArray(N,0,100000);
    SortTestHelper::testSort("Insertionsort",insertionSort,arr,20000);
    delete[] arr;  //注意delete掉new的数组


    // test using int array
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    insertionSort( a, 10 );
    for( int i = 0 ; i < 10 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;

    // test using float array
    float b[4] = {4.4,3.3,2.2,1.1};
    insertionSort( b, 4 );
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<b[i]<<" ";
    cout<<endl;


    return 0;
}

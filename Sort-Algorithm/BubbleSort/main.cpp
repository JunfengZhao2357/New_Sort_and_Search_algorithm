#include <iostream>
#include "SortTestHelper.hpp"
using namespace std;

template<typename T>
void bubbleSort(T arr[], int n){

    for(int i = 0; i < n-1 ; i ++){

        // Every time we put the biggest element to the back
        for( int j = 0 ; j < n-1-i ; j++ )
            if(arr[j] > arr[j+1])
                swap( arr[j], arr[j+1]);

    }
}

int main() {

    // test running time
    int N = 20000;
    int *arr = SortTestHelper::generateRandomArray(N,0,100000);
    SortTestHelper::testSort("Bubblesort",bubbleSort,arr,20000);
    delete[] arr;  //注意delete掉new的数组


    // test using int array
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    bubbleSort( a, 10 );
    for( int i = 0 ; i < 10 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;

    // test using float array
    float b[4] = {4.4,3.3,2.2,1.1};
    bubbleSort( b, 4 );
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<b[i]<<" ";
    cout<<endl;


    return 0;
}
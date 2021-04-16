#include <iostream>
#include "SortTestHelper.hpp"
using namespace std;

template<typename T>
void selectionSort(T arr[], int n){

    for(int i = 0 ; i < n ; i ++){

        
        int minIndex = i;

        for( int j = i + 1 ; j < n ; j ++ )

            if( arr[j] < arr[minIndex] )
                minIndex = j;

        swap( arr[i] , arr[minIndex] );
    }
}

int main() {

    // test running time
    int N = 20000;
    int *arr = SortTestHelper::generateRandomArray(N,0,100000);
    SortTestHelper::testSort("Slectionsort",selectionSort,arr,20000);
    delete[] arr;  //注意delete掉new的数组


    // test using int array
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    selectionSort( a , 10 );
    for( int i = 0 ; i < 10 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;

    // test using float array
    float b[4] = {4.4,3.3,2.2,1.1};
    selectionSort(b,4);
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<b[i]<<" ";
    cout<<endl;


    return 0;
}

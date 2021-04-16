#include <iostream>
#include <vector>
#include "MaxHeap.hpp"
using namespace std;
int main(){
    //MaxHeap test
    MaxHeap aHeap(10);
    aHeap.insert(2);
    aHeap.insert(4);
    aHeap.insert(6);
    cout<<aHeap.pop()<<" "<<aHeap.pop()<<" "<<aHeap.pop()<<endl;
    cout<<aHeap.empty()<<endl;
    return 0;
}
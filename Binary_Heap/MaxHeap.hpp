#include <vector>
#include <iostream>
using namespace std;
class MaxHeap{
public:
     MaxHeap(int capacity){
         data = vector<int>(capacity,0);
         this->capacity = capacity;
         end = -1;
     }
     ~MaxHeap(){}

     int size(){
         return end+1;
     }
     bool empty(){
         return end == -1;
     }

     void insert(int item){
        data[end+1] = item;
        shiftUp(end+1);
        end ++;
    }

    // 从最大堆中取出堆顶元素, 即堆中所存储的最大数据
    int pop(){
        int ret = data[0];
        swap( data[0] , data[end] );
        end --;
        shiftDown(0);
        return ret;
    }

    // 获取最大堆中的堆顶元素
    int getMax(){
        return data[0];
    }

private:
    vector<int>data;
    int end;
    int capacity;

    void shiftUp(int k){
        while( k > 0 && data[(k-1)/2] < data[k] ){
            swap( data[(k-1)/2], data[k] );
            k =(k-1)/2;
        }
    }

    void shiftDown(int k){
        while( 2*k+1 <= end ){
            int j = 2*k+1;
            if( j+1 <= end && data[j+1] > data[j] ) j ++;
            if( data[k] >= data[j] ) break;
            swap( data[k] , data[j] );
            k = j;
        }
    }
};
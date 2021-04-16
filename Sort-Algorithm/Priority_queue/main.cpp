#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
// Sorting the coordinates by x 
struct min_heap_cmp{
    bool operator()(pair<int,int > p1, pair<int,int> p2){
        return p1.first > p2.first;  //min heap
    }
};
struct max_heap_cmp{
    bool operator()(pair<int,int > p1, pair<int,int> p2){
        return p1.first < p2.first;  //max heap
    }
};
vector<pair<int,int> > heapSort(vector<pair<int,int> > Coordinates){
    vector<pair<int,int> >res_tmp;
    priority_queue< pair<int,int>,vector<pair<int,int> >, min_heap_cmp> pq;
    for(auto c : Coordinates){
        pq.push(c);
    }
    while(!pq.empty()){
        res_tmp.push_back(pq.top());
        pq.pop();
    }
    return res_tmp;
}
int main(){
    pair<int,int>p1(1,2);
    pair<int,int>p2(2,3);

     vector<pair<int,int> > test;
     test.push_back(p1);
     test.push_back(p2);

     vector<pair<int,int> > res = heapSort(test);
     for(auto c : res){
         cout<<c.first<<" "<<c.second<<endl;
     }
     return 0;
}



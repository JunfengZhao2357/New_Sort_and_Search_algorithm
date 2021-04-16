#include <iostream>
#include <vector>
#include <string>
using namespace std;
// time complexity : O(n+k)

vector<int> countSort(vector<int>array,int max){
    vector<int>result(array.size(),0);
	vector<int> temp((max + 1),0);
	// 以下循环操作完成后，temp的第i个位置保存着array中，值为i的元素的总个数
	for (int i : array) {
		temp[i]++;
	}
	// 以下循环操作完成后，temp的第i个位置保存着array中，值小于或等于i的元素的总个数
	for (int i = 1; i < temp.size(); i++) {
		temp[i] += temp[i - 1];
	}
	for (int i = array.size() - 1; i >= 0; i--) {
		result[temp[array[i]] - 1] = array[i];
		temp[array[i]]--;
	}
	return result;
}

int main(){
     vector<int>test={1,0,3,1,3,1};
     vector<int>res = countSort(test,3);
     for(auto i : res)
        cout<<i<<endl;
     return 0;

}
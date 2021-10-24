#include <vector>
#include <iostream>
using namespace std;
// time comlexity: O(logn)
int BinarySearch(vector<int>nums,int target){
    int left = 0;
    int right = nums.size()-1;

    while(left <= right){
        int mid = left + (right - left)/2;
        if(nums[mid]==target){
            return mid;
        } 
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else if(nums[mid] > target){
            right = mid -1;
        }
    }
    return -1;
}

int left_bound_binarysearch(vector<int> nums, int target) {
    //If all elements in the vector are larger than the target, we return 0;
    //If all elements in the vector are less than the target, we return -1;
    int left = 0, right = nums.size() - 1;
    // search area is [left, right]
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            // search area is [mid+1, right]
            left = mid + 1;
        } else if (nums[mid] > target) {
            // search area is [left, mid-1]
            right = mid - 1;
        } else if (nums[mid] == target) {
            right = mid - 1;
        }
    }
    // when the while is ending, the left is right+1;
    // If all elements in the vector are less than the target
    if (left >= nums.size() || nums[left] != target)
        return -1;
    return left;
}

int right_bound_binary_search(vector<int> nums, int target) {
     //If all elements in the vector are larger than the target, we return -1;
    //If all elements in the vector are less than the target, we return nums.size()-1;
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 别返回，锁定右侧边界
            left = mid + 1;
        }
    }
    
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}

int main(){
    vector<int> test1 = {1,2,2,2,3,4,5};
    int position_01 = BinarySearch(test1,2);
    int position_02 = left_bound_binarysearch(test1,2);
    int position_03 = right_bound_binary_search(test1,2);
    cout<<position_01<<" "<<position_02<<" "<<position_03<<endl;
    return 0;
}

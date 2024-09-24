#include<bits/stdc++.h>
using namespace std;
void reverseArray(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
}
void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k >= n
        
        // Step 1: Reverse the entire array
        reverseArray(nums, 0, n - 1);
        
        // Step 2: Reverse the first k elements
        reverseArray(nums, 0, k - 1);
        
        // Step 3: Reverse the remaining n - k elements
        reverseArray(nums, k, n - 1);
    
}
int main()
{
    vector<int>nums = {1,2,3,4,5,6,7,8,9,10};
    int k = 4;
    rotate(nums,k);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
    
}

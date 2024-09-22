//optimized approach
#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target) {
    // Store original indices while sorting
    vector<pair<int, int>> indexedArr(n);
    for (int i = 0; i < n; i++) {
        indexedArr[i] = {arr[i], i};  // Store value and original index
    }

    sort(indexedArr.begin(), indexedArr.end());
    int left = 0, right = n - 1;

    while (left < right) {
        int sum = indexedArr[left].first + indexedArr[right].first;
        if (sum == target) {
            return "YES: Indices are " + to_string(indexedArr[left].second) + " and " + to_string(indexedArr[right].second);
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return "NO";
}

int main() {
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 8;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}
//brut eforce 
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(int n, vector<int> &arr, int target) {
    // Store original indices while sorting
   vector<int>ans;
   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       {
           if(arr[i]+arr[j]==target)
           {
           ans.push_back(i);
           ans.push_back(j);
           return ans;
           }
       }
   }
   return {-1,-1};
}

int main() {
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans[0] <<" "<<ans[1] << endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int subarray(vector<int>&arr)
{
    int n = arr.size();
    int res = arr[0];
    for(int i=0;i<n;i++)
    {
        int curr = 0;
        for(int j=i;j<n;j++)
        {
            curr+=arr[j];
             res = max(curr,res);
        }
    }
    return res;
}
int main()
{
    vector<int>arr = {2, 3, -8, 7, -1, 2, 3};
    cout<<"the maximum array is: "<<subarray(arr)<<endl;
    return 0;
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxmin(vector<int>arr)
{
    sort(arr.begin(),arr.end());
   int mini = arr[0]+arr[1];
   int maxi = arr[arr.size()-1]+arr[arr.size()-2];
   cout << arr[0] <<"+"<<arr[1] <<"=" << mini <<endl;
   cout<< arr[arr.size()-2] << "+"<<arr[arr.size()-1] <<"="<< maxi <<endl;
  return 0;
}
int main()
{
    int n;
    cout<< "emter n: " ;
    cin>>n;
    vector<int>arr(n);
    cout<<"enter each ele: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    maxmin(arr);
    return 0;
}

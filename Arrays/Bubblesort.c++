#include<bits/stdc++.h>
using namespace std;
void insertion(int n,vector<int>&arr)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j+1],arr[j]);
            }
        }
    }
}
int main()
{
    int n;
    cout<<"enter a n: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"enter a values: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertion(n,arr);
    cout<<"and the result is: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

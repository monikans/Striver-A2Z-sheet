#include<bits/stdc++.h>
using namespace std;
void insertion(int n,vector<int>&arr)
{
    for(int i=0;i<=n-1;i++)
    {
        int j = i;
        while(j>0&&arr[j-1]>arr[j])
        {
        swap(arr[j-1],arr[j]);
        j--;
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

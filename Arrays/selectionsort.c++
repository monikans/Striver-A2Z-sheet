#include<bits/stdc++.h>
using namespace std;
void selection(int n,vector<int>&arr)
{
    for(int i=0;i<n-1;i++)
    {
        int mini = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[mini])
            {
                mini= j;
            }
        }
        swap(arr[mini],arr[i]);
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
    selection(n,arr);
    cout<<"and the result is: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

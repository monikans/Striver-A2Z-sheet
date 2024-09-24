#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter n: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter each elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    map<int,int>freq;
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    cout<<"frequency elements: "<<endl;
    for(auto ele:freq)
    {
        cout<<ele.first <<" appears "<<" "<<ele.second<<endl;
    }
    return 0;
}

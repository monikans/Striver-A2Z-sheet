//brute force approach
//Time and space complexity is O(log10(n)+1 )

#include<bits/stdc++.h>
using namespace std;
int count(int n)
{
    int cnt =0;
    while(n!=0)
    {
        cnt+=1;
        n=n/10
    }
    return cnt;
}
int main()
{
    int n;
    cout<<"enter n: " ;
    cin>>n;
    cout<<"the count is: "<<count(n)<<endl;
    return 0;
}

//optimised approach
//Time and space complexity is O(1) 

#include<bits/stdc++.h>
using namespace std;
int count(int n)
{
    int cnt = (int)(log10(n)+1);
    return cnt;
}
int main()
{
    int n;
    cout<<"enter n: " ;
    cin>>n;
    cout<<"the count is: "<<count(n)<<endl;
    return 0;
}

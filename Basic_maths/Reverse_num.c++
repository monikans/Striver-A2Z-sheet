//brute force approach
//Time and space complexity is O(log10(n)+1)
//space complexity is O(1)

#include<bits/stdc++.h>
using namespace std;
int reversenum(int n)
{
    int rev = 0;
    while(n!=0)
    {
        int dig = n % 10;
        rev = rev*10+dig;
        n=n/10;
    }
    return rev;
}
int main()
{
    int n;
    cout<<"enter n: " ;
    cin>>n;
    cout<<"the count is: "<<reversenum(n)<<endl;
    return 0;
}

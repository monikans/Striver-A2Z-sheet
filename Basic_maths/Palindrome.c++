//brute force approach
//Time complexity is O(log10(n)+1 )
//space complexity is O(1)
// for numbers

#include<bits/stdc++.h>
using namespace std;
int palindrome(int n)
{
    int rev = 0;
    int temp = n;
    while(n!=0)
    {
        int dig = n % 10;
        rev = rev*10+dig;
        n=n/10;
    }
    if(temp==rev)
    {
        return true;
    }
    else
    {
    return false;
    }
}
int main()
{
    int n;
    cout<<"enter n: " ;
    cin>>n;
    if(palindrome(n))
    {
     cout<<"the number is palindrome "<<endl;   
    }
    else
    {
        cout<<"the number is not palindrome "<<endl; 
    }
    return 0;
}


//optimized approach
//Time complexity is O(n)
//space complexity is O(1)

#include<bits/stdc++.h>
using namespace std;
bool palindrome(const string &str)
{
    int start = 0;
    int end = str.length()-1;
    while(start<end)
    {
        if(str[start]!=str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int main()
{
    string st;
    cout<<"enter a string: " ;
    cin>>st;
    if(palindrome(st))
    {
     cout<<"the number is palindrome "<<endl;   
    }
    else
    {
        cout<<"the number is not palindrome "<<endl; 
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
void reverse(string &str)
{
    int start = 0;
    int end = str.length()-1;
    while(start<end)
    {
        swap(str[start],str[end]);
        start++;
        end--;
    }
}
int main()
{
    string str;
    cout<<"enter str: "<<endl;
    cin>>str;
    reverse(str);
    cout<<"the reversed string is: "<< str <<endl;
    return 0;
}
//using stack
#include<bits/stdc++.h>
using namespace std;
void reverse(string &str)
{
    stack<char>s;
    for(char c:str)
    {
        s.push(c);
    }
    for(int i=0;i<str.size();i++)
    {
        str[i] = s.top();
        s.pop();
    }
}
int main()
{
    string str;
    cout<<"enter str: "<<endl;
    cin>>str;
    reverse(str);
    cout<<"the reversed string is: "<< str <<endl;
    return 0;
}

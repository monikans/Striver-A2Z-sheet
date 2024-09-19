#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cout << "enter a n: "<< endl;
    cin>>n;
    int temp = n;
    int k = log10(abs(n)) + 1;
    int ans=0;
    while(n>0)
    {
        int dig = n % 10;
        ans = ans +pow(dig,k);
        n = n/10;
    }
    if(temp==ans)
    {
        cout<<"its a armstrong" << endl;
    }
    else{
        cout<<"its not a armstrong";
    }
    return 0;
}

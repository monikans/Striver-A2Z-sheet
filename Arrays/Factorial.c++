#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int fact(int n) {
   //int start = 0,end = n-1;
   if(n==0||n==1)
    return 1;
   return n*fact(n-1);
}
int main() {
   int n;
   cout<<"enter n: "<<endl;
   cin>>n;
   cout<<"the factorail of "<<n<<" is "<<fact(n)<<endl;
   return 0;
}

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
   //int start = 0,end = n-1;
   if(n<=1)
    return n;
   return fib(n-1)+fib(n-2);
}
int main() {
   int n;
   cout<<"enter n: "<<endl;
   cin>>n;
   cout<<"the fibonacci series is "<<fib(n)<<endl;
   return 0;
}

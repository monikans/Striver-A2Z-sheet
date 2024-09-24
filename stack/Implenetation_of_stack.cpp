#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int M_stack[MAX];
int top = -1;
void push(int x)
{
    if(top>=(MAX-1))
    {
        cout<<"Stack overflow"<<endl;
    }
    else{
        M_stack[++top] = x;
        cout<<x<<" pushed to the stack"<<endl;
    }
}
int pop()
{
    if(top<0)
    {
        cout<<"stack underflow"<<endl;
        return -1;
    }
    else{
        int x = M_stack[top--];
        return x;
    }
}
int peek()
{
    if(top<0)
    {
        cout<<"stack underflow"<<endl;
        return -1;
    }
    else{
        return M_stack[top];
    }
}
bool isempty()
{
    return (top<0);
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    cout << pop() << " popped from stack" << endl;

    cout << "Top element is " << peek() << endl;

    cout << "Is stack empty? " << (isempty() ? "Yes" : "No") << endl;

    return 0;
}

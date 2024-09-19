#include <iostream>
#include <vector>
#include <algorithm>  // For sort function
using namespace std;

int highestProductOfTwo(const vector<int>& arr) {
    int n = arr.size();
    if (n < 2) {
        // Not enough elements for a product
        cout << "Array must contain at least two elements." << endl;
        return -1;
    }
    
    // Sort the array
    vector<int> sortedArr = arr;  // Copying the original array
    sort(sortedArr.begin(), sortedArr.end());
    
    // The highest product can be either:
    // 1. The product of the two largest numbers.
    // 2. The product of the two smallest numbers (which might be negative) if the array contains negative numbers.
    
    int product1 = sortedArr[n - 1] * sortedArr[n - 2];  // Two largest numbers
    int product2 = sortedArr[0] * sortedArr[1];          // Two smallest (most negative) numbers
    cout<<"the product number is: "<<sortedArr[n-1]<<"*"<<sortedArr[n - 2]<<"="<<product1<<endl;
    cout<<"the negative number is: "<<sortedArr[0]<<"*"<<sortedArr[1]<<"="<<product2<<endl;
    return max(product1, product2);
}

int main() {
    int n;
    cout<< "emter n: " ;
    cin>>n;
    vector<int>arr(n);
    cout<<"enter each element: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int result = highestProductOfTwo(arr);
    
    
    if (result != -1)
        cout << "Highest product of two numbers is: " << result << endl;
    
    return 0;
}

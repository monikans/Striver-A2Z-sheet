// TC = O(N)
// SC = O(N)
#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
   int ans[n];
   for (int i = n - 1; i >= 0; i--) {
      ans[n - i - 1] = arr[i];
   }
   cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
   }
}
int main() {
   int n = 5;
   int arr[] = {5,4,3,2,1};
   reverseArray(arr, n);
   return 0;
}

//other approach
// TC = O(N)
// SC = O(1)
#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
   int start = 0,end = n-1;
   while(start<end)
   {
       swap(start,end);
       start++;
       end--;
   }
   cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}
int main() {
   int n = 5;
   int arr[] = {5,4,3,2,1};
   reverseArray(arr, n);
   return 0;
}

//another approach
// TC = O(N)
// SC = O(1)
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int n) {
   //int start = 0,end = n-1;
   reverse(arr,arr+n);
   cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}
int main() {
   int n = 5;
   int arr[] = {5,4,3,2,1};
   reverseArray(arr, n);
   return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int firstNonRepeatedInt(const vector<int>& nums) {
    unordered_map<int, int> numCount;

    // Step 1: Traverse the array and build the frequency map
    for (int num : nums) {
        numCount[num]++;
    }

    // Step 2: Traverse the array again to find the first non-repeated integer
    for (int num : nums) {
        if (numCount[num] == 1) {
            return num;
        }
    }

    // If no non-repeated integer is found
    return -1; // return -1 to signify no non-repeated integer
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = firstNonRepeatedInt(nums);
    if (result != -1) {
        cout << "The first non-repeated integer is: " << result << endl;
    } else {
        cout << "No non-repeated integer found." << endl;
    }

    return 0;
}

// other approach 
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int firstNonRepeatedInt(const vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> freq;

    // Step 1: Traverse the array and build the frequency map
    for(int i=0;i<n;i++)
    {
        freq[nums[i]]++;
    }
    // Step 2: Traverse the array again to find the first non-repeated integer
    for (int num : nums) {
        if (freq[num] == 1) {
            return num;
        }
    }

    // If no non-repeated integer is found
    return -1; // return -1 to signify no non-repeated integer
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = firstNonRepeatedInt(nums);
    if (result != -1) {
        cout << "The first non-repeated integer is: " << result << endl;
    } else {
        cout << "No non-repeated integer found." << endl;
    }

    return 0;
}

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

char firstNonRepeatedChar(const string &str) {
    unordered_map<char, int> charCount;

    // Step 1: Traverse the string and build the frequency map
    for (char c : str) {
        charCount[c]++;
    }

    // Step 2: Traverse the string again to find the first non-repeated character
    for (char c : str) {
        if (charCount[c] == 1) {
            return c;
        }
    }

    // If no non-repeated character is found
    return '\0'; // null character to signify no non-repeated character
}

int main() {
    string str;
    cout << "Enter the string: ";
    getline(cin, str);

    char result = firstNonRepeatedChar(str);
    if (result) {
        cout << "The first non-repeated character is: " << result << endl;
    } else {
        cout << "No non-repeated character found." << endl;
    }

    return 0;
}

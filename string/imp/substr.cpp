#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "7868190130M7522";
    
    // Find the position of 'M'
    size_t pos = s.find('M');
    
    // Extract the substring starting after 'M'
    if (pos != string::npos && pos + 3 <= s.length()) {
        cout << s.substr(pos + 1, 2); // Extract 2 characters starting from pos+1
    } else {
        cout << "Invalid position or substring length.";
    }

    return 0;
}

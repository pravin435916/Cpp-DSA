#include <iostream>
using namespace std;

int main() {
    cout << "Size of int: " << sizeof(int) << " bytes\n";
    cout << "Size of float: " << sizeof(float) << " bytes\n";
    cout << "Size of long long: " << sizeof(long long) << " bytes\n";
    cout << "Size of long long int: " << sizeof(long long int) << " bytes\n";
    return 0;
}
// There is no difference between long long and long long int in C++. They are exactly the same type.

// long long is a shorthand way of writing it.
// long long int is a more explicit way that emphasizes the fact it's an integer type.
// The keyword int is implicit in long long, so both forms are valid and interchangeable. Whether you use long long or long long int, they both represent the same data type and have the same size (usually 8 bytes) and range (-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807).
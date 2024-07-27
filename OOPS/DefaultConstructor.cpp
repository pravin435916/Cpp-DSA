#include <iostream>
using namespace std;

class Demo{
    int a, b;
    public:
    Demo()   // default constructor
    {
        cout << "Default Constructor" << endl;
    }
    Demo(int a, int b)//parameterised constructor
    {
        cout << "parameterized constructor -values" << a  << " "<< b << endl;
    }
    
// }instance; //before end of semicolon check for user trying to call instance it will default call object 
}instance(100,200); //defaukt and direct call without defining object

int main() {
    Demo obj1; // This will call the default constructor
    Demo obj2(10, 20); // This will call the parameterized constructor

    return 0;
}

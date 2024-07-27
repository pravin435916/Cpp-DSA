// C++ program to demonstrate accessing of data members
#include <bits/stdc++.h>
using namespace std;
class Geeks {
private:
    string geekname;
    int age;
    // Access specifier
public:
    // Member Functions()
    void setName(string name) { 
        geekname = name;
    }
    void setAge(int age) { 
        if(age < 0) {
            cout<<"Age is not negative"<<endl;
            return;
        }
        this->age = age;
    }

    void printname() {
         cout << "Geekname is:" << geekname << age;
        }
};
int main()
{
    // Declare an object of class geeks
    Geeks obj1;
    // accessing data member
    // cannot do it like: obj1.geekname = "Abhi";
    obj1.setName("Abhi");
    obj1.setAge(2);
    // accessing member function
    obj1.printname();
    return 0;
}

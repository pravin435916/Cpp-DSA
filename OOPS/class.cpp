// C++ program to illustrate how create a simple class and
#include <iostream>
#include <string>

using namespace std;

// Define a class named 'Person'
class Person {
    // Data members
    // private:
    public:
    string name;
    int age;
public:

    // Member function to introduce the person
    void introduce()
    {
        cout << "Hi, my name is " << name << " and I am "
             << age << " years old." << endl;
    }
};

int main()
{
    // Create an object of the Person class
    Person person1;

    // accessing data members
    //if data members is private then cant accesss
    person1.name = "Alice";
    person1.age = 30;

    // Call the introduce member method
    person1.introduce();

    return 0;
}

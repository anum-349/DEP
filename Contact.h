#include <iostream>
using namespace std;
#include <string>
class Contact {
    string name;
    string phoneNumber;
public:
    Contact(string nam, string no) 
    {
        name = nam;
        phoneNumber = no;
    }

    string getName() const {
        return name;
    }

    string getPhoneNumber() const 
    {
        return phoneNumber;
    }

    void displayContact() const 
    {
        cout << "Name: " << name << "\nPhone Number: " << phoneNumber << endl;
    }
};

#include"Contact.h"
#include<vector>
void addContact(vector<Contact>& contacts) {
     string name;
     string phoneNumber;
     cout << "Enter name: ";
     cin.ignore();
     getline( cin, name);
     cout << "Enter phone number: ";
     getline( cin, phoneNumber);
    contacts.emplace_back(name, phoneNumber);
     cout << "----Contact added successfully-----\n";
}

void viewContacts(const  vector<Contact>& contacts) {
    if (contacts.empty()) {
         cout << "-------No contacts available-------\n";
        return;
    }
    for (const auto& contact : contacts) {
        contact.displayContact();
    }
}

void deleteContact( vector<Contact>& contacts) {
     string name;
     cout << "Enter the name of the contact to delete: ";
     cin.ignore();
     getline( cin, name);
    auto it =  remove_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
        return contact.getName() == name;
        });
    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
         cout << "Contact Deleted Successfully.\n";
    }
    else {
         cout << "Contact Not Found.\n";
    }
}

int main() {
     vector<Contact> contacts;
    int choice;

    do {
        cout << "**********************************************************************Contact Management System**********************************************************************\n";
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Delete Contact" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
         cin >> choice;

       if(choice==1)
       {
           addContact(contacts);
           cout << endl;
       }
       else if (choice == 2)
       {
           viewContacts(contacts);
           cout << endl;
       }
       else if (choice == 3)
       {
           deleteContact(contacts);
           cout << endl;
       }
       else if (choice == 4)
             cout << "Exiting...\n";
       else
             cout << "Invalid choice. Please try again.\n";

    } while (choice != 4);

    return 0;
}

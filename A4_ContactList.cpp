#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    string email;
    string phone;
    string address;

public:
    // constructor to initialize all the attributes.
    Person() : name(""), age(), email(""), phone(""), address("") {}

    // setter
    void setData(string n, int a, string e, string p, string ad) {
        name = n;
        age = a;
        email = e;
        phone = p;
        address = ad;
    }
    // getter
    string getName() { return name; }
    int getAge() { return age; }
    string getEmail() { return email; }
    string getPhone() { return phone; }
    string getAddress() { return address; }

    // to display all the information of person: name,age,email,phone,address.
    void display() {
        cout << "Name: " << name << "\nAge: " << age << "\nEmail: " << email << "\nPhone: " << phone << "\nAddress: " << address << "\n";
    }
};

class ContactList {
private:
    // set the contact list with fixed size.
    Person contacts[100];
    int count;

public:
    // count start from 0.
    ContactList() : count(0) {}

    // Add a new contact
    void addContact(string name, int age, string email, string phone, string address) {
        // make sure count less than the max array size.
        if (count < 100) {
            contacts[count].setData(name, age, email, phone, address);
            count++;
            cout << "Contact information added!\n";
        }
        else {
            cout << "Contact list is full!\n";
        }
    }

    // create a function to display all contacts person
    void displayAll() {
        if (count == 0) {
            cout << "No contacts to display.\n";
        }
        else {
            for (int i = 0; i < count; i++) {
                cout << "\nContact " << (i + 1) << ":\n";
                contacts[i].display();
            }
        }
    }

    // search contacts by name
    void searchByName(string name) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (contacts[i].getName() == name) {
                cout << "\nContact Found:\n";
                contacts[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No contact found with name: " << name << "\n";
        }
    }
    // search contacts by email
    void searchByEmail(string email) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (contacts[i].getEmail() == email) {
                cout << "\nContact Found:\n";
                contacts[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No contact found with email: " << email << "\n";
        }
    }
    // search contacts by phone number
    void searchByPhone(string phone) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (contacts[i].getPhone() == phone) {
                cout << "\nContact Found:\n";
                contacts[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No contact found with phone: " << phone << "\n";
        }
    }
    // search contacts by address
    void searchByAddress(string address) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (contacts[i].getAddress() == address) {
                cout << "\nContact Found:\n";
                contacts[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No contact found with address: " << address << "\n";
        }
    }
};

void menu() {
    ContactList contactList;
    // create a contact list object.

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Display All Contacts\n";
        cout << "3. Search Contact by Name\n";
        cout << "4. Search Contact by Email\n";
        cout << "5. Search Contact by Phone\n";
        cout << "6. Search Contact by Address\n";
        cout << "7. Exit\n";
        cout << "Enter your choic (1-7): ";
        int choice;
        // get the user's choice.
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, email, phone, address;
            int age;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Age: ";
            cin>> age;
            cout << "Enter Email: ";
            getline(cin, email);
            cout << "Enter Phone: ";
            getline(cin, phone);
            cout << "Enter Address: ";
            getline(cin, address);

            contactList.addContact(name, age, email, phone, address);
            break;
        }
        case 2:
            contactList.displayAll();
            break;
        case 3: {
            string name;
            cin.ignore();
            cout << "Enter Name to Search: ";
            getline(cin, name);
            contactList.searchByName(name);
            break;
        }
        case 4: {
            string email;
            cin.ignore();
            cout << "Enter email to Search: ";
            getline(cin, email);
            contactList.searchByEmail(email);
            break;
        }
        case 5: {
            string phone;
            cin.ignore();
            cout << "Enter phone to Search: ";
            getline(cin, phone);
            contactList.searchByPhone(phone);
            break;
        }
        case 6: {
            string address;
            cin.ignore();
            cout << "Enter address to Search: ";
            getline(cin, address);
            contactList.searchByAddress(address);
            break;
        }
        case 7:
            cout << "Exit successfully!\n";
            return;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
// main function
int main() {
    cout << "Welcome\n";
    menu(); // Call the menu function
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Define a struct for Contact
struct Contact {
    string name;
    string phone;
    string email;
};

// Function to add a contact
void addContact(vector<Contact>& contacts) {
    Contact newContact;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newContact.name);
    cout << "Enter phone: ";
    getline(cin, newContact.phone);
    cout << "Enter email: ";
    getline(cin, newContact.email);

    contacts.push_back(newContact);
    cout << "Contact added successfully!\n";
}

// Function to display all contacts
void displayContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to display.\n";
        return;
    }
    cout << "Contacts List:\n";
    for (const auto& contact : contacts) {
        cout << "Name: " << contact.name << ", Phone: " << contact.phone << ", Email: " << contact.email << endl;
    }
}

// Function to search for a contact by name
void searchContact(const vector<Contact>& contacts) {
    cout << "Enter name to search: ";
    string searchName;
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.name == searchName) {
            cout << "Contact found: Name: " << contact.name << ", Phone: " << contact.phone << ", Email: " << contact.email << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found.\n";
    }
}

// Function to delete a contact by name
void deleteContact(vector<Contact>& contacts) {
    cout << "Enter name to delete: ";
    string deleteName;
    cin.ignore();
    getline(cin, deleteName);

    auto it = remove_if(contacts.begin(), contacts.end(),
                        [&deleteName](const Contact& contact) { return contact.name == deleteName; });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        cout << "Contact deleted successfully.\n";
    } else {
        cout << "Contact not found.\n";
    }
}

int main() {
    vector<Contact> contacts;
    int choice;

    while (true) {
        cout << "\n--- Contact Register System ---\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3:
                searchContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
#include "Contact.h"
#include <iostream>
using namespace std;

Contact::Contact() : address(""), city(""), state(""), zipcode(""), phonenumber("")
{

}

Contact::Contact(string address, string city, string state, string zipcode, string phonenumber) : address(address), city(city), state(state), zipcode(zipcode), phonenumber(phonenumber)
{

}

void Contact::get_contact_info() {
    cout << "Enter Address : " << endl;
    string n;
    getline(cin >> ws, n);
    address = n;
    cout << "Enter City : " << endl;
    cin >> city;
    cout << "Enter State : " << endl;
    cin >> state;
    cout << "Enter Zipcode : " << endl;
    cin >> zipcode;
    cout << "Enter Phone Number : " << endl;
    cin >> phonenumber;
}

void Contact::display_contact_info() const {
    cout << "Address : " << address << ", " << city << ", " << state << " " << zipcode << endl;
    cout << "Phone Number : " << phonenumber << endl;
}



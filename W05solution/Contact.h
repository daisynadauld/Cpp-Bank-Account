#pragma once

#include <string>
using namespace std;

class Contact {

private:
    string address;
    string city;
    string state;
    string zipcode;
    string phonenumber;
public:
    Contact();
    Contact(string address, string city, string state, string zipcode, string phonenumber);
    
    void get_contact_info();
    void display_contact_info() const;
    
};

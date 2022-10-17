#pragma once
#include <string>
#include <memory>
#include "Contact.h"
using namespace std;

class Account {

private:
    int id;
    float balance;
    string name;

    std::shared_ptr<Contact> contact_info;

public:
    Account(); // This is the constructor
    Account(int id, string name, float balance);
    void get_name_and_balance();
    void display_acc_info() const;
    void add_deposit(float deposit);
    void sub_withdraw(float withdraw);
    void set_id(int new_id);
    int get_id();
    float get_balance();
    void add_contact_info();
};

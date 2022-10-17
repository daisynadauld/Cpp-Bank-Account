#include "Account.h"
#include <iostream>
using namespace std;

Account::Account() : id(0), name(""), balance(0.00), contact_info(nullptr)
{

}

Account::Account(int id, string name, float balance) : id(id), name(name), balance(balance), contact_info(nullptr)
{

}

void Account::get_name_and_balance() {
    cout << "Enter the name : " << endl;
    string n;
    getline(cin >> ws, n);
    name = n;
    cout << "Enter the balance : " << endl;
    cin >> balance;
}

void Account::display_acc_info() const {
    cout << "Account ID : " << id << "  Name: " << name << "  Balance: $" << balance << endl;
    if (contact_info != nullptr) 
    {
        contact_info->display_contact_info();
    }
    
    
}

void Account::add_deposit(float deposit) {
    balance += deposit;
}

void Account::sub_withdraw(float withdraw) {
    balance -= withdraw;
}

void Account::set_id(int new_id)
{
    id = new_id;
}

int Account::get_id()
{
    return id;
}

float Account::get_balance()
{
    return balance;
}

void Account::add_contact_info() 
{
    contact_info = std::make_shared<Contact>();
    contact_info->get_contact_info();
}
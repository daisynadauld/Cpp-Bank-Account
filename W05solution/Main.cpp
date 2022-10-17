#include <iostream>
#include <list>
#include "Account.h"
#include <algorithm>
#include <numeric>
using namespace std;

void display_menu(void) {
    cout << "Account Menu:\n";
    cout << "0. Quit Program\n";
    cout << "1. Display Account Information\n";
    cout << "2. Add a deposit to an account\n";
    cout << "3. Withdraw from an account\n";
    cout << "4. Add new account\n";
    cout << "5. Find account by ID\n";
    cout << "6. Remove account\n";
    cout << "7. Show total balance for all accounts\n";
    cout << "8. Add a dividend to all accounts\n";
    cout << "9. Add contact information to an account\n";
    return;
}


int main(void)
{
    list<Account> accounts;
    int running = 1;
    int option = -1;
    while (running) {
        display_menu();
        cout << "Your choice: ";
        cin >> option;
        switch (option) {
        case 0:
            running = 0;
            break;
        case 1:
            for_each(accounts.begin(), accounts.end(), [](auto account) {
                account.display_acc_info();
                });
            break;
        case 2:
        {
            int id;
            float deposit;
            cout << "Enter the ID of the account to find: ";
            cin >> id;
            if (id < 0 || id > accounts.size() - 1) {
                cout << "Error\n";
                break;
            }

            else {
                for (auto i = accounts.begin(); i != accounts.end(); i++)
                {
                    if (i->get_id() == id)
                    {
                        cout << "Found account: ";
                        i->display_acc_info();
                        cout << "Ammount to deposit: $";
                        cin >> deposit;
                        i->add_deposit(deposit);
                    }
                }
            }

            break;
        }
        case 3:
        {
            int id;
            float withdraw;
            cout << "Enter the ID of the account to find: ";
            cin >> id;
            if (id < 0 || id > accounts.size() - 1) {
                cout << "Error\n";
                break;
            }

            else {
                for (auto i = accounts.begin(); i != accounts.end(); i++)
                {
                    if (i->get_id() == id)
                    {
                        cout << "Found account: ";
                        i->display_acc_info();
                        cout << "Ammount to withdraw: $";
                        cin >> withdraw;
                        i->sub_withdraw(withdraw);
                    }
                }
            }

            break;
        }

        case 4:
        {
            Account a;
            a.set_id(accounts.size());
            a.get_name_and_balance();
            accounts.push_back(a);
            break;
        }

        case 5:
        {
            int id;
            cout << "Enter the ID of the account to find: ";
            cin >> id;
            if (id < 0 || id > accounts.size() - 1) {
                cout << "Error\n";
                break;
            }

            else {
                for (auto i = accounts.begin(); i != accounts.end(); i++)
                {
                    if (i->get_id() == id)
                    {
                        i->display_acc_info();
                    }
                }
                break;
            }
        }

        case 6:
        {
            int id;
            cout << "Enter account ID to remove: ";
            cin >> id;
            auto end = remove_if(accounts.begin(), accounts.end(), [id](auto list_item) {
                return id == list_item.get_id();
                });
            accounts.erase(end, accounts.end());
            break;
        }

        case 7:
        {
            auto total = accumulate(accounts.begin(), accounts.end(), 0.0f, [accounts](auto accumulator, auto amount) {
                return accumulator + amount.get_balance();
                });
            cout << "Total in all accounts: $" << total << endl;
            break;
        }

        case 8:
        {
            float div;
            cout << "Enter the dividend as a percentage: ";
            cin >> div;
            div /= 100.0f;
            transform(accounts.begin(), accounts.end(), accounts.begin(), [div](auto account) {
                account.add_deposit(account.get_balance() * div);
                return account;
                });
            break;
        }
        case 9:
        {
            int id;
            cout << "Enter the ID of the account to find: ";
            cin >> id;
            if (id < 0 || id > accounts.size() - 1) {
                cout << "Error\n";
                break;
            }
            else {
                for (auto i = accounts.begin(); i != accounts.end(); i++)
                {
                    if (i->get_id() == id)
                    {
                        i->add_contact_info();
                    }
                }
                break;
            }
        }
        default:
            cout << "Error\n";
            break;
        }
        
    

    }

    return 0;
};


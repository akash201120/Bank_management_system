#include <iostream>
#include <string>
using namespace std;

class bank {
    char name[100], add[100];
    string account_type; // Changed from char to string
    int balance;

public:
    void open_account();
    void deposit_money();
    void withdraw_money();
    void display_account();
};

void bank::open_account() {
    cout << "enter your full name : ";
    cin.ignore(); // Ignore the newline character from the previous input
    cin.getline(name, 100);
    cout << "Enter your address : ";
    cin.getline(add, 100);
    cout << "Type of account you want to open (saving or current): ";
    cin >> account_type;
    cout << "Enter amount for deposit: ";
    cin >> balance;
    cout << "Your account is created";
}

void bank::deposit_money() {
    int deposit_amount;
    cout << "Enter how much you want to deposit: ";
    cin >> deposit_amount;
    balance += deposit_amount;
    cout << "Total amount you deposited: " << balance << endl;
}

void bank::display_account() {
    cout << "Your full name: " << name << endl;
    cout << "Your address: " << add << endl;
    cout << "Type of account: " << account_type << endl;
    cout << "Amount you deposited: " << balance << endl;
}

void bank::withdraw_money() {
    float withdrawal_amount;
    cout << "\nWithdrawal: ";
    cout << "Enter amount to withdraw: ";
    cin >> withdrawal_amount;
    if (withdrawal_amount > balance) {
        cout << "Insufficient balance! Cannot withdraw." << endl;
    } else {
        balance -= withdrawal_amount;
        cout << "Now total amount left: " << balance << endl;
    }
}

int main() {
    int choice;
    char continue_choice;
    bank obj;

    do {
        cout << "\n1) Open An Account\n";
        cout << "2) Deposit Money\n";
        cout << "3) Withdraw Money\n";
        cout << "4) Display Account\n";
        cout << "5) Exit\n";
        cout << "Select an option from above: ";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.open_account();
                break;
            case 2:
                obj.deposit_money();
                break;
            case 3:
                obj.withdraw_money();
                break;
            case 4:
                obj.display_account();
                break;
            case 5:
                cout << "Exiting...";
                return 0; // Exiting the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << "\nDo you want to select next option? (y/n): ";
        cin >> continue_choice;

    } while (continue_choice == 'y' || continue_choice == 'Y');

    return 0;
}


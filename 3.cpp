#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
    int accountNumber;
    double balance = 0;
    string accountHolderName;

public:
    void createAccount(int acnumber, string name) {
        this->accountNumber = acnumber;
        this->accountHolderName = name;
        cout << "\nAccount Created Successfully!";
    }

    void displayAccountInfo() {
        cout << "\n---------Account Details-----------";
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nAccount Holder Name : " << accountHolderName;
        cout << "\nAccount Balance : " << balance;
        cout << "\n-----------------------------------";
    }

    int getAccNumber() const {
        return accountNumber;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Amount Deposited Successfully!";
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Amount Withdrawn Successfully!";
        } else {
            cout << "Insufficient Balance!";
        }
    }

    double calculateInterest(double) const {
        return 0;
    }

    string getAccountType() const {
        return "General";
    }
};

class SavingAccount : public BankAccount {
public:
    string getAccountType() const {
        return "Saving";
    }

    double calculateInterest(double rate) const {
        return (balance * rate) / 100;
    }
};

class CurrentAccount : public BankAccount {
public:
    string getAccountType() const {
        return "Current";
    }

    double calculateInterest(double) const {
        return 0;
    }
};

class FixedDepositAccount : public BankAccount {
public:
    string getAccountType() const {
        return "Fixed Deposit";
    }

    void withdraw(double) {
        cout << "Withdrawals not allowed from Fixed Deposit Account!";
    }

    double calculateInterest(double rate) const {
        return (balance * rate) / 100;
    }
};

BankAccount* findAccountByNumber(BankAccount** accounts, int count, int accNo) {
    for (int i = 0; i < count; ++i) {
        if (accounts[i]->getAccNumber() == accNo) {
            return accounts[i];
        }
    }
    return nullptr;
}

int main() {
    BankAccount** accounts = nullptr;
    int accountCount = 0;
    int choice;

    do {
        cout << "\n\n--- WELCOME TO SBI BANK ---";
        cout << "\n1. Create Saving Account";
        cout << "\n2. Create Current Account";
        cout << "\n3. Create Fixed Deposit Account";
        cout << "\n4. Show All Account Details";
        cout << "\n5. Deposit Money";
        cout << "\n6. Withdraw Money";
        cout << "\n7. Calculate Interest";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int accNo;
            string name;
            cout << "Enter Account Number: ";
            cin >> accNo;

            if (findAccountByNumber(accounts, accountCount, accNo)) {
                cout << "Account with this number already exists!";
                break;
            }

            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);

            BankAccount* acc = new SavingAccount();
            acc->createAccount(accNo, name);

            BankAccount** newAccounts = new BankAccount*[accountCount + 1];
            for (int i = 0; i < accountCount; ++i) {
                newAccounts[i] = accounts[i];
            }
            newAccounts[accountCount] = acc;
            delete[] accounts;
            accounts = newAccounts;
            ++accountCount;

            break;
        }

        case 2: {
            int accNo;
            string name;
            cout << "Enter Account Number: ";
            cin >> accNo;

            if (findAccountByNumber(accounts, accountCount, accNo)) {
                cout << "Account with this number already exists!";
                break;
            }

            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);

            BankAccount* acc = new CurrentAccount();
            acc->createAccount(accNo, name);

            BankAccount** newAccounts = new BankAccount*[accountCount + 1];
            for (int i = 0; i < accountCount; ++i) {
                newAccounts[i] = accounts[i];
            }
            newAccounts[accountCount] = acc;
            delete[] accounts;
            accounts = newAccounts;
            ++accountCount;

            break;
        }

        case 3: {
            int accNo;
            string name;
            cout << "Enter Account Number: ";
            cin >> accNo;

            if (findAccountByNumber(accounts, accountCount, accNo)) {
                cout << "Account with this number already exists!";
                break;
            }

            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);

            BankAccount* acc = new FixedDepositAccount();
            acc->createAccount(accNo, name);

            BankAccount** newAccounts = new BankAccount*[accountCount + 1];
            for (int i = 0; i < accountCount; ++i) {
                newAccounts[i] = accounts[i];
            }
            newAccounts[accountCount] = acc;
            delete[] accounts;
            accounts = newAccounts;
            ++accountCount;

            break;
        }

        case 4: {
            if (accountCount == 0) {
                cout << "No accounts found.";
            } else {
                for (int i = 0; i < accountCount; ++i) {
                    cout << "\n----------------------- " << accounts[i]->getAccountType() << " Account ----------------------";
                    accounts[i]->displayAccountInfo();
                }
            }
            break;
        }

        case 5: {
            int accNo;
            double amount;
            cout << "Enter Account Number for Deposit: ";
            cin >> accNo;
            cout << "Enter Amount: ";
            cin >> amount;

            BankAccount* acc = findAccountByNumber(accounts, accountCount, accNo);
            if (acc) acc->deposit(amount);
            else cout << "Account not found.";
            break;
        }

        case 6: {
            int accNo;
            double amount;
            cout << "Enter Account Number for Withdrawal: ";
            cin >> accNo;
            cout << "Enter Amount: ";
            cin >> amount;

            BankAccount* acc = findAccountByNumber(accounts, accountCount, accNo);
            if (acc) acc->withdraw(amount);
            else cout << "Account not found.";
            break;
        }
        
        case 7: {
            for (int i = 0; i < accountCount; ++i) {
                double rate = 0;
                string type = accounts[i]->getAccountType();
                if (type == "Saving") rate = 3.5;
                else if (type == "Fixed Deposit") rate = 5.0;
                else continue;

                double interest = accounts[i]->calculateInterest(rate);
                cout << "\nInterest for " << type << " Account [" << accounts[i]->getAccNumber() << "]: " << interest;
            }
            break;
        }

        case 8:
            cout << "---------------------------------" << endl;
            cout << "Thank you For Using Bank" << endl;
            cout << "---------------------------------" << endl;
            for (int i = 0; i < accountCount; ++i) {
                delete accounts[i];
            }
            delete[] accounts;
            return 0;

        default:
            cout << "Invalid choice. Please try again.";
        }

    } while (true);

    return 0;
}


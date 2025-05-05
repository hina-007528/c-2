    #include <iostream>
    #include <string>
    using namespace std;
    const int MAX_ACCOUNTS = 100; 


    struct BankAccount {
        string holderName;
        string accountNumber;
        double balance;
    string accountType;  // "savings" or "checking"
    };


    BankAccount accounts[MAX_ACCOUNTS];
    int numAccounts = 0; 


    void openAccount(const string& holderName, const string& accountNumber, double initialDeposit, const string& accountType) {
        if (numAccounts >= MAX_ACCOUNTS) {
        cout << "Error: Cannot open new account. Maximum number of accounts reached." << endl;
            return;
        }

        

        
        accounts[numAccounts] = {holderName, accountNumber, initialDeposit, accountType};
        ++numAccounts;
    cout << "Account opened successfully." << endl;
    }


    void depositMoney(const string& accountNumber, double amount) {
        for (int i = 0; i < numAccounts; ++i) {
            if (accounts[i].accountNumber == accountNumber) {
                accounts[i].balance += amount;
            cout << "Deposited " << amount << " into account " << accountNumber << ". New balance: " << accounts[i].balance << endl;
                return;
            }
        }
        cout << "Error: Account number not found." << endl;
    }


    void withdrawMoney(const string& accountNumber, double amount) {
        for (int i = 0; i < numAccounts; ++i) {
            if (accounts[i].accountNumber == accountNumber) {
                if (amount > accounts[i].balance) {
                    cout << "Error: Insufficient funds." <<endl;
                    return;
                }
                accounts[i].balance -= amount;
            cout << "Withdrew " << amount << " from account " << accountNumber << ". New balance: " << accounts[i].balance << endl;
                return;
            }
        }
    cout << "Error: Account number not found." <<endl;
    }


    void displayAccountDetails(const string& accountNumber) {
        for (int i = 0; i < numAccounts; ++i) {
            if (accounts[i].accountNumber == accountNumber) {
            cout << "Account Number: " << accounts[i].accountNumber << endl;
                cout << "Account Holder: " << accounts[i].holderName <<endl;
                cout << "Balance: " << accounts[i].balance << endl;
                cout << "Account Type: " << accounts[i].accountType << endl;
                return;
            }
        }
    cout << "Error: Account number not found." << endl;
    }

    int main() {
    

        
        openAccount("Alice Smith", "1234567890", 1000.00, "savings");
        openAccount("Bob Johnson", "0987654321", 500.00, "checking");

        depositMoney("1234567890", 200.00);

    
        withdrawMoney("0987654321", 100.00);

    
        cout << "\nAccount Details for 1234567890:" << endl;
        displayAccountDetails("1234567890");

        cout << "\nAccount Details for 0987654321:" << endl;
        displayAccountDetails("0987654321");

        return 0;
    }
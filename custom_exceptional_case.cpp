
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class BankException : public exception
{
protected:
    string message;

public:
    BankException(string msg)
    {
        message = msg;
    }

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

class InsufficientFundsException : public BankException
{
public:
    InsufficientFundsException()
        : BankException("Error: Insufficient balance for withdrawal.")
    {
    }
};

class InvalidAmountException : public BankException
{
public:
    InvalidAmountException()
        : BankException("Error: Amount must be greater than zero.")
    {
    }
};

class BankAccount
{
private:
    string name;
    double balance;

public:
    BankAccount(string n, double b)
    {
        name = n;
        balance = b;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
            throw InvalidAmountException();

        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
            throw InvalidAmountException();

        if (amount > balance)
            throw InsufficientFundsException();

        balance -= amount;
    }

    void display()
    {
        cout << "Account Holder: " << name << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main()
{
    string name;
    double balance, depositAmount, withdrawAmount;

    cout << "Enter Account Holder Name: ";
    cin >> name;

    cout << "Enter Initial Balance: ";
    cin >> balance;

    BankAccount account(name, balance);

    cout << "\nInitial Account Details:" << endl;
    account.display();

    try
    {
        cout << "\nEnter Deposit Amount: ";
        cin >> depositAmount;

        account.deposit(depositAmount);

        cout << "Enter Withdrawal Amount: ";
        cin >> withdrawAmount;

        account.withdraw(withdrawAmount);
    }
    catch (const InsufficientFundsException &e)
    {
        cout << e.what() << endl;
    }
    catch (const InvalidAmountException &e)
    {
        cout << e.what() << endl;
    }
    catch (const BankException &e)
    {
        cout << "Bank Exception: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cout << "General Exception: " << e.what() << endl;
    }

    cout << "\nFinal Account Details:" << endl;
    account.display();

    return 0;
}

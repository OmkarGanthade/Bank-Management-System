#include"Account.h"

Account::Account(int acc_number, std::string acc_holder, double balance)
    :acc_number{acc_number}, acc_holder{acc_holder}, balance{balance}
{

}

int Account::getacc_number() const
{
    return acc_number;
}


std::string Account::getacc_holder() const
{
    return acc_holder;
}


double Account::get_balance() const
{
    return balance;
}

void Account::deposit(double amount)
{
    if(amount<=0)
        return;

    balance += amount;
    transactions.push_back(Transaction("Deposit", amount));
    
}


bool Account::withdraw(double amount)
{
    if(amount<=0)
        return false;
    if(amount > balance)
        return false;
    balance -= amount;
    transactions.push_back(Transaction("Withdraw", amount));

    return true;
}



void Account::display_account() const
{
    std::cout << "Account Number:      " << acc_number << std::endl;
    std::cout << "Account Holder Name: " << acc_holder << std::endl;
    std::cout << "Balance:             " << balance << std::endl;
}


void Account::display_transaction() const
{
    std::cout << "====================\n";
    std::cout << "Transaction History:  \n";
    std::cout << "=====================\n";
    for(auto &t:transactions)
    {
        std::cout << t.get_Transactiontype() << " : " << t.get_amount() << std::endl;
    }

}


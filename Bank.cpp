#include<iostream>
#include<algorithm>
#include"Bank.h"

int Bank::nextaccountnumber  = 1001;


Bank::Bank()
{

}

void Bank::create_acc(std::string holdername, double init_amount)
{
    int acc_number = nextaccountnumber;
    Account newacc(nextaccountnumber++, holdername, init_amount);

    accounts.push_back(newacc);
    std::cout << "Account created successfully\n";
    std::cout << "Account Number: " << acc_number << std::endl;
}

Account* Bank::find_acc(int acc_number)
{
    for(auto &acc:accounts)
    {
        if(acc.getacc_number() == acc_number)
        {
            return &acc;
        }
    }
    return nullptr;
}

bool Bank::deposit(int acc_number, double amount)
{
    Account* acc = find_acc(acc_number);
    if(acc == nullptr)
    {
        return false;
    }
    acc->deposit(amount);

    return true;

}

bool Bank::withdraw(int acc_number, double amount)
{
    Account* acc = find_acc(acc_number);
    if(acc == nullptr)
    {
        return false;
    }

    return acc->withdraw(amount);

}

void Bank::displayallacc() const
{
    for(const auto &acc:accounts)
    {
        acc.display_account();
        std::cout << "------------------------\n";
    }
}


bool Bank::delete_acc(int acc_number)
{
    auto it = std::find_if(accounts.begin(), accounts.end(), [acc_number] 
    (const Account &account)
    {
        return account.getacc_number() == acc_number;
    }
    );

    if(it == accounts.end())
        return false;
    accounts.erase(it);

    return true;
}


void Bank::show_transaction_history(int acc_number)
{
    Account* acc = find_acc(acc_number);
    if(acc == nullptr)
    {
        std::cout << "Account not found!!!\n";
        return;
    }

    acc->display_transaction();

}


const std::vector<Account>& Bank::getAccount() const
{
    return accounts;
}

void Bank::setAccount(const std::vector<Account>& accounts)
{
    this->accounts = accounts;
    if(accounts.empty())
{
    nextaccountnumber = 1001;
}
else
{
    int maxAccount = 0;

    for(const auto &acc : accounts)
    {
        if(acc.getacc_number() > maxAccount)
            maxAccount = acc.getacc_number();
    }

    nextaccountnumber = maxAccount + 1;
}
}
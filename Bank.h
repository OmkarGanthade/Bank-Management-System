#ifndef BANK_H_
#define BANK_H_

#include"Account.h"


class Bank
{
    private:
        std::vector<Account> accounts;
        static int nextaccountnumber;

    public:
        Bank();

        void create_acc(std::string holdername, double init_amount);

        Account* find_acc(int acc_number);
        
        bool delete_acc(int acc_number);

        void displayallacc() const;

        bool deposit(int acc_number, double amount);
        bool withdraw(int acc_number, double amount);

        void show_transaction_history(int acc_number);
        const std::vector<Account>& getAccount() const;
        void setAccount(const std::vector<Account>& accounts);

};




#endif
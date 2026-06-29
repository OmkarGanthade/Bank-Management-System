#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include<iostream>
#include<vector>
#include"Transaction.h"

class Account
{
    private:
        int acc_number;
        std::string acc_holder;
        double balance;

        std::vector<Transaction> transactions;

    public:
        Account(int acc_number, std::string acc_holder, double balance = 0.0);

        int getacc_number() const;
        std::string getacc_holder() const;
        double get_balance() const;


        void deposit(double amount);
        bool withdraw(double amount);

        void display_account() const;
        void display_transaction() const;

};

#endif


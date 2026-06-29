#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include<string>

class Transaction
{
    private:
        std::string type;
        double amount;

    public:
    Transaction(std::string type, double amount);
    std::string get_Transactiontype() const;
    double get_amount() const;
        

};

#endif
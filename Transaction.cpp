#include"Transaction.h"

Transaction::Transaction(std::string type, double amount)
    :type{type}, amount{amount}
{

}


std::string Transaction::get_Transactiontype() const
{
    return type;
}

double Transaction::get_amount() const{
    return amount;
}
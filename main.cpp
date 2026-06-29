#include "Bank.h"
#include "FileManager.h"
#include<limits>

int getInteger(const std::string& message)
{
    int value;

    while(true)
    {
        std::cout << message;

        std::cin >> value;

        if(!std::cin.fail())
            return value;

        std::cin.clear();

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n');

        std::cout << "Invalid input! Please enter a valid number.\n";
    }
}

void displayMenu()
{
    std::cout << "========================\n"
              << " Bank Management System \n"
              << "========================\n";
    
    std::cout << "1. Create Account\n" << "2. Deposit Money\n" << "3. Withdraw Money\n" << "4. Display All Accounts\n"
              << "5. Transaction History\n" << "6. Delete Account\n" << "0. Exit\n";

}


int main()
{
    Bank bank;
    std::vector<Account> loaddedaccount;

    if(FileManager::loadfile(loaddedaccount, "account.txt"))
    {
        bank.setAccount(loaddedaccount);
    }
    int choice{};
do{
    
    displayMenu();
        
    choice = getInteger("Enter your choice: ");

    switch (choice)
    {
    case 1:
    {
    std::string name;
    double balance;

    std::cout << "Enter Account Holder Name : ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    std::getline(std::cin,name);

    std::cout << "Enter Initial Balance : ";
    std::cin >> balance;

    bank.create_acc(name,balance);

    break;
    }
        
    case 2:
    {
        int acc_number;
        double amount;

        std::cout << "Enter the Account number\n";
        std::cin >> acc_number;

        std::cout << "Enter the amount\n";
        std::cin >> amount;

        if(bank.deposit(acc_number, amount))
        {
            std::cout << "Amount deposit successfull!\n";
        }
        else{
            std::cout << "Deposit failed\n";
        }
        break;
    }
    
    case 3:
    {
        int acc_number;
        double amount;

        std::cout << "Enter the Account number\n";
        std::cin >> acc_number;

        std::cout << "Enter the amount\n";
        std::cin >> amount;

        if(bank.withdraw(acc_number, amount))
        {
            std::cout << "Amount withdraw successfull!\n";
        }
        else{
            std::cout << "Withdraw failed\n";
        }
        break;
    }

    case 4:
    {
        bank.displayallacc();
        break;
    }

    case 5:
    {
        int acc_number;
        
        std::cout << "Enter the Account number\n";
        std::cin >> acc_number;

        bank.show_transaction_history(acc_number);

        break;
    }

    case 6:
    {
        int acc_number;
    
        std::cout << "Enter the Account number\n";
        std::cin >> acc_number;


        if(bank.delete_acc(acc_number))
        {
            std::cout << "Account Deleted\n";
        }
        else{
            std::cout << "Account Not Found\n";
        }
        break;
    }
    
    case 0:
        FileManager::saveacc(bank.getAccount(),"account.txt");
        std::cout << "Thankyou!!!\n";
        break;

    default:
        std::cout << "Invalid choice\n Try with different option\n";
        break;
    }
}while(choice!=0);
    

    return 0;
}
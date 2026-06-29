#include<fstream>
#include<sstream>
#include "FileManager.h"


bool FileManager::saveacc(const std::vector<Account>& accounts, const std::string& filename)
{
    std::ofstream outfile(filename);

    if(!outfile)
    {
        return false;
    }
    
    for(const auto& acc:accounts)
    {
         outfile << acc.getacc_number() << ","
                 << acc.getacc_holder() << ","
                 << acc.get_balance() << "\n";
    }
    return true;

}   


bool FileManager::loadfile(std::vector<Account>& accounts, const std::string& filename)
{
    std::ifstream infile(filename);

    if(!infile)
        return false;

    accounts.clear();

    std::string line;

    while(std::getline(infile, line))
    {
        std::stringstream ss(line);

        std::string accName;
        std::string accnumber;
        std::string balance;

        std::getline(ss, accnumber, ',');
        std::getline(ss, accName, ',');
        std::getline(ss, balance, ',');

        accounts.emplace_back(std::stoi(accnumber),accName,std::stod(balance));

    }

    return true;



}
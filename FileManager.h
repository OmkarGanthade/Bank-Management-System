#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_
#include<string>
#include<vector>
#include"Account.h"


class FileManager
{
    public:
        static bool saveacc(const std::vector<Account>& accounts, const std::string& filename);

        static bool loadfile(std::vector<Account>& accounts, const std::string& filename);
};





#endif
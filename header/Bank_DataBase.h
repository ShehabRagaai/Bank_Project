#ifndef Bank_DataBase_H_
#define Bank_DataBase_H_

#include <map>
#include <vector>
#include <string>
#include <cstdint>
#include <chrono>
#include "../thirdparty/json.hpp"
#include "User.h"
#include<fstream>


class Bank_DataBase
{
    private:
	std::map<std::string , User> usrnametoUser_;
    std::map<std::string , User*> AcctoUser_;
	
	
    
	public:
	
	bool IsUserFound(std::string password , std::string username);

    bool setNewUser(std::string usrname , User& user);

	bool deleteuser(std::string Accnum);
	
	void SetTransaction(std::string Accnum , int32_t amount);

    void updateUser(std::string accountNumber, User updatedUser);
	
	std::vector<UserTransaction> getTransaction(std::string Accnum , uint16_t count);
	
	
	bool getUser(User& result , std::string password , std::string usrname);

    std::vector <User> getallusers();
	
	bool getAccountNumber(std::string result,std::string Username);

    bool getAccountBalance(int32_t& result ,std::string Accnum);

	nlohmann::json tojson();
	

    void SaveToFile(std::string filename);
};


#endif
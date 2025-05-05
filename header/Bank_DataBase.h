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
    std::map<std::string , User> PasstoUser_;
	std::map<std::string , User*> AcctoUser_;
	std::map<std::string , User*> usrnametoUser_;
	
    
	public:
	
	bool IsUserFound(std::string password , std::string username);

    void setNewUser(std::string password , User& user);
	
	void deleteuser(std::string Accnum);
	
	void SetTransaction(std::string Accnum , int32_t amount);
	
	std::vector<UserTransaction> getTransaction(std::string Accnum , uint16_t count);
	
	void getbankbalance(std::string Accnum);
	
	User getUser(std::string password);
	
	std::string getAccountNumber(std::string Username);
	
    
	
	nlohmann::json tojson();
	

    void SaveToFile(std::string filename);
};


#endif
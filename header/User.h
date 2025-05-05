#ifndef USER_H_
#define USER_H_

#include <string>
#include <cstdint>
#include <vector>
#include <chrono>
#include <sstream>
#include "../thirdparty/json.hpp"

class UserTransaction 
{
    private:
    int32_t Amount ;
    std::chrono::system_clock::time_point date;
    std::string LocalTime;

    public:
    UserTransaction()= default;
    UserTransaction(int32_t amount , std::chrono::system_clock::time_point d );
    
    nlohmann::json tojson();
    static UserTransaction fromJson(nlohmann::json);

};

class User 
{
    private:
    
    std::string username;
    std::string  Accountnumber;
    std::string fullname;
    uint8_t Age;  
    int32_t balance;
	std::vector<UserTransaction> TransactionHistory;
   
    public:
    User()=default;
    void setFullname(std::string fullname);
    void setUserName(std::string uname);
    void setAccountNumber(std::string Accnum);
    void setAge(uint8_t age);
    void setBalance(int32_t blc);
    void addTransaction(UserTransaction trans);
    
    std::string getFullname();
    std::string getUserName();
    std::string getAccountNumber();
    uint8_t getAge();
    int32_t getBalance();
    std::vector<UserTransaction> getTransactionHsitory();

    nlohmann::json tojson();
    User fromJson(nlohmann::json);

  
    

};


    

#endif
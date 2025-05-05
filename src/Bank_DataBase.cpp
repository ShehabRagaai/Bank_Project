
#include "../header/Bank_DataBase.h"

bool Bank_DataBase::IsUserFound(std::string password, std::string username)
{
    std::map<std::string, User>::iterator it;

    it = usrnametoUser_.find(username);
    if (it != usrnametoUser_.end())
    {
        if ((it->second).getpassword() == password)

            return true;
    }

    return false;
}

bool Bank_DataBase::setNewUser(std::string usrname, User &user)
{
    std::map<std::string, User>::iterator it;

    it = usrnametoUser_.find(usrname);
    if (it != usrnametoUser_.end())
    {
        return false;
    }

    usrnametoUser_[usrname] = user;
    AcctoUser_[user.getAccountNumber()] = &usrnametoUser_[usrname];
    ;
    return true;
}

bool Bank_DataBase::deleteuser(std::string Accnum)
{
    std::map<std::string, User *>::iterator it;

    it = AcctoUser_.find(Accnum);

    if (it != AcctoUser_.end())
    {
        usrnametoUser_.erase(it->second->getUserName());
        AcctoUser_.erase(Accnum);
        return true;
    }

    return false;
}

void Bank_DataBase::SetTransaction(std::string Accnum, int32_t amount)
{    
}

std::vector<UserTransaction> Bank_DataBase::getTransaction(std::string Accnum, uint16_t count)
{
}

bool Bank_DataBase::getAccountBalance(int32_t &result, std::string Accnum)
{

    std::map<std::string, User *>::iterator it;

    it = AcctoUser_.find(Accnum);

    if (it != AcctoUser_.end())
    {
        result = it->second->getBalance();
        return true;
    }

    return false;
}

bool Bank_DataBase::getUser(User& result,std::string password, std::string usrname)
{
    std::map<std::string, User>::iterator it;
    it = usrnametoUser_.find(usrname);
    
    if(it != usrnametoUser_.end())
    {
        if(it->second.getpassword()==password)
        {
          result=it->second;
          return true;
        }
    }

    return false;
}

std::vector<User> Bank_DataBase::getallusers()
{
    std::map<std::string, User>::iterator it;
    std::vector<User> result;
    for (it = usrnametoUser_.begin(); it != usrnametoUser_.end(); it++)
    {
        result.push_back(it->second);
    }

    return result;
}

void Bank_DataBase::updateUser(std::string accountNumber, User updatedUser)
{
}

bool Bank_DataBase::getAccountNumber(std::string result, std::string Username)
{
    std::map<std::string, User>::iterator it;

    it = usrnametoUser_.find(Username);

    if (it != usrnametoUser_.end())
    {
        result = it->second.getAccountNumber();
        return true;
    }

    return false;
}

nlohmann::json Bank_DataBase::tojson()
{
    nlohmann::json Json;
    nlohmann::json JsonArr = nlohmann::json::array();
    nlohmann::json JsonArr2 = nlohmann::json::array();
    std::map<std::string, User>::iterator it;
    std::map<User, std::vector<UserTransaction>>::iterator it2;

    for (it = usrnametoUser_.begin(); it != usrnametoUser_.end(); it++)
    {
        JsonArr.push_back((it->second).tojson());
    }

    Json["Users"] = JsonArr;

    return Json;
}

void Bank_DataBase::SaveToFile(std::string filename)
{

    std::ofstream out(filename);

    nlohmann::json Json = tojson();

    out << Json.dump(4);

    out.close();
}

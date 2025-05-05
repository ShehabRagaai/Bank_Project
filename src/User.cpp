#include "../header/User.h"

void User::addTransaction(UserTransaction trans)
{
    TransactionHistory.push_back(trans);
}
void User::setFullname(std::string fname)
{
    fullname = fname;
}
void User::setUserName(std::string uname)
{
    username = uname;
}
void User::setAccountNumber(std::string Accnum)
{
    Accountnumber = Accnum;
}

void User::setAge(uint8_t age)
{
    Age = age;
}
void User::setBalance(int32_t blc)
{
    balance = blc;
}

std::vector<UserTransaction> User::getTransactionHsitory()
{
    return TransactionHistory;
}

std::string User::getFullname()
{
    return fullname;
}

std::string User::getUserName()
{
    return username;
}
std::string User::getAccountNumber()
{
    return Accountnumber;
}
uint8_t User::getAge()
{
    return Age;
}
int32_t User::getBalance()
{
    return balance;
}

nlohmann::json User::tojson()
{
    nlohmann::json Json;
    Json["Username"] = username;
    Json["Fullname"] = fullname;
    Json["Accountnumber"] = Accountnumber;
    Json["Age"] = Age;
    Json["Balance"] = balance;

    nlohmann::json JsonArr = nlohmann::json::array();

    for (int i = 0; i < TransactionHistory.size(); i++)
    {
        JsonArr.push_back(TransactionHistory[i].tojson());
    }

    Json["TransactionHistory"] = JsonArr;

    return Json;
}
User User::fromJson(nlohmann::json Json)
{
    User obj;
    obj.username = Json["Username"];
    obj.fullname = Json["Fullname"];
    obj.Accountnumber = Json["Accountnumber"];
    obj.Age = Json["Age"];
    obj.balance = Json["Balance"];
    for (const auto &item : Json["TransactionHistory"])
    {
        obj.TransactionHistory.push_back(UserTransaction::fromJson(item));
    }

    return obj;
}

UserTransaction::UserTransaction(int32_t amount, std::chrono::system_clock::time_point d) : Amount(amount), date(d)
{
}

nlohmann::json UserTransaction::tojson()
{
    nlohmann::json Json;
    Json["Amount"] = Amount;

    std::time_t t = std::chrono::system_clock::to_time_t(date);
    std::tm tm = *std::localtime(&t);

    std::stringstream ss;
    ss << std::put_time(&tm, "%d/%m/%y");
    LocalTime = ss.str();
    Json["Date"] = LocalTime;

    return Json;
}

UserTransaction UserTransaction::fromJson(nlohmann::json Json)
{
    UserTransaction obj;
    obj.Amount = Json["Amount"];
    obj.LocalTime = Json["Date"];

    std::tm tm = {};
    std::stringstream ss(obj.LocalTime);
    ss >> std::get_time(&tm, "%d/%m/%y");

    std::time_t tt = std::mktime(&tm);
    obj.date = std::chrono::system_clock::from_time_t(tt);

    return obj;
}

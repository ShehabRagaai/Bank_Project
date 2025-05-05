
  #include "../header/Bank_DataBase.h"


	bool Bank_DataBase::IsUserFound(std::string password , std::string username)
	{
		
	}

    void Bank_DataBase::setNewUser(std::string password , User& user)
	{
		
	}
	
	void Bank_DataBase::deleteuser(std::string Accnum)
	{
	
	}
	
	void Bank_DataBase::SetTransaction(std::string Accnum , int32_t amount)
	{
		
		
	}
	
	std::vector<UserTransaction> Bank_DataBase::getTransaction(std::string Accnum , uint16_t count)
	{
		
	}
	
	void Bank_DataBase::getbankbalance(std::string Accnum)
	{
		
	}
	
	User Bank_DataBase::getUser(std::string password)
	{
		
	}
	
	std::string Bank_DataBase::getAccountNumber(std::string Username)
	{
		
	}
	
    
	
	nlohmann::json Bank_DataBase::tojson()
	{
		nlohmann::json Json;
		nlohmann::json JsonArr = nlohmann::json::array();
		nlohmann::json JsonArr2 = nlohmann::json::array();
		std::map<std::string , User>::iterator it ;
		std::map<User,std::vector<UserTransaction> > :: iterator it2;
		
		for(it=PasstoUser_.begin() ; it!=PasstoUser_.end() ; it++)
		{ 
	        JsonArr.push_back((it->second).tojson());
		}  
		
		Json["Users"]=JsonArr;
		
		return Json;
		
	}
	

    void Bank_DataBase::SaveToFile(std::string filename)
    {
	
		std::ofstream out(filename);
		
		nlohmann::json Json=tojson();
		
		out<<Json.dump(4);
		
		out.close();
		
		
	}

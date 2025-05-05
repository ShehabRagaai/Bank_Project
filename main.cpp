#include <iostream>
#include "User.h"
#include "Bank_DataBase.h"


int main()
{
    
    User usr;
    usr.setFullname("shehab Ahmed");
    usr.tojson();
    std::cout<<usr.getFullname()<<std::endl;

}
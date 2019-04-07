#ifndef GLOBAL_H
#define GLOBAL_H
#include "user.h"
#include"group.h"
#include<string>
#include<map>

namespace global {
   extern map<string,User*>users;  //users is a map that contains the pointer to all users. can be identified through the username
   extern map<string,group*>groups;
}


//extern map<string,User> users;

#endif // GLOBAL_H

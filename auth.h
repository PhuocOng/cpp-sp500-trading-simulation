#pragma once //Khi nao co .h cung phai co pragma once
#include <string> //Ko su dung bat ki library nao co san => phai inform no 
using namespace std;

//Define 3 functions, ko code

bool sign_in();
void sign_up();
bool authenticate(const string& user, const string& pass); //&pass by value and pass by reference


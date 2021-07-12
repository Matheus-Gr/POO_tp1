//
// Created by mathe on 05/07/2021.
//

#ifndef TP_I_EMPLOYEE_H
#define TP_I_EMPLOYEE_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "utils.h"

using namespace std;

class Employee
{
private:
    string _name;
    string _office;
    float _salary;
    string _userName;
    string _password;

public:
    Employee(const string& name, const string& office, float salary, const string& userName, const string& password);

    void register_client(const string& name, const string& address, const string& phone);

    void product_sale(char * product, int quantity = 1, const string& client = "n/a");

    void service_sale(const string& service, float price, const string& client = "n/a");
};

#endif //TP_I_EMPLOYEE_H

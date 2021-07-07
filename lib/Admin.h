//
// Created by otavio on 05/07/2021.
//

#ifndef TP_I_ADMIN_H
#define TP_I_ADMIN_H

#define STRING(num) #num

#include <iostream>
#include <string>
#include <cstdlib>
#include "Seller.h"
#include <cstring>
#include <sstream>
#include "utils.h"

using namespace std;

class Admin {
private:
    string _userName;
    string _password;
    float _cash;
public:
    Admin();
    void add_cash(float cash);
    void remove_cash(float cash);
    float get_cash();
    Seller register_seller(const string& name, const string& office, float salary, const string& userName, const string& password);
    void register_product(const string& productName, float  buyPrice, float salePrice , int quantity = 1);
    void billPayment(const string& valDate, float price, const string& description);
};


#endif //TP_I_ADMIN_H

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
//    void setUserName(const string& userName);
//    void setPassword(const string& password);
    Admin();
    void addCash(float cash);
    void removeCash(float cash);


    static Seller register_seller(const string& name, const string& office, float salary, const string& userName, const string& password);
    static void register_product(const string& productName, float price, int quantity);
    void billPayment(const string& valDate, float price, const string& description);

    void get_seller_list();
    void buy_products();
    void report_generate();

};


#endif //TP_I_ADMIN_H

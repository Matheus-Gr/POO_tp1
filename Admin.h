//
// Created by otavio on 05/07/2021.
//

#ifndef TP_I_ADMIN_H
#define TP_I_ADMIN_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "Seller.h"

using namespace std;

class Admin {
private:
    string userNames;
    string password;
public:
    Seller* register_seller(string name, string office, float salary, string userName, string password);
    void get_seller_list();
    void payment();
    void buy_products();
    void report_generate();

};


#endif //TP_I_ADMIN_H

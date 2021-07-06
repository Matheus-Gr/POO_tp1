//
// Created by otavio on 05/07/2021.
//

#include "Admin.h"


Seller* Admin::register_seller(string name, string office, float salary, string userName, string password) {
    Seller *newSeller;
    newSeller->setName(name);
    newSeller->setOffice(office);
    newSeller->setSalary(salary);
    newSeller->setUserName(userName);
    newSeller->setPassword(password);
    return newSeller;
}

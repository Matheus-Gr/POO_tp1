#include <iostream>
#include <string>
#include <cstdio>
#include "Admin.h"
#include "seller.h"

using namespace std;

int main() {
    Admin admin;
    Seller seller;
    string name = "Mat Gon";
    string office = "Astronaut";
    float salary = 1200.65;
    string userName = "matobrabo@gmail.com";
    string password = "farel159";
//    seller = admin.register_seller(name,office,salary,userName,password);
//    cout << seller->getUserName() << endl << seller->getSalary() << endl;
    char *drug;
    int quant;
    cin>> drug;
    cin>> quant;
    seller.productSale(drug,quant);
    return 0;
}

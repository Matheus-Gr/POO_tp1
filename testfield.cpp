#include <iostream>
#include <string>
#include <cstdio>
#include "lib/Admin.h"
#include "lib/utils.h"
using namespace std;

int main() {

    Admin admin;
    string name = "Mat";
    string office = "Astronaut";
    float salary = 1200.65;
    string userName = "matobrabo@gmail.com";
    string password = "farel159";

    Seller seller = admin.register_seller(name,office,salary,userName,password);
    cout << seller.getUserName() << endl << seller.getSalary() << endl;

    admin.register_product("Piruzao",67.23,2);
    admin.addCash(10000);
    admin.billPayment("01/07/2022",1000,"pagamento do agiota");
    return 0;
}

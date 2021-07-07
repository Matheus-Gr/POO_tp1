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

    admin.add_cash(1000);
    cout << "Current cash: " << admin.get_cash() << endl;
    Seller seller = admin.register_seller(name,office,salary,userName,password);
    seller.service_sale("Tosa",58.25);
    seller.service_sale("Banho",8.5, "Otavio");
//    seller.registerClient("tavin pica torta", "Rua do caralho, bairro da desgraca", "(31)98675-2831");
//    seller.productSale("maconha");
    admin.register_product("cogumelo", 20, 40);
    cout << "Current cash: " << admin.get_cash() << endl;
//    admin.addCash(10000);
//    admin.billPayment("01/07/2022",1000,"pagamento do agiota");
    return 0;
}

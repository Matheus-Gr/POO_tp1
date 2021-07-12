#include <iostream>
#include <string>
#include <cstdio>
#include "lib/Admin.h"
#include "lib/utils.h"
using namespace std;

int main() {

    Admin admin("Matheus","admin",0,"admin","admin");
    Employee tavin = admin.register_employee("Babu bala tensa","vet",3000,"babu","picatorta");
//    tavin.register_client("Poze","Rodo","666-777");
//    tavin.product_sale("maconha", 1000);
//    tavin.service_sale("bolar baseado", 2.50, "Poze");

    return 0;
}

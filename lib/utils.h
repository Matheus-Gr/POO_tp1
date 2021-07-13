//
// Created by mathe on 06/07/2021.
//

#ifndef TP_I_UTILS_H
#define TP_I_UTILS_H

#define STOCK_PATH "../database/stock.txt"
#define TEMP_PATH "../database/temp.txt"
#define CLIENTS_PATH "../database/clients.txt"
#define ACCOUNTS_PATH "../database/accounts.txt"
#define RESUME_PATH "../database/resume.txt"
#define SERVICES_PATH "../database/services.txt"
#define VET_RESUME_PATH "../database/vet_resume.txt"
#define ADMIN_PATH "../database/admin.txt"

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

string getDate();

void add_balance(float value);

#endif //TP_I_UTILS_H

//
// Created by otavio on 05/07/2021.
//

#include "Admin.h"


Seller Admin::register_seller(const string& name, const string& office, float salary,
                              const string& userName, const string& password) {
    Seller newSeller(name,office,salary,userName,password);

    const char *accounts = "../database/accounts.txt";
    FILE *file;
    file = fopen(accounts, "r+");
    fseek(file, 0, SEEK_END);

    stringstream ss;
    ss << userName << " " << password << " " << "/seller" << name << " " << office << " " << salary;
    string report = ss.str();
    fputs(report.c_str(), file);
    fputs("\n",file);

    fclose(file);

    return newSeller;
}

void Admin::register_product(const string& productName, float price, int quantity) {
    const char *FILENAME = "../database/stock.txt";
    const char *TEMP = "../database/stock.txt";

    FILE *file, *temp;
    file = fopen(FILENAME, "r+");
//    file = fopen(TEMP, )
    fseek(file, 0, SEEK_END);

    stringstream ss;
    ss << productName << " " << price << " " << quantity;
    string concatenateText = ss.str();

    char productData[] = "";
    strcpy(productData,concatenateText.c_str());
    fputs(productData,file);
    fputs("\n",file);

    fclose(file);
}

Admin::Admin() {
    _userName  = "admin";
    _password = "admin";
    _cash = 0;
}

void Admin::addCash(float cash) { _cash += cash;}

void Admin::removeCash(float cash) { _cash -= cash;}

void Admin::billPayment(const string& valDate, float price, const string& description) {
    if(_cash < price){
        cout << "Nao ha saldo suficiente para realizar trasacao!";
        return;
    }else{
        int cDay, cMouth, cYear, eDay, eMouth, eYear;
        string currentDate = getDate();
        sscanf(currentDate.c_str(), "%d/%d/%d", &cDay, &cMouth, &cYear);
        sscanf(valDate.c_str(), "%d/%d/%d", &eDay, &eMouth, &eYear);
        int currentTime = cDay + (cMouth*30) + (cYear*365);
        int expirationTime = eDay + (eMouth*30) + (eYear*365);
        if(currentTime > expirationTime){
            cout << "Prazo para o pagamento em questao expirou!";
            return;
        }
    }

    _cash -= price;

    const char *resume = "../resume.txt";
    FILE *file;
    file = fopen(resume, "r+");
    fseek(file, 0, SEEK_END);

    stringstream ss;
    ss << "Pagamento de conta no valor de " << price << " reais. Descricao: " << description << ".";
    string report = ss.str();
    fputs(report.c_str(), file);
    fputs("\n",file);

    fclose(file);

}

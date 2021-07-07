//
// Created by otavio on 05/07/2021.
//

#include "Admin.h"

Admin::Admin() {
    _userName  = "admin";
    _password = "admin";
    _cash = 0;
}
float Admin::get_cash(){
    return _cash;
}

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

void Admin::register_product(const string& productName, float  buyPrice, float salePrice ,int quantity) {
    if(get_cash() < buyPrice){
        cout << "Saldo insuficiente para compra dos produtos";
        return;
    } else{
        remove_cash(buyPrice);
    }

    FILE *stockFile, *tempFile, *resumeFile;
    stockFile = fopen(STOCK_PATH, "r");
    tempFile = fopen(TEMP_PATH, "w");
    resumeFile = fopen(RESUME_PATH, "r+");

    char tempProductName[100];
    float tempPrice;
    int tempQuantity;
    int equal;
    int validLine;
    bool newProduct = true;

    while(!feof(stockFile)){
        validLine = fscanf(stockFile , "%s %f %d", tempProductName, &tempPrice, &tempQuantity);
        if(validLine != -1){
            equal = strcmp(tempProductName, productName.c_str());
            if(!equal){
                tempQuantity += quantity;
                tempPrice = salePrice;
                newProduct = false;
            }
            fprintf(tempFile, "%s %.2f %d\n", tempProductName, tempPrice, tempQuantity);
        }
    }

    if(newProduct){
        fprintf(tempFile, "%s %.2f %d\n", productName.c_str(), salePrice, quantity);
    }

    fseek(resumeFile, 0, SEEK_END);
    stringstream ss;
    ss << "Reposicao no estoque de " << quantity << " " << productName << ", comprado por "
       << buyPrice << " reais, preco de venda definida como " << salePrice << " reais.";
    string report = ss.str();
    fputs(report.c_str(), resumeFile);
    fputs("\n",resumeFile);
    fclose(resumeFile);

    fclose(stockFile);
    fclose(tempFile);
    remove(STOCK_PATH);
    rename(TEMP_PATH, STOCK_PATH);
}


void Admin::add_cash(float cash) { _cash += cash;}

void Admin::remove_cash(float cash) { _cash -= cash;}

void Admin::billPayment(const string& valDate, float price, const string& description) {
    if(get_cash() < price){
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

    remove_cash(price);

    FILE *file;
    file = fopen(RESUME_PATH, "r+");
    fseek(file, 0, SEEK_END);

    stringstream ss;
    ss << "Pagamento de conta no valor de " << price << " reais. Descricao: " << description << ".";
    string report = ss.str();
    fputs(report.c_str(), file);
    fputs("\n",file);

    fclose(file);
}
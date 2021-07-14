//
// Created by otavio on 05/07/2021.
//

#include "Admin.h"

Admin::Admin(const string &name, const string &office, float salary, const string &userName,
             const string &password, float cash) : Employee(name, office, salary, userName, password) {
    set_cash(cash);
}

void Admin::remove_cash(float value) {
    float currentCash;
    currentCash = get_cash();
    set_cash(currentCash - value);

    FILE *adminFile;
    adminFile = fopen(ADMIN_PATH, "w");

    ostringstream currentCashSs;
    currentCashSs << get_cash();
    fputs(currentCashSs.str().c_str(), adminFile);

    fclose(adminFile);
}

float Admin::get_cash() {return _cash;}

void Admin::register_employee(const string& name, const string& office, float salary,
                                const string& userName, const string& password) {
    Employee newSeller(name,office,salary,userName,password);

    FILE *file;
    file = fopen(ACCOUNTS_PATH, "r+");
    fseek(file, 0, SEEK_END);

    stringstream report;
    report << userName << " " << password << " " << office << " " << name << " " << salary;
    fputs(report.str().c_str(), file);
    fputs("\n",file);

    fclose(file);
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
    stringstream report;
    report << "Reposicao no estoque de " << quantity << " " << productName << ", comprado por RS"
       << buyPrice << ", preco de venda definida como RS" << salePrice << ".";
    fputs(report.str().c_str(), resumeFile);
    fputs("\n",resumeFile);
    fclose(resumeFile);

    fclose(stockFile);
    fclose(tempFile);
    remove(STOCK_PATH);
    rename(TEMP_PATH, STOCK_PATH);
}

void Admin::billPayment(const string& valDate, float price, const string& description) {
    if(get_cash() < price){
        cout << "Nao ha saldo suficiente para realizar trasacao!\n";
        return;
    }else{
        int cDay, cMouth, cYear, eDay, eMouth, eYear;
        string currentDate = getDate();
        sscanf(currentDate.c_str(), "%d/%d/%d", &cDay, &cMouth, &cYear);
        sscanf(valDate.c_str(), "%d/%d/%d", &eDay, &eMouth, &eYear);
        int currentTime = cDay + (cMouth*30) + (cYear*365);
        int expirationTime = eDay + (eMouth*30) + (eYear*365);
        if(currentTime > expirationTime){
            cout << "Prazo para o pagamento em questao expirou!\n";
            return;
        }
    }

    remove_cash(price);

    cout << "cash: " << get_cash() << endl;
    cout << "Trasacao realizada com sucesso!\n";

    FILE *file;
    file = fopen(RESUME_PATH, "r+");
    fseek(file, 0, SEEK_END);

    stringstream report;
    report << "Pagamento de conta no valor de RS" << price << ". Descricao: " << description << ".";
    fputs(report.str().c_str(), file);
    fputs("\n",file);

    fclose(file);
}

void Admin::set_cash(float cash) {
    _cash = cash;
}

void Admin::update_cash() {
    FILE *adminFile;
    float cash;
    adminFile = fopen(ADMIN_PATH, "r");
    fscanf(adminFile, "%f", &cash);
    fclose(adminFile);
    set_cash(cash);
}

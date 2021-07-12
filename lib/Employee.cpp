//
// Created by mathe on 05/07/2021.
//

#include <cstring>
#include "Employee.h"

Employee::Employee(const string& name, const string& office, float salary, const string& userName, const string& password) {
    _name = name;
    _office = office;
    _salary = salary;
    _userName = userName;
    _password = password;
}

void Employee::register_client(const string& name, const string& address, const string& phone) {
    FILE *file;
    file = fopen(CLIENTS_PATH, "r+");
    fseek(file, 0, SEEK_END);

    stringstream ss;
    ss << name << "|" << address << "|" << phone;
    string report = ss.str();
    fputs(report.c_str(), file);
    fputs("\n",file);

    fclose(file);
}

void Employee::product_sale(char *product, int quantity, const string& client) {
    FILE *stockFile, *tempFile;
    stockFile = fopen(STOCK_PATH, "r");
    tempFile = fopen(TEMP_PATH, "w");
    int result;
    int n = 0;
    float price;
    int qtd;
    char x;
    char produto[100];
    int flag=0;
    while (!feof(stockFile)) {
        result = fscanf(stockFile, "%s %f %d", produto, &price, &qtd);
        if (result) {
            if (strcmp(produto, product) == 0 && qtd > 0) {
                if(quantity>qtd){
                    cout<<"estoque insulficiente"<<endl;
                }else {
                    cout <<produto << " ---> valor : " << price * quantity << endl;
                    cout << "confirmar compra(S ou N)?" << endl;
                    cin >> x;
             
                    if (x == 'S' or x == 's') {
                        qtd = qtd - quantity;

                        FILE *resumeFile;
                        resumeFile = fopen(RESUME_PATH, "r+");
                        fseek(resumeFile, 0, SEEK_END);

                        stringstream ss;
                        ss <<quantity<< "x de " << product << " vendido por: " << price*quantity << "RS, para " << client;
                        string report = ss.str();
                        fputs(report.c_str(), resumeFile);
                        fputs("\n", resumeFile);

                        fclose(resumeFile);
                        cout << "successo!" << endl;
                    } else cout<<"compra cancelada com sucesso"<<endl;
                }
            }
            fprintf(tempFile, "%s %.2f %d\n", produto, price, qtd);
        }
        n++;
    }
    fclose(stockFile);
    fclose(tempFile);
    remove(STOCK_PATH);
    rename(TEMP_PATH, STOCK_PATH);
}

void Employee::service_sale(const string& service, float price, const string& client) {
    FILE *servicesFile, *resumeFile;
    servicesFile = fopen(SERVICES_PATH,"r+");
    resumeFile = fopen(RESUME_PATH, "r+");

    fseek(servicesFile, 0, SEEK_END);
    fseek(resumeFile, 0, SEEK_END);

    stringstream ss, ss2;
    ss << service << "|" << client << "|" << price;
    string resume = ss.str();
    fputs(resume.c_str(), servicesFile);
    fputs("\n",servicesFile);

    fclose(servicesFile);

    ss2 << service << " para cliente " << client << " no valor de " << price << " reais.";
    string report = ss2.str();
    fputs(report.c_str(), resumeFile);
    fputs("\n",resumeFile);

    fclose(resumeFile);

}



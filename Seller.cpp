//
// Created by mathe on 05/07/2021.
//

#include <cstring>
#include "Seller.h"

void Seller::registerClient(string name, string address, string phone) {
    cout << name << endl << address << endl << phone << endl;
}

void Seller::getClientList() {
    int numLines = 0;
    ifstream in("../clients.txt");
    string unused;
    while (getline(in, unused)) {
        ++numLines;
    }
}

string Seller::getName() {return _name;}

string Seller::getOffice() { return _office; }

float Seller::getSalary() { return _salary; }

string Seller::getUserName() { return _userName; }

string Seller::getPassword() { return _password; }

void Seller::productSale(char *product, int quantity) {
    FILE *arq, *arqProv;
    arq = fopen("../stock.txt", "r");
    arqProv = fopen("../stock2.txt", "w");
    int result;
    int n = 0;
    float price;
    int qtd;
    char x;
    char produto[100];
    int flag=0;
    while (!feof(arq)) {
        result = fscanf(arq, "%s %f %d", produto, &price, &qtd);
        if (result) {
            if (strcmp(produto, product) == 0 && qtd > 0) {
                if(quantity>qtd){
                    cout<<"estoque insulficiente"<<endl;
                }else {
                    cout <<produto << " ---> valor : " << price * quantity << endl;
                    cout << "confirmar compra(S ou N)?" << endl;
                    cin >> x;
                    if (x == 'S') {
                        qtd = qtd - quantity;
                        cout << "successo!" << endl;
                    } else cout<<"compra cancelada com sucesso"<<endl;
                }
            }
            fprintf(arqProv, "%s %.2f %d\n", produto, price, qtd);
        }
        n++;
    }
    fclose(arq);
    fclose(arqProv);
    arq = fopen("../stock.txt", "w");
    arqProv = fopen("../stock2.txt", "r");
    for (int i = 1; i < n; i++) {
        fscanf(arqProv, "%s %f %d", produto, &price, &qtd);
        fprintf(arq, "%s %.2f %d\n", produto, price, qtd);
    }
    fclose(arqProv);
    fclose(arq);
    remove("../stock2.txt");
}

string Seller::getPassword() {return _password;}

Seller::Seller(const string& name, const string& office, float salary, const string& userName, const string& password) {
    _name = name;
    _office = office;
    _salary = salary;
    _userName = userName;
    _password = password;
}

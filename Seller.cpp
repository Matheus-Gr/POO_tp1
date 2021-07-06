//
// Created by mathe on 05/07/2021.
//

#include "Seller.h"

void Seller::registerClient(string name, string address, string phone) {
    cout << name << endl << address << endl << phone << endl;
}

void Seller::getClientList() {
    int numLines = 0;
    ifstream in("../clients.txt");
    string unused;
    while (getline(in, unused)){
        ++numLines;
    }
}
string Seller::getName() {return _name;}

string Seller::getOffice() {return _office;}

float Seller::getSalary() {return _salary;}

string Seller::getUserName() {return _userName;}

string Seller::getPassword() {return _password;}

Seller::Seller(const string& name, const string& office, float salary, const string& userName, const string& password) {
    _name = name;
    _office = office;
    _salary = salary;
    _userName = userName;
    _password = password;
}


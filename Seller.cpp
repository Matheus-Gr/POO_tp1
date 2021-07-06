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

void Seller::setName(string name) {_name = name;}

void Seller::setOffice(string office) {_office = office;}

void Seller::setSalary(float salary) {_salary = salary;}

void Seller::setUserName(string userName) {_userName = userName;}

void Seller::setPassword(string password) {_password = password;}

string Seller::getName() {return _name;}

string Seller::getOffice() {return _office;}

float Seller::getSalary() {return _salary;}

string Seller::getUserName() {return _userName;}

string Seller::getPassword() {return _password;}
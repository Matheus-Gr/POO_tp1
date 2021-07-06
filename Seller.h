//
// Created by mathe on 05/07/2021.
//

#ifndef TP_I_SELLER_H
#define TP_I_SELLER_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Seller
{
private:
    string _name;
    string _office;
    float _salary;
    string _userName;
    string _password;

public:
    Seller(const string& name, const string& office, float salary, const string& userName, const string& password);

    void setName(string name);
    void setOffice(string office);
    void setSalary(float salary);
    void setUserName(string userName);
    void setPassword(string password);

    string getName();
    string getOffice();
    float getSalary();
    string getUserName();
    string getPassword();

    void registerClient(string name, string address, string phone);
    void getClientList();
    void removerProduto(string nomeProduto, int quantidade = 1);
    void getEstoque();
};

#endif //TP_I_SELLER_H

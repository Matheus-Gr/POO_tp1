//
// Created by mathe on 05/07/2021.
//

#ifndef TP_I_EMPLOYEE_H
#define TP_I_EMPLOYEE_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "utils.h"

using namespace std;

class Employee
{
private:
    string _name;
    string _office;
    float _salary;
    string _userName;
    string _password;

public:
    Employee(const string& name, const string& office, float salary, const string& userName, const string& password);

    void set_office(const string& office);

    void set_salary(float salary);

    void set_userName(const string& userName);

    void set_password(const string& password);

    void set_name(const string& name);

    string get_name();

    // Responsavel para cadastrar um cliente
    // name: Nome do cliente
    // address: Endereço do cliente
    // phone: Telefone de contato do cliente
    void register_client(const string& name, const string& address, const string& phone);

    // Responsavel por realizar as vendas de produtos
    // product: Nome do produto que sera vendido
    // quantity: Quantidade que será vendida
    // client: Parameto opcional, nome do cliente para qual será realizado a venda
    void product_sale(char * product, int quantity, const string& client = "n/a");

    // Responsavel por realizar as vendas de serviço
    // service: Nome do serviço que será vendido
    // price: Valor do serviço
    // client: Parameto opcional, nome do cliente para qual será realizado a venda
    void service_sale(const string& service, float price, const string& client = "n/a");

    // Retorna lista de cliente
    void get_client_list();

    // Retorna a lista de serviços
    void get_service_list();

    // Retorna o estoque
    void get_stock_list();

    // Responsavel por registrar o relatorio do procedimento feito pelo veterinario
    // petName: Nome do animal no qual foi realizado procedimento
    // report: Comentário do que foi realizado no PET
    void vet_service_resume(const string& petName, const string& report);
};

#endif //TP_I_EMPLOYEE_H

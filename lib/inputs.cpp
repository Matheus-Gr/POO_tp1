//
// Created by mathe on 12/07/2021.
//

#include "inputs.h"

void register_client_inputs(Employee employee) {
    string clientName, address, phone;
    cout << "Nome do cliente:";
    cin >> clientName;
    cout << "Endereco:";
    cin.ignore();
    getline(cin, address, '\n');
    cout << "Telefone:";
    cin >> phone;

    employee.register_client(clientName, address, phone);
}

void selling_inputs(Employee employee) {
    int option;
    cout << "1) Venda de servico\n"
            "2) Venda de produto\n"
            "Chosse:";
    cin >> option;

    string clientName, service;
    char product[255];
    float price;
    int quantity = 1;


    if (option == 1) {
        cout << "Servico:";
        cin >> service;
        cout << "Preco:";
        cin >> price;

        cout << "Selecionar cliente\n"
                "1) Sim\n"
                "2) Nao\n"
                "choose:";
        cin >> option;

        if (option == 1) {
            employee.get_client_list();
            cout << "Cliente:";
            cin >> clientName;

            employee.service_sale(service, price, clientName);
        } else {
            employee.service_sale(service, price);
        }
    } else {
        employee.get_stock_list();
        cout << "Produto:";
        cin >> product;
        cout << "Quantidade:";
        cin >> quantity;

        cout << "Selecionar cliente\n"
                "1) Sim\n"
                "2) Nao\n"
                "choose:";
        cin >> option;

        if (option == 1) {
            employee.get_client_list();
            cout << "Cliente:";
            cin >> clientName;

            employee.product_sale(product, quantity, clientName);
        } else {
            employee.product_sale(product, quantity);
        }

    }
}

void vet_resume_inputs(Employee employee) {
    string petName, report;
    cout << "Nome do pet:";
    cin >> petName;
    cout << "Relatorio:";
    cin.ignore();
    getline(cin, report, '\n');

    employee.vet_service_resume(petName, report);
}

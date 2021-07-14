#include <iostream>
#include <string>
#include <cstdio>
#include "lib/Admin.h"
#include "lib/inputs.h"

using namespace std;

int main() {
    int option;

    char fuser[255], fpassword[255], foffice[255], fname[255];
    float cash, fsalary = 0;

    strcpy(fuser, "admin");
    strcpy(fpassword, "admin");
    strcpy(foffice, "admin");
    strcpy(fname, "Inacio");

    FILE *adminFile;
    adminFile = fopen(ADMIN_PATH, "r");
    fscanf(adminFile, "%f", &cash);
    fclose(adminFile);

    Admin admin(fname, foffice, fsalary, fuser, fpassword, cash);

    while (true) {
        cout << "========================\n"
                "Sistema veterinario 171\n"
                "1) Login\n"
                "2) Sair\n"
                "Choose:";
        cin >> option;

        if (option == 1) {
            string user, password;
            cout << "User:";
            cin >> user;
            cout << "Password:";
            cin >> password;

            FILE *accountsFile;
            accountsFile = fopen(ACCOUNTS_PATH, "r");
            while (!feof(accountsFile)) {
                fscanf(accountsFile, "%s %s %s %s %f", fuser, fpassword, foffice, fname, &fsalary);
                if (user == fuser and password == fpassword) {
                    if ((string) foffice == "seller") {
                        Employee employee(fname, foffice, fsalary, fuser, fpassword);
                        while (true) {
                            cout << "========================\n"
                                    "1) Cadastrar clientes\n"
                                    "2) Realizar venda\n"
                                    "3) Sair\n"
                                    "Choose:";
                            cin >> option;

                            if (option == 1) {
                                register_client_inputs(employee);
                            } else if (option == 2) {
                                selling_inputs(employee);
                                admin.update_cash();
                            } else if (option == 3) {
                                break;
                            }
                        }
                    } else if ((string) foffice == "vet") {
                        while (true) {
                            Employee employee(fname, foffice, fsalary, fuser, fpassword);
                            cout << "========================\n"
                                    "1) Cadastrar clientes\n"
                                    "2) Ordem de servicos\n"
                                    "3) Relatorio de servico veterinaro\n"
                                    "4) Sair\n"
                                    "Choose:";
                            cin >> option;

                            if (option == 1) {
                                register_client_inputs(employee);
                            } else if (option == 2) {
                                employee.get_service_list();
                                admin.update_cash();
                            } else if (option == 3) {
                                vet_resume_inputs(employee);
                            } else {
                                break;
                            }
                        }
                    }
                } else if (user == "admin" and password == "admin") {
                    while (true) {
                        cout << "========================\n"
                                "Saldo: " << admin.get_cash() << endl;
                        cout << "========================\n"
                                "1) Cadastrar clientes\n"
                                "2) Vender\n"
                                "3) Ordem de servicos\n"
                                "4) Cadastrar funcionario\n"
                                "5) Cadastrar produto\n"
                                "6) Pagar contas\n"
                                "7) Relatorio geral\n"
                                "8) Sair\n"
                                "Choose:";
                        cin >> option;

                        string clientName, address, phone, service, petName, report, name, office, username, valDate, comment;
                        char product[255];
                        float price, salary, buyPrice, salePrice;
                        int quantity = 1;

                        if (option == 1) {
                            cout << "Nome do cliente:";
                            cin >> clientName;
                            cout << "Endereco:";
                            cin.ignore();
                            getline(cin, address, '\n');
                            cout << "Telefone:";
                            cin >> phone;

                            admin.register_client(clientName, address, phone);
                        } else if (option == 2) {
                            cout << "1) Venda de servico\n"
                                    "2) Venda de produto\n"
                                    "Chosse:";
                            fflush(stdin);
                            cin >> option;

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
                                    admin.get_client_list();
                                    cout << "Cliente:";
                                    cin >> clientName;

                                    admin.service_sale(service, price, clientName);
                                } else {
                                    admin.service_sale(service, price);
                                }

                            } else {
                                admin.get_stock_list();
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
                                    admin.get_client_list();
                                    cout << "Cliente:";
                                    cin >> clientName;

                                    admin.product_sale(product, quantity, clientName);
                                } else {
                                    admin.product_sale(product, quantity);
                                }
                            }
                        } else if (option == 3) {
                            admin.get_service_list();
                        } else if (option == 4) {
                            cout << "Nome:";
                            cin >> name;
                            cout << "Cargo:";
                            cin >> office;
                            cout << "Salario:";
                            cin >> salary;
                            cout << "Username:";
                            cin >> username;
                            cout << "Senha:";
                            cin >> password;


                            admin.register_employee(name, office, salary, username, password);
                        } else if (option == 5) {
                            cout << "Product name:";
                            cin >> product;
                            cout << "Valor de compra:";
                            cin >> buyPrice;
                            cout << "Valor de venda:";
                            cin >> salePrice;
                            cout << "Quantidade:";
                            cin >> quantity;

                            admin.register_product(product, buyPrice, salePrice, quantity);
                        } else if (option == 6) {
                            cout << "Data de validade (dd/mm/yyyy):";
                            cin >> valDate;
                            cout << "Valor da conta:";
                            cin >> price;
                            cout << "Descricao:";
                            cin >> comment;
                            admin.billPayment(valDate, price, comment);
                        } else if (option == 7) {
                            char line[255];
                            FILE *resumeFile;
                            resumeFile = fopen(RESUME_PATH, "r");

                            cout << "----------------------\n";
                            while (fgets(line, 255, resumeFile)) {
                                cout << line << endl;
                            }
                            cout << "----------------------\n";

                        } else if (option == 8){
                            break;
                        }
                        admin.update_cash();
                    }
                }
            }
            fclose(accountsFile);
        } else {
            exit(0);
        }
    }

    return 0;
}




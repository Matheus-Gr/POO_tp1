//
// Created by mathe on 05/07/2021.
//

#include <cstring>
#include "Employee.h"

Employee::Employee(const string &name, const string &office, float salary, const string &userName,
                   const string &password) {
    set_name(name);
    set_office(office);
    set_salary(salary);
    set_userName(userName);
    set_password(password);
}

void Employee::register_client(const string &name, const string &address, const string &phone) {
    FILE *file;
    file = fopen(CLIENTS_PATH, "r+");
    fseek(file, 0, SEEK_END);

    stringstream ss;
    ss << name << " " << address << " " << phone;
    string report = ss.str();
    fputs(report.c_str(), file);
    fputs("\n", file);

    fclose(file);
}

void Employee::product_sale(char *product, int quantity, const string &client) {
    FILE *stockFile, *tempFile;
    stockFile = fopen(STOCK_PATH, "r");
    tempFile = fopen(TEMP_PATH, "w");

    int n = 0;
    float price, totalValue;
    int qtd;
    char x;
    char produto[100];
    while (fscanf(stockFile, "%s %f %d", produto, &price, &qtd) == 3) {
        if (strcmp(produto, product) == 0 && qtd > 0) {
            if (quantity > qtd) {
                cout << "estoque insulficiente" << endl;
            } else {
                cout << produto << " ---> valor : " << price * quantity << endl;
                cout << "confirmar compra(S ou N)?" << endl;
                cin >> x;

                if (x == 'S' or x == 's') {
                    qtd = qtd - quantity;

                    FILE *resumeFile;
                    resumeFile = fopen(RESUME_PATH, "r+");
                    fseek(resumeFile, 0, SEEK_END);

                    totalValue = price * quantity;

                    stringstream ss;
                    ss << get_name() << " vendeu " << product << " (" << quantity << "x) por: RS"
                       << totalValue << ", para " << client << ".";
                    string report = ss.str();
                    fputs(report.c_str(), resumeFile);
                    fputs("\n", resumeFile);

                    fclose(resumeFile);
                    cout << "successo!" << endl;
                } else cout << "compra cancelada com sucesso!" << endl;
            }
        }
        fprintf(tempFile, "%s %.2f %d\n", produto, price, qtd);
        n++;
    }
    fclose(stockFile);
    fclose(tempFile);
    remove(STOCK_PATH);
    rename(TEMP_PATH, STOCK_PATH);
    add_balance(totalValue);
}

void Employee::service_sale(const string &service, float price, const string &client) {
    FILE *servicesFile, *resumeFile;
    servicesFile = fopen(SERVICES_PATH, "r+");
    resumeFile = fopen(RESUME_PATH, "r+");

    fseek(servicesFile, 0, SEEK_END);
    fseek(resumeFile, 0, SEEK_END);

    stringstream ss, ss2;
    ss << service << " " << client << " " << price;
    string resume = ss.str();
    fputs(resume.c_str(), servicesFile);
    fputs("\n", servicesFile);

    fclose(servicesFile);

    ss2 << get_name() << " vendeu " << service << " para cliente " << client << " no valor de RS" << price << ".";
    string report = ss2.str();
    fputs(report.c_str(), resumeFile);
    fputs("\n", resumeFile);

    fclose(resumeFile);
    add_balance(price);
}

void Employee::get_client_list() {
    FILE *clientsFile;
    clientsFile = fopen(CLIENTS_PATH, "r");

    char ch, name[255];
    cout << "----------------------\nClientes:\n";

    while (fscanf(clientsFile, "%s", name) == 1) {
        while ((ch = fgetc(clientsFile)) != EOF) {
            if (ch == '\n') break;
        }
        cout << name << endl;
    }
    cout << "----------------------\n";

    fclose(clientsFile);
}

void Employee::get_service_list() {
    FILE *servicesFile;
    servicesFile = fopen(SERVICES_PATH, "r");

    char service[255], client[255];
    float price;

    cout << "----------------------\n";
    while (fscanf(servicesFile, "%s %s %f", service, client, &price) == 3) {
        cout << service << " para " << client << ". Valor: " << price << " reais." << endl << endl;
    }
    cout << "----------------------\n";
    fclose(servicesFile);
}

void Employee::vet_service_resume(const string &petName, const string &report) {
    FILE *vetResumeFile;
    FILE *resumeFile;
    vetResumeFile = fopen(VET_RESUME_PATH, "r+");
    resumeFile = fopen(RESUME_PATH, "r+");
    fseek(vetResumeFile, 0, SEEK_END);
    fseek(resumeFile, 0, SEEK_END);

    stringstream ss;
    ss << petName << ": " << report;
    string resume = ss.str();
    fputs(resume.c_str(), vetResumeFile);
    fputs("\n", vetResumeFile);

    stringstream ss2;
    ss2 << get_name() << " atendeu o pet " << petName << " e realizou o seguinte procedimento: " << report;
    string resume2 = ss2.str();
    fputs(resume2.c_str(), resumeFile);
    fputs("\n", resumeFile);

    fclose(vetResumeFile);
    fclose(resumeFile);
}

void Employee::set_name(const string &name) {
    _name = name;
}

void Employee::set_office(const string &office) {
    _office = office;
}

void Employee::set_salary(float salary) {
    _salary = salary;
}

void Employee::set_userName(const string &userName) {
    _userName = userName;
}

void Employee::set_password(const string &password) {
    _password = password;
}

string Employee::get_name() {
    return _name;
}

void Employee::get_stock_list() {
    FILE *stockFile;
    stockFile = fopen(STOCK_PATH, "r");

    char productName[255];
    float price;
    int quantity;
    cout << "----------------------\nEstoque:\n";

    while (fscanf(stockFile, "%s %f %d", productName, &price, &quantity) == 3) {
        cout << productName << " RS" << price << " " << quantity << "x\n";
    }
    cout << "----------------------\n";
    fclose(stockFile);
}




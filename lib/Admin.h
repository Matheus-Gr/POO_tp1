//
// Created by otavio on 05/07/2021.
//

#ifndef TP_I_ADMIN_H
#define TP_I_ADMIN_H

#define STRING(num) #num

#include <iostream>
#include <string>
#include <cstdlib>
#include "Employee.h"
#include <cstring>
#include <sstream>
#include "utils.h"

using namespace std;

class Admin : public Employee {
private:
    float _cash;
public:
    Admin(const string &name, const string &office, float salary, const string &userName,
          const string &password, float cash);

    void set_cash(float cash);

    float get_cash();

    // Responsavel por carregar o saldo salvo em disco
    void update_cash();

    // Responsavel por descontar valor do saldo
    // value: Valor que sera descontado do saldo
    void remove_cash(float value);

    // Responsavel cadastra um empregado
    // name: Nome do empregado
    // office: Qual o cargo do empregado, valores validos são "seller" para vendedores, e "vet" para veterinarios
    // salary: Salario do empregado
    // userName: Username para ser usado no login
    // password: senha para ser usado no login
    void register_employee(const string &name, const string &office, float salary, const string &userName,
                           const string &password);

    // Responsavel para realizar as compras do estoque
    // productName: Nome do produto usado para indentificação
    // buyPrice: Preço no qual foi pago para comprar os produtos para o estoque
    // salePrice: Preço no qual os produtos sera vendido
    // quantity: Quantidade de produtos comprados
    void register_product(const string &productName, float buyPrice, float salePrice, int quantity);

    // Responsavel por realizar os pagametos de contas do Pet Shop
    // valDate: Data de validade da conta, passada no seguinte formato dd/mm/yyyy
    // price: Valor da conta a ser paga
    // description: Comentario opcional para o pagamento
    void billPayment(const string &valDate, float price, const string &description);
};

#endif //TP_I_ADMIN_H

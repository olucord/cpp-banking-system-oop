#include "ContaPoupanca.hpp"
#include <string>
#include <iostream>

ContaPoupanca::ContaPoupanca(std::string numero, Titular titular) : 
Conta(numero, titular)
{
	std::cout << "Construtor de conta poupança!" << std::endl;

}

ContaPoupanca::~ContaPoupanca()
{
	std::cout << "Destrutor de Conta poupança!" << std::endl;
}

float ContaPoupanca::taxaDeSaque() const {
	return 0.03;
}
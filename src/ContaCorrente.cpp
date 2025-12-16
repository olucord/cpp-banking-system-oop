#include <iostream>
#include "ContaCorrente.hpp"

ContaCorrente::ContaCorrente(std::string numero, Titular titular) : 
Conta(numero, titular)
{
	std::cout << "Construtor de conta corrente!" << std::endl;
}

ContaCorrente::~ContaCorrente()
{
	std::cout << "Destrutor de Conta corrente!" << std::endl;
}

float ContaCorrente::taxaDeSaque() const {
	return 0.05;
}

void ContaCorrente::transferePara(Conta& conta_destino, float valor) {
	std::pair<resultadoSaque, double> resultado = sacar(valor);
	
	if (resultado.first == Sucesso) {
		conta_destino.depositar(valor);
	}
	else {
		std::cout << "Transferência não realizada, pois houve falha no saque!" << std::endl;
	}
	
}
	
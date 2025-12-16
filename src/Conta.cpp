#include <iostream>
#include "Conta.hpp"
#include "Titular.hpp"

// Os atributos de classe são definidos fora do escopo do construtor, que inicializa os atributos das instâncias, mas eles podem ser modificados dentro do esopo do construtor ou em qualquer outro método da classe, visto que eles são globais
int Conta::numeroDeContasCriadas = 0;
	
// O nome do método do construtor é o próprio nome da classe
Conta::Conta(std::string numero, Titular titular) :
	numero(numero),
	titular(titular),
	saldo(0)
{
	// Como o compilador vai achar essa variável associada a classe, não precisamos definir explicitamente que nesse caso se trata de um atributo de classe
	numeroDeContasCriadas++;
	std::cout << "Construtor de conta base!" << std::endl;
};

// Sempre que uma instância for destruída, ele vai executar isso
Conta::~Conta() {
	numeroDeContasCriadas--;
	std::cout << "Destrutor de conta base!" << std::endl;
}

std::pair<Conta::resultadoSaque, double> Conta::sacar(double valorASacar) {
	
//	float taxa; // Seria melhor usar float do que double, caso não precisassemos de muitos recursos, pois assim iríamos economizar memória, porém como é um programa simples de aprendizado, alguns pontos estão com double
	
//	if (tipoDeConta == 1) {
//		taxa = 0.05;
//	}
//	else if (tipoDeConta == 2) {
//		taxa = 0.03;
//	}
//	taxa = tipoDeConta == 1 ? 0.05 : 0.03;
//	
	double tarifaDeSaque = valorASacar * taxaDeSaque(); // imposto sobre meu saque
	double valorDeSaque = valorASacar + tarifaDeSaque; // total deduziado da minha conta
	
	if (valorDeSaque > saldo) {
		std::cout << "\nSaldo insuficiente!\n";
		return std::make_pair(SaldoInsuficiente, saldo);
	}
	else if (valorASacar < 0) {
		std::cout << "\nNão é possível sacar um valor negativo!\n";
	;	return std::make_pair(ValorNegativo, saldo);
	}
	else if (valorASacar == 0) {
		std::cout << "\nNão é possível sacar um valor nulo!\n";
	;	return std::make_pair(ValorNulo, saldo);
	}
	else {
		std::cout << "\nVocê sacou R$ " << valorASacar << " da sua conta!\n";
		std::cout << "Valor de tarifa paga pelo saque R$ " << tarifaDeSaque << "!\n\n";
		saldo -= valorDeSaque;
		return std::make_pair(Sucesso, saldo);
	}
	
}

void Conta::depositar(double valorADepositar) {
	if (valorADepositar < 0) {
		std::cout << "\nNão é possível depositar um valor negativo!\n";
		return;
	}
	else if (valorADepositar == 0) {
		std::cout << "\nNão é possível depositar um valor nulo!\n";
		return;
	}
	else {
		std::cout << "\nVocê depositou R$ " << valorADepositar << " na conta " << titular.nome << "!\n";
		saldo += valorADepositar;
		return;
	}
	
}

void Conta::recuperarNumero() {
	std::cout << "O numero é " << numero << std::endl;
}

double Conta::recuperarSaldo() const {
//	std::cout << "O saldo de " << titular.nome << " é de R$ " << saldo << "!" << std::endl;
	return saldo;
}

void Conta::atribuirNumero(std::string novoNumero) {
	numero = novoNumero;
}

void Conta::recuperarNumeroDeContasCriadas() {
	std::cout << "O número de contas criadas foi de " << Conta::numeroDeContasCriadas << std::endl;
}
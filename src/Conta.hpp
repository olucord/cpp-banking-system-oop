#pragma once
#include <string>
#include <ostream>
#include <utility>
#include "Titular.hpp"

class Conta {
	
private:
	// Atributo pertence a classe Conta
	static int numeroDeContasCriadas;
public:
	// Método pertence a classe Conta
	static void recuperarNumeroDeContasCriadas();
	
	// Atributo pertence a objeto da classe Conta
private:
	std::string numero;
	Titular titular;
public:
	double saldo;
	
	// Métodos pertence a objeto da classe Conta 
public:
	enum resultadoSaque {
		Sucesso, ValorNegativo, ValorNulo, SaldoInsuficiente
	};
	
	Conta(std::string numero, Titular titular);
	virtual ~Conta();
	std::pair<resultadoSaque, double> sacar(double valorASacar);
	void depositar(double valorADepositar);
	// Getters e Setters
	void recuperarNumero();
	double recuperarSaldo() const;
	void atribuirNumero(std::string numero);
	virtual float taxaDeSaque() const = 0;
	friend std::ostream& operator<<(std::ostream& cout, const Conta& conta);
};
#pragma once
#include "Pessoa.hpp"
#include "DiaDaSemana.hpp"


class Funcionario : public Pessoa
{
private:
	float salario;
	DiaDaSemana diaDoPagamento;
public:
	Funcionario(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento);
	virtual float bonificacao() const = 0; // puramente virtual, obrigatório
	float recuperaSalario() const;
};



#pragma once
#include "Funcionario.hpp"
#include "DiaDaSemana.hpp"

class Caixa : public Funcionario
{
public:
	Caixa(Cpf cpfTitular, std::string nomeTitular, float salario, DiaDaSemana diaDoPagamento);
	float bonificacao() const;
};


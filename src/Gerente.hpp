#pragma once
#include "Funcionario.hpp"
#include "Autenticavel.hpp"
#include "DiaDaSemana.hpp"


class Gerente : public Funcionario, public Autenticavel
{
public:
	Gerente(Cpf cpfTitular, std::string nomeTitular, float salario, DiaDaSemana diaDoPagamento, std::string senha);
	float bonificacao() const;
};


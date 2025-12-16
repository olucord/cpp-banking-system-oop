#include "Caixa.hpp"
#include "DiaDaSemana.hpp"

Caixa::Caixa(Cpf cpfTitular, std::string nomeTitular, float salario, DiaDaSemana diaDoPagamento) :
Funcionario(cpfTitular, nomeTitular, salario, diaDoPagamento)
{
}

float Caixa::bonificacao() const {
	return recuperaSalario() * 0.1;
}


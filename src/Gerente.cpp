#include "Gerente.hpp"
#include "DiaDaSemana.hpp"

Gerente::Gerente(Cpf cpfTitular, std::string nomeTitular, float salario, DiaDaSemana diaDoPagamento, std::string senha) :
Funcionario(cpfTitular, nomeTitular, salario, diaDoPagamento), Autenticavel(senha)
{
}

float Gerente::bonificacao() const {
	return recuperaSalario() * 0.5;
}


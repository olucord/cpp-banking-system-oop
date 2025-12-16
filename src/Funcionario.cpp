#include "Funcionario.hpp"

Funcionario::Funcionario(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento) :
Pessoa(cpf, nome), salario(salario), 
diaDoPagamento(diaDoPagamento)
{
}

float Funcionario::recuperaSalario() const {
	return salario;
}




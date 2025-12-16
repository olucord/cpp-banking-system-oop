#include <iostream>
#include "Pessoa.hpp"
#include "Cpf.hpp"

Pessoa::Pessoa(Cpf cpf, std::string nome) : 
cpf(cpf), nome(nome)
{
//	std::cout << "Ativando construtor de Pessoa" << std::endl;
}

void Pessoa::checarTamanhoDoNome() {
	if (nome.size() < 5) {
		std::cout << "Nome muito curto, precisa pelo menos 5 caracteres!";
		exit(1);
	}
}

std::string Pessoa::recuperaNome() const {
	return nome;
}

void Pessoa::funcaoDaClassePessoa() {
	std::cout << "\n\nEssa função é da classe Pessoa!\n\n" << std::endl;
	}

#pragma once
#include <string>
#include "Cpf.hpp"

class Pessoa
{
private:
	Cpf cpf;
public:
	std::string nome;
	Pessoa(Cpf cpf, std::string nome);
	std::string recuperaNome() const;
private:
	void checarTamanhoDoNome();
public:
	void funcaoDaClassePessoa();
};

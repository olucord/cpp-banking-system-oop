#pragma once
#include "Pessoa.hpp"
#include "Autenticavel.hpp"


class Titular : public	Pessoa, public Autenticavel // O método funcaoDaClassePessoa é público
{
public:
	Titular(Cpf cpf, std::string nome, std::string senha);
};


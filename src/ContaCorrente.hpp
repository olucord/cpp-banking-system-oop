#pragma once
#include <string>
#include "Conta.hpp"

class ContaCorrente final : public Conta
{
public:
	ContaCorrente(std::string numero, Titular titular);
	~ContaCorrente();
	float taxaDeSaque() const override;
	void transferePara(Conta& conta_destino, float valor);
};



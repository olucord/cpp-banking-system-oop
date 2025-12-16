#include "Conta.hpp"

class ContaPoupanca final :  public Conta
{
public:
	ContaPoupanca(std::string numero, Titular titular);
	~ContaPoupanca();
	float taxaDeSaque() const override;
};


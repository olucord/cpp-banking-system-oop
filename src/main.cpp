#include <iostream>
#include <string>
#include "Gerente.hpp"
#include "Caixa.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "Conta.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"
using namespace std;

// Para testar o contador de contas "existentes"
void criandoEApagandoUmaContaTemporaria() {
		Cpf cpf("987.654.321-01");
		Titular titular(cpf, "Joaquim", "Jo123");
		ContaPoupanca conta("45621", titular);
}

void realizaSaque(Conta& conta) {
	std::pair<Conta::resultadoSaque, float> resultado = conta.sacar(200);
	if (resultado.first == Conta::Sucesso) {
	cout << "O novo saldo da conta " << resultado.second << endl;
		}
}

void fazLogin(Autenticavel& usuario, string senha) {
	if (usuario.autentica(senha)) {
		cout << "Login realizado com sucesso! " << endl;
	}
	else {
		cout << "Senha inválida!" << endl;
	}
}

// Como a implementação de enum agora foi por meio de "enum class", podemos usar tranquilamente aquelas constantes no escopo global, o que não era possível com apenas o "enum", já que ele limitava nossas variáveis
void Domingo() {
	cout << "Criando um método com o nome \"Domingo\", mesmo ele sendo uma constante de um enum!" << endl;
}

ostream& operator<<(ostream& cout, const Conta& conta) {
	// Criei uma variável do tipo Pessoa (a mais genérica – classe base) e pedi um objeto derivado, um titular. Passei como valor um objeto do tipo Conta, que contém um objeto do tipo Titular dentro dele. Então eu permiti o acesso ao objeto Titular (dentro do objeto Conta), por meio do objeto Conta
	Pessoa titular = conta.titular;
	// Agora posso acessar os membros do meu objeto tipo Titular, mas vemos que o nosso objeto inicial do tipo Conta, ainda continua disponível dentro da função, já que chamamos classes mais genéricas (classes base)
	cout << "\nA conta pertence a " << titular.recuperaNome() << "!\n";
	cout << "O saldo dessa conta é de R$ " << conta.recuperarSaldo() << "!\n\n";
	// Agora quando chamarmos "cout << <objeto do tipo Conta>;" isso, vai trazer um retorno personalizado do objeto que antes não era possível, já que o "cout" não conhecia esse tipo ainda 
	return cout;
}

int main() {
	
	std::setlocale(LC_ALL, ".UTF8"); // Para configurar o UTF-8 na saída do terminal
	
	// Primeira conta
	Cpf cpf("987.654.321-01");
	Titular titular(cpf, "Lucas", "MinhaSenha");
	ContaCorrente umaConta("12345", titular);
	
	umaConta.depositar(500);
//	umaConta.sacar(180);
	umaConta.recuperarSaldo();
	
	// Segunda conta
	// Passando vários objetos dentro do mesmo comando, isso é mais otimizado do que criar várias variáveis
	ContaPoupanca outraConta("54321", Titular(string("987.654.321-01"), "Ana", "123546"));
	outraConta.recuperarSaldo();
	
	umaConta.transferePara(outraConta, 250);
	umaConta.recuperarSaldo();
	outraConta.recuperarSaldo();
	
	criandoEApagandoUmaContaTemporaria();
	Conta::recuperarNumeroDeContasCriadas();
	
	Titular outroTitular(Cpf("12313213"), "454545", "MinhaSenha");
	outroTitular.funcaoDaClassePessoa(); // Acessando método de classe superior
	
	// Note que agora ao tentar passar a constante do enum (dia da semana) também teremos que passar a classe ao qual o enum foi alocado
	Gerente gerente(Cpf("123.456.789-12"), "Marcos", 5800, DiaDaSemana::Quarta, "MinhaSenha");
	cout << "O gerente ganhou uma bonificação de " << gerente.bonificacao() << ", totalizando " << 5800 + gerente.bonificacao() << endl;
	
	Caixa caixa(Cpf("123.456.789-12"), "Ana letícia", 1812, DiaDaSemana::Segunda);
	cout << "O caixa ganhou uma bonificação de " << caixa.bonificacao() << ", totalizando " << 1812 + caixa.bonificacao() << endl;
	
	fazLogin(gerente, "Senhanova123!"); // passando senha errada para ver a mensagem
	
	Domingo();
	
	cout << umaConta;
	
	umaConta.transferePara(outraConta, 1000);	

}

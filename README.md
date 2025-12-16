# 🏦 C++ Banking System - OOP
Sistema bancário completo desenvolvido em C++ aplicando conceitos avançados de Programação Orientada a Objetos. Projeto educacional que simula operações bancárias reais com hierarquia de classes, autenticação e sistema de bonificação para funcionários.

## ✨ Funcionalidades

### Operações Bancárias

- ✅ Criação de contas (Corrente e Poupança)
- ✅ Depósitos com validação de valores
- ✅ Saques com taxas diferenciadas por tipo de conta
- ✅ Transferências entre contas
- ✅ Consulta de saldo e número de contas criadas

### Sistema de Autenticação

- ✅ Autenticação para Titulares e Gerentes
- ✅ Validação de senha para operações sensíveis
- ✅ Sistema seguro usando herança múltipla

### Hierarquia de Funcionários

- ✅ Gerentes com bonificação de 50% do salário
- ✅ Caixas com bonificação de 10% do salário
- ✅ Sistema flexível de dias de pagamento

### Validações e Segurança

- ✅ Validação de CPF
- ✅ Validação de nome (mínimo 5 caracteres)
- ✅ Verificação de saldo antes de saques
- ✅ Proteção contra valores negativos/nulos

## 🏗️ Conceitos de OOP Aplicados

### 1. Herança e Polimorfismo

#### Hierarquia de Contas

```
Conta (classe abstrata)
├── ContaCorrente (taxa de saque: 5%)
└── ContaPoupanca (taxa de saque: 3%)
```

O método `taxaDeSaque()` é virtual e implementado de forma diferente em cada tipo de conta, demonstrando **polimorfismo**.

#### Hierarquia de Pessoas

```
Pessoa
├── Titular
└── Funcionario
    ├── Gerente (bonificação: 50%)
    └── Caixa (bonificação: 10%)
```

### 2. Herança Múltipla

Classes que herdam de múltiplas bases:

- **Titular**: herda de `Pessoa` + `Autenticavel`
- **Gerente**: herda de `Funcionario` + `Autenticavel`

Isso permite que titulares e gerentes tenham capacidade de autenticação sem duplicar código.

### 3. Encapsulamento

- Atributos privados (`saldo`, `senha`, `cpf`)
- Acesso controlado via métodos públicos
- Validações em setters para garantir integridade dos dados
- Métodos `const` para operações de leitura

### 4. Abstração

- Classe `Conta` como base abstrata
- Método virtual puro `taxaDeSaque()`
- Interface `Autenticavel` para autenticação

### 5. Composição

Objetos compostos demonstrando relacionamentos:

- `Conta` **possui** um `Titular`
- `Titular` **possui** um `Cpf`
- `Funcionario` **possui** um `Cpf` e `DiaDaSemana`

### 6. Recursos Avançados

- **Sobrecarga de operadores**: `operator<<` para impressão customizada de contas
- **Membros estáticos**: contador global `numeroDeContasCriadas`
- **Enum classes**: `DiaDaSemana` com escopo seguro
- **std::pair**: retorno estruturado de operações com status + valor
- **Construtores em lista de inicialização**: otimização e clareza

## 🚀 Como Compilar e Executar

### Requisitos

- Compilador C++ com suporte a C++11 ou superior (g++, clang++)
- Sistema operacional: Linux, macOS ou Windows (com MinGW)

### Compilação

```bash
# Navegar até o diretório do projeto
cd cpp-banking-system-oop/src

# Compilar todos os arquivos
g++ -std=c++11 *.cpp -o banco

# Executar o programa
./banco
```

## 💡 Exemplos de Uso

O arquivo ".main" comtém algumas aplicações práticas do código, com testes e comentários instrutivos. Você pode depois criar o seu próprio ".main".

### Criando uma Conta e Realizando Operações

```cpp
// Criar CPF e Titular
Cpf cpf("123.456.789-01");
Titular titular(cpf, "João Silva", "senha123");

// Criar conta corrente
ContaCorrente conta("00001-5", titular);

// Realizar depósito
conta.depositar(1000.00);

// Realizar saque (com taxa de 5%)
conta.sacar(200.00);
// Saldo final: 1000 - 200 - 10 (taxa) = 790

// Consultar saldo
cout << "Saldo: R$ " << conta.recuperarSaldo() << endl;
```

### Transferência entre Contas

```cpp
ContaCorrente origem("00001-5", titular1);
ContaPoupanca destino("00002-3", titular2);

origem.depositar(500.00);
origem.transferePara(destino, 200.00);
// Desconta da origem com taxa, credita no destino
```

### Sistema de Funcionários

```cpp
// Criar gerente com autenticação
Gerente gerente(
    Cpf("987.654.321-00"),
    "Maria Santos",
    5000.00,
    DiaDaSemana::Sexta,
    "senhaGerente"
);

// Calcular bonificação (50% do salário)
float bonus = gerente.bonificacao(); // Retorna 2500.00

// Autenticar
if (gerente.autentica("senhaGerente")) {
    cout << "Acesso autorizado!" << endl;
}
```

### Sobrecarga de Operador

```cpp
ContaCorrente conta("00001-5", titular);
conta.depositar(1000.00);

// Usar operador << customizado
cout << conta;
// Output:
// A conta pertence a João Silva!
// O saldo dessa conta é de R$ 1000.00!
```

## 🎯 Possíveis Melhorias Futuras

- [ ] Persistência de dados em arquivo ou banco de dados
- [ ] Interface gráfica (Qt ou similar)
- [ ] Sistema de logs de transações
- [ ] Validação completa de CPF com dígitos verificadores
- [ ] Limite de saque diário
- [ ] Histórico de transações
- [ ] Juros para conta poupança
- [ ] Testes unitários com Google Test

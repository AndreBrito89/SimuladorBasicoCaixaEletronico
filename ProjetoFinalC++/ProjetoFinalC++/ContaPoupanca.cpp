#include "pch.h"
#include "ContaPoupanca.h"

//construtor
ContaPoupanca::ContaPoupanca()
{

}


ContaPoupanca::~ContaPoupanca()
{
}

//get&set

//-nome
void ContaPoupanca::setTitularNome() {
	std::string nome;
	char captura[1024];
	std::cout << "Digite o nome do titular da conta: ";
	std::cin.getline(captura, 1024);
	nome = captura;
	ContaPoupanca::tCP.nome = nome;
}
std::string ContaPoupanca::getTitularNome() {

	return ContaPoupanca::tCP.nome;
}
//-endereco
void ContaPoupanca::setTitularEndereco() {
	std::string endereco;
	char captura[1024];
	std::cout << "Digite o endereco do titular da conta: ";
	std::cin.getline(captura, 1024);
	endereco = captura;
	ContaPoupanca::tCP.endereco = endereco;
}
std::string ContaPoupanca::getTitularEndereco() {
	return ContaPoupanca::tCP.endereco;
}
//-cpf
void ContaPoupanca::setCpf() {
	char captura[15];
	std::string cpF;
	std::cout << "Digite o cpf titular da conta (somente numeros): ";
	std::cin.getline(captura, 15);
	cpF = captura;
	ContaPoupanca::tCP.cpf = cpF;
}
std::string ContaPoupanca::getCpf() {

	return ContaPoupanca::tCP.cpf;
}
//-numCadastro
void ContaPoupanca::setNumCadastro(int numCad) {
	ContaPoupanca::tCP.numCadastro = numCad;
}
int ContaPoupanca::getNumCadastro() {
	return ContaPoupanca::tCP.numCadastro;
}
//-valor
void ContaPoupanca::setValor() {
	std::string valor;
	double v;
	do {
		std::cout << "Digite o valor inicial da conta poupanca: ";
		std::getline(std::cin, valor);
		std::cout << std::endl;

		std::stringstream(valor) >> v;
	} while (v == NULL);

	ContaPoupanca::valor = v;
}
double ContaPoupanca::getValor() {

	return ContaPoupanca::valor;
}
//metodos

//-deposito
void ContaPoupanca::deposito() {
	std::string valorDeposito;
	double valorD;
	do {
		std::cout << "Digite o valor do deposito: ";
		std::getline(std::cin, valorDeposito);
		std::cout << std::endl;

		std::stringstream(valorDeposito) >> valorD;

	} while (valorD == NULL);



	ContaPoupanca::valor += valorD;
}

//-saque
void ContaPoupanca::saque() {
	std::string valorSaque;
	double valorS;
	do {
		std::cout << "Digite o valor do saque: ";
		std::getline(std::cin, valorSaque);
		std::cout << std::endl;

		std::stringstream(valorSaque) >> valorS;

	} while (valorS == NULL);

	//checka se conta fica no negativo
	if ((ContaPoupanca::valor -= valorS) <= 0) {
		ContaPoupanca::valor += valorS;
		std::cout << "Pedido de saque requisitado por " << getTitularNome() << " foi negado. Saldo insuficiente." << std::endl;
		std::cout << "Valor total da conta R$ " << getValor() << std::endl;
		std::cout << "Valor do saque requisitado R$ " << valorS << std::endl;
	}
	else {
		ContaPoupanca::valor -= valorS;
	}
}

//-mostra saldo
void ContaPoupanca::mostrarSaldo() {

	std::cout << "Saldo atual de " << ContaPoupanca::getTitularNome() << " em sua conta poupanca." << std::endl;
	std::cout << "R$ " << ContaPoupanca::getValor() << std::endl;
	std::cout << std::endl;
}
//-calcula Rendimento
void ContaPoupanca::calculaRendimento(int qtdMes) {
	double valorProjecao = 0;


	for (int i = 0; i < qtdMes; i++) {
		valorProjecao += (ContaPoupanca::getValor()*0.006);
	}
	std::cout << std::endl;
	std::cout << "O valor de rendimento desta conta para " << qtdMes << " meses sera R$ " << valorProjecao + ContaPoupanca::getValor() << std::endl;
	std::cout << std::endl;
}
//-mostrar titular
void ContaPoupanca::mostraTitular() {
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "Nome: " << getTitularNome() << std::endl;
	std::cout << "Endereco: " << getTitularEndereco() << std::endl;
	std::cout << "CPF: " << getCpf() << std::endl;
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << std::endl;
}


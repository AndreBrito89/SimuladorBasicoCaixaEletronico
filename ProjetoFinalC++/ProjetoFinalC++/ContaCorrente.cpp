#include "pch.h"
#include "ContaCorrente.h"

//construtor
ContaCorrente::ContaCorrente()
{

}

ContaCorrente::~ContaCorrente()
{
}

//get&set
//-nome
void ContaCorrente::setTitularNome() {
	std::string nome;
	char captura[1024];
	std::cout << "Digite o nome do titular da conta: ";
	std::cin.getline(captura, 1024);
	nome = captura;
	ContaCorrente::tCC.nome = nome;
}
std::string ContaCorrente::getTitularNome() {
	return ContaCorrente::tCC.nome;
}
//-endereco
void ContaCorrente::setTitularEndereco() {
	std::string endereco;
	char captura[1024];
	std::cout << "Digite o endereco do titular da conta: ";
	std::cin.getline(captura, 1024);
	endereco = captura;
	ContaCorrente::tCC.endereco = endereco;
}
std::string ContaCorrente::getTitularEndereco() {
	return ContaCorrente::tCC.endereco;
}
//-cpf
void ContaCorrente::setCpf() {
	char captura[15];
	std::string cpF;
	std::cout << "Digite o cpf titular da conta (somente numeros): ";
	std::cin.getline(captura, 15);
	cpF = captura;
	ContaCorrente::tCC.cpf = cpF;
}
std::string ContaCorrente::getCpf() {

	return ContaCorrente::tCC.cpf;
}
//-numCadastro
void ContaCorrente::setNumCadastro(int numCad) {
	ContaCorrente::tCC.numCadastro = numCad;
}
int ContaCorrente::getNumCadastro() {
	return ContaCorrente::tCC.numCadastro;
}
//-valor
void ContaCorrente::setValor() {
	std::string valor;
	double v;

	do {
		std::cout << "Digite o valor inicial da conta corrente: ";
		std::getline(std::cin, valor);
		std::cout << std::endl;

		std::stringstream(valor) >> v;

	} while (v == NULL);

	ContaCorrente::valor = v;
}
double ContaCorrente::getValor() {

	return ContaCorrente::valor;
}
//metodos

//-deposito
void ContaCorrente::deposito() {
	std::string valorDeposito;
	double valorD;
	do {
		std::cout << "Digite o valor do deposito: ";
		std::getline(std::cin, valorDeposito);
		std::cout << std::endl;

		std::stringstream(valorDeposito) >> valorD;

	} while (valorD == NULL);



	ContaCorrente::valor += valorD;
}

//-saque
void ContaCorrente::saque() {
	std::string valorSaque;
	double valorS;
	do {
		std::cout << "Digite o valor do saque: ";
		std::getline(std::cin, valorSaque);
		std::cout << std::endl;

		std::stringstream(valorSaque) >> valorS;

	} while (valorS == NULL);
	//checka se conta fica no negativo
	if ((ContaCorrente::valor -= valorS) <= 0) {
		ContaCorrente::valor += valorS;
		std::cout << "Pedido de saque requisitado por " << getTitularNome() << " foi negado. Saldo insuficiente." << std::endl;
		std::cout << "Valor total da conta R$ " << getValor() << std::endl;
		std::cout << "Valor do saque requisitado R$ " << valorS << std::endl;
	}
	else {
		ContaCorrente::valor -= valorS;
	}

}

//-mostra saldo
void ContaCorrente::mostrarSaldo() {

	std::cout << "Saldo atual de " << ContaCorrente::getTitularNome() << " em sua conta corrente." << std::endl;
	std::cout << "R$ " << ContaCorrente::getValor() << std::endl;
	std::cout << std::endl;
}
//-calcula Rendimento
void ContaCorrente::calculaRendimento(int qtdMes) {
	double valorProjecao = 0;


	for (int i = 0; i < qtdMes; i++) {
		valorProjecao += (ContaCorrente::getValor()*0.0045);
	}
	std::cout << std::endl;
	std::cout << "O valor de rendimento desta conta para " << qtdMes << " meses sera R$ " << valorProjecao + ContaCorrente::getValor() << std::endl;
	std::cout << std::endl;

}

void ContaCorrente::mostraTitular() {
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "Nome: " << getTitularNome() << std::endl;
	std::cout << "Endereco: " << getTitularEndereco() << std::endl;
	std::cout << "CPF: " << getCpf() << std::endl;
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << std::endl;
}
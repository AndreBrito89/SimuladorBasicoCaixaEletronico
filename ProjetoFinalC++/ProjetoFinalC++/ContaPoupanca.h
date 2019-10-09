#pragma once
#include "Conta.h"
class ContaPoupanca :
	public Conta
{
private:
	//atributo
	double valor;
public:
	//construtor
	ContaPoupanca();
	~ContaPoupanca();
	//get&set
	//-nome
	void setTitularNome();
	std::string getTitularNome();
	//-endereco
	void setTitularEndereco();
	std::string getTitularEndereco();
	//-cpf
	void setCpf();
	std::string getCpf();
	//-numCadastro
	void setNumCadastro(int numCad);
	int getNumCadastro();
	//-valor
	void Conta::setValor();
	double Conta::getValor();
	//metodos
	void Conta::mostraTitular();
	void Conta::deposito();
	void Conta::saque();
	void Conta::calculaRendimento(int qtdMes);
	void Conta::mostrarSaldo();
};
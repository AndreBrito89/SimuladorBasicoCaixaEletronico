#pragma once
#include <string>
class Conta
{
private:
	//atributo
	struct Titular
	{
		std::string nome, endereco, cpf;
		int numCadastro;
		//padrao
		Titular() {

		}
		//completo
		Titular(std::string nomE, std::string enderecO, std::string cpF, int numcadastrO) : nome(nomE), endereco(enderecO), cpf(cpF), numCadastro(numcadastrO) {
			Titular::nome = nomE;
			Titular::endereco = enderecO;
			Titular::cpf = cpF;
			Titular::numCadastro = numcadastrO;
		}

	};

public:
	Titular tCC, tCP;
	//contrutor
	Conta();
	~Conta();
	//get&set
	//-nome
	virtual void setTitularNome() = 0;
	virtual std::string getTitularNome() = 0;
	//-endereco
	virtual void setTitularEndereco() = 0;
	virtual std::string getTitularEndereco() = 0;
	//-cpf
	virtual void setCpf() = 0;
	virtual std::string getCpf() = 0;
	//-numCadastro
	virtual void setNumCadastro(int numCad) = 0;
	virtual int getNumCadastro() = 0;
	//-valor
	virtual void setValor() = 0;
	virtual double getValor() = 0;
	//metodos
	//geral
	virtual void mostraTitular() = 0;
	virtual void deposito() = 0;
	virtual void saque() = 0;
	virtual void mostrarSaldo() = 0;
	//poupanca&corrente
	virtual void calculaRendimento(int qtdMes) = 0;

};


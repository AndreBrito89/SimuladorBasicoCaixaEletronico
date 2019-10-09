#pragma once
//modificar metodos marcados caso queira aumentar array = *
class Menu
{
	int contadorContaCorrente = 0, contadorContaPoupanca = 0;
public:
	//classes
	ContaCorrente c[3];
	ContaPoupanca p[3];

	Menu();
	~Menu();
	//cadastro
	void cadastraCC();
	void cadastraCP();
	//get&set
	//-corrente
	void setContadorCC();
	int getContadorCC();
	//-poupanca
	void setContadorCP();
	int getContadorCP();
	//metodos
	void menuMain(); //*
	//rendimento
	void escolheInvestimentoRendimento();
	//-escolhe quantos meses de rendimento
	int escolheQtdMeses();
	//-escolha posicao array rendimento
	int escolheRendimentoCC(); //*
	int escolheRendimentoCP(); //*
	//saque
	void escolheInvestimentoSaque();
	//-escolha posicao array saque
	int escolheSaqueCC(); //*
	int escolheSaqueCP(); //*
	//deposito
	void escolheInvestimentoDeposito();
	//-escolha posicao array deposito
	int escolheDepositoCC(); //*
	int escolheDepositoCP(); //*
	void escolheInvestimentoSaldo();
	//-escolha posicao array saldo
	int escolheSaldoCC(); //*
	int escolheSaldoCP(); //*
	//mostrar arrays
	void escolheClientes();
	void mostraClientesPoupanca(); //*
	void mostraClientesCorrente(); //*
	//frufrus
	void frufruMenuBox();
	void frufruEscolheTipoInvestimento();
	void frufruNaoHaCadastroContaC();
	void frufruNaoHaCadastroContaP();
	void frufruClienteCadastradoComSucesso(std::string nome);
	void frufruLimiteCadastrosExcedido();
	void frufruErrouMenu();
	void frufruProgramaFinalizado();
	void frufruVisualizarCreditos();

};
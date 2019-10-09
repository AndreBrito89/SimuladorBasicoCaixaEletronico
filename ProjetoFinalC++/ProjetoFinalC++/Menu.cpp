
#include "pch.h"
#include "Menu.h"


Menu::Menu()
{
}
Menu::~Menu()
{
}
//set&get contadores
//-poupanca
void Menu::setContadorCP() {
	Menu::contadorContaPoupanca++;
}
int Menu::getContadorCP() {
	return Menu::contadorContaPoupanca;
}
//-corrente
void Menu::setContadorCC() {
	Menu::contadorContaCorrente++;
}
int Menu::getContadorCC() {
	return Menu::contadorContaCorrente;
}
//metodos
//main
void Menu::menuMain() {

	int menuFlag = 0, escolha;
	std::string escolhA;


	do {

		frufruMenuBox();


		std::getline(std::cin, escolhA);
		std::cout << std::endl;

		std::stringstream(escolhA) >> escolha;

		switch (escolha) {
			//cadastra poupança
		case 1: {
			if (getContadorCP() >= 3)
				frufruLimiteCadastrosExcedido();
			else
				cadastraCP();

		}
				break;
				//cadastra conta corrente
		case 2: {

			if (getContadorCC() >= 3)
				frufruLimiteCadastrosExcedido();
			else
				cadastraCC();
		}
				break;
				//deposito
		case 3:
			Menu::escolheInvestimentoDeposito();
			break;
			//saque
		case 4:
			Menu::escolheInvestimentoSaque();
			break;
			//visualizar saldo
		case 5:
			Menu::escolheInvestimentoSaldo();
			break;
			//visualizar rendimento
		case 6:
			Menu::escolheInvestimentoRendimento();
			break;
			//sair
		case 7: {
			frufruProgramaFinalizado();
			menuFlag = 1;
		}
			break;
			//sair para creditos
		case 8: {
			frufruVisualizarCreditos();
			menuFlag = 1;
		}
			break;
			//checar cadastrados
		case 9: 
			escolheClientes();
			break;
		default:
			frufruErrouMenu();
			break;
		}
	} while (menuFlag == 0);



}

//cadastro
//-corrente
void Menu::cadastraCC() {
	system("CLS");
	c[getContadorCC()].setNumCadastro(getContadorCC());
	c[getContadorCC()].setTitularNome(), c[getContadorCC()].setTitularEndereco(), c[getContadorCC()].setCpf(), c[getContadorCC()].setValor();
	system("CLS");

	frufruClienteCadastradoComSucesso(c[getContadorCC()].getTitularNome());
	setContadorCC();
}
//-poupanca
void Menu::cadastraCP() {
	system("CLS");
	p[getContadorCP()].setNumCadastro(getContadorCP());
	p[getContadorCP()].setTitularNome(), p[getContadorCP()].setTitularEndereco(), p[getContadorCP()].setCpf(), p[getContadorCP()].setValor();

	system("CLS");
	frufruClienteCadastradoComSucesso(p[getContadorCP()].getTitularNome());
	setContadorCP();
}
//escolhe entre poupanca/corrente saque
void Menu::escolheInvestimentoSaque() {
	system("CLS");
	std::string escolha;
	frufruEscolheTipoInvestimento();
	std::getline(std::cin, escolha);
	int escolhaCC, escolhaCP;

	if (escolha == "c" || escolha == "C") {
		escolhaCC = escolheSaqueCC();
		if (escolhaCC == NULL) {
			system("CLS");
			frufruNaoHaCadastroContaC();
		}
		else if (c[escolhaCC].getTitularNome() == "") {
			system("CLS");
			frufruNaoHaCadastroContaC();
		}

		else {
			system("CLS");
			c[escolhaCC].mostraTitular();
			c[escolhaCC].saque();
		}

	}
	if (escolha == "P" || escolha == "p") {
		escolhaCP = escolheSaqueCP();
		if (escolhaCP == NULL) {
			system("CLS");
			frufruNaoHaCadastroContaP();
		}
		else if (p[escolhaCP].getTitularNome() == "") {
			system("CLS");
			frufruNaoHaCadastroContaP();
		}

		else {
			system("CLS");
			p[escolhaCP].mostraTitular();
			p[escolhaCP].saque();
		}

	}

	if (escolha == "V" || escolha == "v") {
		system("CLS");
	}
}
//escolhe quem do array vai sacar
//-cc
int Menu::escolheSaqueCC() {
	std::string pesquisa;
	char pesquisaN[1024];
	std::string pesquisaC;
	char pesquisaCpf[1024];
	std::cout << "Digite o nome de quem gostaria de sacar:";
	std::cin.getline(pesquisaN, 1024);
	std::cout << "Digite o cpf de quem gostaria de sacar:";
	std::cin.getline(pesquisaCpf, 1024);
	pesquisaC = pesquisaCpf;
	pesquisa = pesquisaN;
	for (int i = 0; i < 3; i++) {
		if (c[i].getTitularNome() == pesquisa && c[i].getCpf() == pesquisaC) {
			return c[i].getNumCadastro();
		}
	}

}
//-cp
int Menu::escolheSaqueCP() {
	std::string pesquisa;
	char pesquisaN[1024];
	std::string pesquisaC;
	char pesquisaCpf[1024];
	std::cout << "Digite o nome de quem gostaria de sacar:";
	std::cin.getline(pesquisaN, 1024);
	std::cout << "Digite o cpf de quem gostaria de sacar:";
	std::cin.getline(pesquisaCpf, 1024);
	pesquisaC = pesquisaCpf;
	pesquisa = pesquisaN;
	for (int i = 0; i < 3; i++) {
		if (p[i].getTitularNome() == pesquisa && p[i].getCpf() == pesquisaC) {
			return p[i].getNumCadastro();
		}
	}
}
//escolhe entre poupanca/corrente deposito

void Menu::escolheInvestimentoDeposito() {
	system("CLS");
	std::string escolha;
	frufruEscolheTipoInvestimento();
	std::getline(std::cin, escolha);
	int escolhaCC, escolhaCP;

	if (escolha == "c" || escolha == "C") {
		escolhaCC = escolheDepositoCC();
		if (escolhaCC == NULL) {
			system("CLS");
			frufruNaoHaCadastroContaC();
		}
		else if (c[escolhaCC].getTitularNome() == "") {
			system("CLS");
			frufruNaoHaCadastroContaC();
		}
		else {
			system("CLS");
			c[escolhaCC].mostraTitular();
			c[escolhaCC].deposito();
		}

	}
	if (escolha == "P" || escolha == "p") {
		escolhaCP = escolheDepositoCP();
		if (escolhaCP == NULL) {
			system("CLS");
			frufruNaoHaCadastroContaP();
		}
		else if (p[escolhaCP].getTitularNome() == "") {
			system("CLS");
			frufruNaoHaCadastroContaP();
		}
		else {
			system("CLS");
			p[escolhaCP].mostraTitular();
			p[escolhaCP].deposito();
		}

	}
	if (escolha == "V" || escolha == "v") {
		system("CLS");
	}

}
//escolhe quem do array vai depositar
//-cc
int Menu::escolheDepositoCC() {
	std::string pesquisa;
	char pesquisaN[1024];
	std::string pesquisaC;
	char pesquisaCpf[1024];
	std::cout << "Digite o nome de quem gostaria de depositar:";
	std::cin.getline(pesquisaN, 1024);
	std::cout << "Digite o cpf de quem gostaria de depositar:";
	std::cin.getline(pesquisaCpf, 1024);
	pesquisaC = pesquisaCpf;
	pesquisa = pesquisaN;
	for (int i = 0; i < 3; i++) {
		if (c[i].getTitularNome() == pesquisa && c[i].getCpf() == pesquisaC) {
			return c[i].getNumCadastro();
		}
	}
}
//-cp
int Menu::escolheDepositoCP() {
	std::string pesquisa;
	char pesquisaN[1024];
	std::string pesquisaC;
	char pesquisaCpf[1024];
	std::cout << "Digite o nome de quem gostaria de depositar:";
	std::cin.getline(pesquisaN, 1024);
	std::cout << "Digite o cpf de quem gostaria de depositar:";
	std::cin.getline(pesquisaCpf, 1024);
	pesquisaC = pesquisaCpf;
	pesquisa = pesquisaN;
	for (int i = 0; i < 3; i++) {
		if (p[i].getTitularNome() == pesquisa && p[i].getCpf() == pesquisaC) {
			return p[i].getNumCadastro();
		}
	}
}
//escolhe entre poupanca/corrente saldo
void Menu::escolheInvestimentoSaldo() {
	system("CLS");
	std::string escolha;
	frufruEscolheTipoInvestimento();
	std::getline(std::cin, escolha);
	int escolhaCC, escolhaCP;

	if (escolha == "c" || escolha == "C") {
		escolhaCC = escolheSaldoCC();
		if (escolhaCC == NULL) {
			system("CLS");
			frufruNaoHaCadastroContaC();
		}
		else if (c[escolhaCC].getTitularNome() == "") {
			system("CLS");
			frufruNaoHaCadastroContaC();
		}
		else {
			system("CLS");
			c[escolhaCC].mostraTitular();
			c[escolhaCC].mostrarSaldo();
		}
	}
	if (escolha == "P" || escolha == "p") {
		escolhaCP = escolheSaldoCP();
		if (escolhaCP == NULL) {
			system("CLS");
			frufruNaoHaCadastroContaP();
		}
		else if (p[escolhaCP].getTitularNome() == "") {
			system("CLS");
			frufruNaoHaCadastroContaP();
		}
		else {
			system("CLS");
			p[escolhaCP].mostraTitular();
			p[escolhaCP].mostrarSaldo();
		}

	}
	if (escolha == "V" || escolha == "v") {
		system("CLS");
	}



}
//escolhe do array quem vai ver o saldo
//-cc
int Menu::escolheSaldoCC()
{
	std::string pesquisa;
	char pesquisaN[1024];
	std::string pesquisaC;
	char pesquisaCpf[1024];
	std::cout << "Digite o nome de quem gostaria de visualizar o saldo:";
	std::cin.getline(pesquisaN, 1024);
	std::cout << "Digite o cpf de quem gostaria de visualizar o saldo:";
	std::cin.getline(pesquisaCpf, 1024);
	pesquisaC = pesquisaCpf;
	pesquisa = pesquisaN;
	for (int i = 0; i < 3; i++) {
		if (c[i].getTitularNome() == pesquisa && c[i].getCpf() == pesquisaC) {
			return c[i].getNumCadastro();
		}
	}

}
//-cp
int Menu::escolheSaldoCP()
{
	std::string pesquisa;
	char pesquisaN[1024];
	std::string pesquisaC;
	char pesquisaCpf[1024];
	std::cout << "Digite o nome de quem gostaria de visualizar o saldo:";
	std::cin.getline(pesquisaN, 1024);
	std::cout << "Digite o cpf de quem gostaria de visualizar o saldo:";
	std::cin.getline(pesquisaCpf, 1024);
	pesquisaC = pesquisaCpf;
	pesquisa = pesquisaN;

	for (int i = 0; i < 3; i++) {
		if (p[i].getTitularNome() == pesquisa && p[i].getCpf() == pesquisaC) {
			return p[i].getNumCadastro();
		}
	}
}
//escolhe lista array
void Menu::escolheClientes()
{
	std::string escolha;
	frufruEscolheTipoInvestimento();
	std::getline(std::cin,escolha);
	if (escolha == "c" || escolha == "C") {
		mostraClientesCorrente();
	}
	if (escolha == "p" || escolha == "P") {
		mostraClientesPoupanca();
	}
	if (escolha == "v" || escolha == "V") {

	}
}
//-mostra array poupanca
void Menu::mostraClientesPoupanca()
{
	system("CLS");
	for (int i = 0; i < 3; i++) {
		p[i].mostraTitular();
	}
}
//-mostra array corrente
void Menu::mostraClientesCorrente()
{
	system("CLS");
	for (int i = 0; i < 3; i++) {
		c[i].mostraTitular();
	}
}


//escolhe entre poupanca e corrente rendimento
void Menu::escolheInvestimentoRendimento() {
	system("CLS");
	std::string escolha;
	frufruEscolheTipoInvestimento();
	std::getline(std::cin, escolha);
	int escolhaCC, escolhaCP;

	if (escolha == "c" || escolha == "C") {
		escolhaCC = escolheRendimentoCC();
		if (escolhaCC == NULL) {
			system("CLS");
			frufruNaoHaCadastroContaC();
		}
		else if (c[escolhaCC].getTitularNome() == "") {
			system("CLS");
			frufruNaoHaCadastroContaC();
		}

		else {
			system("CLS");
			c[escolhaCC].mostraTitular();
			c[escolhaCC].calculaRendimento(escolheQtdMeses());
		}

	}
	if (escolha == "P" || escolha == "p") {
		escolhaCP = escolheRendimentoCP();
		if (escolhaCP == NULL) {
			system("CLS");
			frufruNaoHaCadastroContaP();
		}
		else if (p[escolhaCP].getTitularNome() == "") {
			system("CLS");
			frufruNaoHaCadastroContaP();
		}

		else {
			system("CLS");
			p[escolhaCP].mostraTitular();
			p[escolhaCP].calculaRendimento(escolheQtdMeses());
		}
	}
	if (escolha == "V" || escolha == "v") {
		system("CLS");
	}

}
//-escolhe qtd meses 
int Menu::escolheQtdMeses()
{
	std::string escolha;
	int mes;
	std::cout << "Digite a quantidade de meses que pretende deixar o dinheiro sem alteracoes na conta para o calculo de rendimento: ";
	std::getline(std::cin, escolha);
	std::stringstream(escolha) >> mes;
	return mes;
}
//escolhe do array quem vai ver o rendimento
//-cc
int Menu::escolheRendimentoCC()
{
	std::string pesquisa;
	char pesquisaN[1024];
	std::string pesquisaC;
	char pesquisaCpf[1024];
	std::cout << "Digite o nome de quem gostaria de visualizar o rendimento:";
	std::cin.getline(pesquisaN, 1024);
	std::cout << "Digite o cpf de quem gostaria de visualizar o rendimento:";
	std::cin.getline(pesquisaCpf, 1024);
	pesquisaC = pesquisaCpf;
	pesquisa = pesquisaN;
	for (int i = 0; i < 3; i++) {
		if (c[i].getTitularNome() == pesquisa && c[i].getCpf() == pesquisaC) {
			return c[i].getNumCadastro();
		}
	}
}
//-cp
int Menu::escolheRendimentoCP()
{
	std::string pesquisa;
	char pesquisaN[1024];
	std::string pesquisaC;
	char pesquisaCpf[1024];
	std::cout << "Digite o nome de quem gostaria de visualizar o rendimento:";
	std::cin.getline(pesquisaN, 1024);
	std::cout << "Digite o cpf de quem gostaria de visualizar o rendimento:";
	std::cin.getline(pesquisaCpf, 1024);
	pesquisaC = pesquisaCpf;
	pesquisa = pesquisaN;
	for (int i = 0; i < 3; i++) {
		if (p[i].getTitularNome() == pesquisa && p[i].getCpf() == pesquisaC) {
			return p[i].getNumCadastro();
		}
	}
}
//frufrus
void Menu::frufruMenuBox() {
	std::cout << "***************************************" << std::endl;
	std::cout << "*    $$$  MENU DO BANCO TRESH  $$$    *" << std::endl;
	std::cout << "*_____________________________________*" << std::endl;
	std::cout << "*(1) - CADASTRAR CONTA POUPANCA       * " << std::endl;
	std::cout << "*(2) - CADASTRAR CONTA CORRENTE       *" << std::endl;
	std::cout << "*(3) - REALIZAR DEPOSITO              *" << std::endl;
	std::cout << "*(4) - REALIZAR SAQUE                 *" << std::endl;
	std::cout << "*(5) - VISUALIZAR SALDO               *" << std::endl;
	std::cout << "*(6) - VISUALIZAR RENDIMENTO MENSAL   *" << std::endl;
	std::cout << "*(7) - SAIR DO PROGRAMA               *" << std::endl;
	std::cout << "*(8) - SAIR E VISUALIZAR CREDITOS     *" << std::endl;
	std::cout << "*(9) - VISUALIZAR LISTA DE CLIENTES   *" << std::endl;
	std::cout << "*_____________________________________*" << std::endl;
	std::cout << "*      O QUE GOSTARIA DE FAZER?       *" << std::endl;
	std::cout << "***************************************" << std::endl;
}

void Menu::frufruEscolheTipoInvestimento() {
	std::cout << "Conta corrente ou Conta Poupanca?" << std::endl;
	std::cout << "(C) - Conta Corrente " << std::endl;
	std::cout << "(P) - Conta Poupanca " << std::endl;
	std::cout << "(V) - Voltar " << std::endl;
	std::cout << std::endl;
}

void Menu::frufruNaoHaCadastroContaC() {
	std::cout << "Nao ha cadastro nesta conta corrente!" << std::endl;
	std::cout << "Operacao indisponivel!" << std::endl;
	std::cout << std::endl;
}

void Menu::frufruNaoHaCadastroContaP() {
	std::cout << "Nao ha cadastro nesta conta poupanca!" << std::endl;
	std::cout << "Operacao indisponivel!" << std::endl;
	std::cout << std::endl;
}

void Menu::frufruClienteCadastradoComSucesso(std::string nome)
{
	std::cout << std::endl;
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "Cliente " << nome << " cadastrado com sucesso!" << std::endl;
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << std::endl;
}

void Menu::frufruLimiteCadastrosExcedido()
{
	system("CLS");
	std::cout << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "|Limite de cadastros excedido!|" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << std::endl;
}

void Menu::frufruErrouMenu()
{
	system("CLS");
	std::cout << "***************************************" << std::endl;
	std::cout << "*    Digite um numero entre 1 e 7     *" << std::endl;
}

void Menu::frufruProgramaFinalizado()
{
	system("CLS");
	std::cout << std::endl;
	std::cout << "Programa finalizado." << std::endl;
	std::cout << std::endl;
}

void Menu::frufruVisualizarCreditos()
{
	system("CLS");
	std::cout << std::endl;
	std::cout << "Programa finalizado." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "|---------------------------------------- CREDITOS ------------------------------------------|" << std::endl;
	std::cout << "|     Agradecimentos especiais para as mulheres em minha vida: Iasmim (mae), Flora (irma),   |" << std::endl;
	std::cout << "| Lisan (tia) e Juliana (namorada e companheira em vida), por me aturarem e sempre confiarem |" << std::endl;
	std::cout << "|em mim em todas minhas empreitadas.                                                         |" << std::endl;
	std::cout << "|     Agradecimentos tecnicos a 'DaniboyxD' AKA Daniel Guimaraes por me mostrar diversao em  |" << std::endl;
	std::cout << "|programacao e Carlino Junior pelos ensinamentos em C e C++.                                 |" << std::endl;
	std::cout << "|--------------------------------------------------------------------------------------------| " << std::endl;
	std::cout << "|##### Sistema ficticio para bancos V1.0 - Desenvolvido por Andre de Brito Arnaud em C++ ####|" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << std::endl;
}

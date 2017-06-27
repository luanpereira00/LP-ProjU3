/**
 * @file	fornecedores.cpp
 * @brief	Implementacoes da classe Fornecedores
  * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#include "fornecedores.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::getline;

#include <string>
using std::string;
using std::to_string;

#include <fstream>
using std::ostream;
using std::istream;

/**@brief Construtor Padrao */
Fornecedores::Fornecedores(){
	setNome("");
	setChave(0);
	setQtd(0);
}

/**@return Retorna o nome */
string Fornecedores::getNome(){ return nomeEmpresa;}


/**@return Retorna a chave do produto */
int Fornecedores::getChave(){ return chaveProduto;}

/**@return Retorna a quantidade do produto */
int Fornecedores::getQtd(){ return qtdProduto; }

/**@brief Atualiza o nome 
	*@param n O novo nome */
void Fornecedores::setNome(string n){ nomeEmpresa = n;}


/**@brief Atualiza a chave do produto 
	*@param c A nova chave*/
void Fornecedores::setChave(int c){ chaveProduto = c;}

/**@brief Atualiza a quantidade do produto 
	*@param q A nova quantidade */
void Fornecedores::setQtd(int q){ qtdProduto = q; }

/**@brief Imprime os dados na tela de forma sanitizada */
void Fornecedores::imprimirTela(){
	cout << "Nome: " << nomeEmpresa << endl;
	cout << "Chave: " << chaveProduto << endl;
	cout << "Quantidade do produto: " << qtdProduto << endl;
}

/**@brief Imprime todos os dados para um arquivo no formato csv*/
void Fornecedores::imprimirArquivo(){
	string closing;

	closing = "./data/fornecedores/"+ to_string(getLastFornecedores())+"_fornec.csv";
	ofstream fornec(closing);
	fornec << nomeEmpresa << ";" << chaveProduto << ";" << qtdProduto << endl;  
	fornec.close();
}

/**@brief Le os dados de um arquivo */
void Fornecedores::lerArquivo(){
	bool flag =true;
	int i=0;
	string opening;
	while (flag){
		i++;
		opening = "./data/fornecedores/"+ to_string(i) +"_fornec.csv";
		ifstream fornec(opening);
		if(!fornec) flag=false;
		else {
			if(i==1) cout << "--- Lista de Fornecedores ---" << endl;
			cout << "===========================================" << endl;
			Fornecedores f;
			fornec >> f;
			cout << "--- Fornecedor " << i << " ---" << endl;
			f.imprimirTela();
		}
	}
	cout << "===========================================" << endl;
}


/**@return Retorna o ultimo fornecimento cadastrado */
int Fornecedores::getLastFornecedores(){
	bool flag =true;
	int i=0;
	string opening;
	while (flag){
		i++;
		opening = "./data/fornecedores/"+ to_string(i) +"_fornec.csv";
		ifstream fornec(opening);
		if(!fornec) flag=false;
		else fornec.close();	
	}
	return i;
}

/**@brief Cria um novo fornecimento
*@param e O estoque de produtos */ 
void Fornecedores::criar(Estoque *e){
	
	node<Produtos*>* E;

	e->getListaProd()->imprimirTela();

	cout << "Digite a chave de busca: ";
	cin >> chaveProduto;

	E = e->getListaProd()->buscar(chaveProduto);

	if(E->prox->prox){
		cin.ignore();
		cout << "Digite o nome da empresa: ";
		getline(cin, nomeEmpresa);
		
		do{
			cout << "Digite a quantidade da entrega: ";
			cin >> qtdProduto;
		}while(qtdProduto<1);
		E->prox->dado->setQtdEstoque(E->prox->dado->getQtdEstoque()+qtdProduto);
		imprimirArquivo();
		cout << "ENTREGA CONCLUIDA COM SUCESSO! CONTINUANDO OPERACOES..." << endl;
	} else cerr << "CHAVE NAO ENCONTRADA! NADA A FAZER..." << endl;
	
}	

	/** @brief Sobrecarga do operador de insercao em stream 
	* @details O operador eh sobrecarregado para representar um fornedor na formatacao "nomeDaEmpresa;tipoProduto;chaveProduto;qtdProduto"  
	* @param	os Referencia para stream de saida  
	* @param	a Referencia para o objeto Fornecedor a ser impresso  
	* @return	Referencia para stream de saida  
	*/
ostream& operator<<(ostream& os, Fornecedores &a){
	os << a.getNome() << ";"; 	
	os << a.getChave() << ";";
	os << a.getQtd();
	return os; 
}

/** @brief Sobrecarga do operador de extracao de stream 
	* @param	is Referencia para stream de entrada  
	* @param	a Referencia para o objeto Fornecedor a ser criado com base nos  
	*			valores fornecidos  
	* @return	Referencia para stream de entrada  
	*/ 	
istream& operator>>(istream& is, Fornecedores &a){
	string aux; 
	getline(is, aux, ';'); 	
	a.setNome(aux); 

	getline(is, aux, ';'); 	
	a.setChave(atoi(aux.c_str()));	

	getline(is, aux); 	
	a.setQtd(atoi(aux.c_str()));
	return is; 
}
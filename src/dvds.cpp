/**
 * @file	dvds.cpp
 * @brief	Definicao da classe DVDs para representar produtos do tipo DVD
 * @details Os atributos de um DVD sao o titulo, o genero e a duracao em Duracao
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#include <iostream>
using std::getline;

#include "dvds.h"

/**@brief Construtor padrao*/
DVDs::DVDs(){
	setTipo(4);
	setTitulo("");
	setGenero("");
	setDuracao(0);
}

/**@brief Destrutor padrao*/
DVDs::~DVDs(){
	//FAZ NADA
}

/**@brief Construtor copia 
	*@param a Elemento que sera usado para criacao*/
DVDs::DVDs(DVDs &a){
	tipo = a.tipo;
	chave = a.chave;
	nomeProduto = a.nomeProduto;
	precoUnitario = a.precoUnitario;
	qtdEstoque = a.qtdEstoque;
	titulo = a.titulo;
	genero= a.genero;
	minutos= a.minutos;
}

/**@return Retorna o titulo do DVD*/
string DVDs::getTitulo(){ return titulo; }

/**@return Retorna o genero do DVD*/
string DVDs::getGenero(){ return genero; }

/**@return Retorna a duracao em minutos do DVD*/
int DVDs::getDuracao(){ return minutos; }

/**@brief Atualiza o titulo
	*@param tt O novo titulo */
void DVDs::setTitulo(string tt){ titulo = tt; }

/**@brief Atualiza o genero
	*@param gr O novo genero */
void DVDs::setGenero(string gr){ genero = gr; }

/**@brief Atualiza a duracao em Duracao
	*@param min A nova duracao */
void DVDs::setDuracao(int min){ minutos = min; } //duracao

/**@brief Cria um dvd
	*param key A chave que sera associada ao dvd */
void DVDs::criar(int key){
	bool cinFlag;
	int auxI;
	float auxF;
	string auxS;

	cin.ignore();
	cout << "Digite o nome do DVD: ";
	getline(cin, auxS);


	do{
		cout << "Digite o preco unitario do DVD: ";
		cinFlag = true;
		try{
			cin >> auxF;
			if(cin.fail()) throw FalhaDeLeitura();
		} catch(FalhaDeLeitura &ex){
			cerr << ex.what() << endl;
			cin.clear();
			cin.ignore();
			cinFlag=false;
		}
	}while(!cinFlag or auxF<=0);


	do{
		cout << "Digite a quantidade em estoque do DVD: ";
		cinFlag = true;
		try{
			cin >> auxI;
			if(cin.fail()) throw FalhaDeLeitura();
		} catch(FalhaDeLeitura &ex){
			cerr << ex.what() << endl;
			cin.clear();
			cin.ignore();
			cinFlag=false;
		}
	}while(!cinFlag or auxI<0);

	setTipo(4);
	setChave(key);
	setNomeProd(auxS);
	setPrecoUnit(auxF);
	setQtdEstoque(auxI);

	cin.ignore();
	cout << "Digite o titulo do DVD: ";
	getline(cin, auxS);
	setTitulo(auxS);

	cout << "Digite o genero do DVD: ";
	getline(cin, auxS);
	setGenero(auxS);

	do{
		cout << "Digite a duracao em minutos do DVD: ";
		cinFlag = true;
		try{
			cin >> auxI;
			if(cin.fail()) throw FalhaDeLeitura();
		} catch(FalhaDeLeitura &ex){
			cerr << ex.what() << endl;
			cin.clear();
			cin.ignore();
			cinFlag=false;
		}
	}while(!cinFlag or auxI<0);
	setDuracao(auxI);
}
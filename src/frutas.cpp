/**
 * @file	frutas.cpp
 * @brief	Implementacao da classe Frutas
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#include <iostream>
using std::getline;

#include "frutas.h"
#include "data.h"

/**@brief Construtor padrao*/
Frutas::Frutas(){
	Data d;
	setTipo(5);
	setLote("");
	setDataLote(d);
	setValidade(d);
}

/**@brief Destrutor padrao*/
Frutas::~Frutas(){
	//FAZ NADA
}

/**@brief Construtor copia 
	*@param a Elemento que sera usado para criacao*/
Frutas::Frutas(Frutas &a){
	tipo = a.tipo;
	chave = a.chave;
	nomeProduto = a.nomeProduto;
	precoUnitario = a.precoUnitario;
	qtdEstoque = a.qtdEstoque;
	lote = a.lote;
	dataDeLote = a.dataDeLote;
	dataDeValidade = a.dataDeValidade;
}

/**@return Retorna o lote */
string Frutas::getLote(){ return lote; }

/**@return Retorna a data do lote */
Data* Frutas::getDataLote(){ return &dataDeLote; }

/**@brief Atualiza o lote
	*@param lt O novo lote */
void Frutas::setLote(string lt){ lote = lt; }

/**@brief Atualiza a data do lote
	*@param dl A nova data */ 
void Frutas::setDataLote(Data dl){ dataDeLote = dl; }

/**@brief Cria uma fruta
	*param key A chave que sera associada a fruta */
void Frutas::criar(int key){
	int auxI;
	float auxF;
	string auxS;

	cin.ignore();
	cout << "Digite o nome da fruta: ";
	getline(cin, auxS);
	cout << "Digite o preco unitario da fruta: ";
	cin >> auxF;
	cout << "Digite a quantidade em estoque da fruta: ";
	cin >> auxI;

	setTipo(5);
	setChave(key);
	setNomeProd(auxS);
	setPrecoUnit(auxF);
	setQtdEstoque(auxI);

	cin.ignore();
	cout << "Digite o lote da fruta: ";
	getline(cin, auxS);
	setLote(auxS);

	cout << "Digite a data do lote: ";
	cin >> auxS;
	getDataLote()->string2Data(auxS);

	cout << "Digite a data de validade da fruta: ";
	cin >> auxS;
	getValidade()->string2Data(auxS);
}
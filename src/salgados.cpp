/**
 * @file	salgados.cpp
 * @brief	Implementacoes da classe Salgados
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */
#include <iostream>
using std::getline;

#include "salgados.h"
#include "data.h"

/**@brief Construtor padrao*/
Salgados::Salgados(){
	setTipo(7);
	setQtdSodio(0);
	setGluten(false);
	setLactose(false);
}

/**@brief Destrutor padrao*/
Salgados::~Salgados(){
	//FAZ NADA
}

/**@brief Construtor copia 
	*@param a Elemento que sera usado para criacao*/
Salgados::Salgados(Salgados &a){
	tipo = a.tipo;
	chave = a.chave;
	nomeProduto = a.nomeProduto;
	precoUnitario = a.precoUnitario;
	qtdEstoque = a.qtdEstoque;
	qtdSodio = a.qtdSodio;
	gluten = a.gluten;
	lactose = a.lactose;
	dataDeValidade = a.dataDeValidade;
}

/**@return Retorna a quantidade de sodio*/
float Salgados::getQtdSodio(){ return qtdSodio; }

/**@return Retorna bool para ter gluten */
bool Salgados::getGluten(){ return gluten; }

/**@return Retorna bool para ter lactose */
bool Salgados::getLactose(){ return lactose; }

/**@brief Atualiza a quantidade de sodio
	*@param s A nova quantidade de sodio*/
void Salgados::setQtdSodio(float s){ qtdSodio = s; }

/**@brief Atualiza a informacao sobre gluten
	*@param gt A informacao para atualizar */
void Salgados::setGluten(bool gt){ gluten = gt; }

/**@brief Atualiza a informacao sobre lactose
	*@param lt A informacao para atualizar */
void Salgados::setLactose(bool lt){ lactose = lt; }

/**@brief Cria um salgado
	*param key A chave que sera associada ao salgado */
void Salgados::criar(int key){
	int auxI;
	float auxF;
	string auxS;

	cin.ignore();
	cout << "Digite o nome do salgado: ";
	getline(cin, auxS);
	cout << "Digite o preco unitario do salgado: ";
	cin >> auxF;
	cout << "Digite a quantidade em estoque do salgado: ";
	cin >> auxI;

	setTipo(7);
	setChave(key);
	setNomeProd(auxS);
	setPrecoUnit(auxF);
	setQtdEstoque(auxI);

	cout << "Digite a quantidade de sodio no salgado: ";
	cin >> auxF;
	setQtdSodio(auxF);

	do{
		cout << "Digite bool (0 ou 1) para ter lactose: ";
		cin >> auxI;
	}while(auxI!=0 and auxI!=1);
	setLactose(auxI);

	do{
		cout << "Digite bool (0 ou 1) para ter gluten: ";
		cin >> auxI;
	}while(auxI!=0 and auxI!=1);
	setGluten(auxI);

	cout << "Digite a data de validade do salgado: ";
	cin >> auxS;
	getValidade()->string2Data(auxS);
}

/**
 * @file	doces.cpp
 * @brief	Implementacoes da classe Docess
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#include <iostream>
using std::getline;

#include <string>
using std::string;

#include "doces.h"
#include "data.h"

/**@brief Construtor padrao*/
Doces::Doces(){
	setTipo(3);
	setQtdAcucar(0);
	setGluten(false);
	setLactose(false);
}

/**@brief Destrutor padrao*/
Doces::~Doces(){
	//FAZ NADA
}

/**@brief Construtor copia 
	*@param a Elemento que sera usado para criacao*/
Doces::Doces(Doces &a) {
	tipo = a.tipo;
	chave = a.chave;
	nomeProduto = a.nomeProduto;
	precoUnitario = a.precoUnitario;
	qtdEstoque = a.qtdEstoque;
	qtdAcucar = a.qtdAcucar;
	gluten = a.gluten;
	lactose = a.lactose;
	dataDeValidade = a.dataDeValidade;
}

/**@return Retorna a quantidade de acucar */
float Doces::getQtdAcucar(){ return qtdAcucar; }

/**@return Retorna bool para ter gluten */
bool Doces::getGluten(){ return gluten; }

/**@return Retorna bool para ter lactose */
bool Doces::getLactose(){ return lactose; }

/**@brief Atualiza a quantidade de acucar
	*@param a A nova quantidade de acucar*/
void Doces::setQtdAcucar(float a){ qtdAcucar = a; }

/**@brief Atualiza a informacao sobre gluten
	*@param gt A informacao para atualizar */
void Doces::setGluten(bool gt){ gluten = gt; }

/**@brief Atualiza a informacao sobre lactose
	*@param lt A informacao para atualizar */
void Doces::setLactose(bool lt){ lactose = lt; }

/**@brief Cria um doce
	*param key A chave que sera associada ao doce */
void Doces::criar(int key){
	int auxI;
	float auxF;
	string auxS;

	cin.ignore();
	cout << "Digite o nome do doce: ";
	getline(cin, auxS);
	cout << "Digite o preco unitario do doce: ";
	cin >> auxF;
	cout << "Digite a quantidade em estoque do doce: ";
	cin >> auxI;

	setTipo(3);
	setChave(key);
	setNomeProd(auxS);
	setPrecoUnit(auxF);
	setQtdEstoque(auxI);

	cout << "Digite a quantidade de acucar no doce: ";
	cin >> auxF;
	setQtdAcucar(auxF);

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

	cin.ignore();
	cout << "Digite a data de validade do doce: ";
	cin >> auxS;
	getValidade()->string2Data(auxS);
}

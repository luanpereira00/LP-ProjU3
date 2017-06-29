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
	bool cinFlag = true;
	int auxI;
	float auxF;
	string auxS;

	cin.ignore();
	cout << "Digite o nome do doce: ";
	getline(cin, auxS);

	do{
		cout << "Digite o preco unitario do doce: ";
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
		cout << "Digite a quantidade em estoque do doce: ";
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

	setTipo(3);
	setChave(key);
	setNomeProd(auxS);
	setPrecoUnit(auxF);
	setQtdEstoque(auxI);

	do{
		cout << "Digite a quantidade de acucar no doce: ";
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
	}while(!cinFlag or auxF<0);
	setQtdAcucar(auxF);

	do{
		cout << "Digite bool (0 ou 1) para ter lactose: ";
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
	}while(!cinFlag or auxI<0 or auxI>1);
	setLactose(auxI);

	do{
		cout << "Digite bool (0 ou 1) para ter gluten: ";
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
	}while(!cinFlag or auxI<0 or auxI>1);
	setGluten(auxI);

	int diaAux, mesAux, anoAux;
	//do{
	cout << "Digite a data de validade do doce: " << endl;
	do{
		cout << "Dia: ";
		cinFlag = true;
		try{
			cin >> diaAux;
			if(cin.fail()) throw FalhaDeLeitura();
		} catch(FalhaDeLeitura &ex){
			cerr << ex.what() << endl;
			cin.clear();
			cin.ignore();
			cinFlag=false;
		}
	}while(!cinFlag or diaAux<1 or diaAux>31);

	do{
		cout << "Mes: ";
		cinFlag = true;
		try{
			cin >> mesAux;
			if(cin.fail()) throw FalhaDeLeitura();
		} catch(FalhaDeLeitura &ex){
			cerr << ex.what() << endl;
			cin.clear();
			cin.ignore();
			cinFlag=false;
		}
	}while(!cinFlag or mesAux<1 or mesAux>12);

	do{
		cout << "Ano: ";
		cinFlag = true;
		try{
			cin >> anoAux;
			if(cin.fail()) throw FalhaDeLeitura();
		} catch(FalhaDeLeitura &ex){
			cerr << ex.what() << endl;
			cin.clear();
			cin.ignore();
			cinFlag=false;
		}
	}while(!cinFlag);

	Data d(diaAux, mesAux, anoAux);
	setValidade(d);
}

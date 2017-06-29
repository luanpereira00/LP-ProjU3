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
	bool cinFlag;
	int auxI;
	float auxF;
	string auxS;

	cin.ignore();
	cout << "Digite o nome do salgado: ";
	getline(cin, auxS);
	
	do{
		cout << "Digite o preco unitario do salgado: ";
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
		cout << "Digite a quantidade em estoque do salgado: ";
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

	setTipo(7);
	setChave(key);
	setNomeProd(auxS);
	setPrecoUnit(auxF);
	setQtdEstoque(auxI);

	do{
		cout << "Digite a quantidade de sodio no salgado: ";
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
	setQtdSodio(auxF);

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
	cout << "Digite a data de validade do salgado: " << endl;
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

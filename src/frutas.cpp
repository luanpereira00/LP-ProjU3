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
	bool cinFlag;
	int auxI;
	float auxF;
	string auxS;

	cin.ignore();
	cout << "Digite o nome da fruta: ";
	getline(cin, auxS);
	do{
		cout << "Digite o preco unitario da fruta: ";
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
		cout << "Digite a quantidade em estoque da fruta: ";
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

	setTipo(5);
	setChave(key);
	setNomeProd(auxS);
	setPrecoUnit(auxF);
	setQtdEstoque(auxI);

	cin.ignore();
	cout << "Digite o lote da fruta: ";
	getline(cin, auxS);
	setLote(auxS);

	int diaAux, mesAux, anoAux;
	//do{
	cout << "Digite a data do lote: " << endl;
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

	Data l(diaAux, mesAux, anoAux);
	setDataLote(l);
	

	cout << "Digite a data de validade da fruta: " << endl;
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
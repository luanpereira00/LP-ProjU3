/**
 * @file	bebidas.cpp
 * @brief	Implementacao dos metodos da classe Bebidas
 * @details Os atributos de uma Bebida sao a chave, o nome, o preco, a quantidade em estoque, o teor alcoolico, a quantidade de acucar, o volume total e a data de validade
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::getline;

#include "bebidas.h"
#include "data.h"

/**@brief Construtor padrao*/
Bebidas::Bebidas(){
	setTipo(1);
	setTeorAlcoolico(0.0);
	setQtdAcucar(0.0);
	setVolumeTotal(0);
}

/**@brief Destrutor padrao*/
Bebidas::~Bebidas(){
	//FAZ NADA
}

/**@brief Construtor copia */
Bebidas::Bebidas(Bebidas &a) {
	tipo = a.tipo;
	chave = a.chave;
	nomeProduto = a.nomeProduto;
	precoUnitario = a.precoUnitario;
	qtdEstoque = a.qtdEstoque;
	teorAlcoolico = a.teorAlcoolico;
	qtdAcucar = a.qtdAcucar;
	volumeTotal = a.volumeTotal;
	dataDeValidade = a.dataDeValidade;
}

/**@return Retorna o teor alcoolico */
float Bebidas::getTeorAlcoolico(){ return teorAlcoolico; }

/**@return Retorna a quantidade de acucar */
float Bebidas::getQtdAcucar(){ return qtdAcucar; }

/**@return Retorna o volume total */
int Bebidas::getVolumeTotal(){ return volumeTotal; }

/**@brief Atualiza o teor alcoolico
	*@param t O novo teor alcoolico */
void Bebidas::setTeorAlcoolico(float t){ teorAlcoolico = t; }

/**@brief Atualiza a quantidade de acucar
	*@param a A nova quantidade de acucar*/
void Bebidas::setQtdAcucar(float a){ qtdAcucar = a; }

/**@brief Atualiza o volume total
	*@param v O novo volume total*/
void Bebidas::setVolumeTotal(int v){ volumeTotal = v; }

/**@brief Cria uma bebida
	*param key A chave que sera associada a bebida */
void Bebidas::criar(int key){
	bool cinFlag;
	int auxI;
	float auxF;
	string auxS;
	

	cin.ignore();
	cout << "Digite o nome da bebida: ";
	getline(cin, auxS);

	do{
		cout << "Digite o preco unitario da bebida: ";
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
		cout << "Digite a quantidade em estoque da bebida: ";
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

	setTipo(1);
	setChave(key);
	setNomeProd(auxS);
	setPrecoUnit(auxF);
	setQtdEstoque(auxI);

	do{
		cout << "Digite o teor alcoolico da bebida: ";
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
	setTeorAlcoolico(auxF);


	do{
		cout << "Digite a quantidade de acucar da bebida: ";
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
		cout << "Digite o volume total da bebida: ";
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
	}while(!cinFlag or auxI < 0);
	setVolumeTotal(auxI);

	int diaAux, mesAux, anoAux;
	//do{
	cout << "Digite a data de validade da bebida: " << endl;
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


/**
 * @file	cds.cpp
 * @brief	Implementacao da classe CDs para representar produtos do tipo CD
 * @details Os atributos de um CD sao o nomeDoAlbum, o estilo e o artista
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#include <iostream>
using std::getline;

#include "cds.h"

/**@brief Construtor padrao*/
CDs::CDs(){
	setTipo(2);
	setAlbum("");
	setEstilo("");
	setArtista("");
}

/**@brief Destrutor padrao*/
CDs::~CDs(){
	//FAZ NADA
}

/**@brief Construtor copia 
*@param a Elemento que sera usado para criacao*/
CDs::CDs(CDs &a){
	tipo = a.tipo;
	chave = a.chave;
	nomeProduto = a.nomeProduto;
	precoUnitario = a.precoUnitario;
	qtdEstoque = a.qtdEstoque;
	nomeDoAlbum = a.nomeDoAlbum;
	artista = a.artista;
	estilo = a.estilo;
}

/**@return Retorna o nome do album*/
string CDs::getAlbum(){ return nomeDoAlbum; }

/**@return Retorna o estilo musical*/
string CDs::getEstilo(){ return estilo; }

/**@return Retorna o nome do artista*/
string CDs::getArtista(){ return artista; }

/**@brief Atualiza o nome do album
	*@param a O novo nome do album*/
void CDs::setAlbum(string a){ nomeDoAlbum = a; }

/**@brief Atualiza o estilo musical
	*@param es O novo estilo musical*/
void CDs::setEstilo(string es){ estilo = es; }

/**@brief Atualiza o nome do artista
	*@param t O novo nome do artista*/
void CDs::setArtista(string t){ artista = t; }

/**@brief Cria um cd
	*param key A chave que sera associada ao cd */
void CDs::criar(int key){
	int auxI;
	float auxF;
	string auxS;

	cin.ignore();
	cout << "Digite o nome do CD: ";
	getline(cin, auxS);
	cout << "Digite o preco unitario do CD: ";
	cin >> auxF;
	cout << "Digite a quantidade em estoque do CD: ";
	cin >> auxI;

	setTipo(2);
	setChave(key);
	setNomeProd(auxS);
	setPrecoUnit(auxF);
	setQtdEstoque(auxI);

	cin.ignore();
	cout << "Digite o album do CD: ";
	getline(cin, auxS);
	setAlbum(auxS);

	cout << "Digite o estilo do CD: ";
	getline(cin, auxS);
	setEstilo(auxS);

	cout << "Digite o artista: ";
	getline(cin, auxS);
	setArtista(auxS);
}
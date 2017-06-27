/**
 * @file	livros.cpp
 * @brief	Implementacao da classe Livros
 * @details Os atributos de um Livro sao o titulo, o autor, a editora e o ano de lancamento
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#include <iostream>
using std::getline;

#include "livros.h"

/**@brief Construtor padrao*/
Livros::Livros(){
	setTipo(6);
	setTitulo("");
	setAutor("");
	setEditora("");
	setLancamento(1900);
}

/**@brief Destrutor padrao*/
Livros::~Livros(){
	//FAZ NADA
}

/**@brief Construtor copia 
	*@param a Elemento que sera usado para criacao*/
Livros::Livros(Livros &a){
	tipo = a.tipo;
	chave = a.chave;
	nomeProduto = a.nomeProduto;
	precoUnitario = a.precoUnitario;
	qtdEstoque = a.qtdEstoque;
	titulo = a.titulo;
	autor= a.autor;
	editora= a.editora;
	anoLancamento = a.anoLancamento;
}

/**@return Retorna o titulo*/
string Livros::getTitulo(){ return titulo; }

/**@return Retorna o autor*/
string Livros::getAutor(){ return autor; }

/**@return Retorna a editora */
string Livros::getEditora(){ return editora; }

/**@return Retorna o ano de lancamento*/
int Livros::getLancamento(){ return anoLancamento; }

/**@brief Atualiza o titulo
	*@param tt O novo titulo */
void Livros::setTitulo(string tt){ titulo = tt; }

/**@brief Atualiza o autor
	*@param at O novo autor*/
void Livros::setAutor(string at){ autor = at; }

/**@brief Atualiza a editora
	*@param ed A nova editora */
void Livros::setEditora(string ed){ editora = ed; }

/**@brief Atualiza o ano de lancamento
	*@param aa O novo ano de lancamento*/
void Livros::setLancamento(int aa){ anoLancamento = aa; }

/**@brief Cria um livro
	*param key A chave que sera associada ao livro */
void Livros::criar(int key){
	int auxI;
	float auxF;
	string auxS;

	cin.ignore();
	cout << "Digite o nome do livro: ";
	getline(cin, auxS);
	cout << "Digite o preco unitario do livro: ";
	cin >> auxF;
	cout << "Digite a quantidade em estoque do livro: ";
	cin >> auxI;

	setTipo(6);
	setChave(key);
	setNomeProd(auxS);
	setPrecoUnit(auxF);
	setQtdEstoque(auxI);

	cin.ignore();
	cout << "Digite o titulo do livro: ";
	getline(cin, auxS);
	setTitulo(auxS);

	cout << "Digite o autor do livro: ";
	getline(cin, auxS);
	setAutor(auxS);

	cout << "Digite a editora do livro: ";
	getline(cin, auxS);
	setEditora(auxS);

	cout << "Digite o ano de lancamento do livro: ";
	cin >> auxI;
	setLancamento(auxI);
}

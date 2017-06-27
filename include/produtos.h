/**
 * @file	produtos.h
 * @brief	Definicao da classe mae Produtos para representar um produto
 * @details Os atributos de um produto sao a chave, o nome do produto, o preco unitario e a quantidade em estoque;
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */
#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::getline;
using std::endl;

#include <string>
using std::string;

#include <ostream> 
using std::ostream; 

#include <istream> 
using std::istream;

/** 
 * @class 	Produtos produtos.h
 * @brief 	Classe que representa Produtos
 * @details O atributo de um produto sao a chave, o nome do produto, o preco unitario e a quantidade em estoque;
 */
class Produtos{
private:
	/**@brief Metodo virtual para imprimir */
	virtual ostream& print(ostream&)=0;

	/**@brief Metodo virtual para ler */
	virtual istream& read(istream&)=0;

protected: 
	int tipo; /**< O tipo do produto */
	int chave; /**< A chave primaria associada ao produto*/
	string nomeProduto; /**< O nome do produto*/
	float precoUnitario; /**< O preco unitario*/
	int qtdEstoque; /**< A quantidade em estoque*/


public:
	/**@brief Construtor padrao*/
	Produtos();

	/**@brief Destrutor padrao*/
	virtual ~Produtos();

	/**@return Retorna a chave */
	int getChave();

	/**@return Retorna o tipo do produto */
	int getTipo();

	/** @brief Atualiza o tipo 
	*@param t O novo tipo*/
	void setTipo(int t);

	/**@return Retorna o nome do produto*/
	string getNomeProd();

	/**@return Retorna o preco unitario*/
	float getPrecoUnit();

	/**@return A quantidade em estoque*/
	int getQtdEstoque();

	/**@brief Atualiza a chave
	*@param c A nova chave*/
	void setChave(int c);

	/**@brief Atualiza o nome
	*@param n O novo nome*/
	void setNomeProd(string n);

	/**@brief Atualiza o preco unitario
	*@param p O novo preco*/
	void setPrecoUnit(float p);

	/**@brief Imprime os dados na tela de forma sanitizada */
	void imprimirTela();

	/**@return Retorna a string do nome do tipo de acordo com o valor passado 
	*@param t O valor do tipo passado */
	string tipo2String(int t);

	/**@brief Atualiza a quantidade em estoque
	*@param e A nova quantidade*/
	void setQtdEstoque(int e);

	
	//bool operator<(Produtos *p);

	/**@brief Chama a funcao de imprimir
	*@param os Referencia para a stream de saida
	*@param a Referencia para o objeto
	*@return Retorna a referencia para a stream de saida */
 	friend ostream& operator<<(ostream& os, Produtos &a){
		return a.print(os);
	};
	
	/**@brief Chama a funcao de ler
	*@param is Referencia para a stream de entrada
	*@param a Referencia para o objeto
	*@return Retorna a referencia para a stream de entrada */
	friend istream& operator>>(istream& is, Produtos &a){
		return a.read(is);
	};
};

#endif
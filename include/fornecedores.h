/**
 * @file	fornecedores.h
 * @brief	Definicao da classe Fornecedores para representar uma entrega de fornecedores
 * @details Os atributos de Fornecedores sao o nome da empresa, o tipo de produto que fornecem, a chave do produto no estoque e a quantidade da entrega
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#ifndef FORNECEDORES_H
#define FORNECEDORES_H

#include "estoque.h"

/** 
 * @class 	Fornecedores fornecedores.h
 * @brief 	Classe que representa Fornecedores
 * @details Os atributos de Fornecedores sao o nome da empresa, o tipo de produto que fornecem, a chave do produto no estoque e a quantidade da entrega
 */
class Fornecedores {
private:
	string nomeEmpresa; /**< O nome da empresa*/
	int tipoProduto; /**< O tipo do produto (1-bebida, 2-cd, ... , 7-salgado)*/
	int chaveProduto; /**< A chave do produto no estoque*/
	int qtdProduto; /**< A quantidade do produto a ser entrege*/

public:
	/**@brief Construtor Padrao */
	Fornecedores();

	/**@return Retorna o nome */
	string getNome();

	/**@return Retorna a chave do produto */
	int getChave();

	/**@return Retorna a quantidade do produto */
	int getQtd();

	/**@brief Atualiza o nome 
	*@param n O novo nome */
	void setNome(string n);

	/**@brief Atualiza a chave do produto 
	*@param c A nova chave*/
	void setChave(int c);

	/**@brief Atualiza a quantidade do produto 
	*@param q A nova quantidade */
	void setQtd(int q);

	/**@brief Imprime os dados na tela de forma sanitizada */
	void imprimirTela();

	/**@brief Imprime todos os dados para um arquivo no formato csv*/
	void imprimirArquivo();

	/**@brief Le os dados de um arquivo */
	void lerArquivo();

	/**@brief Cria um novo fornecimento 
	*@param e O estoque de produtos*/
	void criar(Estoque *e);

	/**@return Retorna o numero do ultimo fornecimento */ 
	int getLastFornecedores();

	/** @brief Sobrecarga do operador de insercao em stream 
	* @details O operador eh sobrecarregado para representar um fornedor na formatacao "nomeDaEmpresa;chaveProduto;qtdProdutoEntregue"  
	* @param	os Referencia para stream de saida  
	* @param	a Referencia para o objeto Fornecedor a ser impresso  
	* @return	Referencia para stream de saida  
	*/
	friend ostream& operator<<(ostream& os, Fornecedores &a);

	/** @brief Sobrecarga do operador de extracao de stream 
	* @param	is Referencia para stream de entrada  
	* @param	a Referencia para o objeto Fornecedor a ser criado com base nos  
	*			valores fornecidos  
	* @return	Referencia para stream de entrada  
	*/ 
	friend istream& operator>>(istream& is, Fornecedores &a);
};

#endif
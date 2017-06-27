/**
 * @file	carrinho.h
 * @brief	Declaracao da classe Estoque para representar um carrinho de produtos
 * @details Os atributos de um Carrinho sao as listas de produtos herdadas da classe Estoque e o preco total da compra
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#ifndef CARRINHO_H
#define CARRINHO_H

#include "estoque.h"

#include <string>
using std::to_string;
using std::string;

/** 
 * @class 	Carrinho carrinho.h
 * @brief 	Classe que representa Carrinho
 */
class Carrinho : public Estoque {
private:
	float precoCompra; /**< Preco total da compra */
public:
	/**@return Retorna o preco da compra */
	float getPrecoCompra();

	/**@brief Atualiza o preco da compra 
	*@param pc O preco da compra*/
	void setPrecoCompra(float pc);

	/**@return Retorna bool para o carrinho estar vazio */
	bool isEmpty();

	/**@return O numero da ultima nota fiscal cadastrada */
	int verUltimaNotaFiscal();

	/**@brief Grava o carrinho num arquivo */
	void gravarArquivo();

	/**@brief Lista o carrinho */
	void listar();

	/**@brief Limpa o carrinho */
	void limpar();

	/**@brief Adiciona produtos ao carrinho 
	*@param e O estoque de produtos */
	void adicionarProduto(Estoque *e);

	/**@brief Remove produtos do carrinho 
	*@param e O estoque de produtos */
	void removerProduto(Estoque *e);

	/**@brief Atualiza o preco da compra somando com um valor passado como argumento 
	* @param pc O novo valor a somar */
	void calcularCompra(float pc);
};

#endif
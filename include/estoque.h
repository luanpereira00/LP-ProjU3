/**
 * @file	estoque.h
 * @brief	Declaracao da classe Estoque para representar um estoque de produtos
 * @details Os atributos de um Estoque sao as listas de produtos e ultima chave primaria associada
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

#include "lista.h"

#include "produtos.h"
#include "bebidas.h"
#include "cds.h"
#include "doces.h"
#include "dvds.h"
#include "frutas.h"
#include "livros.h"
#include "salgados.h"
#include "exceptions.h"

/** 
 * @class 	Estoque estoque.h
 * @brief 	Classe que representa Estoque
 */
class Estoque {
private:
	lista<Produtos*> *ll_Prod; /**< A lista de Prod*/
	
public:
	/**@brief Construtor padrao*/
	Estoque();

	/**@brief Destrutor padrao*/
	~Estoque();

	/**@return Retorna a lista de Prod */
	lista<Produtos*>* getListaProd();

	/**@brief Atualiza a lista de Prod 
	*@param ll A nova lista de prod*/
	void setListaProd(lista<Produtos*> *ll);

	/**@brief Lista todo o estoque  */
	void listarEstoque();

	/**@brief Lista todo o estoque detalhadamente */
	void listarEstoqueDetalhado();

	/**@brief Le os dados da memoria para inicializar o estoque  */
	void lerDados();

	/**@brief Grava os dados do estoque na memoria  */
	void gravarDados();

	/**@brief Cadastra um produto */
	void cadastrarProduto();

	/**@brief Remove um produto do cadastro */
	void removerProduto();
};

#endif
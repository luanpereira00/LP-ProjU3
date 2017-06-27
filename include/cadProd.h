/**
 * @file	cadProd.h
 * @brief	Definicao de funções que cadastram/adicionam w removem produtos de estoque/carrinho
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#ifndef CADPROD_H
#define CADPROD_H

#include "estoque.h"
#include "carrinho.h"
#include "bebidas.h"
#include "cds.h"
#include "doces.h"
#include "dvds.h"
#include "frutas.h"
#include "livros.h"
#include "salgados.h"
#include "estoque.h"

/**@brief Cadastra um produto no estoque */
void cadastrarProdutos(Estoque *e, int a);

/**@brief Remove um produto do estoque */
void removerProduto(Estoque *e, int a);

/**@brief Adiciona um produto ao carrinho */
void adicionarAoCarrinho(Estoque *e, Carrinho *carrinho, int a);

/**@brief Remove um produto do carrinho */
void removerDoCarrinho(Estoque *e, Carrinho *carrinho, int a);

#endif
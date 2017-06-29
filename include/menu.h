/**
 * @file	menu.h
 * @brief	Declaracao de menus do sistema
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#ifndef MENU_H
#define MENU_H

#include "exceptions.h"
/**
@brief Menu Princial
@details Direciona para Produtos, Nota Fiscal, Fornecedores e Venda
@return Retorna a escolha do usuario
*/
int menuPrincipal(); 

/**
@brief Menu Produtos
@details Direciona para Cadastrar, Remover e Listar Produtos
@return Retorna a escolha do usuario
*/
int menuProdutos();

/**
@brief Menu Fornecedores
@details Direciona para Cadastrar e Listar
@return Retorna a escolha do usuario
*/
int menuFornecedores();

/**
@brief Menu Nota Fiscal
@details Direciona para Listar Notas Fiscais
@return Retorna a escolha do usuario
*/
int menuNotaFiscal();

/**
@brief Menu Carrinho
@details Direciona para Carrinho de compra, no qual pode-se listar, adicionar ao carrinho, remover ou finalizar a compra
@return Retorna a escolha do usuario
*/
int menuCarrinho();

/**
@brief Menu Opcoes Produtos
@details Direciona para uma das opcoes de produtos
@return Retorna a escolha do usuario
*/
int menuOpcoesProdutos();
#endif
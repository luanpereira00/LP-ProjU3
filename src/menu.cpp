/**
 * @file	menu.cpp
 * @brief	Implementacao de menus do sistema
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include "estoque.h"

/**
@brief Menu Princial
@details Direciona para Produtos, Nota Fiscal, Fornecedores e Venda
@return Retorna a escolha do usuario
*/
int menuPrincipal(){
	int result;
	do{
		cout << "=======================================" << endl;
		cout << "--- Menu Principal ---" << endl;
		cout << "1 - Menu Produtos" << endl;
		cout << "2 - Menu Nota Fiscal" << endl;
		cout << "3 - Menu Fornecedores" << endl;
		cout << "4 - Iniciar Venda" << endl;
		cout << "0 - Sair" << endl;
		cout << "Opcao: ";
		cin >> result;
		if(result<0 or result>4) cerr << "OPCAO INVALIDA! TENTE NOVAMENTE..." << endl;
	}while(result<0 or result>4);

	return result;
} 

/**
@brief Menu Produtos
@details Direciona para Cadastrar, Remover e Listar Produtos
@return Retorna a escolha do usuario
*/
int menuProdutos(){
	int result;
	do{
		cout << "=======================================" << endl;
		cout << "--- Menu de Produtos ---" << endl;
		cout << "1 - Cadastrar Produto" << endl;
		cout << "2 - Remover Produto Cadastrado" << endl;
		cout << "3 - Listar Todos os Produtos Cadastrados" << endl;
		cout << "4 - Listar Detalhadamente os Produtos Cadastrados" << endl;
		cout << "0 - Voltar" << endl;
		cout << "Opcao: ";
		cin >> result;
		if(result<0 or result>4) cerr << "OPCAO INVALIDA! TENTE NOVAMENTE..." << endl;
	}while(result<0 or result>4);

	return result;
} 

/**
@brief Menu Fornecedores
@details Direciona para Cadastrar e Listar
@return Retorna a escolha do usuario
*/
int menuFornecedores(){
	int result;
	do{
		cout << "=======================================" << endl;
		cout << "--- Menu de Fornecedores ---" << endl;
		cout << "1 - Cadastrar Fornecimento" << endl;
		cout << "2 - Listar Todos os Fornecimentos Encontrados" << endl;
		cout << "0 - Voltar" << endl;
		cout << "Opcao: ";
		cin >> result;
		if(result<0 or result>2) cerr << "OPCAO INVALIDA! TENTE NOVAMENTE..." << endl;
	}while(result<0 or result>2);

	return result;
}

/**
@brief Menu Nota Fiscal
@details Direciona para Listar Notas Fiscais
@return Retorna a escolha do usuario
*/
int menuNotaFiscal(){
	int result;
	do{
		cout << "=======================================" << endl;
		cout << "--- Menu de Notas Fiscais ---" << endl;
		cout << "1 - Listar Notas Fiscais" << endl;
		cout << "0 - Voltar" << endl;
		cout << "Opcao: ";
		cin >> result;
		if(result<0 or result>1) cerr << "OPCAO INVALIDA! TENTE NOVAMENTE..." << endl;
	}while(result<0 or result>1);

	return result;
} 


/**
@brief Menu Carrinho
@details Direciona para Carrinho de compra, no qual pode-se listar, adicionar ao carrinho, remover ou finalizar a compra
@return Retorna a escolha do usuario
*/
int menuCarrinho(){
	int result;
	do{
		cout << "=======================================" << endl;
		cout << "--- Menu de Carrinho ---" << endl;
		cout << "1 - Adicionar ao Carrinho" << endl;
		cout << "2 - Remover do Carrinho" << endl;
		cout << "3 - Listar Carrinho" << endl;
		cout << "4 - Finalizar compra" << endl;
		cout << "0 - Voltar" << endl;
		cout << "Opcao: ";
		cin >> result;
		if(result<0 or result>4) cerr << "OPCAO INVALIDA! TENTE NOVAMENTE..." << endl;
	}while(result<0 or result>4);

	return result;
} 

/**
@brief Menu Opcoes Produtos
@details Direciona para uma das opcoes de produtos
@return Retorna a escolha do usuario
*/
int menuOpcoesProdutos(){
	int result;
	do{
		cout << "=======================================" << endl;
		cout << "--- Produtos ---" << endl;
		cout << "Qual tipo de produto deseja? " << endl;
		cout << "1 - Bebida" << endl;
		cout << "2 - CD" << endl;
		cout << "3 - Doce" << endl;
		cout << "4 - DVD" << endl;
		cout << "5 - Fruta" << endl;
		cout << "6 - Livro" << endl;
		cout << "7 - Salgado" << endl;
		cout << "0 - Voltar" << endl;
		cout << "Opcao: ";
		cin >> result;
		if (result<0 or result>7) cerr << "OPCAO INVALIDA! TENTE NOVAMENTE..." << endl;
	}while(result<0 or result>7);
	return result;
}

//menu
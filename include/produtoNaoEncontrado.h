/**
 * @file	produtoNaoEncontrado.h
 * @brief	Definicao da classe de tratamento de excecao para resolver casos de impressao de TED que estejam vazias
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	25/06/2017
 * @date	25/06/2017
 */
#ifndef _PRODUTO_NAO_ENCONTRADO_H_
#define _PRODUTO_NAO_ENCONTRADO_H_

#include <exception>
using std::exception;


/** 
 * @class 	ProdutoNaoEncontradoNaLista produtoNaoEncontrado.h
 * @brief 	Classe que representa uma excecao para imprimir TED vazia
 */
class ProdutoNaoEncontradoNaLista : exception {
public:
	/** @return Retorna a excecao*/
	const char* what(){
		return "OPS! Produto nao encontrado na lista! Nada a fazer...";
	}
};

#endif
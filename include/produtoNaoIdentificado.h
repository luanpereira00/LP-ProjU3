/**
 * @file	produtoNaoIdentificado.h
 * @brief	Definicao da classe de tratamento de excecao para resolver casos de impressao de TED que estejam vazias
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	25/06/2017
 * @date	25/06/2017
 */
#ifndef _PRODUTO_NAO_IDENTIFICADO_H_
#define _PRODUTO_NAO_IDENTIFICADO_H_

#include <exception>
using std::exception;



/** 
 * @class 	ProdutoNaoIdentificado produtoNaoIdentificado.h
 * @brief 	Classe que representa uma excecao para imprimir TED vazia
 */
class ProdutoNaoIdentificado : exception {
public:
	/** @return Retorna a excecao*/
	const char* what(){
		return "Produto nao identificado! Nada a fazer...";
	}
};

#endif
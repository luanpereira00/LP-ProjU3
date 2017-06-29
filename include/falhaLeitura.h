/**
 * @file	falhaLeitura.h
 * @brief	Definicao da classe de tratamento de excecao para resolver casos de impressao de TED que estejam vazias
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	25/06/2017
 * @date	25/06/2017
 */
#ifndef _FALHA_LEITURA_H_
#define _FALHA_LEITURA_H_

#include <exception>
using std::exception;



/** 
 * @class 	FalhaDeLeitura falhaLeitura.h
 * @brief 	Classe que representa uma excecao para imprimir TED vazia
 */
class FalhaDeLeitura : exception {
public:
	/** @return Retorna a excecao*/
	const char* what(){
		return "OPS! Falha de Leitura... Tente novamente!";
	}
};

#endif
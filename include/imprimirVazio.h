/**
 * @file	imprimirVazio.h
 * @brief	Definicao da classe de tratamento de excecao para resolver casos de impressao de TED que estejam vazias
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	25/06/2017
 * @date	25/06/2017
 */
#ifndef _IMPRIMIR_VAZIO_H_
#define _IMPRIMIR_VAZIO_H_

#include <exception>
using std::exception;



/** 
 * @class 	ImprimirTEDVazio imprimirVazio.h
 * @brief 	Classe que representa uma excecao para imprimir TED vazia
 */
class ImprimirTEDVazio : exception {
public:
	/** @return Retorna a excecao*/
	const char* what(){
		return "Impossivel imprimir TED: TED vazio!";
	}
};

#endif
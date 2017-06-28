/**
 * @file	removerVazio.h
 * @brief	Definicao da classe de tratamento de excecao para resolver casos de remocao de elementos em TEDs que estejam vazias
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	25/06/2017
 * @date	25/06/2017
 */
#ifndef _REMOVER_VAZIO_H_
#define _REMOVER_VAZIO_H_


/** 
 * @class 	RemoverDeTEDVazio removerVazio.h
 * @brief 	Classe que representa uma excecao para remover elementos de uma TED vazia
 */
class RemoverDeTEDVazio : public exception {
public:
	/** @return Retorna a excecao*/
	const char* what(){
		return "Impossivel remover elemento: TED vazio!";
	}
};


#endif
/**
 * @file	impossivelRemover.h
 * @brief	Definicao da classe de tratamento de excecao para resolver casos de remocao de elementos em TEDs que estejam vazias
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	25/06/2017
 * @date	25/06/2017
 */
#ifndef _IMPOSSIVEL_REMOVER_H_
#define _IMPOSSIVEL_REMOVER_H_


/** 
 * @class 	ImpossivelRemoverElemento impossivelRemover.h
 * @brief 	Classe que representa uma excecao para remover elementos de uma TED vazia
 */
class ImpossivelRemoverElemento : public exception {
public:
	/** @return Retorna a excecao*/
	const char* what(){
		return "Impossivel remover elemento: Nao pertence a lista!";
	}
};


#endif
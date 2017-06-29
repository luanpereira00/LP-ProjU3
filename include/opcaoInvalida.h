/**
 * @file	opcaoInvalida.h
 * @brief	Definicao da classe de tratamento de excecao para resolver casos de opcoes de menus invalidas
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	25/06/2017
 * @date	25/06/2017
 */
#ifndef _OPCAO_INVALIDA_H_
#define _OPCAO_INVALIDA_H_


/** 
 * @class 	opcaoInvalida opcaoInvalida.h
 * @brief 	Classe que representa uma excecao para opcoes invalidas de menus
 */
class opcaoInvalida : public exception {
public:
	/** @return Retorna a excecao*/
	const char* what(){
		return "Opcao invalida! Tente novamente...";
	}
};


#endif
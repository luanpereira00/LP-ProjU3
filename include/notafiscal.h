/**
 * @file	notafiscal.h
 * @brief	Definicao da classe NotaFiscal para representar uma nota fiscal
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */
#ifndef NOTAFISCAL_H
#define NOTAFISCAL_H

#include "estoque.h"

#include <string>
using std::to_string;
using std::string;



/** 
 * @class 	NotaFiscal notafiscal.h
 * @brief 	Classe que representa NotaFiscal
 * @details A nota fiscal somente eh exibida
 */
class NotaFiscal : public Estoque {
public:
	/**@brief Ler notas da memoria e as exibe */
	void lerArquivo();
};
#endif
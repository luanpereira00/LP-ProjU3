/**
 * @file	pereciveis.cpp
 * @brief	Implementacoes da classe mae Pereciveis
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#include "pereciveis.h"
#include "data.h"

/**@brief Construtor padrao*/
Pereciveis::Pereciveis(){
	Data d;
	setValidade(d);
}

/**@brief Destrutor padrao*/
Pereciveis::~Pereciveis(){
	//FAZ NADA
}

/**@return Retorna a data de validade */
Data* Pereciveis::getValidade(){ return &dataDeValidade; }

/**@brief Atualiza a data de validade 
*@param A nova data de validade */
void Pereciveis::setValidade(Data d){ dataDeValidade = d; }

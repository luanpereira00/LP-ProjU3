/**
 * @file	pereciveis.h
 * @brief	Definicao da classe mae Pereciveis para representar um perecivel
 * @details O atributo de um Perecivel eh a data de validade
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#ifndef PERECIVEIS_H
#define PERECIVEIS_H

#include "data.h"

/** 
 * @class 	Pereciveis pereciveis.h
 * @brief 	Classe que representa Pereciveis
 * @details O atributo de um Perecivel eh a data de validade
 */
class Pereciveis {
protected: 
	Data dataDeValidade; /**< A data de validade*/

public:
	/**@brief Construtor padrao*/
	Pereciveis();

	/**@brief Destrutor padrao*/
	~Pereciveis();

	/**@return Retorna a data de validade */
	Data* getValidade();

	/**@brief Atualiza a data de validade 
	*@param A nova data de validade */
	void setValidade(Data d);
};

#endif
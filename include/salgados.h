/**
 * @file	salgados.h
 * @brief	Definicao da classe Salgados para representar produtos do tipo Salgado
 * @details Os atributos de um Salgado sao a qtdSodio, ter gluten, ter lactose
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#ifndef SALGADOS_H
#define SALGADOS_H

#include <ostream> 
using std::ostream; 

#include <istream> 
using std::istream;

#include <string>
using std::string;

#include "data.h"
#include "pereciveis.h"
#include "produtos.h"

/** 
 * @class 	Salgados salgados.h
 * @brief 	Classe que representa Salgados
 * @details Os atributos de um Salgado sao a qtdSodio, ter gluten, ter lactose. Herda atributos e métodos de Produtos e Pereciveis.
 */
class Salgados : public Produtos, public Pereciveis {
private:
	float qtdSodio; /**< A quantidade de sodio*/
	bool gluten; /**< Informacao sobre conter gluten*/
	bool lactose; /**< Informacao sobre conter lactose*/

	/**@brief Imprime um salgado na formatacao "tipo;chave;nome;preco;qtd;sodio;gluten;lactose;validade"
	*@param os Referencia para o stream de saida 
	*@return Retorna a stream de saida */
	ostream& print(ostream& os){
		os << getTipo() << ";";
		os << getChave() << ";"; 	
		os << getNomeProd() << ";"; 	
		os << getPrecoUnit() << ";";
		os << getQtdEstoque() << ";";
		os << getQtdSodio() << ";";
		os << getGluten() << ";";
		os << getLactose() << ";";
		os << *(getValidade());
		return os; 
	};

	/**@brief Le um salgado na formatacao "tipo;chave;nome;preco;qtd;sodio;gluten;lactose;validade"
	*@param is Referencia para o stream de entrada 
	*@return Retorna a stream de entrada */
	istream& read(istream& is){
		string aux; 
		Data d;

		getline(is, aux, ';'); 	
		setChave(atoi(aux.c_str())); 	
		getline(is, aux, ';'); 	
		setNomeProd(aux); 	
		getline(is, aux, ';'); 	
		setPrecoUnit(atof(aux.c_str()));
		getline(is, aux, ';');
		setQtdEstoque(atoi(aux.c_str())); 
		getline(is, aux, ';'); 	
		setQtdSodio(atof(aux.c_str())); 
		getline(is, aux, ';'); 	
		setGluten(atoi(aux.c_str()));
		getline(is, aux, ';'); 	
		setLactose(atoi(aux.c_str()));
		getline(is, aux); 
		d.string2Data(aux);
		setValidade(d);	
		return is; 
	};

public:
	/**@brief Construtor padrao*/
	Salgados();

	/**@brief Destrutor padrao*/
	~Salgados();

	/**@brief Construtor copia 
	*@param a Elemento que sera usado para criacao*/
	Salgados(Salgados &a);

	/**@return Retorna a quantidade de sodio*/
	float getQtdSodio();

	/**@return Retorna bool para ter gluten */
	bool getGluten();

	/**@return Retorna bool para ter lactose */
	bool getLactose();

	/**@brief Atualiza a quantidade de sodio
	*@param s A nova quantidade de sodio*/
	void setQtdSodio(float s);

	/**@brief Atualiza a informacao sobre gluten
	*@param gt A informacao para atualizar */
	void setGluten(bool gt);

	/**@brief Atualiza a informacao sobre lactose
	*@param lt A informacao para atualizar */
	void setLactose(bool lt);

	/**@brief Cria um salgado
	*param key A chave que sera associada ao salgado */
	void criar(int key);
};

#endif
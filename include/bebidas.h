/**
 * @file	bebidas.h
 * @brief	Definicao da classe Bebidas para representar produtos do tipo Bebida
 * @details Os atributos de uma Bebida sao o teorAlcoolico, a qtdAcucar, volumeTotal
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */
#ifndef BEBIDAS_H
#define BEBIDAS_H

#include <ostream> 
using std::ostream; 

#include <istream> 
using std::istream;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::getline;
using std::endl;

#include "data.h"
#include "pereciveis.h"
#include "produtos.h"

/** 
 * @class 	Bebidas bebidas.h
 * @brief 	Classe que representa Bebidas
 * @details Os atributos de uma Bebida sao o teorAlcoolico, a qtdAcucar, volumeTotal. Herda atributos e métodos de Produtos e Pereciveis.
 */
class Bebidas : public Produtos, public Pereciveis {
private:
	float teorAlcoolico; /**< O teor alcoolico da bebida (em %)*/
	float qtdAcucar; /**< A quantidade de acucar da bebida (em mm)*/
	int volumeTotal; /**< O volume total da bebida (em ml)*/

	/**@brief Imprime uma bebida na formatacao "tipo;chave;nome;preco;qtd;teorAlcoolico;qtdAcucar;volume;validade"
	*@param os Referencia para o stream de saida 
	*@return Retorna a stream de saida */
	ostream& print(ostream& os){
		os << getTipo() << ";";
		os << getChave() << ";"; 	
		os << getNomeProd() << ";"; 	
		os << getPrecoUnit() << ";";
		os << getQtdEstoque() << ";";
		os << getTeorAlcoolico() << ";"; 	
		os << getQtdAcucar() << ";";
		os << getVolumeTotal() << ";";
		
		os << *(getValidade());
		return os;
	};

	/**@brief Le uma bebida na formatacao "tipo;chave;nome;preco;qtd;teorAlcoolico;qtdAcucar;volume;validade"
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
		setTeorAlcoolico(atof(aux.c_str())); 
		getline(is, aux, ';'); 	
		setQtdAcucar(atof(aux.c_str()));
		getline(is, aux, ';'); 	
		setVolumeTotal(atoi(aux.c_str()));
		getline(is, aux); 
		d.string2Data(aux);
		setValidade(d);	
		return is; 
	};

public:
	/**@brief Construtor padrao*/
	Bebidas();

	/**@brief Destrutor padrao*/
	~Bebidas();

	/**@brief Construtor copia 
	*@param a Elemento que sera usado para criacao*/
	Bebidas(Bebidas &a);

	/**@return Retorna o teor alcoolico */
	float getTeorAlcoolico();

	/**@return Retorna a quantidade de acucar */
	float getQtdAcucar();

	/**@return Retorna o volume total */
	int getVolumeTotal();

	/**@brief Atualiza o teor alcoolico
	*@param t O novo teor alcoolico */
	void setTeorAlcoolico(float t);

	/**@brief Atualiza a quantidade de acucar
	*@param a A nova quantidade de acucar*/
	void setQtdAcucar(float a);
	
	/**@brief Atualiza o volume total
	*@param v O novo volume total*/
	void setVolumeTotal(int v);

	/**@brief Cria uma bebida
	*param key A chave que sera associada a bebida */
	void criar(int key);
};

#endif
/**
 * @file	produtos.cpp
 * @brief	Implementacoes da classe mae Produtos
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#include "produtos.h"

/**@brief Construtor padrao*/
Produtos::Produtos(){ 
	setTipo(0);
	setChave(0);
	setNomeProd("");
	setPrecoUnit(0);
	setQtdEstoque(0);
}

/**@brief Destrutor padrao*/
Produtos::~Produtos(){
	//Faz Nada
}

/**@return Retorna o tipo do produto */
int Produtos::getTipo(){ return tipo; }

/** @brief Atualiza o tipo 
	*@param t O novo tipo*/
void Produtos::setTipo(int t){tipo=t;}

/**@return Retorna a chave */
int Produtos::getChave(){ return chave; }

/**@return Retorna o nome do produto*/
string Produtos::getNomeProd(){ return nomeProduto; }

/**@return Retorna o preco unitario*/
float Produtos::getPrecoUnit(){ return precoUnitario; }

/**@return A quantidade em estoque*/
int Produtos::getQtdEstoque(){ return qtdEstoque; }

/**@brief Atualiza a chave
	*@param c A nova chave*/
void Produtos::setChave(int c) { chave = c; }

/**@brief Atualiza o nome
	*@param n O novo nome*/
void Produtos::setNomeProd(string n){ nomeProduto = n; }

/**@brief Atualiza o preco unitario
	*@param p O novo preco*/
void Produtos::setPrecoUnit(float p){ precoUnitario = p; }

/**@brief Atualiza a quantidade em estoque
	*@param e A nova quantidade*/
void Produtos::setQtdEstoque(int e){ qtdEstoque = e; }


/**@return Retorna a string do nome do tipo de acordo com o valor passado 
	*@param t O valor do tipo passado */
string Produtos::tipo2String(int t){
	switch(t){
		case 1:
			return "BEBIDA"; 
		break;
		case 2:
			return "CD"; 
		break;
		case 3:
			return "DOCE"; 
		break;
		case 4:
			return "DVD"; 
		break;
		case 5:
			return "FRUTA"; 
		break;
		case 6:
			return "LIVRO"; 
		break;
		case 7:
			return "SALGADO"; 
		break;
		default:
			return "ERRO";
		break;
	}
}

/**@brief Imprime os dados na tela de forma sanitizada */
void Produtos::imprimirTela(){
	cout << "---------------------------------------" << endl;
	//cout << "=======================================" << endl;
	cout << "Chave: " << getChave() << "\t"; 	
	cout << "Tipo: " << tipo2String(getTipo()) << endl;
	
	cout << "Nome do Produto: " <<getNomeProd() << endl; 	
	cout << "Preco unitario: " << getPrecoUnit() << endl;
	cout << "Quantidade: " << getQtdEstoque() << endl;
}


/*bool Produtos::operator<(Produtos p) {
	if(chave<p.chave) return true;
	else return false;
}*/

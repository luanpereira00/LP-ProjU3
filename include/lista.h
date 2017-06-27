/**
 * @file	lista.h
 * @brief	Definicao da classe lista para representar uma lista ligada ordenada duplamente encadeada de dados
 * @details Os atributos de uma lista sao as sentinelas de inicio e de fim
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	17/05/2017
 * @date	17/05/2017
 */
#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <fstream>
using std::ofstream;
using std::ifstream;

/** @brief Declaracao de template para o tipo T*/
template <typename T>

/** 
* @struct node lista.h
* @brief Um struct para representar os nos de lista ligada
*/
struct node{
	T dado; /**< Elemento generico do no*/
	node* prox; /**< Apontador para o proximo no*/
	node* anter; /**< Apontador para o no anterior*/
};

/** 
 * @class 	lista lista.h
 * @brief 	Classe que representa uma lista ligada ordenada duplamente encadeada de dados
 * @details Os atributos de uma lista sao as sentinelas de inicio e de fim 
 */
template <typename T>
class lista{
private:
	node<T>* inicio; /**< Sentinela de inicio da lista*/
	node<T>* fim; /**< Sentinela de fim da lista*/

public:
	/** @brief Construtor padrao */
	lista(){
		inicio = new struct node<T>;
		fim = new struct node<T>;

	//	T padrao;

		inicio->dado=nullptr;
		inicio->prox=fim;
		inicio->anter=NULL;

		fim->dado=nullptr;
		fim->prox=NULL;
		fim->anter=inicio;
	}

	/** @brief Destrutor padrao */
	~lista(){
		node<T>* tmp = new node<T>;
		node<T>* aux = inicio;
		tmp->prox=inicio->prox;
		while(tmp->prox->prox){
			delete aux;
			aux = tmp->prox;
			tmp->prox=tmp->prox->prox;
		}
		delete aux;
		delete tmp->prox;;
		delete tmp;
	}

	/** @return Retorna a sentinela de inicio da lista ligada*/
	node<T>* getInicio(){
		return inicio;
	}

	/** @return Retorna a sentinela de fim da lista ligada*/
	node<T>* getFim(){
		return fim;
	}

	/** 
	* @brief Insere um elemento do tipo T ordenadamente na lista
	* @param el O elemento que sera inserido na lista 
	*/
	void inserir(T el){
		//cout << "Inserindo o elemento " << el << endl;
		node<T>* it = buscar(el);
		node<T>* tmp = new node<T>;
		tmp->dado=el;
		tmp->prox=it->prox;
		tmp->anter=it;

		it->prox->anter=tmp;
		it->prox=tmp;
	}

	/** 
	* @brief Remove um elemento da lista ligada. (Informa também caso o elemento nao exista)
	* @param el O elemento que sera removido da lista 
	*/
	void remover(T el){
		//cout << endl;
		//cout << "Removendo o elemento " << el << endl;
		node<T>* it = buscar(el);
		if(it->prox->dado==el){
			node<T>* tmp = new node<T>;
			tmp->prox=it->prox->prox;
			tmp->anter=it;

			delete it->prox; 

			it->prox=tmp->prox;
			it->prox->anter=tmp->anter;

			delete tmp; 
		}
		else cerr << "ERRO: Impossivel remover o elemento " << el << " (nao existe na lista)! ...Continuando operacoes" << endl;
	}

	/** 
	* @brief Destroi a lista removendo todos os elementos
	*/
	void destruir(){
		//cout << endl;
		//cout << "Removendo o elemento " << el << endl;
		node<T>* it = inicio;
		while(it->prox->prox){
			node<T>* tmp = new node<T>;
			tmp->prox=it->prox->prox;
			tmp->anter=it;

			delete it->prox; 

			it->prox=tmp->prox;
			it->prox->anter=tmp->anter;

			delete tmp; 
		}
	}

	/** @brief Imprime toda a lista ligada em arquivo*/
	void imprimir(){
		node<T>* it = inicio;
		while(it->prox->prox){
			cout << *(it->prox->dado) << endl;
			it=it->prox;
		}
	}

	/** @brief Imprime toda a lista ligada*/
	void imprimirTela(){
		node<T>* it = inicio;
		while(it->prox->prox){
			it->prox->dado->imprimirTela();
			it=it->prox;
		}
		cout << "---------------------------------------" << endl;
		//cout << "=======================================" << endl;
	}

	/** @brief Le de uma stream de dados e insere na lista*/
	/*void lerArquivo(ifstream *a){
		T el;
		int j, i = 0;
		*a >> j;
		while(i<j){
			*a >> *el;
			inserir(el);
			i++;
		}
	}*/

	/** @brief Passa para uma stream de dados os elementos da lista*/
	void imprimirArquivo(ofstream *a){
		node<T>* it = inicio;
		*a << contarElementos() << endl;
		while(it->prox->prox){
			*a << *(it->prox->dado) << endl;
			it=it->prox;
		}
	}

	/**@return Retorna a menor chave livre da lista */
	int getMinKeyFree(){
		node<T>* it = inicio;
		int i=1;
		while(it->prox->prox){
			if(it->prox->dado->getChave()==i){
				i++;
				it=it->prox;
			}
			else return i;
		}
		return i;
	}

	/** @brief Conta quantos elementos tem na lista*/
	int contarElementos(){
		node<T>* it = inicio;
		int i=0;
		while(it->prox->prox){
			i++;
			it=it->prox;
		}
		return i;
	}

	/** 
	* @brief Busca na lista ligada
	* @param el O elemento que sera buscado na lista 
	*/
	node<T>* buscar(T el){
		node<T>* it = inicio;
		while(it->prox->prox && it->prox->dado->getChave()<el->getChave()){
			it=it->prox;
		}
		return it;
	}

	/** 
	* @brief Busca na lista ligada
	* @param el O elemento que sera buscado na lista 
	*/
	node<T>* buscar(int key){
		node<T>* it = inicio;
		while(it->prox->prox && it->prox->dado->getChave()!=key){
			it=it->prox;
		}
		return it;
	}
};

#endif

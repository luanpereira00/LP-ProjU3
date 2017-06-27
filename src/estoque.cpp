/**
 * @file	estoque.cpp
 * @brief	Implementacao da classe Estoque para representar um estoque de produtos
 * @details Os atributos de um Estoque sao as listas de produtos e ultima chave primaria associada
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <string>
using std::to_string;
using std::string;

#include "estoque.h"
#include "menu.h"

/**@brief Construtor padrao*/
Estoque::Estoque(){
	ll_Prod = new lista<Produtos*>;
}

/**@brief Destrutor padrao*/
Estoque::~Estoque(){
	delete ll_Prod;
}

/**@return Retorna a lista de Prod */
lista<Produtos*> *Estoque::getListaProd(){ return ll_Prod; }

/**@brief Atualiza a lista de Prod 
	*@param ll A nova lista de prod*/
void Estoque::setListaProd(lista<Produtos*> *ll){ ll_Prod = ll;}

/**@brief Lista todo o estoque  */
void Estoque::listarEstoque(){ 
 	cout << "======================================" << endl;
	cout << "--- Lista de Estoque ---" << endl << endl;
	if(ll_Prod->contarElementos()>0) {
		//cout << "Lista de Prod: " << endl;
		ll_Prod->imprimirTela();
	} else cout << "A lista esta vazia..." << endl;
	//cout << "-----------------------" << endl;
}

/**@brief Lista todo o estoque detalhadamente */
void Estoque::listarEstoqueDetalhado(){ 
 	cout << "======================================" << endl;
	cout << "--- Lista de Estoque Detalhada ---" << endl << endl;
	if(ll_Prod->contarElementos()>0) {
		//cout << "Lista de Prod: " << endl;
		ll_Prod->imprimir();
	} else cout << "A lista esta vazia..." << endl;
	//cout << "-----------------------" << endl;
}

/**@brief Le os dados da memoria para inicializar o estoque  */
void Estoque::lerDados(){
	Bebidas *b;
	CDs *c;
	Doces *d;
	DVDs *v;
	Frutas *f;
	Livros *l;
	Salgados *s;

	string opening;
	int iter, qtdLista;
	string tipo;

	opening = "./data/listasProdutos/ll_Prod.csv";
	ifstream prod(opening);
	if(!prod) cerr << "Impossivel abrir o arquivo de Produtos!" << endl;
	else{
		iter = 0;
		prod>>qtdLista;
		//cout << qtdLista;
		prod.ignore();
		while(iter<qtdLista) {
			getline(prod, tipo, ';');
			if(tipo=="1"){
				b = new Bebidas;
				prod >> *b;
				//cout << *b << endl;
				getListaProd()->inserir(b);
			}else if (tipo=="2"){
				c = new CDs;
				prod >> *c;
				//cout << *c << endl;
				getListaProd()->inserir(c);
			}else if (tipo=="3"){
				d = new Doces;
				prod >> *d;
				//cout << *d << endl;
				getListaProd()->inserir(d);
			}else if (tipo=="4"){
				v = new DVDs;
				prod >> *v;
				//cout << *v << endl;
				getListaProd()->inserir(v);
			}else if (tipo=="5"){
				f = new Frutas;
				prod >> *f;
				//cout << *f << endl;
				getListaProd()->inserir(f);
			}else if (tipo=="6"){
				l = new Livros;
				prod >> *l;
				//cout << *l << endl;
				getListaProd()->inserir(l);
			}else if (tipo=="7"){
				s = new Salgados;
				prod >> *s;
				//cout << *s << endl;
				getListaProd()->inserir(s);
			}else {
				cerr << "ERRO - TIPO DE PRODUTO NAO IDENTIFICADO! NADA A FAZER..." << endl;
				//exit(1);
			}

			iter++;
		}
		prod.close();
	}
}

/**@brief Grava os dados do estoque na memoria  */
void Estoque::gravarDados(){
	string closing;

	closing = "./data/listasProdutos/ll_Prod.csv";
	ofstream prod(closing);
	ll_Prod->imprimirArquivo(&prod);
	prod.close();
}

/**@brief Cadastra um produto */
void Estoque::cadastrarProduto(){
	Bebidas *b;
	CDs *c;
	Doces *d;
	DVDs *v;
	Frutas *f;
	Livros *l;
	Salgados *s;
	int key = getListaProd()->getMinKeyFree();
	int prod = menuOpcoesProdutos(); 
	switch(prod){
		case 1:
			b = new Bebidas;		
			b->criar(key);		
			getListaProd()->inserir(b);
			cout << "Inserido com sucesso!" << endl;
		break;
		case 2:
			c = new CDs;
			c->criar(key);		
			getListaProd()->inserir(c);
			cout << "Inserido com sucesso!" << endl;
		break;
		case 3:
			d = new Doces;
			d->criar(key);		
			getListaProd()->inserir(d);
			cout << "Inserido com sucesso!" << endl;
		break;
		case 4:
			v = new DVDs;
			v->criar(key);		
			getListaProd()->inserir(v);
			cout << "Inserido com sucesso!" << endl;
		break;
		case 5:
			f = new Frutas;
			f->criar(key);		
			getListaProd()->inserir(f);
			cout << "Inserido com sucesso!" << endl;
		break;
		case 6:
			l = new Livros;
			l->criar(key);		
			getListaProd()->inserir(l);
			cout << "Inserido com sucesso!" << endl;
		break;
		case 7:
			s = new Salgados;
			s->criar(key);		
			getListaProd()->inserir(s);
			cout << "Inserido com sucesso!" << endl;
		break;
		case 0:
		break;
	}
}

/**@brief Remove um produto do cadastro */
void Estoque::removerProduto(){
	node<Produtos*>* P;
	int key;
	getListaProd()->imprimirTela();
	cout << "======================================" << endl;
	cout << "Digite a chave do produto para remover: ";
	cin >> key;

	P = getListaProd()->buscar(key);
	if(P->prox->prox){
		getListaProd()->remover(P->prox->dado);
		cout << "Removido com sucesso!" << endl;
	}
	else cerr << "PRODUTO NAO ENCONTRADO! NADA A FAZER..."<< endl;
}
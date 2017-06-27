/**
 * @file	notafiscal.cpp
 * @brief	Implementacao da classe NotaFiscal para representar uma nota fiscal
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#include "notafiscal.h"

/**@brief Ler notas da memoria e as exibe */
void NotaFiscal::lerArquivo(){
	cout << "======================================" << endl;
	cout << "--- Notas Fiscais Identificadas ---"<< endl;
	bool flag=true;
	int numArq=1;
	int qtdLista=0;
	int iter=0;
	bool find = false;
	string preco="0";
	string opening;
	string tipo="";

	Bebidas *b;
	CDs *c;
	Doces *d;
	DVDs *v;
	Frutas *f;
	Livros *l;
	Salgados *s;

	while(flag){
		opening = "./data/notasFiscais/"+to_string(numArq)+"_nota.csv";
		ifstream nota(opening);
		if(!nota) {
			flag = false;
			//if(!find) find = 
		}
		else{
			iter = 0;
			find = true;
			cout << "\t=== NOTA " << numArq << " ==="  << endl; 
			nota >> qtdLista;
			nota.ignore();
		//cout << qtdLista << endl;
			while(iter<qtdLista) {
				getline(nota, tipo, ';');
				if(tipo=="1"){
					b = new Bebidas;	
					nota >> *b;
					//cout << *b << endl;
					b->imprimirTela();
					delete b;
				}else if (tipo=="2"){
					c = new CDs;	
					nota >> *c;
					//cout << *c << endl;
					c->imprimirTela();
					delete c;
				}else if (tipo=="3"){
					d = new Doces;	
					nota >> *d;
					//cout << *d << endl;
					d->imprimirTela();
					delete d;
				}else if (tipo=="4"){
					v = new DVDs;	
					nota >> *v;
						//cout << *v << endl;
					v->imprimirTela();
					delete v;
				}else if (tipo=="5"){
					f = new Frutas;	
					nota >> *f;
						//cout << *f << endl;
					f->imprimirTela();
					delete f;
				}else if (tipo=="6"){
					l = new Livros;	
					nota >> *l;
						//cout << *l << endl;
					l->imprimirTela();
					delete l;
				}else if (tipo=="7"){
					s = new Salgados;	
					nota >> *s;
						//cout << *s << endl;
					s->imprimirTela();
					delete s;
				}else {
					cerr << "ERRO! NADA A FAZER..." <<endl;
					//exit(1);
				}

				iter++;
			}
			cout << "--------------------------------------" << endl;
			nota >> preco;
			cout << "........................ Preco: " << preco << endl;
			cout << "======================================" << endl;
			nota.close();
		}
		numArq++;
	}
	if(!find) cerr << "NENHUMA NOTA ENCONTRADA..." << endl;

	//int qtdNotas = verUltimaNotaFiscal();

}
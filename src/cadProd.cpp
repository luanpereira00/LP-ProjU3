/**
 * @file	cadProd.cpp
 * @brief	Implementação de funções que cadastram/adicionam w removem produtos de estoque/carrinho
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */
#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::getline;

#include <string>
using std::string;

#include <cstdlib>

#include "cadProd.h"

/**@brief Cadastra um produto no estoque */
void cadastrarProdutos(Estoque *e, int a){
	string auxS;
	float auxF;
	int auxI;
	Data dv;
	Bebidas b;
	CDs c;
	Doces d;
	DVDs v;
	Frutas f;
	Livros l;
	Salgados s;
	if(a!=0){
		cin.ignore();
		cout << "Digite o nome do produto: ";
		getline(cin, auxS);
		cout << "Digite o preco unitario do produto: ";
		cin >> auxF;
		cout << "Digite a quantidade em estoque do produto: ";
		cin >> auxI;
		switch(a){
			case 1: //BEBIDAS
				b.setChave(e->getLastKey()+1);
				b.setNomeProd(auxS);
				b.setPrecoUnit(auxF);
				b.setQtdEstoque(auxI);

				cout << "Digite o teor alcoolico da bebida: ";
				cin >> auxF;
				b.setTeorAlcoolico(auxF);

				cout << "Digite a quantidade de acucar da bebida: ";
				cin >> auxF;
				b.setQtdAcucar(auxF);

				cout << "Digite o volume total da bebida: ";
				cin >> auxI;
				b.setVolumeTotal(auxI);
				cout << "Digite a data de validade da bebida: ";
				cin >> auxS;
				dv.string2Data(auxS);
				b.setValidade(dv);

				e->setLastKey(e->getLastKey()+1);
				e->getListaBebidas()->inserir(b);
				cout << "Inserido com sucesso!" << endl;
			break;
			case 2: //CDS
				c.setChave(e->getLastKey()+1);
				c.setNomeProd(auxS);
				c.setPrecoUnit(auxF);
				c.setQtdEstoque(auxI);

				cin.ignore();
				cout << "Digite o nome do album do CD: ";
				getline(cin, auxS);
				c.setAlbum(auxS);

				//cin.ignore();
				cout << "Digite o estilo do CD: ";
				getline(cin, auxS);
				c.setEstilo(auxS);

				//cin.ignore();
				cout << "Digite o nome do artista do CD: ";
				getline(cin, auxS);
				c.setArtista(auxS);

				e->setLastKey(e->getLastKey()+1);
				e->getListaCDs()->inserir(c);
				cout << "Inserido com sucesso!" << endl;
			break;
			case 3: //DOCES
				d.setChave(e->getLastKey()+1);
				d.setNomeProd(auxS);
				d.setPrecoUnit(auxF);
				d.setQtdEstoque(auxI);

				cout << "Digite a quantidade de acucar no doce: ";
				cin >> auxF;
				d.setQtdAcucar(auxF);

				cout << "Digite 1(true) ou 0(false) para ter gluten: ";
				cin >> auxI;
				//criar condicional
				d.setGluten(auxI);

				cout << "Digite 1(true) ou 0(false) para ter lactose: ";
				cin >> auxI;
				d.setLactose(auxI);

				cout << "Digite a data de validade do doce: ";
				cin >> auxS;
				dv.string2Data(auxS);
				d.setValidade(dv);

				e->setLastKey(e->getLastKey()+1);
				e->getListaDoces()->inserir(d);
				cout << "Inserido com sucesso!" << endl;
			break;
			case 4: //DVDS
				v.setChave(e->getLastKey()+1);
				v.setNomeProd(auxS);
				v.setPrecoUnit(auxF);
				v.setQtdEstoque(auxI);

				cin.ignore();
				cout << "Digite o titulo do DVD: ";
				getline(cin, auxS);
				v.setTitulo(auxS);

				//cin.ignore();
				cout << "Digite o genero do DVD: ";
				getline(cin, auxS);
				v.setGenero(auxS);

				cout << "Digite a duracao do DVD: ";
				cin >> auxI;
				v.setMinutos(auxI);

				e->setLastKey(e->getLastKey()+1);
				e->getListaDVDs()->inserir(v);
				cout << "Inserido com sucesso!" << endl;
			break;
			case 5: //FRUTAS
				f.setChave(e->getLastKey()+1);
				f.setNomeProd(auxS);
				f.setPrecoUnit(auxF);
				f.setQtdEstoque(auxI);

				cin.ignore();
				cout << "Digite o lote da fruta: ";
				getline(cin, auxS);
				f.setLote(auxS);

				cout << "Digite a data do lote: ";
				cin >> auxS;
				dv.string2Data(auxS);
				f.setValidade(dv);

				cout << "Digite a data de validade do doce: ";
				cin >> auxS;
				dv.string2Data(auxS);
				f.setValidade(dv);

				e->setLastKey(e->getLastKey()+1);
				e->getListaFrutas()->inserir(f);
				cout << "Inserido com sucesso!" << endl;
			break;
			case 6: //LIVROS
				l.setChave(e->getLastKey()+1);
				l.setNomeProd(auxS);
				l.setPrecoUnit(auxF);
				l.setQtdEstoque(auxI);

				cin.ignore();
				cout << "Digite o titulo do livro: ";
				getline(cin, auxS);
				l.setTitulo(auxS);

				//cin.ignore();
				cout << "Digite o autor do livro: ";
				getline(cin, auxS);
				l.setAutor(auxS);

				//cin.ignore();
				cout << "Digite a editora do livro: ";
				getline(cin, auxS);
				l.setEditora(auxS);

				cout << "Digite o ano de lancamento: ";
				cin >> auxI;
				l.setAno(auxI);

				e->setLastKey(e->getLastKey()+1);
				e->getListaLivros()->inserir(l);
				cout << "Inserido com sucesso!" << endl;
			break;
			case 7: //SALGADOS
				s.setChave(e->getLastKey()+1);
				s.setNomeProd(auxS);
				s.setPrecoUnit(auxF);
				s.setQtdEstoque(auxI);

				cout << "Digite a quantidade de sodio no salgado: ";
				cin >> auxF;
				s.setQtdSodio(auxF);

				cout << "Digite 1(true) ou 0(false) para ter gluten: ";
				cin >> auxI;
				//criar condicional
				s.setGluten(auxI);

				cout << "Digite 1(true) ou 0(false) para ter lactose: ";
				cin >> auxI;
				s.setLactose(auxI);

				cout << "Digite a data de validade do salgado: ";
				cin >> auxS;
				dv.string2Data(auxS);
				s.setValidade(dv);

				e->setLastKey(e->getLastKey()+1);
				e->getListaSalgados()->inserir(s);
				cout << "Inserido com sucesso!" << endl;
			break;
		}
		
		//doces
		//frutas
		//libros
		//salgados
	}
}

/**@brief Remove um produto do estoque */
void removerProduto(Estoque *e, int a){
	cout << "--- Produtos Cadastrados ---" << endl;
	int key;
	if(a!=0){
		switch(a){
			case 1: //BEBIDAS

				e->getListaBebidas()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				e->getListaBebidas()->remover(key);
			break;
			case 2: //CDS
				e->getListaCDs()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				e->getListaCDs()->remover(key);
			break;
			case 3: //DOCES
				e->getListaDoces()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				e->getListaDoces()->remover(key);
			break;
			case 4: //DVDS
				e->getListaDVDs()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				e->getListaDVDs()->remover(key);
			break;
			case 5: //FRUTAS
				e->getListaFrutas()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				e->getListaFrutas()->remover(key);
			break;
			case 6: //LIVROS
				e->getListaLivros()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				e->getListaLivros()->remover(key);
			break;
			case 7: //SALGADOS
				e->getListaSalgados()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				e->getListaSalgados()->remover(key);
			break;
		}
	}
}


/**@brief Adiciona um produto ao carrinho */
void adicionarAoCarrinho(Estoque *e, Carrinho *carrinho, int a){
	cout << "--- Produtos Cadastrados ---" << endl;
	int key;
	Bebidas b;
	node<Bebidas>* B;
	CDs c;
	node<CDs>* C;
	Doces d;
	node<Doces>* D;
	DVDs v;
	node<DVDs>* V;
	Frutas f;
	node<Frutas>* F;
	Livros l;
	node<Livros>* L;
	Salgados s;
	node<Salgados>* S;

	if(a!=0){
		switch(a){
			case 1: //BEBIDAS
				e->getListaBebidas()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				B = e->getListaBebidas()->buscar(key);
				if(B->prox->prox){
					b = B->prox->dado;
					if(B->prox->dado.getQtdEstoque()>0){
						B->prox->dado.setQtdEstoque(B->prox->dado.getQtdEstoque()-1);			
						carrinho->calcularCompra(b.getPrecoUnit());
						if(carrinho->getListaBebidas()->getQtdKey(key)==0) {
							b.setQtdEstoque(1);
							carrinho->getListaBebidas()->inserir(b);
							cout << "ADICIONADO COM SUCESSO!" << endl;
						}else {
							carrinho->getListaBebidas()->buscar(key)->prox->dado.setQtdEstoque(carrinho->getListaBebidas()->buscar(key)->prox->dado.getQtdEstoque()+1);
						}
					}else cerr << "PRODUTO FORA DE ESTOQUE! NADA A FAZER..." << endl;
				}
			break;
			case 2: //CDS
				e->getListaCDs()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				C = e->getListaCDs()->buscar(key);
				if(C->prox->prox){
					c = C->prox->dado;
					if(C->prox->dado.getQtdEstoque()>0){
						C->prox->dado.setQtdEstoque(C->prox->dado.getQtdEstoque()-1);			
						carrinho->calcularCompra(c.getPrecoUnit());
						if(carrinho->getListaCDs()->getQtdKey(key)==0) {
							c.setQtdEstoque(1);
							carrinho->getListaCDs()->inserir(c);
							cout << "ADICIONADO COM SUCESSO!" << endl;
						}else {
							carrinho->getListaCDs()->buscar(key)->prox->dado.setQtdEstoque(carrinho->getListaCDs()->buscar(key)->prox->dado.getQtdEstoque()+1);
						}
					}else cerr << "PRODUTO FORA DE ESTOQUE! NADA A FAZER..." << endl;
				}
			break;
			case 3: //DOCES
				e->getListaDoces()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				D = e->getListaDoces()->buscar(key);
				if(D->prox->prox){
					d = D->prox->dado;
					if(D->prox->dado.getQtdEstoque()>0){
						D->prox->dado.setQtdEstoque(D->prox->dado.getQtdEstoque()-1);			
						carrinho->calcularCompra(d.getPrecoUnit());
						if(carrinho->getListaDoces()->getQtdKey(key)==0) {
							d.setQtdEstoque(1);
							carrinho->getListaDoces()->inserir(d);
							cout << "ADICIONADO COM SUCESSO!" << endl;
						}else {
							carrinho->getListaDoces()->buscar(key)->prox->dado.setQtdEstoque(carrinho->getListaDoces()->buscar(key)->prox->dado.getQtdEstoque()+1);
						}
					}else cerr << "PRODUTO FORA DE ESTOQUE! NADA A FAZER..." << endl;
				}
			break;
			case 4: //DVDS
				e->getListaDVDs()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				V = e->getListaDVDs()->buscar(key);
				if(V->prox->prox){
					v = V->prox->dado;
					if(V->prox->dado.getQtdEstoque()>0){
						V->prox->dado.setQtdEstoque(V->prox->dado.getQtdEstoque()-1);			
						carrinho->calcularCompra(v.getPrecoUnit());
						if(carrinho->getListaDVDs()->getQtdKey(key)==0) {
							v.setQtdEstoque(1);
							carrinho->getListaDVDs()->inserir(v);
							cout << "ADICIONADO COM SUCESSO!" << endl;
						}else {
							carrinho->getListaDVDs()->buscar(key)->prox->dado.setQtdEstoque(carrinho->getListaDVDs()->buscar(key)->prox->dado.getQtdEstoque()+1);
						}
					}else cerr << "PRODUTO FORA DE ESTOQUE! NADA A FAZER..." << endl;
				}
			break;
			case 5: //FRUTAS
				e->getListaFrutas()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				F = e->getListaFrutas()->buscar(key);
				if(F->prox->prox) {
					f = F->prox->dado;
					if(F->prox->dado.getQtdEstoque()>0){
						F->prox->dado.setQtdEstoque(F->prox->dado.getQtdEstoque()-1);			
						carrinho->calcularCompra(f.getPrecoUnit());
						if(carrinho->getListaFrutas()->getQtdKey(key)==0) {
							f.setQtdEstoque(1);
							carrinho->getListaFrutas()->inserir(f);
							cout << "ADICIONADO COM SUCESSO!" << endl;
						}else {
							carrinho->getListaFrutas()->buscar(key)->prox->dado.setQtdEstoque(carrinho->getListaFrutas()->buscar(key)->prox->dado.getQtdEstoque()+1);
						}
					}else cerr << "PRODUTO FORA DE ESTOQUE! NADA A FAZER..." << endl;
				}
			break;
			case 6: //LIVROS
				e->getListaLivros()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				L = e->getListaLivros()->buscar(key);
				if(L->prox->prox){
					l = L->prox->dado;
					if(L->prox->dado.getQtdEstoque()>0){
						L->prox->dado.setQtdEstoque(L->prox->dado.getQtdEstoque()-1);			
						carrinho->calcularCompra(l.getPrecoUnit());
						if(carrinho->getListaLivros()->getQtdKey(key)==0) {
							l.setQtdEstoque(1);
							carrinho->getListaLivros()->inserir(l);
							cout << "ADICIONADO COM SUCESSO!" << endl;
						}else {
							carrinho->getListaLivros()->buscar(key)->prox->dado.setQtdEstoque(carrinho->getListaLivros()->buscar(key)->prox->dado.getQtdEstoque()+1);
						}
					}else cerr << "PRODUTO FORA DE ESTOQUE! NADA A FAZER..." << endl;
				}
			break;
			case 7: //SALGADOS
				e->getListaSalgados()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				S = e->getListaSalgados()->buscar(key);
				if(S->prox->prox){
					s = S->prox->dado;
					if(S->prox->dado.getQtdEstoque()>0){
						S->prox->dado.setQtdEstoque(S->prox->dado.getQtdEstoque()-1);			
						carrinho->calcularCompra(s.getPrecoUnit());
						if(carrinho->getListaSalgados()->getQtdKey(key)==0) {
							s.setQtdEstoque(1);
							carrinho->getListaSalgados()->inserir(s);
							cout << "ADICIONADO COM SUCESSO!" << endl;
						}else {
							carrinho->getListaSalgados()->buscar(key)->prox->dado.setQtdEstoque(carrinho->getListaSalgados()->buscar(key)->prox->dado.getQtdEstoque()+1);
						}
					}else cerr << "PRODUTO FORA DE ESTOQUE! NADA A FAZER..." << endl;
				}
			break;
		}
	}
}

/**@brief Remove um produto do carrinho */
void removerDoCarrinho(Estoque *e, Carrinho *carrinho, int a){
	//cout << "--- Produtos Cadastrados ---" << endl;
	int key;
	node<Bebidas>* B;
	node<CDs>* C;
	node<Doces>* D;
	node<DVDs>* V;
	node<Frutas>* F;
	node<Livros>* L;
	node<Salgados>* S;
	
	if(a!=0){
		//carrinho->listar();
		switch(a){
			case 1: //BEBIDAS
				carrinho->getListaBebidas()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				B = e->getListaBebidas()->buscar(key);
				if(B->prox->prox and carrinho->getListaBebidas()->buscar(key)->prox->prox){
					B->prox->dado.setQtdEstoque(B->prox->dado.getQtdEstoque()+carrinho->getListaBebidas()->buscar(key)->prox->dado.getQtdEstoque());
					carrinho->calcularCompra((-1)*carrinho->getListaBebidas()->buscar(key)->prox->dado.getPrecoUnit()*carrinho->getListaBebidas()->buscar(key)->prox->dado.getQtdEstoque());
					carrinho->getListaBebidas()->remover(key);
				}
				
				
			break;
			case 2: //CDS
				carrinho->getListaCDs()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				C = e->getListaCDs()->buscar(key);
				if(C->prox->prox and carrinho->getListaCDs()->buscar(key)->prox->prox){
					C->prox->dado.setQtdEstoque(C->prox->dado.getQtdEstoque()+carrinho->getListaCDs()->buscar(key)->prox->dado.getQtdEstoque());
					carrinho->calcularCompra((-1)*carrinho->getListaCDs()->buscar(key)->prox->dado.getPrecoUnit()*carrinho->getListaCDs()->buscar(key)->prox->dado.getQtdEstoque());
					carrinho->getListaCDs()->remover(key);
				}
			break;
			case 3: //DOCES
				carrinho->getListaDoces()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				D = e->getListaDoces()->buscar(key);
				if(D->prox->prox and carrinho->getListaDoces()->buscar(key)->prox->prox){
					D->prox->dado.setQtdEstoque(D->prox->dado.getQtdEstoque()+carrinho->getListaCDs()->buscar(key)->prox->dado.getQtdEstoque());
					carrinho->calcularCompra((-1)*carrinho->getListaDoces()->buscar(key)->prox->dado.getPrecoUnit()*carrinho->getListaDoces()->buscar(key)->prox->dado.getQtdEstoque());
					carrinho->getListaDoces()->remover(key);
				}
			break;
			case 4: //DVDS
				carrinho->getListaDVDs()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				V = e->getListaDVDs()->buscar(key);
				if(V->prox->prox and carrinho->getListaDVDs()->buscar(key)->prox->prox){
					V->prox->dado.setQtdEstoque(V->prox->dado.getQtdEstoque()+carrinho->getListaDVDs()->buscar(key)->prox->dado.getQtdEstoque());
					carrinho->calcularCompra((-1)*carrinho->getListaDVDs()->buscar(key)->prox->dado.getPrecoUnit()*carrinho->getListaDVDs()->buscar(key)->prox->dado.getQtdEstoque());
					carrinho->getListaDVDs()->remover(key);
				}
			break;
			case 5: //FRUTAS
				carrinho->getListaFrutas()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				F = e->getListaFrutas()->buscar(key);
				if(F->prox->prox and carrinho->getListaFrutas()->buscar(key)->prox->prox){
					F->prox->dado.setQtdEstoque(F->prox->dado.getQtdEstoque()+carrinho->getListaFrutas()->buscar(key)->prox->dado.getQtdEstoque());
					carrinho->calcularCompra((-1)*carrinho->getListaFrutas()->buscar(key)->prox->dado.getPrecoUnit()*carrinho->getListaFrutas()->buscar(key)->prox->dado.getQtdEstoque());
					carrinho->getListaFrutas()->remover(key);
				}
			break;
			case 6: //LIVROS
				carrinho->getListaLivros()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				L = e->getListaLivros()->buscar(key);
				if(L->prox->prox and carrinho->getListaLivros()->buscar(key)->prox->prox){
					L->prox->dado.setQtdEstoque(L->prox->dado.getQtdEstoque()+carrinho->getListaLivros()->buscar(key)->prox->dado.getQtdEstoque());
					carrinho->calcularCompra((-1)*carrinho->getListaLivros()->buscar(key)->prox->dado.getPrecoUnit()*carrinho->getListaLivros()->buscar(key)->prox->dado.getQtdEstoque());
					carrinho->getListaLivros()->remover(key);
				}
			break;
			case 7: //SALGADOS
				carrinho->getListaSalgados()->imprimirTela();
				cout << "Digite a chave de busca: ";
				cin >> key;
				S = e->getListaSalgados()->buscar(key);
				if(S->prox->prox and carrinho->getListaSalgados()->buscar(key)->prox->prox){
					S->prox->dado.setQtdEstoque(S->prox->dado.getQtdEstoque()+carrinho->getListaSalgados()->buscar(key)->prox->dado.getQtdEstoque());
					carrinho->calcularCompra((-1)*carrinho->getListaSalgados()->buscar(key)->prox->dado.getPrecoUnit()*carrinho->getListaSalgados()->buscar(key)->prox->dado.getQtdEstoque());
					carrinho->getListaSalgados()->remover(key);
				}
			break;
		}
	}
}
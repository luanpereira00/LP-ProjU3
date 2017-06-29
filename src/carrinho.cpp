/**
 * @file	carrinho.cpp
 * @brief	Implementacao da classe Estoque para representar um carrinho de produtos
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#include "carrinho.h"

/**@return Retorna o preco da compra */
float Carrinho::getPrecoCompra(){ return precoCompra; }

/**@brief Atualiza o preco da compra 
	*@param pc O preco da compra*/
void Carrinho::setPrecoCompra(float pc){ precoCompra = pc; }

/**@brief Grava o carrinho num arquivo */
void Carrinho::gravarArquivo(){
	string closing;
	if(!isEmpty()){
		int a = verUltimaNotaFiscal();
		closing = "./data/notasFiscais/"+ to_string(a) +"_nota.csv";
		ofstream nota(closing);
		getListaProd()->imprimirArquivo(&nota);
		nota << getPrecoCompra();
		nota.close();	
		limpar();
		cout << "Venda finalizada com sucesso! Nota fiscal gerada..." << endl;
	}
	else cerr << "Carrinho vazio! Nada a fazer..." << endl;
}

/**@return Retorna bool para o carrinho estar vazio */
bool Carrinho::isEmpty(){
	if(getListaProd()->contarElementos()>0) return false;
	return true;
}

/**@return O numero da ultima nota fiscal cadastrada */
int Carrinho::verUltimaNotaFiscal(){
	bool flag =true;
	int i=0;
	string opening;
	while (flag){
		i++;
		opening = "./data/notasFiscais/"+ to_string(i) +"_nota.csv";
		ifstream nota(opening);
		if(!nota) flag=false;
		else nota.close();	
	}
	return i;
}

/**@brief Lista o carrinho */
void Carrinho::listar(){
	
	try{
		if(getListaProd()->contarElementos()>0) {
			cout << "-----------------------" << endl;
			cout << "Carrinho: " << endl << endl;
			getListaProd()->imprimirTela();
			cout << "Total do carrinho: " << getPrecoCompra() << endl;

			cout << "-----------------------" << endl;
		}
		else throw ImprimirTEDVazio();
	} catch (ImprimirTEDVazio &ex){
		cerr << ex.what() << endl;
	}
	
	
}

/**@brief Limpa o carrinho */
void Carrinho::limpar(){
	getListaProd()->destruir();
	precoCompra = 0;
}

/**@brief Adiciona produtos ao carrinho 
	*@param e O estoque de produtos */
void Carrinho::adicionarProduto(Estoque *e){
	cout << "--- Produtos Cadastrados ---" << endl;
	int key;
	int tipo;
	int qtd;
	node<Produtos*>* E;
	node<Produtos*>* C;
	Bebidas *b;
	CDs *c;
	Doces *d;
	DVDs *v;
	Frutas *f;
	Livros *l;
	Salgados *s;

	e->getListaProd()->imprimirTela();
	cout << "Digite a chave de busca: ";
	cin >> key;
	E = e->getListaProd()->buscar(key);
	try{
		if(E->prox->prox){
			bool cinFlag = true;
			//cout << "Produto encontrado..." << endl;
			do{
				cout << "Digite a quantidade para adicionar ao carrinho: ";
				cinFlag = true;
				try{
					cin >> qtd;
					if(cin.fail()) throw FalhaDeLeitura();
				} catch(FalhaDeLeitura &ex){
					cerr << ex.what() << endl;
					cin.clear();
					cin.ignore();
					cinFlag=false;
				}
			}while(!cinFlag);

			tipo = E->prox->dado->getTipo();
			
			if(E->prox->dado->getQtdEstoque()-qtd>=0){
				E->prox->dado->setQtdEstoque(E->prox->dado->getQtdEstoque()-qtd);
				switch(tipo){
					case 1: 
						b = new Bebidas;
						*b = dynamic_cast<Bebidas&>(*E->prox->dado);
						calcularCompra(b->getPrecoUnit()*qtd);
					break;
					case 2: 
						c = new CDs;
						*c = dynamic_cast<CDs&>(*E->prox->dado);
						calcularCompra(c->getPrecoUnit()*qtd);
					break;
					case 3: 
						d = new Doces;
						*d = dynamic_cast<Doces&>(*E->prox->dado);
						calcularCompra(d->getPrecoUnit()*qtd);
					break;
					case 4: 
						v = new DVDs;
						*v = dynamic_cast<DVDs&>(*E->prox->dado);
						calcularCompra(v->getPrecoUnit()*qtd);
					break;
					case 5: 
						f = new Frutas;
						*f = dynamic_cast<Frutas&>(*E->prox->dado);
						calcularCompra(f->getPrecoUnit()*qtd);
					break;
					case 6: 
						l = new Livros;
						*l = dynamic_cast<Livros&>(*E->prox->dado);
						calcularCompra(l->getPrecoUnit()*qtd);
					break;
					case 7: 
						s = new Salgados;
						*s = dynamic_cast<Salgados&>(*E->prox->dado);
						calcularCompra(s->getPrecoUnit()*qtd);
					break;
					default:
					break;
				}			
				
				C = getListaProd()->buscar(key);
				if(!C->prox->prox) {
					switch(tipo){
						case 1: 
							b->setQtdEstoque(qtd);
							getListaProd()->inserir(b);
						break;
						case 2: 
							c->setQtdEstoque(qtd);
							getListaProd()->inserir(c);
						break;
						case 3: 
							d->setQtdEstoque(qtd);
							getListaProd()->inserir(d);
						break;
						case 4: 
							v->setQtdEstoque(qtd);
							getListaProd()->inserir(v);
						break;
						case 5: 
							f->setQtdEstoque(qtd);
							getListaProd()->inserir(f);
						break;
						case 6: 
							l->setQtdEstoque(qtd);
							getListaProd()->inserir(l);
						break;
						case 7: 
							s->setQtdEstoque(qtd);
							getListaProd()->inserir(s);
						break;
						default:
						break;
					}
					cout << "ADICIONADO COM SUCESSO!" << endl;
				}else C->prox->dado->setQtdEstoque(C->prox->dado->getQtdEstoque()+qtd);
			}else cerr << "NAO HA ESSA QUANTIDADE DE PRODUTOS NO ESTOQUE! NADA A FAZER..." << endl;
		} else throw ProdutoNaoEncontradoNaLista();	
	} catch(ProdutoNaoEncontradoNaLista &ex){
		cerr << ex.what() << endl;
	}
}

	/**@brief Remove produtos do carrinho 
	*@param e O estoque de produtos */
void Carrinho::removerProduto(Estoque *e){
	//cout << "--- Produtos Cadastrados ---" << endl;
	bool cinFlag;
	int key;
	int qtd;
	node<Produtos*> *P;
	
	getListaProd()->imprimirTela();

	do{
		cout << "Digite a chave de busca: ";
		cinFlag = true;
		try{
			cin >> key;
			if(cin.fail()) throw FalhaDeLeitura();
		} catch(FalhaDeLeitura &ex){
			cerr << ex.what() << endl;
			cin.clear();
			cin.ignore();
			cinFlag=false;
		}
	}while(!cinFlag);

	P = getListaProd()->buscar(key);
	try{
		if(P->prox->prox){
			qtd = P->prox->dado->getQtdEstoque();
			getListaProd()->remover(P->prox->dado);
			P = e->getListaProd()->buscar(key);
			P->prox->dado->setQtdEstoque(P->prox->dado->getQtdEstoque()+qtd);
			calcularCompra(P->prox->dado->getPrecoUnit()*qtd*(-1));
			cout << "Removido com sucesso!" << endl;
		} else throw ProdutoNaoEncontradoNaLista();
	}catch(ProdutoNaoEncontradoNaLista &ex){
		cerr << ex.what() << endl;
	}
}

/**@brief Atualiza o preco da compra somando com um valor passado como argumento 
	* @param preco O novo valor a somar */
void Carrinho::calcularCompra(float preco){
	setPrecoCompra(getPrecoCompra()+preco);
}
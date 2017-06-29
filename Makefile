# Makefile, separando os diferentes elementos da aplicacao
# como codigo (src), cabecalhos (include), executaveis (build), bibliotecas (lib), etc.
# Cada elemento e alocado em uma pasta especifica, organizando melhor seu codigo fonte.
#
# Algumas variaveis sao usadas com significado especial:
#
# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito
#

# Comandos do sistema operacional
# Linux: rm -rf 
# Windows: cmd //C del 
RM = rm -rf 

# Compilador
CC=g++ 

# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
DAT_DIR=./data
TEST_DIR=./test

# Opcoes de compilacao
CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all init clean doxy debug doc 

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: init exec
debug: CFLAGS += -g -O0
debug: exec

init:
	@mkdir -p $(BIN_DIR)/
	@mkdir -p $(OBJ_DIR)/

# Alvo (target) para a construcao do executavel
# Define os arquivos main.o, pereciveis.o, produtos.o, bebidas.o, cds.o, data.o, doces.o dvds.o, frutas.o, livros.o, e salgados.o como dependencia
exec: $(OBJ_DIR)/main.o $(OBJ_DIR)/fornecedores.o $(OBJ_DIR)/carrinho.o $(OBJ_DIR)/notafiscal.o $(OBJ_DIR)/estoque.o $(OBJ_DIR)/menu.o $(OBJ_DIR)/pereciveis.o $(OBJ_DIR)/produtos.o $(OBJ_DIR)/data.o $(OBJ_DIR)/bebidas.o $(OBJ_DIR)/cds.o $(OBJ_DIR)/doces.o $(OBJ_DIR)/dvds.o $(OBJ_DIR)/frutas.o $(OBJ_DIR)/livros.o $(OBJ_DIR)/salgados.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'exec' criado em $(BIN_DIR)] +++"
	@echo "============="

#$(SRC_DIR)/pereciveis.cpp $(SRC_DIR)/produtos.cpp  $(INC_DIR)/pereciveis.h $(INC_DIR)/produtos.h
# Alvo (target) para a construcao do objeto main.o
# Define os arquivos main.cpp, pereciveis.cpp, produtos.cpp, bebidas.cpp, cds.cpp, data.cpp, doces.cpp, dvds.cpp, frutas.cpp, libros.cpp, salgados.cpp, pereciveis.h, produtos.h, bebidas.h, cds.h, data.h, doces.h, dvds.h, frutas.h, livros.h e salgados.h como dependencias.
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/fornecedores.h $(INC_DIR)/menu.h $(INC_DIR)/estoque.h $(INC_DIR)/carrinho.h $(INC_DIR)/notafiscal.h $(INC_DIR)/exceptions.h
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do objeto pereciveis.o
# Define os arquivos menu.cpp, menu.h, data.cpp e data.h como dependencias.
$(OBJ_DIR)/menu.o: $(SRC_DIR)/menu.cpp $(INC_DIR)/menu.h $(INC_DIR)/exceptions.h
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do objeto pereciveis.o
# Define os arquivos menu.cpp, menu.h, data.cpp e data.h como dependencias.
$(OBJ_DIR)/fornecedores.o: $(SRC_DIR)/fornecedores.cpp $(INC_DIR)/fornecedores.h $(INC_DIR)/estoque.h
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do objeto pereciveis.o
# Define os arquivos menu.cpp, menu.h, data.cpp e data.h como dependencias.
$(OBJ_DIR)/estoque.o: $(SRC_DIR)/estoque.cpp $(INC_DIR)/menu.h $(INC_DIR)/exceptions.h $(INC_DIR)/estoque.h $(INC_DIR)/lista.h $(INC_DIR)/bebidas.h $(INC_DIR)/cds.h $(INC_DIR)/data.h $(INC_DIR)/doces.h $(INC_DIR)/dvds.h $(INC_DIR)/frutas.h $(INC_DIR)/livros.h $(INC_DIR)/salgados.h
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do objeto pereciveis.o
# Define os arquivos menu.cpp, menu.h, data.cpp e data.h como dependencias.
$(OBJ_DIR)/carrinho.o: $(SRC_DIR)/carrinho.cpp $(INC_DIR)/carrinho.h $(INC_DIR)/lista.h $(INC_DIR)/bebidas.h $(INC_DIR)/cds.h $(INC_DIR)/data.h $(INC_DIR)/doces.h $(INC_DIR)/dvds.h $(INC_DIR)/frutas.h $(INC_DIR)/livros.h $(INC_DIR)/salgados.h
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do objeto pereciveis.o
# Define os arquivos menu.cpp, menu.h, data.cpp e data.h como dependencias.
$(OBJ_DIR)/notafiscal.o: $(SRC_DIR)/notafiscal.cpp $(INC_DIR)/notafiscal.h $(INC_DIR)/lista.h $(INC_DIR)/bebidas.h $(INC_DIR)/cds.h $(INC_DIR)/data.h $(INC_DIR)/doces.h $(INC_DIR)/dvds.h $(INC_DIR)/frutas.h $(INC_DIR)/livros.h $(INC_DIR)/salgados.h
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do objeto pereciveis.o
# Define os arquivos pereciveis.cpp, pereciveis.h, data.cpp e data.h como dependencias.
$(OBJ_DIR)/pereciveis.o: $(SRC_DIR)/pereciveis.cpp $(INC_DIR)/pereciveis.h $(INC_DIR)/data.h
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do objeto produtos.o
# Define os arquivos produtos.cpp e produtos.h como dependencias.
$(OBJ_DIR)/produtos.o: $(SRC_DIR)/produtos.cpp $(INC_DIR)/produtos.h
	$(CC) -c $(CFLAGS) -o $@ $<		

# Alvo (target) para a construcao do objeto data.o
# Define os arquivos data.cpp e data.h como dependencias.
$(OBJ_DIR)/data.o: $(SRC_DIR)/data.cpp $(INC_DIR)/data.h
	$(CC) -c $(CFLAGS) -o $@ $<		

# Alvo (target) para a construcao do objeto bebidas.o
# Define os arquivos bebidas.cpp, bebidas.h, produtos.cpp e produtos.h como dependencias.
$(OBJ_DIR)/bebidas.o: $(SRC_DIR)/bebidas.cpp $(INC_DIR)/bebidas.h $(INC_DIR)/data.h $(INC_DIR)/produtos.h $(INC_DIR)/pereciveis.h
	$(CC) -c $(CFLAGS) -o $@ $<		

# Alvo (target) para a construcao do objeto cds.o
# Define os arquivos cds.cpp, cds.h, produtos.cpp e produtos.h como dependencias.
$(OBJ_DIR)/cds.o: $(SRC_DIR)/cds.cpp $(INC_DIR)/cds.h $(SRC_DIR)/produtos.cpp $(INC_DIR)/produtos.h
	$(CC) -c $(CFLAGS) -o $@ $<			

# Alvo (target) para a construcao do objeto docs.o
# Define os arquivos doces.cpp, doces.h, produtos.cpp e produtos.h como dependencias.
$(OBJ_DIR)/doces.o: $(SRC_DIR)/doces.cpp $(INC_DIR)/doces.h $(INC_DIR)/data.h $(INC_DIR)/produtos.h $(INC_DIR)/pereciveis.h
	$(CC) -c $(CFLAGS) -o $@ $<			

# Alvo (target) para a construcao do objeto dvds.o
# Define os arquivos dvds.cpp, dvds.h, produtos.cpp e produtos.h como dependencias.
$(OBJ_DIR)/dvds.o: $(SRC_DIR)/dvds.cpp $(INC_DIR)/dvds.h $(INC_DIR)/produtos.h
	$(CC) -c $(CFLAGS) -o $@ $<		

# Alvo (target) para a construcao do objeto frutas.o
# Define os arquivos frutas.cpp, frutas.h, produtos.cpp, produtos.h, data.cpp e data.h como dependencias.
$(OBJ_DIR)/frutas.o: $(SRC_DIR)/frutas.cpp $(INC_DIR)/frutas.h $(INC_DIR)/data.h $(INC_DIR)/produtos.h $(INC_DIR)/pereciveis.h
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do objeto livros.o
# Define os arquivos livros.cpp, livros.h, produtos.cpp e produtos.h como dependencias.
$(OBJ_DIR)/livros.o: $(SRC_DIR)/livros.cpp $(INC_DIR)/livros.h $(INC_DIR)/produtos.h
	$(CC) -c $(CFLAGS) -o $@ $<			

# Alvo (target) para a construcao do objeto salgados.o
# Define os arquivos salgados.cpp, salgados.h, produtos.cpp e produtos.h como dependencias.
$(OBJ_DIR)/salgados.o: $(SRC_DIR)/salgados.cpp $(INC_DIR)/salgados.h $(INC_DIR)/data.h $(INC_DIR)/produtos.h $(INC_DIR)/pereciveis.h
	$(CC) -c $(CFLAGS) -o $@ $<						
			
# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen -g

doc:
	doxygen

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/* 
	$(RM) $(OBJ_DIR)/*	
	$(RM) $(DOC_DIR)/*	
#pragma once
#include "Populacao.h"
#include "Bloco.h"
#include "Mina.h"
#include "Pedreira.h"
#include "Floresta.h"

class Mapa{
	int linhas, colunas;
	vector < Populacao *> populacoes; // vector de ponteiros para as populaçoes
	vector < Bloco * > blocos; //vector de ponteiros para blocos
	vector < FonteRecurso * > recursos;
public:
	Mapa();
	~Mapa();	
	int getLinhas() const;
	int getColunas() const;
	Bloco * getBloco(int lin, int col) const;
	FonteRecurso * getRecurso(int lin, int col)const;
	void setLinhas(int linhas);
	void setColunas(int colunas);
	string getPlayerList()const;

	void addBloco(Bloco * _bloco);
	void addPopulcao(Populacao * pop);
	bool addRecurso(int lin, int col, int quant, int tipo);
	bool hasRecurso(int lin, int col)const;

	Populacao * getPopulacao(string nome)const;
	void removePopulacao(string nome);
	bool checkPopulcacao(string nome)const;
	bool checkBloco(int linha, int col)const;
	int getSizePop()const;
	Populacao * getPopByPos(int i) const;
	Populacao * getPlayerOne()const;
};
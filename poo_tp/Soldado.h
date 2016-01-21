#pragma once
#include "Unidade.h"

class Soldado :public Unidade{
	static int contaSold;
	int saude = 40;
	const int velocidade = 2;
	const int madeira = 10;
	const int ouro = 10;
	const int ataque = 5;
	const int defesa = 20;
	bool canAtack = true;
	bool wasAtacked = false;
	string setName();
	void setSaude(int dano);
	void setColuna(int col);
	void setLinha(int lin);
public:
	Soldado(int lin, int col);
	// gets
	string getName() const;
	int getSaude() const;
	int getMadeira() const;
	int getPedra() const;
	int getOuro()const;
	int getLin()const;
	int getCol()const;
	bool getCarry() const;
	bool getAtack() const;
	bool getWasAtacked() const;
	string getDetail() const;
	void movimentar(int lin, int col);
};
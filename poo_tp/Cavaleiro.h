#pragma once
#include "Unidade.h"
class Cavaleiro :public Unidade{
	static int contaCav;
	int saude = 60;
	const int velocidade = 2;
	const int madeira = 20;
	const int pedra = 5;
	const int ouro = 10;
	const int ataque = 8;
	const int defesa = 40;
	bool canAtack = true;
	bool wasAtacked = false;
	string setName();
	void setSaude(int dano);
	void setColuna(int col);
	void setLinha(int lin);
public:
	Cavaleiro(int lin, int col);
	
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


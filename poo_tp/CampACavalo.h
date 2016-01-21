#pragma once
#include "Unidade.h"
class CampACavalo: public Unidade{
	static int contaCampC;
	int saude = 40;
	const int velocidade = 1;
	const int madeira = 20;
	const int pedra = 5;
	const int ouro = 5;
	const int ataque = 0;
	const int defesa = 0;
	bool canAtack = false;
	bool wasAtacked = false;
	string setName();
	void setSaude(int dano);
	void setColuna(int col);
	void setLinha(int lin);
public:
	CampACavalo(int lin, int col);

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


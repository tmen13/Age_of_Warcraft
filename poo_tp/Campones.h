#pragma once
#include "Unidade.h"

class Campones :public Unidade{
	static int contaCamp;
	int saude = 20;
	const int velocidade = 1;
	const int visao = 2;
	const int madeira = 10;
	const int pedra = 0;
	const int ouro = 5;
	const int ataque = 0;
	const int defesa = 0;
	bool canCarry = true;
	bool canAtack = false;
	bool wasAtacked = false;
	string setName();
	void setSaude(int dano);
	void setColuna(int col);
	void setLinha(int lin);
public:
	Campones(int linha, int coluna);
	~Campones();
	// gets
	int getLin()const;
	int getCol()const;
	string getName() const;
	int getSaude() const;
	int getMadeira() const;
	int getPedra() const;
	int getOuro()const;
	bool getCarry() const;
	bool getAtack() const;
	bool getWasAtacked() const;
	string getDetail() const;
	void movimentar(int lin, int col);
};
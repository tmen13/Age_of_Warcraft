#pragma once
#include "core.h"
#include "Castelo.h"
#include "Quartel.h"
#include "Quinta.h"
#include "Estabulo.h"
#include "Soldado.h"
#include "Campones.h"
#include "CampACavalo.h"
#include "Cavaleiro.h"
#include "Quartel.h"
#include "Quinta.h"
#include "Estabulo.h"

class Populacao{
	bool isUser = false;
	static int contaPop;
	string name;
	int ouro=150, pedra=440, madeira=560;
	Populacao * playerOne;
	vector<Unidade*> unidades;
	vector<Edificio*> edificios;
public:
	Populacao(string name);
	Populacao(const Populacao &copia);
	string getNomePop() const;
	int Populacao::getOuro()const;
	int Populacao::getPedra()const;
	int Populacao::getMadeira()const;
	void setUser(bool isUser);
	
	//unidades
	string getListUnidades() const;
	void addUnidade(Unidade *_unidade);
	Unidade* getUnidade(string nome)const;
	void removeUnidade(Unidade* nome);
	bool checkUnidade(string nome)const;	
	int getSizeUnis()const;
	Unidade* getUniByPos(int i) const;

	//edificios
	string getListEidificios() const;
	void addEdificio(Edificio *_edificio);
	Edificio* getEdificio(string nome)const;
	void removeEdificio(string nome);
	bool checkEdificio(string nome)const;
	bool checkAddEdificio(Edificio * _edificio) const;
	int getSizeEdis()const;
	Edificio* getEdiByPos(int i) const;
	const Populacao& operator=(const Populacao& copia);
	int contaQuinta();
};
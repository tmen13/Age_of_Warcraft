#include "Campones.h"

int Campones::contaCamp = 0;

Campones::Campones(int lin, int col){
	contaCamp++;
	name = setName();
	this->lin = lin;
	this->col = col;
}

Campones::~Campones(){
}

// gets
string Campones::getName() const{ return name; }
int Campones::getSaude() const{ return saude; }
int Campones::getMadeira() const{ return madeira; }
int Campones::getPedra() const{ return pedra; }
int Campones::getOuro()const{ return ouro; }
bool Campones::getCarry() const{ return canCarry; }
bool Campones::getAtack() const{ return canAtack; }
bool Campones::getWasAtacked() const{ return wasAtacked; }
int Campones::getLin()const{ return lin; }
int Campones::getCol()const{ return col; }

string Campones::getDetail() const{
	ostringstream oss;
	oss << "Nome: " << getName() << "Saude: " << getSaude() << endl;
	return oss.str();
}

//sets

void Campones::setColuna(int col){ this->col = col; }
void Campones::setLinha(int lin){ this->lin = lin; }

void Campones::setSaude(int dano){
	saude -= dano;
	if (saude <= 0){
		saude = 0;
	}
}

string Campones::setName(){
	ostringstream oss;
	oss << "P" << setw(2) << setfill('0') << contaCamp;
	return oss.str();
}

void Campones::movimentar(int lin, int col){
	this->setLinha(lin);
	this->setColuna(col);
}
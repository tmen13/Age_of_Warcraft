#include "CampACavalo.h"

int CampACavalo::contaCampC = 0;

CampACavalo::CampACavalo(int lin, int col){
	contaCampC++;
	name = setName();
	this->lin = lin;
	this->col = col;
}

string CampACavalo::getName() const{ return name; }
int CampACavalo::getSaude() const{ return saude; }
int CampACavalo::getMadeira() const{ return madeira; }
int CampACavalo::getPedra() const{ return pedra; }
int CampACavalo::getOuro()const{ return ouro; }
int CampACavalo::getLin()const{ return lin; }
int CampACavalo::getCol()const{ return col; }
bool CampACavalo::getCarry() const{ return canCarry; }
bool CampACavalo::getAtack() const{ return canAtack; }
bool CampACavalo::getWasAtacked() const{ return wasAtacked; }

string CampACavalo::getDetail() const{
	ostringstream oss;
	oss << getName() << "(" << getLin() << "/" << getCol() << ")" << endl;
	return oss.str();
}

//sets
void CampACavalo::setSaude(int dano){
	saude -= dano;
	if (saude <= 0){
		saude = 0;
	}
}

string CampACavalo::setName(){
	ostringstream oss;
	oss << "B" << setw(2) << setfill('0') << contaCampC;
	return oss.str();
}

void CampACavalo::setColuna(int col){ this->col = col; }
void CampACavalo::setLinha(int lin){ this->lin = lin; }

void CampACavalo::movimentar(int lin, int col){
	this->setLinha(lin);
	this->setColuna(col);
}

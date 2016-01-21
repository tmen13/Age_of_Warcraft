#include "Bloco.h"

Bloco::Bloco(int lin, int col){
	this->col = col;
	this->lin = lin;
}

int Bloco::getCol()const{ return col; }
int Bloco::getLin()const{ return lin; }
bool Bloco::getEmpty()const{ return isEmpty; }
bool Bloco::getWasSaw() const{ return wasSaw; }
void Bloco::setEmpty(bool setB){ this->isEmpty=setB; }
void Bloco::setWasSaw(bool setB){  this->wasSaw=setB; }
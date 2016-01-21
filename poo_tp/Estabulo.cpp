#include "Estabulo.h"

int Estabulo::contaEst = 0;

Estabulo::Estabulo(int lin, int col){
	contaEst++;
	name = setName();
	this->lin = lin;
	this->col = col;
}

string Estabulo::getName() const{ return name; }
int Estabulo::getEstado()const{ return estado; }
int Estabulo::getMadeira() const{ return madeira; }
int Estabulo::getPedra() const{ return pedra; }
int Estabulo::getOuro()const { return ouro; }
int Estabulo::getLin()const{ return lin; }
int Estabulo::getCol()const{ return col; }
int Estabulo::getLimite()const { return limite; }
string Estabulo::getDetail()const{
	ostringstream oss;
	oss << getName() << "(" << getLin() << "/" << getCol() << ")" << endl;
	return oss.str();
}

//sets
string Estabulo::setName(){
	ostringstream oss;
	oss << "E" << setw(2) << setfill('0') << contaEst;
	return oss.str();
}

void Estabulo::setEstado(int dano){
	estado -= dano;
	if (estado <= 0){
		estado = 0;
	}
}
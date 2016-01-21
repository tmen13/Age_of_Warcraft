#include "Floresta.h"

Floresta::Floresta(int lin, int col, int quant){
	this->lin = lin;
	this->col = col;
	this->quantidade = quant;
	this->nome = "M";
}

string Floresta::getName() const{ return nome; }
int Floresta::getQuantidade(){ return quantidade; }
int Floresta::getLin()const{ return lin; }
int Floresta::getCol()const{ return col; }
void Floresta::setQuantidade(int quant){
	quantidade -= quant;
	if (quantidade <= 0){
		quantidade = 0;
	}
}
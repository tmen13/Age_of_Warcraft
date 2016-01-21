#pragma once
#include "Mapa.h"

Mapa::Mapa(){}

int Mapa::getLinhas() const{ return linhas; }
int Mapa::getColunas() const{ return colunas; }
void Mapa::setLinhas(int linhas){ this->linhas = linhas; }
void Mapa::setColunas(int colunas){ this->colunas = colunas; }

Bloco * Mapa::getBloco(int lin, int col) const{
	if (checkBloco(lin, col)){
		for (size_t i = 0; i < blocos.size(); i++){
			if (blocos[i]->getCol() == col && blocos[i]->getLin() == lin)
				return blocos[i];
		}
	}
	else
		return nullptr;
}

void Mapa::addBloco(Bloco * bloco){
	blocos.push_back(bloco);
}

void Mapa::addPopulcao(Populacao * pop){
	if (!checkPopulcacao(pop->getNomePop())){
		populacoes.push_back(pop);
	}
}

string Mapa::getPlayerList()const{
	ostringstream oss;
	for (size_t i = 0; i < populacoes.size(); i++){
		oss << populacoes[i]->getNomePop();
	}
	return oss.str();
}

Populacao* Mapa::getPopulacao(string nome)const{
	if (checkPopulcacao(nome)){
		for (size_t i = 0; i < populacoes.size(); i++){
			if (populacoes[i]->getNomePop() == nome)
				return populacoes[i];
		}
	}
	else
		return nullptr;
}

void Mapa::removePopulacao(string nome){
	if (checkPopulcacao(nome)){
		for (size_t i = 0; i < populacoes.size(); i++){
			if (populacoes[i]->getNomePop() == nome)
				populacoes.erase(populacoes.begin() + i);
		}
	}
}

bool Mapa::checkPopulcacao(string nome)const{
	for (size_t i = 0; i < populacoes.size(); i++){
		if (nome == populacoes[i]->getNomePop())
			return true;
	}
	return false;
}

bool Mapa::checkBloco(int linha, int coluna)const{
	for (size_t i = 0; i < blocos.size(); i++){
		if (blocos[i]->getCol() == coluna && blocos[i]->getLin() == linha)
			return true;
	}
	return false;
}

int Mapa::getSizePop()const{ return populacoes.size(); }
Populacao * Mapa::getPlayerOne()const{ return populacoes[0]; }
Populacao * Mapa::getPopByPos(int i) const{ return populacoes[i]; }

bool Mapa::addRecurso(int lin, int col, int quant, int tipo){
	FonteRecurso *recurso;
	if (!hasRecurso(lin, col)){
		if (tipo == 0)
			recurso = new Mina(lin, col, quant);
		if (tipo == 1)
			recurso = new Pedreira(lin, col, quant);
		if (tipo == 2)
			recurso = new Floresta(lin, col, quant);
		recursos.push_back(recurso);
		return true;
	}
	else
		return false;
}

bool Mapa::hasRecurso(int lin, int col)const{
	for (size_t i = 0; i < recursos.size(); i++){
		if (recursos[i]->getLin() == lin && recursos[i]->getCol() == col){
			return true;
			break;
		}
		else{
			return false;
			break;
		}
	}
}

FonteRecurso* Mapa::getRecurso(int lin, int col)const{
	for (size_t i = 0; i < recursos.size(); i++){
		if (recursos[i]->getLin() == lin && recursos[i]->getCol() && col){
			return recursos[i];
			break;
		}
		else{
			return false;
			break;
		}
	}
}
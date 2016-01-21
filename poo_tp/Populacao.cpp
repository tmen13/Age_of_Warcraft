#include "Populacao.h"

int Populacao::contaPop = 0;

Populacao::Populacao(string name){
	contaPop++;
	this->name = name;
}

Populacao::Populacao(const Populacao &copia){
	this->isUser = copia.isUser;
	this->name = copia.name;
	this->ouro = copia.ouro;
	this->pedra = copia.pedra;
	this->madeira = copia.madeira;
	this->unidades = copia.unidades;
	this->edificios = copia.edificios;
}

const Populacao& Populacao::operator=(const Populacao& copia){
	if (this != &copia){
		this->isUser = copia.isUser;
		this->name = copia.name;
		this->ouro = copia.ouro;
		this->pedra = copia.pedra;
		this->madeira = copia.madeira;
		this->unidades = copia.unidades;
		this->edificios = copia.edificios;
	}
	return *this;
}

string Populacao::getNomePop() const{ return name; }
int Populacao::getOuro() const{ return ouro; }
int Populacao::getPedra() const{ return pedra; }
int Populacao::getMadeira() const{ return madeira; }

void Populacao::setUser(bool isUser){ this->isUser = isUser; }

/*         Manipular edificios                    */
void Populacao::addEdificio(Edificio *_edificio){
	if (!checkEdificio(_edificio->getName())){
		edificios.push_back(_edificio);
	}
}

bool Populacao::checkAddEdificio(Edificio * _edificio)const{
	string nomeEdi, nomeEdif;
	
	if (_edificio->getLimite() != 1){
		return true;
	}
	else {
		/*for (size_t i = 0; i < edificios.size(); i++){
			nomeEdi = edificios[i]->getName();
			
			if (nomeEdi.find('C') != string::npos || nomeEdi.find('Q') != string::npos || nomeEdi.find('E') != string::npos){
				return false;
				break;
			}
			else
				return true;
		}*/
		nomeEdi = _edificio->getName();
		if (nomeEdi.find('C') != string::npos){
			for (size_t i = 0; i < edificios.size(); i++){
				nomeEdif = edificios[i]->getName();
				if (nomeEdif.find('C') != string::npos )
					return false;
			}
		}
		if (nomeEdi.find('Q') != string::npos){
			for (size_t i = 0; i < edificios.size(); i++){
				nomeEdif = edificios[i]->getName();
				if (nomeEdif.find('Q') != string::npos)
					return false;
			}
		}
		if (nomeEdi.find('E') != string::npos){
			for (size_t i = 0; i < edificios.size(); i++){
				nomeEdif = edificios[i]->getName();
				if (nomeEdif.find('E') != string::npos)
					return false;
			}
		}
	}
}

string Populacao::getListEidificios()const{
	ostringstream oss;
	for (size_t i = 0; i < edificios.size(); i++){
		oss << edificios[i]->getDetail();
	}
	return oss.str();
}

Edificio* Populacao::getEdificio(string nome)const{
	if (checkEdificio(nome)){
		for (size_t i = 0; i < edificios.size(); i++){
			if (edificios[i]->getName() == nome)
				return edificios[i];
		}
	}
	return nullptr;
}

void Populacao::removeEdificio(string nome){
	if (checkUnidade(nome)){
		for (size_t i = 0; i < edificios.size(); i++){
			if (edificios[i]->getName() == nome)
				edificios.erase(edificios.begin() + i);
		}
	}
}

bool Populacao::checkEdificio(string nome)const{
	for (size_t i = 0; i < edificios.size(); i++){
		if (nome == edificios[i]->getName())
			return true;
	}
	return false;
}

int Populacao::getSizeEdis()const{ return edificios.size(); }
Edificio* Populacao::getEdiByPos(int i) const{ return edificios[i]; };

/*         Manipular unidades                    */
void Populacao::addUnidade(Unidade *_unidade){
	if (!checkUnidade(_unidade->getName()))
		unidades.push_back(_unidade);
}

string Populacao::getListUnidades()const{
	ostringstream oss;
	for (size_t i = 0; i < unidades.size(); i++){
		oss << unidades[i]->getDetail();
	}
	return oss.str();
}

Unidade* Populacao::getUnidade(string nome)const{
	if (checkUnidade(nome)){
		for (size_t i = 0; i < unidades.size(); i++){
			if (unidades[i]->getName() == nome)
				return unidades[i];
		}
	}
	return nullptr;
}

void Populacao::removeUnidade(Unidade *nome){
	if (checkUnidade(nome->getName())){
		for (size_t i = 0; i < unidades.size(); i++){
			if (unidades[i]->getName() == nome->getName())
				unidades.erase(unidades.begin() + i);
		}
	}
}

bool Populacao::checkUnidade(string nome)const{
	for (size_t i = 0; i < unidades.size(); i++){
		if (nome == unidades[i]->getName())
			return true;
	}
	return false;
}
int Populacao::getSizeUnis()const{ return unidades.size(); }
Unidade* Populacao::getUniByPos(int i) const{ return unidades[i]; };

int Populacao::contaQuinta(){
	string nomeEdi;
	int conta=0, result;

	for (int i = 0; i < playerOne->getSizeEdis(); i++){
		nomeEdi = playerOne->getEdiByPos(i)->getName();
		if (nomeEdi.find('F') != string::npos)
			conta++;
	}
	result = 4 * conta;
	return result;
}
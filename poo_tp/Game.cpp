#include "Game.h"

string validCommands[NUM_CMDS][2] = {
	{ "pop", "2" },//pop nome
	{ "sete", "5" },//sete nomepop oque linha coluna, edificio
	{ "setu", "5" },//sete nomepop oque linha coluna,unidade
	{ "load", "2" },//load ficheiro
	{ "sair", "1" },//sair
	{ "scroll", "1" },//scroll
	{ "next", "1" },//next
	{ "next", "2" },//next instantes
	{ "ENTER", "1" },//enter
	{ "go", "4" }, //go id delta_linha delta_coluna
	{ "goto", "4" }, //goto id linha coluna
	{ "setf", "4" }, //setf oque linha coluna
	{ "mostra", "2" }, //mostra nome
	{ "sel", "2" }, //sel id
	{ "mina", "3" }, //mina id idfonte
	{ "ataca", "3" }, //ataca id idvitima
	{ "conserta", "3" }, //conserta id id_edificio
	{ "deambula", "2" }, //deambula id
	{ "mke", "5" }, //mke id oque linha coluna
	{ "mku", "2" },//mku oque
	{ "stop", "1" }//para musica
};
string StartGame[2][2] = { { "mkgame", "3" },//mkgame linha coluna
{ "load", "2" } };//load ficheiro

vector<string> &split(const string &s, char delim, vector<string> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}

bool is_number(const string& s)
{
	return !s.empty() && find_if(s.begin(),
		s.end(), [](char c) { return !isdigit(c); }) == s.end();
}

Game::Game(){
	myConsole = new Consola();
	myMapa = new Mapa();
}

void Game::Start(){
	string cmd = "";
	//PlayIntro();
	do{
		printStartUI();
		getline(cin, cmd);
		if (cmd == "sair")
			exit(0);
	} while (cmd == "");
	processCommand(cmd);
	if (status){
		do{
			printInterface();
			do{
				getline(cin, cmd);
			} while (cmd == "");
			processCommand(cmd);
		} while (status);
	}
	else{
		myConsole->setTextColor(myConsole->VERMELHO);
		myConsole->gotoxy(20, 16);
		cout << "Comando invalido!" << endl;
	}
};

void Game::mkgame(int linhas, int colunas){
	if (linhas < 10)
		linhas = 10;
	if (colunas < 20)
		colunas = 20;
	myMapa->setLinhas(linhas);
	myMapa->setColunas(colunas);
}
void Game::pop(string nome){
	if (!myMapa->checkPopulcacao(nome)){
		int numpopulacoes = myMapa->getSizePop();
		if (numpopulacoes != 4){
			jogador = new Populacao(nome);
			if (numpopulacoes == 0){
				jogador->setUser(true);
				userON = true;
				playerOne = jogador;
			}
			myMapa->addPopulcao(jogador);
		}
	}
}

//verifica se o comando é valido
void Game::processCommand(string cmd){
	int opt, n_params;
	bool isValid = false;
	vector <string> aux;
	aux = split(cmd, ' ');
	n_params = aux.size();

	if (aux[0] == StartGame[0][0] && n_params == atoi(StartGame[0][1].c_str()))
	{
		if (!status){
			if (is_number(aux[1]) && is_number(aux[2])){
				mkgame(atoi(aux[1].c_str()), atoi(aux[2].c_str()));
				fillMapaWithBlocos();
				//fillMapaWithRecursos();
				status = true;
			}
		}
	}

	if (aux[0] == StartGame[1][0] && n_params == atoi(StartGame[1][1].c_str()))
	{
		load(aux[1]);
	}

	if (status && aux[0] != StartGame[0][0]){
		for (int i = 0; i < NUM_CMDS; i++){
			if (aux[0] == validCommands[i][0] && n_params == atoi(validCommands[i][1].c_str())){
				opt = i;
				isValid = true; //é valido e tem todos os parametros
				break;
			}
		}

		if (isValid){
			switch (opt)	{
			case 0: //pop nome	
				pop(aux[1]);
				break;
			case 1: //sete popnome oque linha coluna, edificio
				if (is_number(aux[3]) && is_number(aux[4])){
					sete(aux[1], aux[2], atoi(aux[3].c_str()), atoi(aux[4].c_str()));
				}
				break;
			case 2: //setu popnome oque linha coluna, unidade
				if (is_number(aux[3]) && is_number(aux[4])){
					setu(aux[1], aux[2], atoi(aux[3].c_str()), atoi(aux[4].c_str()));
				}
				break;
			case 3: //load ficheiro
				if (!wasLoad)
					load(aux[1]);
				wasLoad = true;
				break;
			case 4: //sair
				exit(0);
				break;
			case 5://scroll
				scroll();
				break;
			case 6: // next
				break;
			case 7: //next instantes
				break;
			case 8: //ENTER
				break;
			case 9: //go id delta_linha delta_coluna
				if (is_number(aux[2]) && is_number(aux[3])){
					go(aux[1], atoi(aux[2].c_str()), atoi(aux[3].c_str()), "go");
				}
				break;
			case 10: //goto linha coluna
				if (is_number(aux[2]) && is_number(aux[3])){
					go(aux[1], atoi(aux[2].c_str()), atoi(aux[3].c_str()), "goto");
				}
				break;
			case 11: //setf oque linha coluna
				if (is_number(aux[2]) && is_number(aux[3])){
					setf(aux[1], atoi(aux[2].c_str()), atoi(aux[3].c_str()));
				}
				break;
			case 12: //mostra nome
				show = true;
				showname = aux[1];
				break;
			case 13: //sel id
				vista = true;
				showname = aux[1];
				break;
			case 14: //mina id idfonte
				break;
			case 15: //ataca id idvitima
				break;
			case 16: //conserta id id_edificio
				break;
			case 17: //deambula id
				break;
			case 18: //mke id oque linha coluna
				if (is_number(aux[3]) && is_number(aux[4])){
					mke(aux[1], aux[2], atoi(aux[3].c_str()), atoi(aux[4].c_str()));
				}
				break;
			case 19: //mku oque
				mku(aux[1]);
				break;
			case 20:
				StopSound();
				break;
			default:
				break;
			}
		}
	}
}

/*            Manipulação do som            */

void Game::PlayIntro(){
	PlaySound(TEXT("Sounds/intro.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}

void Game::StopSound(){
	PlaySound(NULL, 0, 0);
}

/*				INTERFACES				*/
void Game::printStartUI(){
	myConsole->setScreenSize(20, 80);
	myConsole->setTextColor(myConsole->CYAN);
	myConsole->setBackgroundColor(myConsole->BRANCO_CLARO);
	myConsole->clrscr();
	myConsole->gotoxy(30, 4);
	cout << "****AGE OF WARCRAFT****" << endl;
	myConsole->setTextColor(myConsole->VERDE);

	for (int i = 20; i < 61; i++){
		myConsole->gotoxy(i, 0);
		cout << (char)176 << endl;
		myConsole->gotoxy(i, 8);
		cout << (char)176 << endl;
	}
	for (int j = 0; j < 8; j++){
		myConsole->gotoxy(20, j);
		cout << (char)176 << endl;
		myConsole->gotoxy(60, j);
		cout << (char)176 << endl;
	}

	myConsole->setTextColor(myConsole->PRETO);
	myConsole->gotoxy(20, 11);
	cout << "Para criar um jogo use o comando: mkgame <lin> <col>" << endl;
	myConsole->gotoxy(20, 12);
	cout << "Para sair do jogo use o comando: sair" << endl;
	myConsole->gotoxy(20, 14);
	cout << "Comando: _____________ " << endl;
	myConsole->gotoxy(29, 14);
}

void Game::printInterface(){
	string cmd;
	myConsole->clrscr();
	myConsole->setScreenSize(40, 104);
	myConsole->setTextColor(myConsole->CYAN);
	myConsole->setBackgroundColor(myConsole->BRANCO_CLARO);
	myConsole->gotoxy(25, 1);
	cout << "****AGE OF WARCRAFT****" << endl;

	printMapa();

	if (userON){
		playerOne = myMapa->getPopByPos(0);
		int numpopulacoes = myMapa->getSizePop();
		myConsole->setTextColor(myConsole->VERMELHO_CLARO);
		myConsole->gotoxy(80, 2);
		cout << myMapa->getPopByPos(0)->getNomePop();

		if (numpopulacoes >= 2){
			myConsole->setTextColor(myConsole->COR_DE_ROSA);
			myConsole->gotoxy(80, 3);
			cout << myMapa->getPopByPos(1)->getNomePop();
		}
		if (numpopulacoes >= 3){
			myConsole->setTextColor(myConsole->AMARELO_CLARO);
			myConsole->gotoxy(80, 4);
			cout << myMapa->getPopByPos(2)->getNomePop();
		}
		if (numpopulacoes >= 4){
			myConsole->setTextColor(myConsole->VERDE_CLARO);
			myConsole->gotoxy(80, 5);
			cout << myMapa->getPopByPos(3)->getNomePop();
		}

		myConsole->setTextColor(myConsole->PRETO);
		myConsole->gotoxy(75, 6);
		cout << "Jogador: ";
		myConsole->setTextColor(myConsole->VERMELHO_CLARO);
		myConsole->gotoxy(84, 6);
		cout << playerOne->getNomePop();

		myConsole->setTextColor(myConsole->AMARELO);
		myConsole->gotoxy(75, 21);
		cout << "Ouro";
		myConsole->gotoxy(84, 21);
		cout << playerOne->getOuro();
		myConsole->setTextColor(myConsole->CINZENTO);
		myConsole->gotoxy(84, 22);
		cout << playerOne->getPedra();
		myConsole->gotoxy(75, 22);
		cout << "Pedra";
		myConsole->setTextColor(myConsole->VERMELHO);
		myConsole->gotoxy(84, 23);
		cout << playerOne->getMadeira();
		myConsole->gotoxy(75, 23);
		cout << "Madeira";
	}

	myConsole->setTextColor(myConsole->VERDE);
	//linha horizontal 
	for (int i = 0; i < 70; i++){
		myConsole->gotoxy(i, 33);
		cout << (char)176 << endl;
	}
	//linha vertical
	for (int j = 0; j < 40; j++){
		myConsole->gotoxy(70, j);
		cout << (char)176 << endl;
	}

	myConsole->setTextColor(myConsole->PRETO);
	myConsole->gotoxy(83, 8);
	cout << "Listagem: ";
	if (show)
		mostra(showname);
	myConsole->gotoxy(83, 24);
	cout << "Vista";
	if (vista)
		sel(showname);
	myConsole->gotoxy(83, 0);
	cout << "Legenda";
	myConsole->gotoxy(83, 19);
	cout << "Recursos";
	myConsole->gotoxy(83, 29);
	cout << "Dados";

	myConsole->gotoxy(0, 34);
	cout << "Comando: __________________________________" << endl;
	myConsole->gotoxy(9, 34);
}

void Game::fillMapaWithBlocos(){
	for (int i = 0; i < myMapa->getColunas(); i++){
		for (int j = 0; j < myMapa->getLinhas(); j++){
			bloco = new Bloco(j, i);
			myMapa->addBloco(bloco);
		}
	}
}

void Game::fillMapaWithRecursos(){ //tem bug
	int nlinhas, ncolunas, nRecursos, conta, rlinha, rcoluna, rquant;
	nlinhas = myMapa->getLinhas();
	ncolunas = myMapa->getColunas();
	nRecursos = static_cast<int>((nlinhas * ncolunas)*0.3) / 3;
	srand(time(0));
	for (int i = 0; i < 3; i++){
		conta = 1;
		do{
			rlinha = (rand() % (nlinhas - 0 + 1)) + 0;
			rcoluna = (rand() % (ncolunas - 0 + 1)) + 0;
			rquant = (rand() % (120 - 60 + 1)) + 60;
			bloco = myMapa->getBloco(rlinha, rcoluna);
			if (myMapa->addRecurso(rlinha, rcoluna, rquant, i) && bloco != nullptr){
				bloco->setEmpty(false);
				conta++;
			}
		} while (conta != nRecursos);
	}
}

void Game::printMapa(){
	int conta = 0;
	//tabuleiro
	//linhas horizontais
	for (int c = 0; c < 60; c++){
		for (int k = 0; k <= MAX_LIN; k++){
			myConsole->gotoxy(c + 3, k + 3 + k);
			cout << (char)205;
			conta++;
		}
	}
	//linhas verticais
	for (int c = 0; c <= MAX_COL; c++){
		for (int k = 0; k < 20; k++){
			myConsole->gotoxy(c + 2 + c + c, k + 4);
			cout << (char)179;
			conta++;
		}
	}

	for (int i = 0; i < MAX_COL; i++){
		for (int j = 0; j < MAX_LIN; j++){
			int * result;
			myConsole->setTextColor(myConsole->PRETO);

			//numeros
			myConsole->setTextColor(myConsole->VERDE);
			myConsole->gotoxy(i + 3 + i + i, 2);
			if (i < 10)
				cout << setw(2) << setfill(' ') << i + scrollCol << endl;
			else
				cout << i + scrollCol << endl;

			if (i == 1){
				myConsole->setTextColor(myConsole->VERDE);
				myConsole->gotoxy(i, j + 4 + j);
				cout << j + scrollLin << endl;
			}
			bloco = myMapa->getBloco(j + scrollLin, i + scrollCol);
			//blocos
			if (!bloco->getWasSaw()){
				myConsole->setTextColor(myConsole->PRETO);
				myConsole->gotoxy(i + 4 + i + i, j + 4 + j);
				cout << (char)178;
			}
			else {

				if (bloco->getEmpty()){
					cout << (char)0;
				}
				else {
					result = processaBloco(bloco);
					myConsole->setTextColor(result[0]);
					myConsole->gotoxy(i + 4 + i + i, j + 4 + j);
					cout << (char)result[1];
				}
			}
		}
	}
}

void Game::sete(string nome, string oque, int linha, int coluna){
	jogador = myMapa->getPopulacao(nome);
	bloco = myMapa->getBloco(linha, coluna);
	string nomeEdi;
	if (jogador != nullptr && bloco != nullptr && checkCanAddEdi(linha, coluna)){
		if (oque == "cast" || oque == "castelo"){
			edi = new Castelo(linha, coluna);
			if (jogador->checkAddEdificio(edi)){
				if (jogador->getNomePop() == playerOne->getNomePop()){
					jogador->addEdificio(edi);
					bloco->setEmpty(false);
					bloco->setWasSaw(true);
					visivel(linha, coluna);
				}
				else {
					jogador->addEdificio(edi);
					bloco->setEmpty(false);
				}
			}
		}
		if (oque == "quar" || oque == "quartel"){
			edi = new Quartel(linha, coluna);
			if (jogador->checkAddEdificio(edi)){
				jogador->addEdificio(edi);
				if (jogador->getNomePop() == playerOne->getNomePop()){

					bloco->setEmpty(false);
					bloco->setWasSaw(true);
					visivel(linha, coluna);
				}
				else {
					jogador->addEdificio(edi);
					bloco->setEmpty(false);
				}
			}
		}
		if (oque == "est" || oque == "estabulo"){
			edi = new Estabulo(linha, coluna);
			if (jogador->checkAddEdificio(edi)){
				jogador->addEdificio(edi);
				if (jogador->getNomePop() == playerOne->getNomePop()){

					bloco->setEmpty(false);
					bloco->setWasSaw(true);
					visivel(linha, coluna);
				}
				else {
					jogador->addEdificio(edi);
					bloco->setEmpty(false);
				}
			}
		}
		if (oque == "quin" || oque == "quinta"){
			edi = new Quinta(linha, coluna);
			if (jogador->checkAddEdificio(edi)){
				jogador->addEdificio(edi);
				if (jogador->getNomePop() == playerOne->getNomePop()){

					bloco->setEmpty(false);
					bloco->setWasSaw(true);
					visivel(linha, coluna);
				}
				else {
					jogador->addEdificio(edi);
					bloco->setEmpty(false);
				}
			}
		}
	}
}

void Game::setu(string nome, string oque, int linha, int coluna){
	jogador = myMapa->getPopulacao(nome);
	bloco = myMapa->getBloco(linha, coluna);

	if (jogador != nullptr && bloco != nullptr){
		if (oque == "sold" || oque == "soldado"){
			uni = new Soldado(linha, coluna);
			jogador->addUnidade(uni);

			if (jogador->getNomePop() == playerOne->getNomePop()){
				bloco->setEmpty(false);
				bloco->setWasSaw(true);
				visivel(linha, coluna);
			}
			else {
				bloco->setEmpty(false);
			}
		}
		if (oque == "camp" || oque == "campones"){
			uni = new Campones(linha, coluna);
			jogador->addUnidade(uni);

			if (jogador->getNomePop() == playerOne->getNomePop()){
				bloco->setEmpty(false);
				bloco->setWasSaw(true);
				visivel(linha, coluna);
			}
			else {
				bloco->setEmpty(false);
			}
		}
		if (oque == "cav" || oque == "cavaleiro"){
			uni = new Cavaleiro(linha, coluna);
			jogador->addUnidade(uni);

			if (jogador->getNomePop() == playerOne->getNomePop()){
				bloco->setEmpty(false);
				bloco->setWasSaw(true);
				visivel(linha, coluna);
			}
			else {
				bloco->setEmpty(false);
			}
		}
		if (oque == "cv" || oque == "campAcavalo"){
			uni = new CampACavalo(linha, coluna);
			jogador->addUnidade(uni);

			if (jogador->getNomePop() == playerOne->getNomePop()){
				bloco->setEmpty(false);
				bloco->setWasSaw(true);
				visivel(linha, coluna);
			}
			else {
				bloco->setEmpty(false);
			}
		}
	}
}

void Game::setf(string oque, int linha, int coluna){
	bloco = myMapa->getBloco(linha, coluna);
	srand(time(0));
	int quant = (rand() % (120 - 60 + 1)) + 60;
	if (bloco != nullptr){
		if (oque == "min" || oque == "mina"){
			if (myMapa->addRecurso(linha, coluna, quant, 0))
				bloco->setEmpty(false);
		}
		if (oque == "ped" || oque == "pedra"){
			if (myMapa->addRecurso(linha, coluna, quant, 1))
				bloco->setEmpty(false);
		}
		if (oque == "flo" || oque == "floresta"){
			if (myMapa->addRecurso(linha, coluna, quant, 2))
				bloco->setEmpty(false);
		}
	}
}

int * Game::processaBloco(Bloco * _bloco){
	//jogador 1 -> vermelho claro -> 12
	//jogador 2 -> cor de rosa -> 13
	//jogador 3 -> amarelo claro -> 14
	//jogador 4 -> verde claro -> 10

	static int result[2];
	string nomeUni, nomeEdi, nomeRec;
	if (_bloco != nullptr){
		for (int i = 0; i < myMapa->getSizePop(); i++){
			for (int j = 0; j < myMapa->getPopByPos(i)->getSizeUnis(); j++){
				nomeUni = myMapa->getPopByPos(i)->getUniByPos(j)->getName();
				if (myMapa->getPopByPos(i)->getUniByPos(j)->getLin() == _bloco->getLin() && myMapa->getPopByPos(i)->getUniByPos(j)->getCol() == _bloco->getCol()){
					if (i == 0)
						result[0] = 12;
					if (i == 1)
						result[0] = 13;
					if (i == 2)
						result[0] = 1;
					if (i == 3)
						result[0] = 10;

					if (nomeUni.find('S') != string::npos)
						result[1] = 2;
					if (nomeUni.find('B') != string::npos)
						result[1] = 184;
					if (nomeUni.find('K') != string::npos)
						result[1] = 1;
					if (nomeUni.find('P') != string::npos)
						result[1] = 21;
				}
			}
			for (int k = 0; k < myMapa->getPopByPos(i)->getSizeEdis(); k++){
				nomeEdi = myMapa->getPopByPos(i)->getEdiByPos(k)->getName();
				if (myMapa->getPopByPos(i)->getEdiByPos(k)->getLin() == _bloco->getLin() && myMapa->getPopByPos(i)->getEdiByPos(k)->getCol() == _bloco->getCol()){
					if (i == 0)
						result[0] = 12;
					if (i == 1)
						result[0] = 13;
					if (i == 2)
						result[0] = 1;
					if (i == 3)
						result[0] = 10;

					if (nomeEdi.find('C') != string::npos)
						result[1] = 15;
					if (nomeEdi.find('Q') != string::npos)
						result[1] = 127;
					if (nomeEdi.find('F') != string::npos)
						result[1] = 23;
					if (nomeEdi.find('E') != string::npos)
						result[1] = 20;
				}
			}
		}

		if (myMapa->hasRecurso(_bloco->getLin(), _bloco->getCol())){
			fr = myMapa->getRecurso(_bloco->getLin(), _bloco->getCol());
			if (fr != nullptr){
				result[0] = 0;
				result[1] = 0;
				nomeRec = fr->getName();
				if (fr->getLin() == _bloco->getLin() && fr->getCol() == _bloco->getCol()){
					if (nomeRec.find('O') != string::npos){
						result[0] = 6;
						result[1] = 207;
					}
					if (nomeRec.find('P') != string::npos){
						result[0] = 8;
						result[1] = 157;
					}
					if (nomeRec.find('M') != string::npos){
						result[0] = 4;
						result[1] = 190;
					}
				}
			}
		}
	}
	else {
		result[0] = 1;
		result[1] = 178;
	}
	return result;
}

void Game::scroll(){
	char tecla;
	int difCol = 0, difLin = 0;
	difCol = myMapa->getColunas() - MAX_COL;
	difLin = myMapa->getLinhas() - MAX_LIN;

	while (1){
		tecla = myConsole->getch();
		if (tecla == 'c')
			break;
		if ((tecla != myConsole->ESQUERDA) && (tecla != myConsole->DIREITA) &&
			(tecla != myConsole->CIMA) && (tecla != myConsole->BAIXO)) continue;
		if (tecla == myConsole->ESQUERDA){
			if (scrollCol <= difCol && scrollCol > 0)
				scrollCol--;
		}
		if (tecla == myConsole->DIREITA){
			if (scrollCol < difCol)
				scrollCol++;
		}
		if (tecla == myConsole->CIMA){
			if (scrollLin <= difLin && scrollLin > 0)
				scrollLin--;
		}
		if (tecla == myConsole->BAIXO){
			if (scrollLin < difLin)
				scrollLin++;
		}
		myConsole->clrscr();
		printInterface();
	}
}

void Game::visivel(int l, int c){
	bloco = myMapa->getBloco(l, c);
	if (myMapa->getPopByPos(0) && bloco != nullptr){
		for (int i = 1; i <= 2; i++){
			for (int j = 1; j <= 2; j++){
				bloco = myMapa->getBloco(l + i, c); //linha baixo
				if (bloco != nullptr){
					bloco->setWasSaw(true);
				}
				bloco = myMapa->getBloco(l - i, c - j); //canto sup esquerdo
				if (bloco != nullptr){
					bloco->setWasSaw(true);
				}
				bloco = myMapa->getBloco(l + i, c - j); //canto inf esquerdo
				if (bloco != nullptr){
					bloco->setWasSaw(true);
				}
				bloco = myMapa->getBloco(l - i, c + j); //canto sup direito
				if (bloco != nullptr){
					bloco->setWasSaw(true);
				}
				bloco = myMapa->getBloco(l + i, c + j); //canto inf direito
				if (bloco != nullptr){
					bloco->setWasSaw(true);
				}
				bloco = myMapa->getBloco(l - i, c); //linha cima
				if (bloco != nullptr){
					bloco->setWasSaw(true);
				}

				bloco = myMapa->getBloco(l, c + j); //coluna direita
				if (bloco != nullptr){
					bloco->setWasSaw(true);
				}
				bloco = myMapa->getBloco(l, c - j); //coluna esquerda
				if (bloco != nullptr){
					bloco->setWasSaw(true);
				}
			}
		}
	}
}

void Game::load(string filename){
	fstream fich;
	fich.open(filename);
	if (fich.is_open()){
		string str;
		istringstream iss(str);

		while (getline(fich, str)){
			processCommand(str);
		}
		fich.close();
	}
	wasLoad = true;
}

bool Game::checkCanAddEdi(int linha, int coluna){
	for (int i = 0; i < myMapa->getSizePop(); i++){
		for (int j = 0; j < myMapa->getPopByPos(i)->getSizeEdis(); j++){
			edi = myMapa->getPopByPos(i)->getEdificio(myMapa->getPopByPos(i)->getEdiByPos(j)->getName());
			if (edi->getCol() == coluna && edi->getLin() == linha){
				return false;
				break;
			}
			else {
				return true;
				break;
			}
		}
		return true;
	}
}

void Game::mostra(string nome){
	jogador = myMapa->getPopulacao(nome);
	vector<string> vecmostra;

	vecmostra.clear();
	for (int i = 0; i < myMapa->getSizePop(); i++){
		if (myMapa->getPopByPos(i)->getNomePop() == nome){
			if (i == 0)
				myConsole->setTextColor(myConsole->VERMELHO_CLARO);
			if (i == 1)
				myConsole->setTextColor(myConsole->COR_DE_ROSA);
			if (i == 2)
				myConsole->setTextColor(myConsole->AZUL);
			if (i == 3)
				myConsole->setTextColor(myConsole->VERDE_CLARO);
			myConsole->gotoxy(93, 8);
			cout << nome;
		}
	}

	if (jogador != nullptr){
		myConsole->setTextColor(myConsole->PRETO);
		string aux;

		for (int i = 0; i < jogador->getSizeUnis(); i++){
			aux = jogador->getUniByPos(i)->getDetail();
			vecmostra.push_back(aux);
		}

		for (int j = 0; j < jogador->getSizeEdis(); j++){
			aux = jogador->getEdiByPos(j)->getDetail();
			vecmostra.push_back(aux);
		}

		for (size_t i = 0; i < vecmostra.size(); i++){
			if (i < 10){
				myConsole->gotoxy(71, 9 + i);
				cout << vecmostra[i];
			}
			if (i >= 10 && i < 20){
				myConsole->gotoxy(82, i - 1);
				cout << vecmostra[i];
			}
			if (i >= 20){
				myConsole->gotoxy(93, i - 11);
				cout << vecmostra[i];
			}
		}
	}
}

void Game::go(string nome, int linha, int coluna, string flag){
	int colDestino, linDestino;
	int colOrigem, linOrigem;
	if (nome == ".")
		nome = showname;
	for (int i = 0; i < myMapa->getSizePop(); i++){
		uni = myMapa->getPopByPos(i)->getUnidade(nome);
		if (uni != nullptr){
			colOrigem = uni->getCol();
			linOrigem = uni->getLin();
			if (flag == "go"){ //posicao + deslocamento
				colDestino = uni->getCol() + coluna;
				linDestino = uni->getLin() + linha;
				bloco = myMapa->getBloco(linDestino, colDestino);
				if (bloco != nullptr){
					if (myMapa->getPopByPos(i)->getNomePop() == playerOne->getNomePop()){
						uni->movimentar(linDestino, colDestino);
						bloco->setEmpty(false);
						bloco->setWasSaw(true);
						visivel(linDestino, colDestino);
					}
					else {
						uni->movimentar(linDestino, colDestino);
						bloco->setEmpty(false);
					}
					redefineEmpty(linOrigem, colOrigem);
				}
			}
			if (flag == "goto"){ //nova posicao
				colDestino = coluna;
				linDestino = linha;
				bloco = myMapa->getBloco(linDestino, colDestino);
				if (bloco != nullptr){
					if (myMapa->getPopByPos(i)->getNomePop() == playerOne->getNomePop()){
						uni->movimentar(linDestino, colDestino);
						bloco->setEmpty(false);
						bloco->setWasSaw(true);
						visivel(linDestino, colDestino);
					}
					else {
						uni->movimentar(linDestino, colDestino);
						bloco->setEmpty(false);
					}
					redefineEmpty(linOrigem, colOrigem);
				}
			}
		}
	}
}

void Game::sel(string nome){
	string nomeUni, nomeEdi;

	for (int i = 0; i < myMapa->getSizePop(); i++){
		for (int j = 0; j < myMapa->getPopByPos(i)->getSizeUnis(); j++){
			nomeUni = myMapa->getPopByPos(i)->getUniByPos(j)->getName();
			if (nomeUni == nome){
				myConsole->gotoxy(81, 25);
				cout << "Uni";
				myConsole->gotoxy(81, 26);
				cout << nome;
				myConsole->gotoxy(81, 27);
				cout << myMapa->getPopByPos(i)->getUniByPos(j)->getSaude();
			}
		}
		for (int k = 0; k < myMapa->getPopByPos(i)->getSizeEdis(); k++){
			nomeEdi = myMapa->getPopByPos(i)->getEdiByPos(k)->getName();
			if (nomeEdi == nome){
				myConsole->gotoxy(81, 25);
				cout << "Edi";
				myConsole->gotoxy(81, 26);
				cout << nome;
				myConsole->gotoxy(81, 27);
				cout << myMapa->getPopByPos(i)->getEdiByPos(k)->getEstado();
			}
		}
	}
}

void Game::redefineEmpty(int linha, int coluna){
	bloco = myMapa->getBloco(linha, coluna);
	if (bloco != nullptr){
		for (int i = 0; i < myMapa->getSizePop(); i++){
			for (int j = 0; j < myMapa->getPopByPos(i)->getSizeUnis(); j++){
				if (myMapa->getPopByPos(i)->getUniByPos(j)->getLin() == bloco->getLin() &&
					myMapa->getPopByPos(i)->getUniByPos(j)->getCol() == bloco->getCol()){
					bloco->setEmpty(false);
				}
				else
					bloco->setEmpty(true);
			}
		}
	}
}

void Game::mku(string oque){
	string nomeEdi;
	int lin, col;
	//int espaco = playerOne->contaQuinta();

	if (playerOne != nullptr){
		if (oque == "camp" || oque == "campones"){
			for (int i = 0; i < playerOne->getSizeEdis(); i++){
				nomeEdi = playerOne->getEdiByPos(i)->getName();
				if (nomeEdi.find('C') != string::npos && playerOne->getMadeira() >= 10 && playerOne->getOuro() >= 5){
					lin = playerOne->getEdiByPos(i)->getLin();
					col = playerOne->getEdiByPos(i)->getCol();
					uni = new Campones(lin, col);
					playerOne->addUnidade(uni);
				}
			}
		}
		if (oque == "sold" || oque == "soldado"){
			for (int i = 0; i < playerOne->getSizeEdis(); i++){
				nomeEdi = playerOne->getEdiByPos(i)->getName();
				if (nomeEdi.find('Q') != string::npos && playerOne->getMadeira() >= 10 && playerOne->getOuro() >= 10){
					lin = playerOne->getEdiByPos(i)->getLin();
					col = playerOne->getEdiByPos(i)->getCol();
					uni = new Soldado(lin, col);
					playerOne->addUnidade(uni);
				}
			}
		}
		if (oque == "cav" || oque == "cavaleiro"){
			for (int i = 0; i < playerOne->getSizeEdis(); i++){
				nomeEdi = playerOne->getEdiByPos(i)->getName();
				if (nomeEdi.find('E') != string::npos && playerOne->getMadeira() >= 20 && playerOne->getOuro() >= 10 && playerOne->getPedra() >= 5){
					lin = playerOne->getEdiByPos(i)->getLin();
					col = playerOne->getEdiByPos(i)->getCol();
					uni = new Cavaleiro(lin, col);
					playerOne->addUnidade(uni);
				}
			}
		}
		if (oque == "cv" || oque == "campACavalo"){
			for (int i = 0; i < playerOne->getSizeEdis(); i++){
				nomeEdi = playerOne->getEdiByPos(i)->getName();
				if (nomeEdi.find('E') != string::npos && playerOne->getMadeira() >= 20 && playerOne->getOuro() >= 5 && playerOne->getPedra() >= 5){
					lin = playerOne->getEdiByPos(i)->getLin();
					col = playerOne->getEdiByPos(i)->getCol();
					uni = new CampACavalo(lin, col);
					playerOne->addUnidade(uni);
				}
			}
		}
	}
}

void Game::mke(string nome, string oque, int linha, int coluna){
	int lin, col;
	string nomeUni;

	for (int i = 0; i < playerOne->getSizeUnis(); i++){
		nomeUni = playerOne->getUniByPos(i)->getName();
		if (nomeUni == nome && nomeUni.find('P') != string::npos){
			lin = playerOne->getUniByPos(i)->getLin();
			col = playerOne->getUniByPos(i)->getCol();
			if (lin != linha || col != coluna)
				go(nome, linha, coluna, "goto");
			bloco = myMapa->getBloco(linha, coluna);
				if (oque == "cast" || oque == "castelo"){
					edi = new Castelo(linha, coluna);
					playerOne->addEdificio(edi);
				}
				if (oque == "quar" || oque == "quartel"){
					edi = new Quartel(linha, coluna);
					playerOne->addEdificio(edi);
				}
				if (oque == "est" || oque == "estabulo"){
					edi = new Estabulo(linha, coluna);
					playerOne->addEdificio(edi);
				}
				if (oque == "quin" || oque == "quinta"){
					edi = new Quinta(linha, coluna);
					playerOne->addEdificio(edi);
				}
		}
	}
}
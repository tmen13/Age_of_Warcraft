#pragma once
#include "Consola.h"
#include "Mapa.h"
#include <random>

const int NUM_CMDS = 21; // numero de comandos
const int MAX_COL = 20;
const int MAX_LIN = 10;
static int scrollCol = 0;
static int scrollLin = 0;

vector<string> &split(const string &s, char delim, vector<string> &elems);
vector<string> split(const string &s, char delim);
bool is_number(const string& s);

class Game{
	Consola * myConsole;
	Populacao * jogador, * playerOne;
	Mapa * myMapa;
	Bloco * bloco;
	Unidade * uni;
	Edificio * edi;
	FonteRecurso * fr;
	bool status = false; // se existe um jogo ou nao
	bool userON = false;
	bool show = false;
	bool vista = false;
	bool wasLoad = false;
	string showname;
public:
	Game();
	~Game();

	void Start();  //começa o jogo
	void printStartUI();
	void printInterface();

	//metodo para os comandos
	void processCommand(string cmd);
	void mkgame(int linhas, int colunas);
	void pop(string nome);
	void sete(string nome, string oque, int linha, int coluna);
	void setu(string nome, string oque, int linha, int coluna);
	void load(string filename);
	void scroll();
	void next();
	void next(int inst);
	void enter();
	void go(string nome, int linha, int coluna, string flag);
	void setf(string oque, int linha, int coluna);
	void mostra(string nome);
	void sel(string nome);
	void mina(int id, int idfonte);
	void ataca(int id, int idvitima);
	void conserta(int id, int ide);
	void deambula(int id);
	void mke(string nome, string oque, int linha, int coluna);
	void mku(string oque);
	void visivel(int l, int c);


	//sons
	void PlayIntro();
	void StopSound();

	//misc
	void fillMapaWithBlocos();
	void fillMapaWithRecursos();
	void printMapa();
	int * processaBloco(Bloco * _bloco);
	bool checkCanAddEdi(int linha, int coluna);
	void redefineEmpty(int linha, int coluna);
};
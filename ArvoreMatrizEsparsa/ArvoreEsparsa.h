#pragma once
using namespace std;
#include "NoArvoreEsparsa.h"
#include "InfoArvoreEsparsa.h"
#ifndef ARVOREESPARSA_H_INCLUDED
#define ARVOREESPARSA_H_INCLUDED


class ArvoreEsparsa : 
{
public:
	ArvoreEsparsa(InfoArvoreEsparsa* valorPadrao);
	~ArvoreEsparsa();
	InfoArvoreEsparsa* pegar(int linha, int coluna);
	void inserir(int linha, int coluna, InfoArvoreEsparsa* valor);
private:
	NoArvoreEsparsa * raiz;
	void balancear() throw();
};

#endif
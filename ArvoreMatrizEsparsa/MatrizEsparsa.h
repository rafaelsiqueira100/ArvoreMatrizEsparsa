#pragma once
#include "ArvoreEsparsa.h"
#include "InfoArvoreEsparsa.h"
#include "MinhaInfo.h"
#ifndef MATRIZESPARSA_H_INCLUDED
#define MATRIZESPARSA_H_INCLUDED
class MatrizEsparsa
{
public:
	MatrizEsparsa(InfoArvoreEsparsa*);
	~MatrizEsparsa();
	
	InfoArvoreEsparsa* pegar(int, int);
	void inserir(int linha, int, InfoArvoreEsparsa*);
private:
	ArvoreEsparsa arvoreLinhas;
	InfoArvoreEsparsa*valorPadrao;
};
#endif

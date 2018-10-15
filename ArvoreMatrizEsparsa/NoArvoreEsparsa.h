#pragma once

#ifndef NOARVOREESPARSA_H_INCLUDED
#define NOARVOREESPARSA_H_INCLUDED
using namespace std;
#include<iostream>
#include "InfoArvoreEsparsa.h"
class NoArvoreEsparsa
{
public:
	NoArvoreEsparsa() throw(char*);
	~NoArvoreEsparsa();
	NoArvoreEsparsa(const NoArvoreEsparsa&) throw(char*);
	friend ostream& operator<< (ostream&, const NoArvoreEsparsa&) throw();
	NoArvoreEsparsa* getPtrNoFilho(unsigned char) const throw(char*);
	void setPtrNoFilho(NoArvoreEsparsa*, unsigned char) throw(char*);
	InfoArvoreEsparsa* getPtrInfo(unsigned int) const throw();
	char inserirVetorOrdem(NoArvoreEsparsa*)throw();
	char removerVetorOrdem(InfoArvoreEsparsa*, NoArvoreEsparsa*)throw();
	char isCheio() const throw();
	char isVazio() const throw();
	char isFolha() const throw();
	char haInfo(InfoArvoreEsparsa*) const throw();
	char haChave(InfoArvoreEsparsa*)const throw();
	char getEquilibrio() const throw();
	char getNiveis() const throw();
	void balancear() throw();
	void rotacaoEsquerda() throw();
	void rotacaoDireita() throw();
	void setChave(InfoArvoreEsparsa*) throw();
	InfoArvoreEsparsa* getChave() throw();
private:
	InfoArvoreEsparsa * info;
	NoArvoreEsparsa* esq;
	NoArvoreEsparsa* dir;
	InfoArvoreEsparsa* acharInfoPorLugar() throw(char*);
	char equilibrio;
	char calcularEquilibrio() throw();
	InfoArvoreEsparsa* menorDosMaiores() throw(char*);
	InfoArvoreEsparsa* maiorDosMenores() throw(char*);
	InfoArvoreEsparsa* chave;//chave seria o n�mero de linha/coluna
	void rotacaoDuplaEsquerda() throw();
	void rotacaoDuplaDireita() throw();

};
#endif
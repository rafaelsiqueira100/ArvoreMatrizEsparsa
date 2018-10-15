#pragma once
using namespace std;
#include "NoArvoreEsparsa.h"
#include "InfoArvoreEsparsa.h"
#include "NoArvoreEsparsa.h"
#ifndef ARVOREESPARSA_H_INCLUDED
#define ARVOREESPARSA_H_INCLUDED


class ArvoreEsparsa : InfoArvoreEsparsa
{
public:
	ArvoreEsparsa();
	ArvoreEsparsa(InfoArvoreEsparsa*);
	~ArvoreEsparsa();
	InfoArvoreEsparsa* pegar(int );
	void inserir(int , int, InfoArvoreEsparsa* );
	char haChave(InfoArvoreEsparsa*)const throw();
	friend ostream& operator<< (ostream&, const InfoArvoreEsparsa&) throw();
	char operator<(const InfoArvoreEsparsa&)const throw();
	char operator>(const InfoArvoreEsparsa&)const throw();
	char operator==(const InfoArvoreEsparsa&)const throw();
	char operator<=(const InfoArvoreEsparsa&)const throw();
	char operator>=(const InfoArvoreEsparsa&)const throw();
	InfoArvoreEsparsa& operator=(const InfoArvoreEsparsa&)throw();
	ostream& print(ostream&) const throw();

private:
	NoArvoreEsparsa * raiz;
	InfoArvoreEsparsa* valorPadrao;
	void balancear() throw();
};

#endif
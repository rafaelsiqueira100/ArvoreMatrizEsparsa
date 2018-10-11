#pragma once

#ifndef MINHAINFO_H_INCLUDED
#define MINHAINFO_H_INCLUDED
#include "InfoArvoreEsparsa.h"
#include <iostream>
using namespace std;
class MinhaInfo : public InfoArvoreEsparsa
{
public:
	MinhaInfo();
	MinhaInfo(int);
	MinhaInfo(const InfoArvoreEsparsa&) throw();
	friend ostream& operator<< (ostream&, const MinhaInfo&) throw();
	int getValor() const throw();
	void setValor(int) throw();
	char operator<(const InfoArvoreEsparsa&)const throw();
	char operator>(const InfoArvoreEsparsa&)const throw();
	char operator==(const InfoArvoreEsparsa&)const throw();
	char operator<=(const InfoArvoreEsparsa&)const throw();
	char operator>=(const InfoArvoreEsparsa&)const throw();
	InfoArvoreEsparsa& operator=(const InfoArvoreEsparsa&)throw();
	ostream& print(ostream&) const throw();

private:
	int valor;

};
#endif


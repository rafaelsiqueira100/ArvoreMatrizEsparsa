#include "stdafx.h"
#include "ArvoreEsparsa.h"


ArvoreEsparsa::ArvoreEsparsa()
{
}


ArvoreEsparsa::ArvoreEsparsa(InfoArvoreEsparsa* valorPadrao)
{
	this->valorPadrao = valorPadrao;
}

ArvoreEsparsa::~ArvoreEsparsa()
{
	if (this->raiz != nullptr)
		delete raiz;
}
ostream& operator<< (ostream& os, const InfoArvoreEsparsa& arvore) throw() {
	return arvore.print(os);
}
char ArvoreEsparsa::operator<(const InfoArvoreEsparsa& outra)const throw() {
	return this->raiz->getPtrInfo(0) < ((const ArvoreEsparsa&)outra).raiz->getPtrInfo(0);
}
char ArvoreEsparsa::operator>(const InfoArvoreEsparsa& outra)const throw() {
	return this->raiz->getPtrInfo(0) > ((const ArvoreEsparsa&)outra).raiz->getPtrInfo(0);
}
char ArvoreEsparsa::operator==(const InfoArvoreEsparsa& outra)const throw() {
	return this->raiz->getPtrInfo(0) == ((const ArvoreEsparsa&)outra).raiz->getPtrInfo(0);
}
char ArvoreEsparsa::operator<=(const InfoArvoreEsparsa& outra)const throw() {
	return this->raiz->getPtrInfo(0) <= ((const ArvoreEsparsa&)outra).raiz->getPtrInfo(0);
}
char ArvoreEsparsa::operator>=(const InfoArvoreEsparsa& outra)const throw() {
	return this->raiz->getPtrInfo(0) >= ((const ArvoreEsparsa&)outra).raiz->getPtrInfo(0);
}
InfoArvoreEsparsa& ArvoreEsparsa::operator=(const InfoArvoreEsparsa& outra)throw() {
	this->raiz = new NoArvoreEsparsa(*(((const ArvoreEsparsa&)outra).raiz));
	return *this;
}
ostream& ArvoreEsparsa::print(ostream& os) const throw() {
	if(this->raiz == nullptr)
		return os << "{  }" << '\n';
	return	os << '{' << *(this->raiz) << '}' << '\n';
}
char ArvoreEsparsa::haChave(InfoArvoreEsparsa* novoInfo)const throw() {
	return this->raiz->haChave(novoInfo);
}
InfoArvoreEsparsa* ArvoreEsparsa::pegar(int chave) {
	if (!haChave(chave))
		return nullptr;
	else {
		NoArvoreEnaria* noRel = this->raiz;
		while (1) {
			if (noRel == nullptr)
				return 0;
			if ((noRel->chave) != nullptr) {
				if (*(noRel->chave) == *chave) {
					return true;
				}
				if (*(noRel->chave) > *chave) {
					//ir pro ponteiro de nó i-1
					noRel = (noRel->esq);
					goto loop;
				}
				if (*(noRel->chave) < *chave) {
					noRel = (noRel->dir);
					goto loop;
				}

			}
			else {
				return 0;
			}
	}

}
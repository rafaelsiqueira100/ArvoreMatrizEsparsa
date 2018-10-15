#include "stdafx.h"
#include "MatrizEsparsa.h"


MatrizEsparsa::MatrizEsparsa(InfoArvoreEsparsa* valorPadrao)
{
	this->valorPadrao = valorPadrao;
	ArvoreEsparsa* arvorePadrao = nullptr;
	this->arvoreLinhas = *(new ArvoreEsparsa((InfoArvoreEsparsa*)arvorePadrao));//Valor padrão que não será armazenado na árvore de linhas será uma árvore de colunas vazia

}


MatrizEsparsa::~MatrizEsparsa()
{
}
InfoArvoreEsparsa* MatrizEsparsa::pegar(int linha, int coluna) {

}
void MatrizEsparsa::inserir(int linha, int coluna, InfoArvoreEsparsa*valor) {
	MinhaInfo* coluna = new MinhaInfo(coluna);
	MinhaInfo* linha = new MinhaInfo(linha);
	if (*valor == *valorPadrao) {

	}
	else {
		//inserir
		if (this->arvoreLinhas->haChave(linha)) {

		}
	}
}
#include "stdafx.h"
#include "MatrizEsparsa.h"


MatrizEsparsa::MatrizEsparsa(InfoArvoreEsparsa* valorPadrao) :
	arvoreLinhas(),
	valorPadrao(valorPadrao),
	menorLinha(0),
	menorColuna(0),
	maiorLinha(-1),
	maiorColuna(-1),
	vazia(1),
	numElementos(0)
{}


MatrizEsparsa::~MatrizEsparsa()
{
	if (this->valorPadrao != nullptr)
		delete this->valorPadrao;
}
InfoArvoreEsparsa* MatrizEsparsa::pegar(int linha, int coluna) {
	MinhaInfo li(linha);//chave=linha
	MinhaInfo col(coluna);//chave=coluna
	if (this->arvoreLinhas.haInfo(&li)) {
		MinhaInfo* infoLinha = (MinhaInfo*)(this->arvoreLinhas.pegar(li));
		ArvoreEsparsa* arvoreColunas = (ArvoreEsparsa*)((*infoLinha).getInfo());
		if ((*arvoreColunas).haInfo(&col)) {
			MinhaInfo* infoColuna = (MinhaInfo*)((*arvoreColunas).pegar(col));
			return (*infoColuna).getInfo();
		}
		else {//n�o existe essa coluna na �rvore
			
			return valorPadrao;
		}
	}
	else {//n�o existe essa linha na �rvore
		return valorPadrao;
	}
}
void MatrizEsparsa::inserir(int linha, int coluna, InfoArvoreEsparsa*valor) throw(char*){
	if (vazia) {
		this->menorLinha = linha;
		this->maiorLinha = linha;
		this->menorColuna = coluna;
		this->maiorColuna = coluna;
	}
	else {
		if (linha < this->menorLinha)
			this->menorLinha = linha;
		if (linha > this->maiorLinha)
			this->maiorLinha = linha;
		if (coluna < this->menorColuna)
			this->menorColuna = coluna;
		if (coluna > this->maiorColuna)
			this->maiorColuna = coluna;
	}
	vazia = 0;

	MinhaInfo* li = new MinhaInfo(linha);//chave=linha
		if (this->arvoreLinhas.haInfo(li)) {
			//alterar
			
			MinhaInfo* infoLinha = (MinhaInfo*)(this->arvoreLinhas.pegar(*li));
			ArvoreEsparsa* arvoreColunas = (ArvoreEsparsa*)((*infoLinha).getInfo());
			if (arvoreColunas == nullptr) {
				//throw("�rvore de colunas nula!");
				return;
			}
			MinhaInfo* col = new MinhaInfo(coluna);//chave=coluna
			if ((*arvoreColunas).haInfo(col)) {
				//alterar
				if (*valor == *valorPadrao) {
				//remover
					(*arvoreColunas).remover(col);
					this->numElementos--;
					
					if (this->numElementos == 0)
						this->vazia = 1;
				}
				else {
					//altera o valor
					MinhaInfo* infoColuna = (MinhaInfo*)((*arvoreColunas).pegar(*col));
					(*infoColuna).setInfo(*valor);
				}
			}
			else {//n�o existe essa coluna na �rvore
				//inserir outro n�
				if (*valor == *valorPadrao) {
				//n�o faz nada
				}
				else {
					//insere essa coluna e valor na �rvore
					
					MinhaInfo* col = new MinhaInfo(coluna, valor);
					//linha-coluna tem um valor
					(*arvoreColunas).inserir(col);
					this->numElementos++;
				}
			}
		}
		else {//n�o existe essa linha na �rvore
		//inserir outro n�
			if (*valor == *valorPadrao) {
				//n�o faz nada
			}
			else{
				//insere essa linha, coluna e valor na �rvore
		
				MinhaInfo* col = new MinhaInfo(coluna, valor);//linha-coluna tem um valor
				ArvoreEsparsa* arvoreColunas = new ArvoreEsparsa();
				(*arvoreColunas).inserir(col);
				MinhaInfo* novaLi = new MinhaInfo(linha, arvoreColunas);
				//linha tem uma info
				this->arvoreLinhas.inserir(novaLi);
				this->numElementos++;
			
			}
		}
	}



ostream& operator<<(ostream& os, const MatrizEsparsa& matriz) throw()
{
	os << "{ " << '\n' <<
		"Valor padrao = [ ";
		
	if (matriz.valorPadrao == nullptr)
		os << "null";
	else
		os << (*((MinhaInfo*)(matriz.valorPadrao))).getChave();
	os << ']' << '\n';
	os <<'\n' <<"Matriz = " << '\n';
	int indiceLinhas, indiceColunas;
	char haLinha, haColuna;
	if (matriz.vazia)
		os << "nada" << '\n';
	else {
		for (indiceLinhas = matriz.menorLinha; indiceLinhas <= matriz.maiorLinha; indiceLinhas++) {
			MinhaInfo* infoLinha = new MinhaInfo(indiceLinhas);
			haLinha = (((matriz).arvoreLinhas)).haInfo(infoLinha);

			//(ArvoreEsparsa) ((MinhaInfo)(matriz.arvoreLinhas.pegar(*(new MinhaInfo(indiceLinhas))))).getInfo();

			infoLinha = (MinhaInfo*)((*(ArvoreEsparsa*)(&matriz.arvoreLinhas))).pegar((const InfoArvoreEsparsa&)*infoLinha);
			ArvoreEsparsa* arvoreColunas = (ArvoreEsparsa*)(infoLinha->getInfo());
			for (indiceColunas = matriz.menorColuna; indiceColunas <= matriz.maiorColuna; indiceColunas++) {
				MinhaInfo* infoColuna = new MinhaInfo(indiceColunas);
				if (!haLinha) {
					os << " [ " << (*((MinhaInfo*)(matriz.valorPadrao))).getChave() << " ] ";
				}
				else {
					haColuna = (*arvoreColunas).haInfo(infoColuna);
					if (!haColuna) {
						os << " [ " << (*((MinhaInfo*)(matriz.valorPadrao))).getChave() << " ] ";
					}
					else {
						infoColuna = (MinhaInfo*)((*arvoreColunas).pegar((const InfoArvoreEsparsa&)*infoColuna));
						os << " [ " << (*(MinhaInfo*)(infoColuna->getInfo())).getChave() << " ] ";
					}
				}
			}
			os << '\n';
		}
	}
	os << "} " << '\n';
	return os;
}

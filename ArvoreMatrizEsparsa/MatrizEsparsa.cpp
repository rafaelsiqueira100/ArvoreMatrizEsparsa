#include "stdafx.h"
#include "MatrizEsparsa.h"


MatrizEsparsa::MatrizEsparsa(InfoArvoreEsparsa* valorPadrao) :
	arvoreLinhas(),
	valorPadrao(valorPadrao),
	menorLinha(0),
	menorColuna(0),
	maiorLinha(-1),
	maiorColuna(-1),
	vazia(1)
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
		else {//não existe essa coluna na árvore
			
			return valorPadrao;
		}
	}
	else {//não existe essa linha na árvore
		return valorPadrao;
	}
}
void MatrizEsparsa::inserir(int linha, int coluna, InfoArvoreEsparsa*valor) {
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
	MinhaInfo li (linha);//chave=linha
	MinhaInfo col(coluna);//chave=coluna
	
		if (this->arvoreLinhas.haInfo(&li)) {
			//alterar
			MinhaInfo* infoLinha = (MinhaInfo*)(this->arvoreLinhas.pegar(li));
			ArvoreEsparsa* arvoreColunas = (ArvoreEsparsa*)((*infoLinha).getInfo());
				if ((*arvoreColunas).haInfo(&col)) {
					//alterar
					if (*valor == *valorPadrao) {
					//remover
						(*arvoreColunas).remover(&col);
					}
					else {
						//altera o valor
						MinhaInfo* infoColuna = (MinhaInfo*)((*arvoreColunas).pegar(col));
						(*infoColuna).setInfo(*valor);
					}
				}
				else {//não existe essa coluna na árvore
					//inserir outro nó
					if (*valor == *valorPadrao) {
					//não faz nada
					}
					else {
						//insere essa coluna e valor na árvore
						col.setInfo(*valor);//linha-coluna tem um valor
						(*arvoreColunas).inserir(&col);
					}
				}
		}
		else {//não existe essa linha na árvore
		//inserir outro nó
			if (*valor == *valorPadrao) {
				//não faz nada
			}
			else{
				//insere essa linha, coluna e valor na árvore
				col.setInfo(*valor);//linha-coluna tem uma info
				ArvoreEsparsa* arvoreColunas = new ArvoreEsparsa();
				(*arvoreColunas).inserir(&col);
				li.setInfo(*arvoreColunas);//linha tem uma info
				this->arvoreLinhas.inserir(&li);

			
			}
		}
	}



ostream& operator<<(ostream& os, const MatrizEsparsa& matriz) throw()
{
	//mudar isso
	os << "{ " << '\n' <<
		"Valor padrao = [ ";
		
	if (matriz.valorPadrao == nullptr)
		os << "null";
	else
		os << ((MinhaInfo)(*matriz.valorPadrao)).getChave();
	os << ']' << '\n';
	os << "Matriz = " << '\n';
	int indiceLinhas, indiceColunas;
	char haLinha, haColuna;

	for (indiceLinhas = matriz.menorLinha; indiceLinhas <= matriz.maiorLinha; indiceLinhas++) {
		MinhaInfo* infoLinha = new MinhaInfo(indiceLinhas);
		haLinha = (((matriz).arvoreLinhas)).haInfo(infoLinha);
		
		//(ArvoreEsparsa) ((MinhaInfo)(matriz.arvoreLinhas.pegar(*(new MinhaInfo(indiceLinhas))))).getInfo();
		
		infoLinha = (MinhaInfo*)((ArvoreEsparsa)(matriz.arvoreLinhas)).pegar((const InfoArvoreEsparsa&)*infoLinha);
		ArvoreEsparsa arvoreColunas = *(ArvoreEsparsa*)(infoLinha->getInfo());
		for (indiceColunas = matriz.menorColuna; indiceColunas <= matriz.maiorColuna; indiceColunas++) {
			MinhaInfo* infoColuna = new MinhaInfo(indiceColunas);
			if (!haLinha) {
				os << " [ " << matriz.valorPadrao << " ] ";
			}
			else {
				haColuna = arvoreColunas.haInfo(infoColuna);
				if (!haColuna) {
					os << " [ " << matriz.valorPadrao << " ] ";
				}
				else {
					infoColuna = (MinhaInfo*)(arvoreColunas.pegar((const InfoArvoreEsparsa&)*infoColuna));
					os << " [ " << infoColuna->getInfo() << " ] ";
				}
			}
		}
		os << '\n';
	}
	if ((matriz).maiorLinha < (matriz).menorLinha)
		os << "nada"<<'\n';
	os << "} " << '\n';
	return os;
}

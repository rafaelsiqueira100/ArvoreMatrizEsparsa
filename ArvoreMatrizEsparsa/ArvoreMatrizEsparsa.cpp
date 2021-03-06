// ArvoreMatrizEsparsa.cpp : define o ponto de entrada para o aplicativo do console.
//


#include "MatrizEsparsa.h"
#include "MinhaInfo.h"

int main()
{
	
	int valorPadrao;
	
	valorPadrao = 0;
	cout << " Digite o valor inteiro mais comum da matriz : " << '\n';
	cin >> valorPadrao ;
	if (cin.fail()) {
		return 1;
	}
	
	MinhaInfo* infoPadrao = new MinhaInfo(valorPadrao);
	MatrizEsparsa matriz(infoPadrao);
	int linha, coluna, novoValor;
	MinhaInfo* novaInfo = nullptr;
	int opcao;
	cout << "O que deseja fazer ?" << '\n';
	cout << " 0		- PRINTAR A MATRIZ" << '\n';
	cout << " 1		- INSERIR NA MATRIZ" << '\n';
	cout << " 2		- OBTER ELEMENTO DA MATRIZ"<<'\n';
	cout << " OUTRO		- SAIR" << '\n';
	cin >> opcao;
	while (opcao+1) {
		switch (opcao) {
			case 0:
				cout << matriz;
				break;
			case 1:
				cout << "Digite a linha desejada para inserir :";
				cin >> linha;
				cout << "Digite a coluna desejada para inserir :";
				cin >> coluna;
				cout << "Digite o valor desejado para inserir :";
				cin >> novoValor;
				novaInfo = new MinhaInfo(novoValor);
				matriz.inserir(linha, coluna, novaInfo);
				cout << matriz;

				break;
			case 2:
				cout << "Digite a linha desejada para selecionar :";
				cin >> linha;
				cout << "Digite a coluna desejada para selecionar :";
				cin >> coluna;
				novaInfo = new MinhaInfo(*matriz.pegar(linha, coluna));
				cout << " Elemento ["<< linha <<"]["<< coluna <<"] = " << *novaInfo;
				break;
			default:
				return 0;
		}
		cout << '\n';
		cout << "O que deseja fazer ?" << '\n';
		cout << " 0		- PRINTAR A MATRIZ" << '\n';
		cout << " 1		- INSERIR NA MATRIZ" << '\n';
		cout << " 2		- OBTER ELEMENTO DA MATRIZ" << '\n';
		cout << " OUTRO		- SAIR" << '\n';
		cin >> opcao;
		
	}
fim:if (infoPadrao != nullptr)
		delete infoPadrao;
	if (novaInfo != nullptr)
		delete novaInfo;
	
}


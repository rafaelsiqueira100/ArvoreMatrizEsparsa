// ArvoreMatrizEsparsa.cpp : define o ponto de entrada para o aplicativo do console.
//


#include "MatrizEsparsa.h"
#include "MinhaInfo.h"
int main()
{
	char x;
	cout << " Digite o valor mais comum da matriz : ";
	int valorPadrao;
	cin >> valorPadrao;
	MinhaInfo* infoPadrao = new MinhaInfo(valorPadrao);
	MatrizEsparsa matriz(infoPadrao);
	int linha, coluna, novoValor;
	MinhaInfo* novaInfo = nullptr;
	int opcao;
	cout << "O que deseja fazer ?";
	cout << " 0 - SAIR";
	cout << " 1 - PRINTAR A MATRIZ";
	cout << " 2 - INSERIR NA MATRIZ";
	cout << " 3 - OBTER ELEMENTO DA MATRIZ"<<'\n';
	cin >> opcao;
	while (opcao) {
		switch (opcao) {
			case 1:
				cout << matriz;
				break;
			case 2:
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
			case 3:
				cout << "Digite a linha desejada para selecionar :";
				cin >> linha;
				cout << "Digite a coluna desejada para selecionar :";
				cin >> coluna;
				novaInfo = new MinhaInfo(*matriz.pegar(linha, coluna));
				cout << " Elemento ["<< linha <<"]["<< coluna <<"] = " << *novaInfo;
				break;
		}
		cout << '\n';
		cout << "O que deseja fazer ?";
		cout << " 0 - SAIR";
		cout << " 1 - PRINTAR A MATRIZ";
		cout << " 2 - INSERIR NA MATRIZ";
		cout << " 3 - OBTER ELEMENTO DA MATRIZ"<<'\n';
		cin >> opcao;
	}
	delete infoPadrao;
	if(novaInfo!=nullptr)
		delete novaInfo;
}


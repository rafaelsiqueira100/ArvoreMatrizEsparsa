
#include "MinhaInfo.h"
MinhaInfo::MinhaInfo() : valor(0) {}

MinhaInfo::MinhaInfo(int vlr) {
	this->valor = vlr;
}
MinhaInfo::MinhaInfo(const InfoArvoreEsparsa& outra) :
	MinhaInfo(((const MinhaInfo&)outra).valor)
{}
ostream& operator<< (ostream& os, const MinhaInfo& info) throw() {
	return info.print(os);
}
ostream& MinhaInfo::print(ostream& os)const throw() {
	return os << this->valor;
}
int MinhaInfo::getValor()const throw() {
	return this->valor;
}
void MinhaInfo::setValor(int novoValor) throw() {
	this->valor = (novoValor);
}
char MinhaInfo::operator<(const InfoArvoreEsparsa& outra)const throw() {
	return this->valor <((const MinhaInfo&)outra).getValor();
}
char MinhaInfo::operator>(const InfoArvoreEsparsa& outra)const throw() {
	return this->valor > ((const MinhaInfo&)outra).getValor();
}
char MinhaInfo::operator==(const InfoArvoreEsparsa& outra)const throw() {
	return this->valor == ((const MinhaInfo&)outra).getValor();
}
char MinhaInfo::operator<=(const InfoArvoreEsparsa& outra)const throw() {
	return this->valor <= ((const MinhaInfo&)outra).getValor();
}
char MinhaInfo::operator>=(const InfoArvoreEsparsa& outra)const throw() {
	return this->valor >= ((const MinhaInfo&)outra).getValor();
}
InfoArvoreEsparsa& MinhaInfo::operator=(const InfoArvoreEsparsa& outra)throw() {
	valor = (((const MinhaInfo&)outra).valor);
	return *this;
}

#include "Estil.hxx"

Estil::Estil(const std::string& nomEstil): _nom(nomEstil) {}

std::string Estil::nom()
{
	return _nom;
}


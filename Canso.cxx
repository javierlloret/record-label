#include "Canso.hxx"
#include "Estil.hxx"

#include <iostream>

Canso::Canso(){}
Canso::Canso(const std::string& titol): _titol(titol) {}

Canso::~Canso()
{
	_llistaNomsFitxers.clear();

}

//Methods
void Canso::titol(const std::string& titol)
{
	_titol=titol;
}

void Canso::autor(const std::string& autor)
{
	_autor=autor;
}

std::string Canso::autor()
{		
	return _autor;
}

std::string Canso::fitxersAText(const std::string& directori)
{
	std::string aux;
	std::string fit;

	_llistaNomsFitxers.sort();

	for(LlistaNomsFitxers::iterator it=_llistaNomsFitxers.begin();it!=_llistaNomsFitxers.end();it++)
	{
		aux+=directori+(*it)+"\n";
	}
	return aux;

}

void Canso::llistaNomsFitxers(LlistaNomsFitxers& pllistaNomsFitxers)
{
	_llistaNomsFitxers=pllistaNomsFitxers;
}

void Canso::afegeixEstil(Estil* estil)
{
	_llistaPuntersAEstils.push_back(estil);
}


bool Canso::isEstil(const std::string nomEstil)
{
	for(LlistaPuntersAEstils::iterator it=_llistaPuntersAEstils.begin();it!=_llistaPuntersAEstils.end();it++)
	{
		if(nomEstil==(*it)->nom())
			return true;
	}

	return false;
}

std::string Canso::estilsAText()
{
	std::string text;

	for(LlistaPuntersAEstils::iterator it=_llistaPuntersAEstils.begin();it!=_llistaPuntersAEstils.end();it++)
	{
		text+=(*it)->nom() + "\n";
	}

	return text;
}

void Canso::fitxerWav(const std::string& fitxerWav)
{
	_fitxerWav=fitxerWav;
}

std::string Canso::fitxerWav()
{
	return _fitxerWav;
}

void Canso::anyProduccio(const std::string& anyProduccio )
{
	_anyProduccio=anyProduccio;
}

void Canso::infoAddicional(const std::string& infoAdicional)
{
	_InfoAdicional=infoAdicional;
}

std::string Canso::titol()
{
	return _titol;
}

std::string Canso::anyProduccio()
{
	return _anyProduccio;
}

std::string Canso::converteixAText()
{
	std::string tempCanso;
	tempCanso+="titol: "+titol()+"\n";
	tempCanso+="autor: "+autor()+"\n";
	tempCanso+="fitxer original: "+fitxerWav()+"\n";
	return tempCanso;
}

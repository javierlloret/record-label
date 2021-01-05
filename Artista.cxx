#include "Artista.hxx"

Artista::Artista() {}
Artista::Artista(std::string nom):_nom(nom) {}

Artista::~Artista()
{
	_diccionariCansons.clear();
}


//Public methods

void Artista::nom( const std::string& nom )
{
	_nom=nom;
}

void Artista::afegirCanso(Canso& canso)
{
	_diccionariCansons.afegeix(canso.titol(),canso);
}

Canso Artista::obtenirCanso(std::string clau)
{
	return _diccionariCansons.obte(clau);
}

std::string Artista::nom() const
{
	return _nom;
}
void Artista::descripcio( const std::string& descripcio )
{
	_descripcio=descripcio;
}
std::string Artista::descripcio() const
{
	return _descripcio;
}
void Artista::esGrup( bool esGrup )
{
	_esGrup=esGrup;
}
bool Artista::esGrup() const
{
	return _esGrup;
}
void Artista::componentsGrup( const std::string& nomsComponents )
{
	_nomsComponents=nomsComponents;
}

std::string Artista::tornaCansons()
{
	return _diccionariCansons.imprimeixClaus();
}

std::string Artista::componentsGrup() const
{
	return _nomsComponents;
}

std::string Artista::converteixAText()
{
	std::string tempString;

	tempString+="artist: "+nom();
	tempString+="\n";
	tempString+="description: "+descripcio();
	tempString+="\n";
	tempString+="is band?:" ;
	tempString+=esGrup()? " yes" : " no";
	tempString+="\n";
	tempString+="band members: "+componentsGrup()+"\n";

	return tempString;
}

std::string Artista::tornaEstils()
{
	std::string tempString;

	_diccionariCansons.initIndex();

	for(int i=0;i<(_diccionariCansons.size());i++)
		tempString+=(_diccionariCansons.obteNext()).estilsAText();

	return tempString;

}

void Artista::initDiccionariCansons()
{
	_diccionariCansons.initIndex();
}

Canso& Artista::tornaNextCanso()
{
	return _diccionariCansons.obteNext();
}

int Artista::DiccionariCansonsSize()
{
	return _diccionariCansons.size();
}

#ifndef Artista_hxx
#define Artista_hxx

#include <map>
#include <fstream>
#include "Canso.hxx"
#include "Diccionari.hxx"
#include "NotificadorNovaCanso.hxx"

// <<ConcretSubject>> from Observer pattern
class Artista : public NotificadorNovaCanso
{
public:

	Artista();
	Artista(std::string nom);
	~Artista();


	void nom( const std::string& nom );

	void afegirCanso(Canso& canso);

	Canso obtenirCanso(std::string clau);

	std::string nom() const;

	void descripcio( const std::string& descripcio );

	std::string descripcio() const;

	void esGrup( bool esGrup );

	bool esGrup() const;

	void componentsGrup( const std::string& nomsComponents );

	std::string tornaCansons();

	std::string componentsGrup() const;

	std::string converteixAText();

	std::string tornaEstils();

	void initDiccionariCansons();

	Canso& tornaNextCanso();

	int DiccionariCansonsSize();


private:

	std::string _nom;
	std::string _descripcio;
	std::string _nomsComponents;
	bool _esGrup;
	Diccionari<Canso> _diccionariCansons;

};

#endif

#ifndef Facade_hxx
#define Facade_hxx

#include <string>
#include <list>
#include "Artista.hxx"
#include "FileSystemHelper.hxx"
#include "Canso.hxx"
#include "Diccionari.hxx"
#include "GrupDeConversors.hxx"
#include "Estil.hxx"
#include "Usuari.hxx"
#include "NovetatsWeb.hxx"
#include "InfoCanso.hxx"
#include <iostream>


class Facade
{

	typedef std::list<Estil> LlistaEstils;
	typedef std::list<std::string> LlistaNomsEstils;
	typedef std::list<Usuari> LlistaUsuaris;


public:
	Facade();
	Facade(const std::string& fitxerName);
	~Facade();

	void afegeixArtista( const Artista& nouArtista );

	std::string artistesAText();

	std::string titolsDeArtista(const std::string& idArtista);

	void afegeixCanso(const std::string& idArtista, const InfoCanso& info, const std::string& pFitxerWav );

	void directoriFormatsComprimits(const std::string& directori);

	std::string fitxersComprimits(const std::string& nomArtista,const std::string& titolCanso);

	void converteix(const std::string& nfitxer,const std::string& dirSortida,const std::string& prefixe);

	void afegeixEstil(const std::string& nomEstil);

	std::string llistaEstils();

	std::string estilsDeCanso(const std::string& idArtista,const std::string& titol);

	std::string estilsDeArtista(std::string nomArtista);

	std::string artistesDeEstil(std::string nomEstil);

	void afegeixUsuari(const std::string& nom,const std::string& email);

	void subscriuUsuariAEstil(const std::string& idUsuari,const std::string& nomEstil);

	void subscriuUsuariAArtista(const std::string& nomUsuari, const std::string& nomArtista);

	void subscriuNovetatsWebAEstil(const std::string& nomEstil);

	void subscriuNovetatsWebAArtista(const std::string& nomArtista);

	std::string logNovetatsWeb();

	void usuariVolRebreSms(const std::string& nomUsuari,const std::string& nMobil);

private:
	Usuari* buscaUsuari(const std::string& nomUsuari);
	Estil* buscaEstil(const std::string& nomEstil);
	void creaConversors();
	bool isEstilAArtista(Artista& artista,std::string nomEstil);
	std::string directori();

	Diccionari<Artista> _diccionariArtistes;
	LlistaEstils _llistaEstils;
	LlistaUsuaris _llistaUsuaris;
	GrupDeConversors _grupDeConversors;
	std::string _directori;
	NovetatsWeb _novetatsWeb;
};

#endif

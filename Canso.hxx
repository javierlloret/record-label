#ifndef _Canso_hxx
#define _Canso_hxx

#include <string>
#include <list>


class Estil;

typedef std::list<Estil*> LlistaPuntersAEstils;	

class Canso
{
	typedef std::list<std::string> LlistaNomsFitxers;
	

public:

	Canso();
	
	Canso(const std::string& titol);
	
	~Canso();

	void titol(const std::string& titol); 

	void autor(const std::string& autor);

	std::string autor();

	std::string fitxersAText(const std::string& directori);

	void llistaNomsFitxers(LlistaNomsFitxers& pllistaNomsFitxers);

	void afegeixEstil(Estil* estil );
	
	bool isEstil(const std::string nomEstil);
	
	std::string estilsAText();

	void fitxerWav(const std::string& fitxerWav);

	std::string fitxerWav();
	
	void anyProduccio(const std::string& anyProduccio ); 
	
	void infoAddicional(const std::string& infoAdicional); 
	
	std::string titol();
	
	std::string anyProduccio();
	
	std::string converteixAText();


private:
	std::string _titol;
	std::string _autor;
	std::string _fitxerWav;
	std::string _anyProduccio;
	std::string _InfoAdicional;
	LlistaNomsFitxers _llistaNomsFitxers;
	LlistaPuntersAEstils _llistaPuntersAEstils;
};

#endif

		

 	

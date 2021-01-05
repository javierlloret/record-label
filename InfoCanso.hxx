#ifndef _InfoCanso_hxx
#define _InfoCanso_hxx

#include <string>
#include <list>

class Estil;

typedef std::list<std::string> LlistaIdEstils;

class InfoCanso
{

public:
	InfoCanso(const std::string& titol, const std::string& autor);
	~InfoCanso();

	void afegeixEstil(const std::string& nomEstil);
	LlistaIdEstils tornaEstils() const;
	int llistaSize() const;
	void initLlista() const;
	std::string obteNext() const;
	std::string titol() const;
	std::string autor() const;
		
private:
	LlistaIdEstils _llistaIdEstils;
	std::string _titol;
	std::string _autor;
	mutable int index;	//Utilizo un indice de la lista mutable


};


#endif

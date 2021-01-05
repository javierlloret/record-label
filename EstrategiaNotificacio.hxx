#ifndef _EstrategiaNotificacio_hxx
#define _EstrategiaNotificacio_hxx

#include <string>

class Usuari;
class Canso;

// <<Strategy>> del patro Strategy
class EstrategiaNotificacio
{
public:
	virtual void enviaNotificacio(Usuari& usuari,Canso& canso, const std::string& origen)=0;
};

#endif


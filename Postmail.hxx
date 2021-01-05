#ifndef Postmail_hxx
#define Postmail_hxx

#include <string>
#include "EstrategiaNotificacio.hxx"
#include "Canso.hxx"

// <<ConcreteStrategy>> del patro Strategy
class Postmail: public EstrategiaNotificacio
{
	public:
		void enviaNotificacio(Usuari& usuari,Canso& canso,const std::string& origen);
};
#endif

 



#ifndef Email_hxx
#define Email_hxx

#include <string>
#include "EstrategiaNotificacio.hxx"

// <<ConcreteStrategy>> from Strategy pattern
class Email: public EstrategiaNotificacio
{
	public:
		void enviaNotificacio(Usuari& usuari,Canso& canso,const std::string& origen);
};
#endif

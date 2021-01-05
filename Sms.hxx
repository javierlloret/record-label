#ifndef Sms_hxx
#define Sms_hxx

#include <string>
#include "EstrategiaNotificacio.hxx"
#include "Canso.hxx"
#include "MailStub.hxx" 

// <<ConcreteStrategy>> del patro Strategy
class Sms: public EstrategiaNotificacio
{
	public:
		void enviaNotificacio(Usuari& usuari,Canso& canso,const std::string& origen);


};

#endif




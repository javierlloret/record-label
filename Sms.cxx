#include "Sms.hxx"	
#include "MailStub.hxx"
#include "Usuari.hxx"

void Sms::enviaNotificacio(Usuari& usuari,Canso& canso,const std::string& origen)
{
	std::string missatge("[SingAlong] Nova canso ");
	missatge +=origen +": " + canso.titol();
	SmsStub::laInstancia().enviaSms(usuari.mobil(), missatge);
}


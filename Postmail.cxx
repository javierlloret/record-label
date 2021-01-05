#include "Postmail.hxx"	
#include "MailStub.hxx"
#include "Usuari.hxx"

void Postmail::enviaNotificacio(Usuari& usuari,Canso& canso,const std::string& origen)
{
	std::string missatgeTemp;
	std::string SingAlong="[SingAlong] ";
	std::string Noumissatge="Nova canso ";
	std::string postmailTemp=usuari.adresa();
	std::string assumpteTemp=SingAlong+"novetat "+origen;
	missatgeTemp=Noumissatge+origen+": "+canso.titol();	
	PostmailStub::laInstancia().enviaPostmail(postmailTemp,assumpteTemp,missatgeTemp);
}
	

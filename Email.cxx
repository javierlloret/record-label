#include "Email.hxx"	
#include "MailStub.hxx"
#include "Usuari.hxx"

void Email::enviaNotificacio(Usuari& usuari,Canso& canso,const std::string& origen)
{
	std::string missatgeTemp;
	std::string SingAlong="[SingAlong] ";
	std::string Noumissatge="Nova canso ";
	std::string emailTemp=usuari.email();
	std::string assumpteTemp=SingAlong+"novetat "+origen;
	missatgeTemp=Noumissatge+origen+": "+canso.titol();	
	MailStub::laInstancia().enviaMail(emailTemp,assumpteTemp,missatgeTemp);
}
	

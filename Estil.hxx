#ifndef _Estils_hxx
#define _Estils_hxx

#include <string>
#include "Usuari.hxx"
#include "MailStub.hxx"
#include "NotificadorNovaCanso.hxx"

// <<ConcretSubject>> from Observer pattern
class Estil : public NotificadorNovaCanso
{
public:

	Estil(const std::string& nomEstil);

	std::string nom();


private:
	std::string _nom;


};

#endif

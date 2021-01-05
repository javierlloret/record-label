#ifndef NovetatsWeb_hxx
#define NovetatsWeb_hxx

#include "ReceptorDeNotificacionsNovaCanso.hxx"
#include "MailStub.hxx"

// <<ConcreteObserver>> del patro Observer
class NovetatsWeb : public ReceptorDeNotificacionsNovaCanso
{
public:
	// metode update() implementat 
	void afegidaNovaCanso(Canso& canso,const std::string& origen);

	std::string log (void);
	

private:
	LogDeMissatges  _log;
	std::string _nomEstil;
	std::string _nomCanso;
};

#endif

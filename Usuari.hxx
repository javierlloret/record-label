#ifndef _Usuari_hxx
#define _Usuari_hxx

#include <string>
#include "Canso.hxx"
#include "ReceptorDeNotificacionsNovaCanso.hxx"
#include "MailStub.hxx"
#include "EstrategiaNotificacio.hxx"
#include "Sms.hxx"
#include "Email.hxx"

// <<ConcreteObserver>> from Observer pattern
// <<Context>> from Strategy pattern
class Usuari : public ReceptorDeNotificacionsNovaCanso
{
public:
	Usuari(std::string nom,std::string email);
	~Usuari();

	std::string& nom();

	std::string& email();

	std::string& adresa();

	void volRebreSms(const std::string& mobil);

	void volRebreCarta(const std::string& adresa);

	void notificaAmb(EstrategiaNotificacio* estrategia);

	void mobil(const std::string& mobil);

	void adresa(const std::string& adresa);

	std::string& mobil();

	// metode update from pattern
	void afegidaNovaCanso(Canso& canso,const std::string& origen);

private:
	std::string _nom;
	std::string _email;
	std::string _mobil;
	std::string _adresa;
	EstrategiaNotificacio* _estrategiaNotificacio;
};
#endif

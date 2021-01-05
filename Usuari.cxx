#include "Usuari.hxx"
#include "Postmail.hxx"


Usuari::Usuari(std::string nom,std::string email) : _nom(nom), _email(email) 
{
	_estrategiaNotificacio = NULL;
}

Usuari::~Usuari()
{
	delete[] _estrategiaNotificacio;
}

std::string& Usuari::nom()
{
	return _nom;
}

std::string& Usuari::email()
{
	return _email;
}

std::string& Usuari::adresa()
{
	return _adresa;
}

void Usuari::volRebreSms(const std::string& mobil)
{
	_mobil=mobil;
	notificaAmb(new Sms);
}

void Usuari::volRebreCarta(const std::string& adresa)
{
	_adresa=adresa;
	notificaAmb(new Postmail);
}

void Usuari::notificaAmb(EstrategiaNotificacio* estrategia)
{
	_estrategiaNotificacio = estrategia;
}

void Usuari::mobil(const std::string& mobil)
{
	_mobil=mobil;

}

void Usuari::adresa(const std::string& adresa)
{
	_adresa=adresa;
}

std::string& Usuari::mobil()
{
	return _mobil;
}

// metode update implementat
void Usuari::afegidaNovaCanso(Canso& canso,const std::string& origen)
{
	if(_estrategiaNotificacio==NULL)	notificaAmb(new Email);
	_estrategiaNotificacio->enviaNotificacio(*this, canso, origen);
}



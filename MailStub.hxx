#ifndef MailStub_hxx
#define MailStub_hxx

#include <string>
#include <list>

class LogDeMissatges
{
	typedef std::list<std::string> MissatgesEnviats;
public:

	void afegeixMissatge( const std::string& missatge )
	{
		_enviats.push_back(missatge);
	}

	//It returns all sent emails ordered alphabetically
	std::string log()
	{
		_enviats.sort();
		MissatgesEnviats::const_iterator it = _enviats.begin();
		std::string resultat;
		for (; it!=_enviats.end(); it++)
		{
			resultat += (*it)+"\n";
		}
		return resultat;
	}
	void esborraEnviats()
	{
		_enviats.clear();
	}
private:
	MissatgesEnviats _enviats;
};

// --------------------------------------------------------------------------------

class MailStub : public LogDeMissatges
{

	MailStub()	{}

public:

	static MailStub& laInstancia()
	{
		static MailStub _laInstancia;
		return _laInstancia;
	}

	void enviaMail(
		const std::string& a,
		const std::string& assumpte, const std::string& cosMissatge)
	{
		std::string mail= "A: " + a + "\n";
		mail += "Assumpte: " + assumpte + "\n";
		mail += "Missatge: " + cosMissatge;

		afegeixMissatge(mail);
	}

	//It returns all sent emails ordered alphabetically
	std::string mailsEnviats()
	{
		return log();
	}


};

// --------------------------------------------------------------------------------

class SmsStub : public LogDeMissatges
{
	SmsStub() {} //ctr privat: � un singleton

public:
	static SmsStub& laInstancia()
	{
		static SmsStub _laInstancia;
		return _laInstancia;
	}

	void enviaSms(const std::string& mobil, const std::string& noticia)
	{
		std::string missatge("SMS a ");
		missatge += mobil + ": " + noticia;
		afegeixMissatge(missatge);
	}

	//It returns all sent emails ordered alphabetically
	std::string missatgesEnviats()
	{
		return log();
	}

};

// --------------------------------------------------------------------------------

class PostmailStub : public LogDeMissatges
{
	//singleton pattern
	PostmailStub()	{}

public:

	static PostmailStub& laInstancia()
	{
		static PostmailStub _laInstancia;
		return _laInstancia;
	}

	void enviaPostmail(
		const std::string& a,
		const std::string& assumpte, const std::string& cosMissatge)
	{
		std::string mail= "A: " + a + "\n";
		mail += "Assumpte: " + assumpte + "\n";
		mail += "Missatge: " + cosMissatge;

		afegeixMissatge(mail);
	}

	//It returns all sent emails ordered alphabetically
	std::string postmailsEnviats()
	{
		return log();
	}


};


#endif

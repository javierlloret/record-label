#ifndef Exepcio_hxx
#define Exepcio_hxx

#include <string>

class ExepcioFitxerWavInexistent : public std::exception
	{
	public:

		virtual ~ExepcioFitxerWavInexistent() throw()
		{}

		virtual const char* what() const throw()
		{
			return "Fitxer WAV inexistent";

		}
	};

class ExepcioArtistaInexistent : public std::exception
	{
	public:
		virtual ~ExepcioArtistaInexistent() throw()
		{}
		virtual const char* what() const throw()
		{

			return "Facade::afegeixCanso : identificador d'artista inexistent";
		}
	};

class ExepcioUsuariInexistent : public std::exception
	{
	public:
		virtual ~ExepcioUsuariInexistent() throw()
		{}
		virtual const char* what() const throw()
		{

			return "Facade::buscaUsuari : identificador d'usuari inexistent";
		}
	};


class ExepcioEstilInexistent : public std::exception
	{
	public:
		virtual ~ExepcioEstilInexistent() throw()
		{}
		virtual const char* what() const throw()
		{

			return "Facade::buscaEstil : identificador de estil inexistent";
		}
	};

class ExepcioConversorIncorrecte : public std::exception
	{
	public:
		virtual ~ExepcioConversorIncorrecte() throw()
		{}
		virtual const char* what() const throw()
		{

			return "GrupDeConversors::crea : Conversor incorrecte";
		}
	};



class ExepcioParametreConversorIncorrecte : public std::exception
{

	public:
		virtual ~ExepcioParametreConversorIncorrecte() throw()
		{}
		virtual const char* what() const throw()
		{

			return "GrupDeConversors::crea : Parametre de conversor incorrecte";
		}

};


class ExepcioConversorMp3NoRetornaNomFitxerSortida : public std::exception
{

	public:
		virtual ~ExepcioConversorMp3NoRetornaNomFitxerSortida() throw()
		{}
		virtual const char* what() const throw()
		{

			return "ConversorMp3::converteix : No retorna nom de fitxer de sortida";
		}

};

class ExepcioConversorOggNoRetornaNomFitxerSortida : public std::exception
{

	public:
		virtual ~ExepcioConversorOggNoRetornaNomFitxerSortida() throw()
		{}
		virtual const char* what() const throw()
		{

			return "ConversorOgg::converteix : No retorna nom de fitxer de sortida";
		}

};

class ExepcioGrupConversorsNoRetornaLlistaFitxersSortida : public std::exception
{

	public:
		virtual ~ExepcioGrupConversorsNoRetornaLlistaFitxersSortida() throw()
		{}
		virtual const char* what() const throw()
		{

			return "GrupDeConversors::converteix : No retorna llista de noms de fitxers de sortida";
		}

};

class ClauNoTrobada : public std::exception
{
public:
	virtual ~ClauNoTrobada() throw() {}
	const char* what() const throw()
	{
		return "Identificador d'artista inexistent";
	}
};

class ClauRepetida : public std::exception
{
public:
	virtual ~ClauRepetida() throw() {}
	const char* what() const throw()
	{
		return "Clau ja introduida";
	}
};

class DiccionariBuit : public std::exception
{
public:
	virtual ~DiccionariBuit() throw() {}
	const char* what() const throw()
	{
		return "El diccionari no te elements";
	}
};




#endif

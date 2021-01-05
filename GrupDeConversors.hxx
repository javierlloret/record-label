#ifndef GrupDeConversors_hxx
#define GrupDeConversors_hxx

#include <string>
#include <list>

class Conversor;
class ConversorMp3;
class ConversorOgg;


typedef std::list<std::string> LlistaNomsFitxers;

class GrupDeConversors
{

	typedef std::list<Conversor*> LlistaConversors;


public:

	~GrupDeConversors();

	void crea(const std::string& tipusFormat,const std::string& sufixe);
	void afegeix(ConversorMp3* cmp3 );
	void afegeix(ConversorOgg* cOgg );
	LlistaNomsFitxers& converteix(const std::string& nfitxer,const std::string& dirSortida,const std::string& prefixe);
	void carregaConfiguracio (std::istream& input);


private:
	LlistaConversors _llistaConversors;
	LlistaNomsFitxers _llistaNomsFitxers;
	std::string _mp3;
	std::string _ogg;
};

#endif

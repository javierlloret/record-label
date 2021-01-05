#include "GrupDeConversors.hxx"
#include "Conversor.hxx"
#include "ConversorMp3.hxx"
#include "ConversorOgg.hxx"
#include "Exepcio.hxx"



GrupDeConversors::~GrupDeConversors()
{

	_llistaNomsFitxers.clear();

	for(LlistaConversors::iterator it=_llistaConversors.begin();it!=_llistaConversors.end();it++)
	{
		delete (*it);

	}

}

void GrupDeConversors::crea(const std::string& tipusFormat,const std::string& sufixe)
{
	_mp3="mp3";
	_ogg="ogg";

	frk_Rate temp;


	if(sufixe.compare("96"))
			temp=bps96;
	else
	if(sufixe.compare("128"))
			temp=bps128;
	else
	if(sufixe.compare("192"))
			temp=bps192;
	else
	if(sufixe.compare("240"))
			temp=bps240;
	else
		throw ExepcioParametreConversorIncorrecte();


	std::string parametre2="_";

	int tempInt;
	parametre2+=sufixe;

	if(_mp3.compare(tipusFormat)==0)
		afegeix(new ConversorMp3(temp,parametre2));
	else
	if(_ogg.compare(tipusFormat)==0)
	{
		tempInt=atoi(sufixe.c_str());
		afegeix(new ConversorOgg(tempInt,parametre2));
	}
	else
		throw ExepcioConversorIncorrecte();

}

void GrupDeConversors::afegeix(ConversorMp3* cmp3 )
{
	_llistaConversors.push_back(cmp3);
}

void GrupDeConversors::afegeix(ConversorOgg* cOgg )
{
	_llistaConversors.push_back(cOgg);
}

LlistaNomsFitxers& GrupDeConversors::converteix(const std::string& nfitxer,const std::string& dirSortida,const std::string& prefixe)
{
	//We clear the file list
	_llistaNomsFitxers.clear();

	for(LlistaConversors::iterator it=_llistaConversors.begin();it!=_llistaConversors.end();it++)
	{
		std::string temp=(*it)->converteix(nfitxer,dirSortida,prefixe);
		_llistaNomsFitxers.push_back(temp);
	}

	return _llistaNomsFitxers;
}


void GrupDeConversors::carregaConfiguracio(std::istream& input)
{
	std::string token1, token2;
	while (!input.eof())
	{
		input >> token1;

		if (!input.eof())
		{
			input >> token2;

			crea( token1, token2 );
		}
	}
}

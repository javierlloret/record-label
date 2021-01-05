#include "ConversorOgg.hxx"
 

ConversorOgg::ConversorOgg( int bps, std::string sufixe )
{
	_bps=bps;
	_sufixe=sufixe;
}

std::string ConversorOgg::converteix(std::string fitxerWav, std::string dirSortida, std::string prefixe)
{
 

	std::string tempString;
	std::string tempString2;

	_fitxerWav=fitxerWav;
	_directori=dirSortida;
	_prefixe=prefixe;

	int index=_fitxerWav.find("/");
	_fitxerWav.erase(_fitxerWav.begin(),_fitxerWav.begin()+index+1);
	tempString=_fitxerWav;

	int index2=tempString.find(".");
	tempString.erase(index2,tempString.size());

	tempString2=_directori+"/";
	tempString2+=_prefixe+tempString+_sufixe+".ogg";

	OGG::compress(fitxerWav,tempString2,getBps());

	return tempString2;
}

int ConversorOgg::getBps()
{
	return _bps;
}


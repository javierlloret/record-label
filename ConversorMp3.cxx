#include "ConversorMp3.hxx"
#include "FraunhofferTools.hxx"

ConversorMp3::ConversorMp3( frk_Rate bps, std::string sufixe ) : _bps(bps), _sufixe(sufixe){}

std::string ConversorMp3::converteix(std::string fitxerWav, std::string dirSortida, std::string prefixe)
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
	tempString2+=_prefixe+tempString+_sufixe+".mp3";

	frk_MP3_compression(fitxerWav.c_str(),tempString2.c_str(),getBps());


	return tempString2;

}

frk_Rate& ConversorMp3::getBps()
{
	return _bps;
}


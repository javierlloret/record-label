#ifndef ConversorMp3_hxx
#define ConversorMp3_hxx

#include <string>
#include <fstream>
#include "Conversor.hxx"
#include "FraunhofferTools.hxx"

class ConversorMp3 : public Conversor
{

public:
	ConversorMp3( frk_Rate bps, std::string sufixe );

	std::string converteix(std::string fitxerWav, std::string dirSortida, std::string prefixe);



private:
	frk_Rate& getBps();

	std::string _prefixe;	
	std::string _directori;
	std::string _sufixe;
	std::string _fitxerWav;
	frk_Rate _bps;
};


#endif

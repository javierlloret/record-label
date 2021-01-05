#ifndef ConversorOgg_hxx
#define ConversorOgg_hxx

#include <string>
#include "Conversor.hxx"
#include "OggCompressor.hxx"


class ConversorOgg : public Conversor
{
public:
	ConversorOgg( int bps, std::string sufixe );

	std::string converteix(std::string fitxerWav, std::string dirSortida, std::string prefixe);


private:
	int getBps();

	int _bps;
	std::string _prefixe;
	std::string _directori;
	std::string _sufixe;
	std::string _fitxerWav;
};


#endif

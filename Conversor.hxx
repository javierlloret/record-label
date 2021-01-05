#ifndef _Conversor_hxx
#define _Conversor_hxx
#include <string>
#include "Exepcio.hxx"

class Conversor
{

public:

	virtual std::string converteix(std::string nfitxer, std::string dirSortida, std::string prefixe)=0;

	virtual ~Conversor(){};
	
};
		
#endif
	

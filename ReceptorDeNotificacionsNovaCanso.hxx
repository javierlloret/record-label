#ifndef ReceptorDeNotificacionsNovaCanso_hxx
#define ReceptorDeNotificacionsNovaCanso_hxx

#include "Canso.hxx"
#include <string> 

class EstrategiaNotificacio;
// <<Observer>> del patro  Observer
class ReceptorDeNotificacionsNovaCanso
{
public:

	virtual ~ReceptorDeNotificacionsNovaCanso(){}

	// metode update() virtual
	virtual void afegidaNovaCanso(Canso& canso,const std::string& origen)=0;

 
};

#endif

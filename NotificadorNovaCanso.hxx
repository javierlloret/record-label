#ifndef NotificadorNovaCanso_hxx
#define NotificadorNovaCanso_hxx

#include "ReceptorDeNotificacionsNovaCanso.hxx"

class Canso;

// <<Subject>> from Observer pattern
class NotificadorNovaCanso
{

	typedef  std::list<ReceptorDeNotificacionsNovaCanso*> LlistaReceptors;

public:
	NotificadorNovaCanso();

	// method attach() from Observer
	void subscriu(ReceptorDeNotificacionsNovaCanso& receptor);

	// method notify() from Observer
	void notificaNovaCanso(Canso& canso, const std::string& origen);




private:

	LlistaReceptors _llistaReceptors;
};


#endif

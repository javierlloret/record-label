#include "NotificadorNovaCanso.hxx"

NotificadorNovaCanso::NotificadorNovaCanso()
{
}

// metode attach() del patro
void NotificadorNovaCanso::subscriu(ReceptorDeNotificacionsNovaCanso& receptor) 
{
	_llistaReceptors.push_back(&receptor);
}

// metode notify() del patro
void NotificadorNovaCanso::notificaNovaCanso(Canso& canso, const std::string& origen)
{
	for(LlistaReceptors::iterator it=_llistaReceptors.begin();it!=_llistaReceptors.end();it++)
	{
		(*it)->afegidaNovaCanso(canso, origen);
	}
}


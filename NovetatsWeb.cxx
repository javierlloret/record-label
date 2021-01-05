#include "NovetatsWeb.hxx"

 
void NovetatsWeb::afegidaNovaCanso(Canso& canso,const std::string& origen)
{
	std::string tempString;
	tempString="novetat "+origen+". Nova canso: "+canso.titol();
	_log.afegeixMissatge(tempString);
}

std::string NovetatsWeb::log (void)
{
	return _log.log();
}

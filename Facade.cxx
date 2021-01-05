#include "Facade.hxx"	
	
	
Facade::Facade(){}

Facade::Facade(const std::string& fitxerName)
{
	std::ifstream fitxer;
	
	fitxer.open(fitxerName.c_str());
	_grupDeConversors.carregaConfiguracio(fitxer);
	fitxer.close();	
}

Facade::~Facade()
{
	 _llistaEstils.clear();
	 _llistaUsuaris.clear();
	_diccionariArtistes.clear();

}


void Facade::afegeixArtista( const Artista& nouArtista )
{
	_diccionariArtistes.afegeix(nouArtista.nom(),nouArtista);
}

std::string Facade::artistesAText()
{
	std::string tempString;
	std::string auxString;
	std::string sortidaString;
	bool start=true;
	
	
	tempString=_diccionariArtistes.imprimeixClaus();

	if(tempString=="")
	{
		sortidaString="";
		return sortidaString;
	}

	while(true)
	{

		int index=tempString.find("\n");

		if(index<0)
			break;

		if(!start)
			sortidaString+="\n";	

		auxString=tempString.substr(0,index);
		sortidaString+=(_diccionariArtistes.obte(auxString)).converteixAText();
		tempString.erase(tempString.begin(),tempString.begin()+index+1);

		if(start)
			start=false;
	}
	return sortidaString;
}

std::string Facade::titolsDeArtista(const std::string& idArtista)	
{
	return _diccionariArtistes.obte(idArtista).tornaCansons();
}

void Facade::afegeixCanso(const std::string& idArtista, const InfoCanso& infoCanso, const std::string& nomFitxerWav )
{
 
	
	std::string prefixe;	
	Canso tempCanso;
	Estil* tempPunterEstil;

	
	//Añado título y autor a canción
	tempCanso.titol(infoCanso.titol());
	tempCanso.autor(infoCanso.autor());
	

	//Inicializo el índice de la lista de nombres de estilos de infocansons
	infoCanso.initLlista();	
	
	//Recorro los nombres de estilo de infocanso, los busco en nuestra lista de estilos y los introduzco en la canso
	for(int i=0;i<infoCanso.llistaSize();i++)
	{	
		tempPunterEstil = buscaEstil(infoCanso.obteNext());
		tempCanso.afegeixEstil(tempPunterEstil);
		tempPunterEstil->notificaNovaCanso(tempCanso,tempPunterEstil->nom()); 
	}

	tempCanso.fitxerWav(nomFitxerWav);	

	//Creamos los conversores
	creaConversors();

	prefixe=idArtista+"_";
	
	//Le paso la lista de noms de fitxers
	tempCanso.llistaNomsFitxers(_grupDeConversors.converteix(nomFitxerWav,directori(),prefixe));
		
	Artista tempArtista=_diccionariArtistes.obte(idArtista);
	tempArtista.notificaNovaCanso(tempCanso,idArtista);
	tempArtista.afegirCanso(tempCanso);
	_diccionariArtistes.afegeix(tempArtista.nom(),tempArtista);

}

void Facade::directoriFormatsComprimits(const std::string& directori)
{
	_directori=directori;
}


std::string Facade::fitxersComprimits(const std::string& nomArtista,const std::string& titolCanso)
{
	return _diccionariArtistes.obte(nomArtista).obtenirCanso(titolCanso).fitxersAText(directori());
}

std::string Facade::directori()
{
	return _directori;
}

void Facade::converteix(const std::string& nfitxer,const std::string& dirSortida,const std::string& prefixe)
{
	_grupDeConversors.converteix(nfitxer,dirSortida,prefixe);
}

void Facade::afegeixEstil(const std::string& nomEstil)
{
	Estil estil(nomEstil);
	_llistaEstils.push_back(estil);
}



std::string Facade::llistaEstils()
{
	std::string tempString;

	for(LlistaEstils::iterator it=_llistaEstils.begin();it!=_llistaEstils.end();it++)
	{
		tempString+=it->nom();
		if(_llistaEstils.size()>1)
			tempString+="\n";	
	}
	return tempString;
}



std::string Facade::estilsDeCanso(const std::string& idArtista,const std::string& titol)
{
	return _diccionariArtistes.obte(idArtista).obtenirCanso(titol).estilsAText();
}

std::string Facade::estilsDeArtista(std::string nomArtista)
{
	return _diccionariArtistes.obte(nomArtista).tornaEstils();
}

std::string Facade::artistesDeEstil(std::string nomEstil)
{
	std::string tempString;
	Artista tempArtista;

	_diccionariArtistes.initIndex();

	for(int i=0;i<(_diccionariArtistes.size());i++)		//Recorro los artistas
	{
		tempArtista=_diccionariArtistes.obteNext();
		tempArtista.initDiccionariCansons();
		
		if(isEstilAArtista(tempArtista,nomEstil))	//Si el artista tiene alguna canción que pertenezca a este estilo 
			tempString+=tempArtista.nom()+"\n";		//Lo añadimos a nuestro string

	}

	return tempString;

}



void Facade::afegeixUsuari(const std::string& nom,const std::string& email)
{
	Usuari usuari(nom,email);
	
	_llistaUsuaris.push_back(usuari);
	_llistaUsuaris.back().notificaAmb( new Email );
}


void Facade::subscriuUsuariAEstil(const std::string& idUsuari,const std::string& nomEstil)
{
	buscaEstil(nomEstil)->subscriu(*buscaUsuari(idUsuari));	
}

void Facade::subscriuUsuariAArtista(const std::string& nomUsuari, const std::string& nomArtista)
{
	Artista tempArtista;		
	
	tempArtista=_diccionariArtistes.obte(nomArtista);			
	tempArtista.subscriu(*buscaUsuari(nomUsuari));
	_diccionariArtistes.afegeix(nomArtista,tempArtista);	
}


void Facade::subscriuNovetatsWebAEstil(const std::string& nomEstil)
{
	buscaEstil(nomEstil)->subscriu(_novetatsWeb);
}

void Facade::subscriuNovetatsWebAArtista(const std::string& nomArtista)
{
	Artista tempArtista;		
	
	tempArtista=_diccionariArtistes.obte(nomArtista);			
	tempArtista.subscriu(_novetatsWeb);
	_diccionariArtistes.afegeix(nomArtista,tempArtista);	
}


std::string Facade::logNovetatsWeb()
{
	return _novetatsWeb.log();
}

void Facade::usuariVolRebreSms(const std::string& nomUsuari,const std::string& nMobil)
{
	buscaUsuari(nomUsuari)->volRebreSms(nMobil);
}

//Métodos Privados

Usuari* Facade::buscaUsuari(const std::string& nomUsuari)
{
	for(LlistaUsuaris::iterator it=_llistaUsuaris.begin();it!=_llistaUsuaris.end();it++)
	{
		if(it->nom()==nomUsuari)
			return (&(*it));
	}

	throw ExepcioUsuariInexistent();		
}

Estil* Facade::buscaEstil(const std::string& nomEstil)
{
	for(LlistaEstils::iterator it=_llistaEstils.begin();it!=_llistaEstils.end();it++)
	{
		if(it->nom()==nomEstil)
			return (&(*it));
	}

	throw ExepcioEstilInexistent();
}

void Facade::creaConversors()
{
	_grupDeConversors.crea("mp3","128");
	_grupDeConversors.crea("ogg","128");
	_grupDeConversors.crea("mp3","192");
	_grupDeConversors.crea("ogg","192");
	_grupDeConversors.crea("mp3","96");
	_grupDeConversors.crea("ogg","96");		
}

bool Facade::isEstilAArtista(Artista& artista,std::string nomEstil)
{
	std::string tempString;

	for(int i=0;i<(artista.DiccionariCansonsSize());i++)		
	{
		if( artista.tornaNextCanso().isEstil(nomEstil) )
			return true;
	}

	return false;
}


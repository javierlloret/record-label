#include "InfoCanso.hxx"
#include "Exepcio.hxx"

InfoCanso::InfoCanso(const std::string& titol, const std::string& autor) : _titol(titol), _autor(autor)
{
	index=-1;
}

InfoCanso::~InfoCanso()
{

	_llistaIdEstils.clear();

}

void InfoCanso::afegeixEstil(const std::string& nomEstil)
{
	_llistaIdEstils.push_back(nomEstil);
}

std::string InfoCanso::titol() const
{
	return _titol;
}

std::string InfoCanso::autor() const
{
	return _autor;
}

LlistaIdEstils InfoCanso::tornaEstils() const
{
	return _llistaIdEstils;
}


int InfoCanso::llistaSize() const
{
	return _llistaIdEstils.size();
}

void InfoCanso::initLlista() const
{
	index=-1;
}


std::string InfoCanso::obteNext() const
{

	int temp;
	LlistaIdEstils::const_iterator it=_llistaIdEstils.begin();
	index++;
	temp=index;


	while(temp>0)
	{
		it++;
		temp--;
	}

	if (it==_llistaIdEstils.end()) //key not found
		throw ClauNoTrobada();

	return (*it);


}

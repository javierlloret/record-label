#ifndef __Diccionari__
#define __Diccionari__

#include <map>
#include "Exepcio.hxx"

template <typename Element>

class Diccionari
{
	
typedef std::map<std::string, Element> MapaDElements;

public:
	Diccionari() 
	{
		index=-1;
	}
	
	Element& obte(std::string clau)
	{
		typename MapaDElements::iterator it= _elements.find(clau);
		if (it==_elements.end()) // no s'ha trobat la clau
			throw ClauNoTrobada();
		return it->second;
	}
	
	void afegeix(std::string clau, const Element& element)
	{
		if (!_elements.insert( MapaDElements::value_type(clau, element) ).second )
		{	
			_elements.erase(clau);
			_elements.insert( MapaDElements::value_type(clau, element) );
		}	
	}

	std::string imprimeixClaus()
	{
		std::string temp;

		typename MapaDElements::iterator it;
		for (it=_elements.begin(); it!=_elements.end(); it++)
		{
				temp+=it->first+"\n";
			
				 
		}
		return temp;
	}
	
	int size()
	{
		return _elements.size();
	}
	

	void initIndex()
	{
		index=-1;
	}
		

	Element& obteNext()
	{
		int temp;
		typename MapaDElements::iterator it= _elements.begin();
		index++;
		temp=index;
		while(temp>0)
		{
			it++;
			temp--;
		}
	
		if (it==_elements.end()) // no s'ha trobat la clau
			throw ClauNoTrobada();
		
		return it->second;
		
	}		
	
	void clear()
	{
		_elements.clear();
	}
	
	
private:
	MapaDElements _elements;
	int index;
};

#endif



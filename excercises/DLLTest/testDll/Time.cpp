#include "pch.h"
#include "testDll.h"

Time::Time( int h, int m, int s )
{
	this->setTime( h, m, s );
}

Time::Time( Time const& time )
{
	*this = time;
}

Time& Time::operator=( Time const& time )
{
	this->setTime( time.getHour(), time.getMin(), time.getSec() );	
	return *this;
}

ZDLL_API std::ostream& 
operator<<( std::ostream& os, Time const& time )
{
	os << time.m_nHour << ":" << time.m_nMin << ":" << time.m_nSec;
	return os;
}

ZDLL_API std::istream& 
operator >> ( std::istream& in, Time& time )
{
	int temp;
	std::cout << "Hour: ";
	in >> temp;
	time.setHour( temp );
	std::cout << "Minute: ";
	in >> temp;
	time.setMin( temp );
	std::cout << "Second: ";
	in >> temp;
	time.setSec( temp );
	return in;
}

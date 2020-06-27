#include "pch.h"
#include "testDLL.h"

Date::Date( int y, int m, int d )
{
	this->setDate(y, m, d);
}

Date::Date( Date const& date )
{
	*this = date;
}

Date& Date::operator=( Date const& date )
{
	this->setDate( date.getYear(), date.getMonth(), date.getDay() );
	return *this;
}

ZDLL_API std::ostream& operator<<( std::ostream& os, Date const& date )
{
	os << date.m_nYear << "/" << date.m_nMonth << "/" << date.m_nDay;
	return os;
}

ZDLL_API std::istream& operator >> ( std::istream& in, Date& date )
{
	int temp;
	std::cout << "Year: ";
	in >> temp;
	date.setYear( temp );
	std::cout << "Month: ";
	in >> temp;
	date.setMonth( temp );
	std::cout << "Day: ";
	in >> temp;
	date.setDay( temp );
	return in;
}

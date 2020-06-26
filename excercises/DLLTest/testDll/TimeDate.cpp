#include "pch.h"
#include "testDll.h"


TimeDate::TimeDate( int h, int min, int s, int year, int month, int day )
{
	this->setYear( year );
	this->setMonth( month );
	this->setDay( day );
	this->setHour( h );
	this->setMin( min );
	this->setSec( s );
}

TimeDate::TimeDate( TimeDate const& timeDate )
{
	*this = timeDate;
}

TimeDate::TimeDate( Time const& time, Date const& date ) : Time( time ), Date( date )
{
}

TimeDate& TimeDate::operator=( TimeDate const& timeDate )
{
	this->setYear( timeDate.getYear() );
	this->setMonth( timeDate.getMonth() );
	this->setDay( timeDate.getDay() );
	this->setHour( timeDate.getHour() );
	this->setMin( timeDate.getMin() );
	this->setSec( timeDate.getSec() );
	return *this;
}

void TimeDate::setTimeDate( int h, int min, int s, int y, int m, int d )
{
	this->setYear( y );
	this->setMonth( m );
	this->setDay( d );
	this->setHour( h );
	this->setMin( min );
	this->setSec( s );
}

ZDLL_API std::ostream& operator<<(std::ostream& out, TimeDate& timeDay )
{
	out << timeDay.getDate() << " " << timeDay.getTime();
	return out;
}

ZDLL_API std::istream& operator >> (std::istream& in, TimeDate& timeDay )
{
	int temp;
	std::cout << "Year: ";
	in >> temp;
	timeDay.setYear( temp );
	std::cout << "Month: ";
	std::cin >> temp;
	timeDay.setMonth( temp );
	std::cout << "Day: ";
	in >> temp;
	timeDay.setDay( temp );

	std::cout << std::endl << "Hour: ";
	in >> temp;
	timeDay.setHour( temp );
	std::cout << "Minute: ";
	in >> temp;
	timeDay.setMin( temp );
	std::cout << "Second: ";
	in >> temp;
	timeDay.setSec( temp );
	
	return in;
}
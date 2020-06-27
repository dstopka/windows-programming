#pragma once

class ZDLL_API TimeDate : public Time, public Date
{
public:
	TimeDate( int h = 0, int min = 0, int s = 0, int year = 1900, int month = 1, int day = 1 );
	~TimeDate() {}
	TimeDate( TimeDate const& timeDate );
	TimeDate( Time const& time, Date const& date );
	TimeDate& operator=( TimeDate const& timeDate );
	void setTimeDate( int h, int min, int s, int year, int month, int day );
	friend ZDLL_API std::ostream & operator<<( std::ostream& out, TimeDate& timeDate );
	friend ZDLL_API std::istream & operator >> ( std::istream& in, TimeDate& timeDate );
};


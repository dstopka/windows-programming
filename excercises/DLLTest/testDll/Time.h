#pragma once

#include <iostream>

class ZDLL_API Time
{
public:
	Time( int = 0, int = 0, int = 0 );
	Time( Time const& time );
	Time& operator=( Time const& time );
	~Time() {}

	inline Time getTime() const;
	inline int getHour() const;
	inline int getMin() const;
	inline int getSec() const;
	inline void setTime( int h, int min, int s );
	inline void setHour( int h );
	inline void setMin( int min );
	inline void setSec( int s );

	friend ZDLL_API std::ostream & operator<<( std::ostream& os, Time const& time );
	friend ZDLL_API std::istream & operator >> ( std::istream& in, Time & time );

private:
	int m_nHour;
	int m_nMin;
	int m_nSec;
};

inline Time
Time::getTime() const { return *this; }

inline int
Time::getHour() const { return m_nHour; }

inline int
Time::getMin() const { return m_nMin; }

inline int
Time::getSec() const { return m_nSec; }

inline void
Time::setTime( int h, int min, int s )
{
	this->setHour( h );
	this->setMin( min );
	this->setSec( s );
}

inline void
Time::setHour( int h )
{
	if( h >= 0 && h <= 24 )
		this->m_nHour = h;
}

inline void
Time::setMin( int min )
{
	if( min >= 0 && min < 60 )
		this->m_nMin = min;
}

inline void
Time::setSec( int s )
{
	if (s >= 0 && s < 60 )
		this->m_nSec = s;
}


#pragma once

#include <iostream>

class ZDLL_API Date
{
public:
	Date( int = 1900, int = 1, int = 1 );
	Date( Date const& date );
	Date& operator=( Date const& date );
	~Date() {}

	inline Date getDate() const;
	inline int getYear() const;
	inline int getMonth() const;
	inline int getDay() const;
	inline void setDate( int year, int month, int day );
	inline void setYear( int year );
	inline void setMonth( int month );
	inline void setDay( int day );
	friend ZDLL_API std::ostream & operator<<( std::ostream& out, Date const& date );
	friend ZDLL_API std::istream & operator >> ( std::istream& in, Date& date );

private:
	int m_nYear;
	int m_nMonth;
	int m_nDay;
};


inline Date
Date::getDate() const { return *this; }

inline int
Date::getYear() const { return m_nYear; }

inline int
Date::getMonth() const { return m_nMonth; }

inline int
Date::getDay() const { return m_nDay; }

inline void Date::setDate( int year, int month, int day )
{
	this->setYear( year );
	this->setMonth( month );
	this->setDay( day );
}

inline void
Date::setYear( int year ) { this->m_nYear = year; }

inline void
Date::setMonth( int month ) { this->m_nMonth = month; }

inline void
Date::setDay( int day ) { this->m_nDay = day; }

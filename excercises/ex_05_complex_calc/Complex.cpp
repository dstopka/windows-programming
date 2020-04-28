#include "stdafx.h"
#include "Complex.h"

CComplex::CComplex( double re, double im ) : m_re(re), m_im(im)
{}

CComplex::CComplex( const CComplex & other )
{
	*this = other;
}

CComplex & CComplex::operator=( const CComplex & other )
{
	if(this != &other )
	{
		m_re = other.getRe();
		m_im = other.getIm();
	}
	return *this;
}

CComplex::~CComplex()
{}

CComplex & CComplex::operator+=( const CComplex & rhs )
{
	this->m_re += rhs.getRe();
	this->m_im += rhs.getIm();
	return *this;
}

CComplex & CComplex::operator-=( const CComplex & rhs )
{
	this->m_re -= rhs.getRe();
	this->m_im -= rhs.getIm();
	return *this;
}

CComplex & CComplex::operator*=( const CComplex & rhs )
{
	this->m_re = this->m_re * rhs.getRe() - this->m_im * rhs.getIm();
	this->m_im = this->m_re * rhs.getIm() + this->m_im * rhs.getRe();
	return *this;
}

CComplex & CComplex::operator/=( const CComplex & rhs )
{
	CComplex numerator(rhs * rhs.Module());
	*this *= rhs;
	this->m_re /= numerator.getRe();
	this->m_im /= numerator.getRe();
	return *this;
}

void CComplex::setIm( double _im )
{
	m_im = _im;
}

void CComplex::setRe( double _re )
{
	m_re = _re;
}

void CComplex::setComplex( double _re, double _im )
{
	m_re = _re;
	m_im = _im;
}

double CComplex::getRe() const
{
	return m_re;
}

double CComplex::getIm() const
{
	return m_im;
}

CComplex CComplex::Coupled() const
{
	return CComplex(this->m_re, - this->m_im);
}

double CComplex::Module() const
{
	return sqrt(m_re * m_re + m_im * m_im);
}

CComplex operator+( const CComplex & lhs, const CComplex & rhs )
{
	CComplex res( lhs );
	res += rhs;
	return res;
}

CComplex operator-( const CComplex & lhs, const CComplex & rhs )
{
	CComplex res( lhs );
	res -= rhs;
	return res;
}

CComplex operator/( const CComplex & lhs, const CComplex & rhs )
{
	CComplex res( lhs );
	res /= rhs;
	return res;
}

CComplex operator*( const CComplex & lhs, const CComplex & rhs )
{
	CComplex res( lhs );
	res *= rhs;
	return res;
}

bool operator==( const CComplex & lhs, const CComplex & rhs )
{
	if ( lhs.getRe() == rhs.getRe() && lhs.getIm() == rhs.getIm() )
		return true;
	return false;
}

bool operator!=( const CComplex & lhs, const CComplex & rhs )
{
	return !(lhs == rhs);
}

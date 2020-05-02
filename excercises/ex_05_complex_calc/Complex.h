#pragma once
class CComplex
{
public:
	CComplex(double re = 0, double im = 0);
	CComplex( const CComplex& other );
	CComplex& operator =( const CComplex& other );
	~CComplex();

	CComplex& operator +=( const CComplex& rhs );
	CComplex& operator -=( const CComplex& rhs );
	CComplex& operator *=( const CComplex& rhs );
	CComplex& operator /=( const CComplex& rhs );
	friend CComplex operator +( const CComplex& lhs, const CComplex& rhs );
	friend CComplex operator -( const CComplex& lhs, const CComplex& rhs );
	friend CComplex operator /( const CComplex& lhs, const CComplex& rhs );
	friend CComplex operator *( const CComplex& lhs, const CComplex& rhs );
	friend bool operator == ( const CComplex& lhs, const CComplex& rhs );
	friend bool operator != ( const CComplex& lhs, const CComplex& rhs );

	void setIm( double _im );
	void setRe( double _re );
	void setComplex( double _re, double _im );
	double getRe() const;
	double getIm() const;
	CComplex Coupled() const;
	double Module() const;
	
protected:
	double m_re;
	double m_im;
};


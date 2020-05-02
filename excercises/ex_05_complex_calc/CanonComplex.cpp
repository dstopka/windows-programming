#include "stdafx.h"
#include "CanonComplex.h"

#include <string>

CCanonComplex::CCanonComplex( const CComplex & complex ) : CComplex(complex)
{
}

CCanonComplex::~CCanonComplex()
{
}

std::ostream & operator<<( std::ostream & output, const CCanonComplex & c )
{
	bool realPrinted = false;

	if ( c.m_re != 0 || (c.m_re == 0 && c.m_im == 0) ) {
		output << c.m_re;
		realPrinted = true;
	}

	if ( c.m_im > 0 ) {
		if ( realPrinted ) {
			output << "+";
		}
		if ( c.m_im != 1 ) {
			output << c.m_im;
		}
		output << "i";
	}

	else if ( c.m_im < 0 ) {
		if ( c.m_im == -1 ) {
			output << "-";
		}
		else {
			output << c.m_im;
		}
		output << "i";
	}

	return output;
}

std::istream & operator>>( std::istream & input, CCanonComplex & c )
{
	std::string complexText;
	int plusPos, minusPos, i_Pos;
	double coefficient1;
	bool real, imag;

	input >> coefficient1; // fails for pure imag nums converts "bi" to zero.
	getline( input, complexText );

	plusPos = complexText.find( '+' );
	minusPos = complexText.find( '-' );
	i_Pos = complexText.find( 'i' );

	real = i_Pos < 0; // real number won't contain the character i
	imag = minusPos < 0 && plusPos < 0; // pure imag number if no + or -

	if ( real ) {
		c.m_re = coefficient1;
		c.m_im = 0.0;
	}

	else if ( imag ) {
		c.m_re = 0.0;
		c.m_im = coefficient1;
	}

	else {
		c.m_re = coefficient1;

		complexText.replace( i_Pos, 1, " " );

		if ( plusPos >= 0 )
			complexText.replace( plusPos, 1, " " );

		if ( minusPos >= 0 )
			complexText.replace( minusPos, 1, " " );

		c.m_im = atof( complexText.c_str() );

		if ( c.m_im == 0 )
			c.m_im = 1; // 1 + i, 1 - i

		if ( minusPos >= 0 )
			c.m_im = -c.m_im;
	}

	return input;
}

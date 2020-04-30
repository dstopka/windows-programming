#include "stdafx.h"
#include "CanonComplex.h"

CCanonComplex::CCanonComplex( const CComplex & complex ) : CComplex(complex)
{
}

CCanonComplex::~CCanonComplex()
{
}

std::ostream & operator<<( std::ostream & output, const CCanonComplex & c )
{
	output << c.getRe() << " + " << c.getIm() << "i";
	return output;
}

std::istream & operator >> ( std::istream & input, CCanonComplex & c )
{
	double a;
	double b;
	input >> a >> b;
	c.setComplex( a, b );
	return input;
}

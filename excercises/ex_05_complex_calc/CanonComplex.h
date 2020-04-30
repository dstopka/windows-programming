#pragma once
#include "Complex.h"
#include <iostream>
class CCanonComplex :
	public CComplex
{
public:
	CCanonComplex(const CComplex& complex);
	~CCanonComplex();
	friend std::ostream & operator <<( std::ostream &output, const CComplex& c );
	friend std::istream & operator >>( std::istream &input,  CComplex& c );
};


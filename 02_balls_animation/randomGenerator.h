#pragma once

class randomGenerator
{
public:
	randomGenerator();
	~randomGenerator();

public:
	template<typename T> 
	void random( T lowerBound, T upperBound );

};

template<typename T>
inline void randomGenerator::random( T lowerBound, T upperBound )
{
}

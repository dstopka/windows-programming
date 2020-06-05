#pragma once

namespace Random
{
	template<typename T> 
	static T random( T lowerBound, T upperBound )
	{
		return static_cast<T>(rand() % (upperBound - lowerBound) + lowerBound);
	}
};
#include "stdafx.h"
#include "testDll.h"
#include <iostream>

int main()
{
	Date date( 2020, 5, 15 );
	std::cout << "date = " << date << std::endl;
	Time time( 20, 35, 0 );
	std::cout << "time = " << time << std::endl;
	TimeDate timeDate1( time, date );
	TimeDate timeDate2( timeDate1 );

	std::cout << std::endl << "timeDate2 = " << timeDate2 << std::endl;
    return 0;
}


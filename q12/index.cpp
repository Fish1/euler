#include <iostream>

#include <cmath>

unsigned long generateTriangle(unsigned long index)
{
	index += 1;

	return (index * index + index) / 2;
}

unsigned long countDivisors(unsigned long number)
{
	unsigned long result = 2;

	unsigned long upto = sqrt(number);

	for(unsigned long index = 2; index <= upto; ++index)
	{
		// divisors come in pairs, therefor we count two for each one
		if(number % index == 0)
		{
			result += 2;
		}
	}

	return result;
}

int main(void)
{
	for(unsigned long i = 0; i < 100000000; ++i)
	{
		unsigned long t = generateTriangle(i);
	
		unsigned long c = countDivisors(t);
		
		std::cout << t << "\t" << c << std::endl;

		if(c > 2000)
		{
			break;
		}
	}	
}

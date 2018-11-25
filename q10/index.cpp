#include <iostream>

#include <cmath>

bool isPrime(unsigned long number)
{
	for(unsigned long index = 2; index <= sqrt(number); ++index)
	{
		if(number % index == 0)
		{
			return false;
		}
	}

	return true;
}

int main(void)
{
	unsigned long sum = 0;

	unsigned long a = 2;

	while(a < 2000000)
	{
		if(isPrime(a))
		{
			sum += a;
			std::cout << sum << std::endl;
		}

		++a;
	}

	std::cout << sum << std::endl;

	return 0;
}

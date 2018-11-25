#include <iostream>

#include <vector>

std::vector<unsigned long> primes;

unsigned long getPrime(unsigned int index)
{
	unsigned long afterLastPrime = 1;

	while(primes.size() <= index)
	{
		unsigned long check = (*(primes.end() - 1)) + afterLastPrime;	
	
		bool isPrime = true;

		for(unsigned long prime : primes)
		{
			if(check % prime == 0)
			{
				isPrime = false;
				afterLastPrime += 1;	
				break;
			}
		}

		if(isPrime == true)
		{
			primes.push_back(check);
			afterLastPrime = 1;
		}
	}

	return primes.at(index);
}

int main(void)
{
	primes.push_back(2);

	for(unsigned long index = 0; index < 200000; ++index)
	{
		std::cout << getPrime(index) << std::endl;
	}

	return 0;
}

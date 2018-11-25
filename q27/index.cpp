#include <iostream>

#include <vector>

#include <cmath>

std::vector<unsigned long> primes;

unsigned long getPrime(unsigned long index)
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

bool isPrime(long number)
{
	unsigned long primeIndex = 0;
	unsigned long prime = getPrime(0);
		
	unsigned long upto = sqrt(number);

	while(prime <= upto)
	{
		if(number % prime == 0)
		{
			return false;
		}

		prime = getPrime(primeIndex++);
	}

	return true;
}

long f(long n, long a, long b)
{
	return (n * n) + (a * n) + b;
}

int main(void)
{
	primes.push_back(2);

	for(long a = -999; a < 1000; ++a)
	{
		for(long b = -1000; b <= 1000; ++b)
		{
			unsigned long n = 0;
	
			unsigned long result = 0;

			unsigned long count = 0;
			
			do
			{
				result = f(n,a,b);
				++count;
			} 
			while(isPrime(result));
			std::cout << a << std::endl;
		}
	}


	return 0;
}

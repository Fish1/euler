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

	unsigned long prime = 2;
	unsigned long prime_index = 0;

	unsigned long largest_prime_factor = 0;

	unsigned long test = 600851475143;

	while(prime <=  test / 2)
	{
		if(test % prime == 0)
		{
			largest_prime_factor = prime;
		}	

		++prime_index;

		prime = getPrime(prime_index);

//		std::cout << test / 2 << std::endl;
		std::cout << largest_prime_factor<< std::endl;
	}

	std::cout << largest_prime_factor << std::endl;

	return 0;
}

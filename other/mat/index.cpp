#include <iostream>

#include <iomanip>

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
		if(number % index == 0)
		{
			result += 2;
		}
	}

	return result;
}

int main(void)
{
	primes.push_back(2);

	std::vector<std::vector<unsigned long> > matrix;

	for(unsigned long index = 2; index <= 100; ++index)
	{
//		unsigned long p = getPrime(index);
		unsigned long p = index;
		p = countDivisors(p);

//		unsigned long p = generateTriangle(index);
//		unsigned long p = index;		
		std::vector<unsigned long> p_row;
		p_row.push_back(p);
		
		matrix.push_back(p_row);
	}

	unsigned long range = matrix.size() - 1;
	unsigned long column = 0;
	
	while(range != 0)
	{
		for(unsigned long index = 0; index < range; ++index)
		{
			unsigned long a = matrix.at(index).at(column);
			unsigned long b = matrix.at(index + 1).at(column);	

			matrix.at(index).push_back(a ^ b);
		}

		++column;
		--range;
	}

	for(auto & row : matrix)
	{
		for(auto & n : row)
		{
			//std::cout << std::setw(3) << std::setfill('0') <<  n << " ";
			std::cout << n << "\t";
		}

		std::cout << std::endl;
	}

	return 0;
}

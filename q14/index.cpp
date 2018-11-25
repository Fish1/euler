#include <iostream>

unsigned long countCollatz(unsigned long number)
{
	unsigned long count = 1;

	while(number != 1)
	{
		if(number % 2 == 0)
		{
			number = number / 2;
		}
		else
		{
			number = 3 * number + 1;
		}
		
		count += 1;
	}

	return count;
}

int main(void)
{
	unsigned long longestIndex = 0;
	unsigned long longest = 0;

	for(unsigned long index = 1; index < 1000000; ++index)
	{
		unsigned long c = countCollatz(index);
		
		if(c > longest)
		{
			longest = c;
			longestIndex = index;
		}

		std::cout << index << " " << c << std::endl;	
	}

	std::cout << std::endl;

	std::cout << longestIndex << " --- " << longest << std::endl;

	return 0;
}

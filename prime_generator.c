#include <stdio.h>
#include <math.h>

void sundaram_sieve(long long lower_bound, long long upper_bound) //This sieve took too long, but is left here for purposes of shame
{
	unsigned long long n = ceil( (upper_bound-1)/2 );
	unsigned long long numbers[n];

	for(unsigned long long i = 0; i < n; i++) //List of composites
		numbers[i] = i+1;	

	for(unsigned long long j = 1; j <= n/3 + 1; j++)
	{
		for(unsigned long long i = 1; i <= j; i++)
		{
			if(i+j+2*i*j <= n)
				numbers[i+j+2*i*j - 1] = 0;
		}
	}

	if(2 >= lower_bound && 2 <= upper_bound)
		printf("2\n"); //Prints 2 since sieve only finds odd primes

	//Double all numbers and increment by one giving primes under upper_bound found
	for(unsigned long long i = 0; i < n; i++)
	{
		if(numbers[i] != 0 && numbers[i]*2 + 1 > lower_bound)
		{
			numbers[i] = numbers[i]*2 + 1;
			printf("%llu\n", numbers[i]);
		}
	}
}

void segmented_sieve_eratosthenes(long lower_bound, long upper_bound)
{
	unsigned int max_prime = ceil(sqrt(upper_bound));

	unsigned int primes[max_prime]; //To hold primes

	primes[0] = 2; //Initial prime
	if(2 >= lower_bound)
		printf("2\n");
	unsigned int j = 1; //Index variable for primes[]

	for(unsigned int i = 3; i <= max_prime; i+=2) //Check primeness of all odd numbers up to sqrt(upper_bound)
	{
		for(unsigned int k = 0; k < j; k++) //Divide by all prime factors and see if composite or not
		{
			if(i % primes[k] == 0) //Divide by primes
			{
				break;
			}
			else if(k == j-1) //Implies i is prime
			{
				primes[j] = i;
				j++;
				if(i >= lower_bound)
					printf("%u\n", i);				
			}
		}
	}

	unsigned int final_prime = --j;
	//At this point, we have a list of primes up to sqrt(upper_bound). Check segments for primeness now

	long result[max_prime]; //Will hold final primes list
	result[max_prime-1] = primes[final_prime] + 2;
	if(result[max_prime-1] < lower_bound)
		result[max_prime-1] = lower_bound;
	if(result[max_prime-1] % 2 == 0)
		result[max_prime-1] += 1;
	result[0] = 0; //So while loop executes

	while(result[0] <= upper_bound) //Keeps iterating until array surpasses upper bound
	{
		result[0] = result[max_prime-1];
		for(unsigned int i = 0; i < max_prime; i++) //Iterate through this segment
		{
			for(unsigned int k = 0; k <= final_prime; k++) //Iterate through primes
			{
				if(result[i] % primes[k] == 0)
				{
					break;
				}
				else if(k == final_prime)
				{
					if(result[i] <= upper_bound)
						printf("%u\n", result[i]);
				}
			}
			if(i != max_prime - 1) //Fills next value of segment
				result[i+1] = result[i] + 2;
		}
	}
}

/*
	for(unsigned int i = 0; i <= final_prime; i++) //Copies over primes we already have
	{
		result[i] = primes[i];
		if(primes[i] >= lower_bound)
			printf("%u\n", primes[i]);
	}

printf("BREAK\n");
	long begin = primes[final_prime] + 1;
	if(begin < lower_bound)
		begin = lower_bound;

	for(long i = begin; i <= upper_bound; i++) //Go through all numbers and check if prime, if so, print
	{
		long testNum = i;
		for(long k = 0; k <= final_prime; k++)
		{
			if(testNum == 1) //Implies i is composite
			{
				break;
			}
			else if(testNum % primes[k] == 0) //Divide by primes
			{
				testNum = testNum/primes[k];
				k--;
			}			
		}
		if(testNum != 1 && testNum >= lower_bound) //Implies i prime
		{
			final_prime++;
			primes[final_prime] = i;
			printf("%li\n", i);
		}
	}
} */

int main()
{
	int test_cases;
	scanf("%d", &test_cases);
	unsigned long long lower_bound = 0;
	unsigned long long upper_bound = 0;
	for(int i = 1; i <= test_cases; i++) //Gather boundaries m < n	
	{
		scanf("%llu %llu", &lower_bound, &upper_bound);
		segmented_sieve_eratosthenes(lower_bound, upper_bound);
		printf("\n");
	}

	return 0;
}

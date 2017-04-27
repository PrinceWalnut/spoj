#include <stdio.h>
#include <math.h>

void sundaram_sieve(long long lower_bound, long long upper_bound)
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

int main()
{
	int test_cases;
	scanf("%d", &test_cases);
	unsigned long long lower_bound = 0;
	unsigned long long upper_bound = 0;
	for(int i = 1; i <= test_cases; i++) //Gather boundaries m < n	
	{
		scanf("%llu %llu", &lower_bound, &upper_bound);
		sundaram_sieve(lower_bound, upper_bound);
		printf("\n");
	}

	return 0;
}

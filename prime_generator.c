#include <stdio.h>

void sundaram_sieve(int lower_bound, int upper_bound)
{
	int n = upper_bound/2 - 1;
	int numbers[n];

	for(int i = 0; i < n; i++) //List of composites
		numbers[i] = i;	
	
	for(int j = 1; j <= n/3 + 1; j++)
	{
		for(int i = 1; i <= j; i++)
		{
			numbers[i+j+2*i*j] = 0;
		}
	}

	//Double all numbers and increment by one giving primes under upper_bound found
	for(int i = 0; i < n; i++)
	{
		if(numbers[i] != 0)
		{
			numbers[i] = numbers[i]*2 + 1;
			printf("%d", numbers[i]);
		}
	}
}

int main()
{
	int test_cases;
	scanf("%d", &test_cases);
	int lower_bound = 0;
	int upper_bound = 0;

	for(int i = 1; i <= test_cases; i++) //Gather boundaries m < n	
	{
		scanf("%d %d", &lower_bound, &upper_bound);
		sundaram_sieve(lower_bound, upper_bound);
		printf("\n");
	}
}

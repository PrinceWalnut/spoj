#include <stdio.h>

int main()
{
	int answer = 42;
	int input;

	while(input != answer)
	{
		scanf("%d", &input);
		if(input == answer)
			break;
		printf("%d\n", input);
	}

	return 0;
}

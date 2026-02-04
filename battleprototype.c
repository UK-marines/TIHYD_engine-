#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>
#define dice(n) (rand() % n + 1)



int main()
{
	srand(time(NULL));
	while (1) 
	{
	int sides = 0;
	int throws = 0;
	int result = 0;
	printf("Enter amount of dice sides: \n");
	scanf("%7d", &sides); 
	printf("Enter amount of throws: \n");
	scanf("%7d", &throws); 

	for (int i = 0; i < throws;) {
		if (throws <= 0 || sides <= 0) {break;}
		result += dice(sides);
		i++;

	}
	if (result == 0) {printf("You fucked up with dice. Try again kid.");}
	else 
	{
		printf("You rolled a dice: %d\n", result);
		char s = 0;
		printf("press something to throw again...\n");
		while (getchar() != '\n'); 
		getchar();
		if (s != 0) {return 0;}
	}

	}
}



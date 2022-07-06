#include <stdio.h>
char* empty_card = "   ------- \n  |%i      | \n  |   %s   | \n  |      %i| \n   ------- \n";
//♥//♠//♣//♦
int main()
{
	static char* symbol;
	char name;

	printf(empty_card, 5, "♦", 5);
	printf(empty_card, 5, "♦", 5);
	return 0;
}

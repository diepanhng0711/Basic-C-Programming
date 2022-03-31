#include<stdio.h>

void split(double num, int *int_part, double *frac_part)
{
	*int_part = (int)num;
	*frac_part = num - *int_part;
}

int main()
{
	double num, fraction;
	int integer;

	printf("Please enter a real number: ");
	scanf("%lf", &num);

	split(num, &integer, &fraction);
	printf("The integer part is %d\n", integer);
	printf("The remaining fraction is %lf\n", fraction);

	return 0;
}

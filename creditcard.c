/* Assignment 3: creditcard.c - Given a credit limit, current balance, annual percentage rate (APR) and monthly payment, write a C program that computes and prints the interest paid and the remaining balance at theend of each monthly cycle. The program should continue printing the monthly values until the debt is paid off (i.e. the remaining balance becomes zero). */
/* Author: Edison Lin */

#include <stdio.h>

int main(void)
{
	int c, m;
	float a, b, bb, i, nb, nnb, p;
	m = 0;

	printf("Enter the credit limit: ");
	scanf("%d", &c);
	printf("Enter the balance on the card: ");
	scanf("%f", &b);
	printf("Enter the APR: ");
	scanf("%f", &a);
	printf("Enter the monthly payment: ");
	scanf("%f", &p);
	printf("\nMonth\t    Balance\t      Interest\t     Payment\t      New Balance\n");
	nb = b;
	bb = b;

	while (nb > 0)
	{
		m += 1;
		i = (b * (a / 100)) / 12;
		nb = b + i - p;
                if (nb <= 0)
                {
			if (nb < 0)
                	{
                        	nb = 0.0;
                	}
                        p = b + i;
			printf("%d \t %10.2f \t %10.2f \t %10.2f \t   %10.2f \n\n", m, b, i, p, nb);
			break;
                }
		printf("%d \t %10.2f \t %10.2f \t %10.2f \t   %10.2f\n", m, b, i, p, nb);
		b = nb;
	}

	nnb = p + bb;
	printf("It will take $%.2f over %d months to pay off this debt. \n", nnb, m); 
	return 0;
}

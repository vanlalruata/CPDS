// Read an amount in Indian Rupees, including paise, and convert the amount into words using the Indian numbering system.

#include <stdio.h>

void numberToWords(long long n)
{
    char *ones[] = {
        "", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen",
        "Nineteen"
    };

    char *tens[] = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    if (n >= 10000000)
    {
        numberToWords(n / 10000000);
        printf(" Crore ");
        n %= 10000000;
    }

    if (n >= 100000)
    {
        numberToWords(n / 100000);
        printf(" Lakh ");
        n %= 100000;
    }

    if (n >= 1000)
    {
        numberToWords(n / 1000);
        printf(" Thousand ");
        n %= 1000;
    }

    if (n >= 100)
    {
        numberToWords(n / 100);
        printf(" Hundred ");
        n %= 100;
    }

    if (n >= 20)
    {
        printf("%s ", tens[n / 10]);
        n %= 10;
    }

    if (n > 0)
    {
        printf("%s ", ones[n]);
    }
}

int main()
{
    double amount;
    long long rupees;
    int paise;

    printf("Enter amount in Indian Rupees: ");
    scanf("%lf", &amount);

    /* Convert rupees and paise */
    rupees = (long long)amount;
    paise = (int)((amount - rupees) * 100 + 0.5);

    /* Handle rounding such as 99.99 */
    if (paise == 100)
    {
        rupees++;
        paise = 0;
    }

    printf("\nAmount in words: ");

    if (rupees == 0)
    {
        printf("Rupees Zero");
    }
    else
    {
        printf("Rupees ");
        numberToWords(rupees);
    }

    if (paise > 0)
    {
        printf("and ");

        numberToWords(paise);

        printf("Paise ");
    }

    printf("Only\n");

    return 0;
}
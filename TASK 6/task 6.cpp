#include <stdio.h>

int main(void){
    int household_no;
    int previous, current;
    unsigned int units;
    long long energy = 0;
    long long total;

    printf("Enter household number: ");
    if (scanf("%d", &household_no) != 1 || household_no <= 0)
    {
        printf("Invalid household number.\n");
        return 1;
    }

    printf("Enter previous reading: ");
    if (scanf("%d", &previous) != 1 ||
        previous < 0 || previous > 65535)
    {
        printf("Invalid previous reading.\n");
        return 1;
    }

    printf("Enter current reading: ");
    if (scanf("%d", &current) != 1 ||
        current < 0 || current > 65535)
    {
        printf("Invalid current reading.\n");
        return 1;
    }

    if (current >= previous)
        units = (unsigned int)(current - previous);
    else
        units = (unsigned int)(65536 - previous + current);

    if (units > 200)
    {
        energy = 100LL * 225 + (long long)(units - 200) * 450;
    }
    else if (units > 100)
    {
        energy = (long long)(units - 100) * 225;
    }

    total = energy + 5000LL;

    printf("\nHousehold number: %d\n", household_no);
    printf("Units consumed: %u\n", units);
    printf("Energy charge: Rs %lld.%02lld\n",
           energy / 100, energy % 100);
    printf("Fixed charge: Rs 50.00\n");
    printf("Total bill: Rs %lld.%02lld\n",
           total / 100, total % 100);

    return 0;
}


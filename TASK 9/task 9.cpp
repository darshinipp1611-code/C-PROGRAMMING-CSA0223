#include <stdio.h>
#include <limits.h>

#define METER_MAX 65535U
#define FIXED_PAISE 5000LL
#define RATE2_PAISE 225LL
#define RATE3_PAISE 450LL

unsigned int get_units(unsigned int previous, unsigned int current){
    if (current >= previous)
        return current - previous;

    return (METER_MAX + 1U - previous) + current;
}

long long compute_bill(unsigned int units){
    long long energy = 0;

    if (units > 200)
        energy = 100LL * RATE2_PAISE
               + (long long)(units - 200) * RATE3_PAISE;
    else if (units > 100)
        energy = (long long)(units - 100) * RATE2_PAISE;

    return FIXED_PAISE + energy;
}

int main(void){
    unsigned int previous, current, units;

    printf("Enter previous reading (0-65535): ");
    if (scanf("%u", &previous) != 1 || previous > METER_MAX)
    {
        printf("Invalid previous reading.\n");
        return 1;
    }

    printf("Enter current reading (0-65535): ");
    if (scanf("%u", &current) != 1 || current > METER_MAX)
    {
        printf("Invalid current reading.\n");
        return 1;
    }

    units = get_units(previous, current);

    long long total = compute_bill(units);

    printf("\nUnits consumed: %u\n", units);
    printf("Fixed charge: Rs 50.00\n");
    printf("Total bill: Rs %lld.%02lld\n",
           total / 100, total % 100);

    return 0;
}

#include <stdio.h>


long long compute_bill(int units){
    long long energy = 0;

    if (units > SLAB2_UNITS)
    {
        energy += (long long)(units - SLAB2_UNITS) * RATE3_PAISE;
        energy += (long long)(SLAB2_UNITS - SLAB1_UNITS) * RATE2_PAISE;
    }
    else if (units > SLAB1_UNITS)
    {
        energy += (long long)(units - SLAB1_UNITS) * RATE2_PAISE;
    }

#ifdef DEBUG
    printf("DEBUG: units = %d, energy = %lld paise\n", units, energy);
#endif

    return FIXED_CHARGE_PAISE + energy;
}

int main(void){
    int units;

    printf("Enter units consumed: ");

    if (scanf("%d", &units) != 1 || units < 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    long long total = compute_bill(units);
    printf("Total bill = Rs %lld.%02lld\n", total / 100, total % 100);

    return 0;
}

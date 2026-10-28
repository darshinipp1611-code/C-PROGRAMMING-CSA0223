#include <stdio.h>

#define WH_PER_UNIT 1000LL

int main(void){
    long long rate2, rate3, fixed_charge;
    long long normal_wh = 0;
    long long peak_wh = 0;
    long long normal_units, peak_units;
    long long normal_energy, peak_energy, total;
    int reading_count;
    long long wh;
    int peak;

    FILE *file = fopen("tariff.txt", "r");

    if (file == NULL)
    {
        printf("Cannot open tariff.txt\n");
        return 1;
    }

    if (fscanf(file, "%lld%lld%lld",
               &rate2, &rate3, &fixed_charge) != 3 ||
        rate2 < 0 || rate3 < 0 || fixed_charge < 0)
    {
        printf("Invalid tariff configuration.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("Enter number of readings: ");
    if (scanf("%d", &reading_count) != 1 || reading_count < 0)
    {
        printf("Invalid reading count.\n");
        return 1;
    }

    for (int i = 0; i < reading_count; i++)
    {
        printf("Enter watt-hours and peak flag (0 or 1): ");

        if (scanf("%lld%d", &wh, &peak) != 2 ||
            wh < 0 || (peak != 0 && peak != 1))
        {
            printf("Invalid reading.\n");
            return 1;
        }

        if (peak == 1)
            peak_wh += wh;
        else
            normal_wh += wh;
    }

    normal_units = normal_wh / WH_PER_UNIT;
    peak_units = peak_wh / WH_PER_UNIT;

    normal_energy = normal_units * rate2;

    /* Peak-hour energy costs 20% more.
       Integer rounding is applied to the surcharge in paise. */
    peak_energy = peak_units * rate2;
    peak_energy += (peak_energy + 2) / 5;

    total = fixed_charge + normal_energy + peak_energy;

    printf("\nNormal energy: %lld Wh\n", normal_wh);
    printf("Peak energy: %lld Wh\n", peak_wh);
    printf("Total bill: Rs %lld.%02lld\n",
           total / 100, total % 100);

    return 0;
}


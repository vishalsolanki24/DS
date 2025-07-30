#include <stdio.h>

void main() {
    int totalDays, years, weeks, days;

    
    printf("Enter total number of days: ");
    scanf("%d", &totalDays);

    
    years = totalDays / 365;
    weeks = (totalDays % 365) / 7;
    days = (totalDays % 365) % 7;

    printf("%d days = %d year(s), %d week(s), %d day(s)\n", totalDays, years, weeks, days);

  
}

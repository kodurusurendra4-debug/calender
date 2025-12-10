#include<stdio.h>

int getfirstdayofyear(int year)
{
    int day;
    day = (year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    return day;
}

int leapyear(int year)
{
    if ((year%4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printmonth(int year)
{
    char *month[] = {"January", "February", "March", "April", "May", "June",
                     "July", "August", "September", "October", "November", "December"};
    
    int daysinamonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (leapyear(year))
    {
        daysinamonth[1] = 29;
    }

    int startday = getfirstdayofyear(year);
    FILE *calender;
    calender=fopen("calender.txt","a");
    if (calender == NULL)
{
    printf("Error: Could not open the file for writing.\n");
    return; // Exit the function if the file couldn't be opened
}

    for (int i = 0; i < 12; i++)
    {
        fprintf(calender,"\n\n-------------%s %d-------------\n", month[i], year);
        fprintf(calender,"Sun Mon Tue Wed Thu Fri Sat\n");

        for (int k = 0; k < startday; k++)
        {
            fprintf(calender,"    ");
        }

        for (int day = 1; day <= daysinamonth[i]; day++)
        {
            fprintf(calender,"%3d ", day);
            startday++;
            if (startday > 6)
            {
                startday = 0;
                fprintf(calender,"\n");
            }
        }

        if (startday != 0) fprintf(calender,"\n");      
    }
    fclose(calender);
    for (int i = 0; i < 12; i++)
    {
        printf("\n\n-------------%s %d-------------\n", month[i], year);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        for (int k = 0; k < startday; k++)
        {
            printf("    ");
        }

        for (int day = 1; day <= daysinamonth[i]; day++)
        {
            printf("%3d ", day);
            startday++;
            if (startday > 6)
            {
                startday = 0;
                printf("\n");
            }
        }

        if (startday != 0) printf("\n");      
    }
}

int main()
{
    int year;
    printf("Enter the year: ");
    scanf("%d", &year);

    printmonth(year);
    getchar;

    return 0;
}
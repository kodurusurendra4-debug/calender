#include<stdio.h>
//give the first day of the year
int getfirstdayofyear(int year)
{
    int day;
    day = (year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    return day;
}
//checks whether the year is leap year or not
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
//this function is used for printing the months in the calender
void printmonth(int year)
{
    char *month[] = {"January", "February", "March", "April", "May", "June",
                     "July", "August", "September", "October", "November", "December"};
    
    int daysinamonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (leapyear(year))
    {
        daysinamonth[1] = 29;//if it is leap year then the days will be 29 in february
    }

    int startday = getfirstdayofyear(year);
    FILE *calender;//creating a file pointer
    //opening file calender.txt
    calender=fopen("calender.txt","a");
    if (calender == NULL)
{
    printf("Error: Could not open the file for writing.\n");
    return; // Exit the function if the file couldn't be opened
}

    for (int i = 0; i < 12; i++)//print the months in the file
    {
        fprintf(calender,"\n\n-------------%s %d-------------\n", month[i], year);
        fprintf(calender,"Sun Mon Tue Wed Thu Fri Sat\n");

        for (int k = 0; k < startday; k++)//print the space in the calender in the file
        {
            fprintf(calender,"    ");
        }

        for (int day = 1; day <= daysinamonth[i]; day++)//print the days in the calender in the file
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
    fclose(calender);//closing the file...
    //printing the calender in the terminal..
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

    printmonth(year);//caling printmonth to print the calender..  

    return 0;

}

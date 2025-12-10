# calender
# CALENDER

Simple & Direct	A console-based calendar application written in C. Displays a calendar for any given year.
Feature-Focused	A lightweight command-line calendar utility developed in C, featuring dynamic month and year generation.
Educational	My first C project: a simple calendar generator used for practicing C programming fundamentals and date handling.
#DESIGN AND IMPLEMENTATION

1.For taking input we used scanf()
2.the months are stored in array
3.for knowing it as leap year or not we used (year % 4 == 0 && year % 100 != 0) || year % 400 == 0
4.for no of days in a month we used an array
5.for saving it in a fille we used FILE 

#THE FUNCTIONS IN THE CODE

getfirstdayofyear(int year)----------- to get the starting day
leapyear(int year)-------------------- to check the year is leap year or not
printmonth(int year)------------------ to print the months of the month
main()-------------------------------- to run the code

#FLOW OF THE PROGRAM----

1.start
2.take the input of year by the user 
3.the compiler checks the forst day of the year using getfirstday()
4.checks whether the year is leap year or not using leapyear()
5.print the monts of the year using forloop, leapyear(),getfirstdayofyear()
6.the year is directly printed in a text file called calender()
7.stop

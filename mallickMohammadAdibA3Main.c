/************************mallickMohammadAdibA3Main.c**************
Student Name: Mohammad Adib Mallick    Email Id: mallick@uoguelph.ca 
Due Date: November 30th                Course Name: CIS 1300

I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:

1) I have read and understood the University policy on academic integrity. 2) I
have completed the Computing with Integrity Tutorial on Moodle; and 3) I have
achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for
this course.
********************************************************/

/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc -std=c99 -Wall mallickMohammadAdibA3.c mallickMohammadAdibA3Main.c
Running: ./a.out
OR
gcc -std=c99 -Wall mallickMohammadAdibA3.c mallickMohammadAdibA3Main.c -o assn3
Running the Program: ./assn3
*********************************************************/

#include "givenA3.h"

int main (int argc, char * argv[]) {
   //declare --all variables here

    int country [COUNTRIES][MEDALCAT];
    int countries;
    int minOrMax;
    char countryNames [COUNTRIES][MAX_LENGTH_CNAME];
    int choice;
    int which_category;
    int totalAllMedals [MEDALCAT];
    int totalAllCountries [COUNTRIES];
    int max_medals;
    int indexMedal;
    int indexCountry;
    int indexOfCountries[COUNTRIES];
    // call function readFromFile to populate your arrays
    // readFromFile (argv[1], country, countryNames)
   
    do {
        printf ("\nHere is the menu \n\n");
        printf ("1. Display all country names read from file and the total number of medals won by each\n");
        printf ("2.    Function 2 -  Find total number of medals won by each country\n");
        printf ("3.    Function 3 -  Finds total number of medals in each category (Gold, Silver, Bronze)\n");
        printf ("4.    Function 4 -  Display horizontal histogram\n");
        printf ("5.    Function 5 -  Search for a country and return the total number of medals won by it\n");
        printf ("6.    Function 6 -  Rank and display top three countries in order of total medals won\n");
        printf ("7.    Function 7 -  Rank and display top three countries in order of total gold medals won\n");
        printf ("8.    Function 8 -  Find and display all countries that won no X medals, given X as either Gold, Silver or Bronze\n");
        printf ("9.    Function 9 -  Find and display all countries that won ONLY X medals, given X as either Gold, Silver or Bronze\n");
        printf ("10.   Function 10 - Find and display name of the country that has minimum or maximum length among all countries read in option 1\n");
        
        printf ("11.    Exit\n");
        
        
        printf ("Enter your choice: ");
        scanf ("%d", &choice);
        
        switch (choice) {

            case 1:
                // write code to display all country names read from file and the total number of medals won by each
                readFromFile(argv[1],country,countryNames);
                findTotalPerCountry(country,totalAllCountries);

                printf("COUNTRY NAME    \tGOLD  \tSILVER \tBRONZE\n");

                for(int k=0; k<COUNTRIES; k++)
                {
                printf("%-12s     \t%d     \t%d     \t%d \n", countryNames[k], country[k][0],  country[k][1],  country[k][2]);
                }
                break;

            case 2: 
                readFromFile(argv[1],country,countryNames);
                findTotalPerCountry(country,totalAllCountries);
                // write code to call Function 2 - Find total number of medals won by each country
                findTotalPerCountry(country,totalAllCountries); 
                //for loop to print the countries and total medals per country   
                for(int k=0;k<COUNTRIES;k++)  
                printf("%-12s:\t   \t%d\n",countryNames[k],totalAllCountries[k]);           
                break;
                
            case 3:
                readFromFile(argv[1],country,countryNames);
                findTotalPerCountry(country,totalAllCountries);
                max_medals=findTotalPerMedal(country,totalAllMedals,&which_category);
                printf("Gold = %d\n",totalAllMedals[0]);
                printf("Silver = %d\n",totalAllMedals[1]);
                printf("Bronze = %d\n",totalAllMedals[2]);
                printf("Max number of the medals: %d  ",max_medals);
                printf("Category ");
                if(which_category == 0){
                printf("(Gold)\n");
                }
                else if(which_category == 1){
                printf("(Silver)\n");
                }
                else if(which_category == 2){
                printf("(Bronze)\n");
                }
                break;

            case 4:      
                readFromFile(argv[1],country,countryNames);
                findTotalPerCountry(country,totalAllCountries);
                //Calling the hHistogram function
                hHistogram(countryNames,totalAllCountries);                
                break;

            case 5:
                readFromFile(argv[1],country,countryNames);
                findTotalPerCountry(country,totalAllCountries);
                printf("Enter the name of country to be searched: \n");
                char search_country[MAX_LENGTH_CNAME];
                //Calling the searchCountry function
                scanf("%s",search_country);
                int medals;
                medals = searchCountry(search_country,countryNames,totalAllCountries);
                if(medals!=-1)
                {
                printf("Total Medals won by %s is:%d ",search_country, medals);
                }
                else    
                {
                printf("Country not found");
                }  
                break;

            case 6:
                readFromFile(argv[1],country,countryNames);
                findTotalPerCountry(country,totalAllCountries);
                printf("Top 3 teams by total medals: \n");
                //Calling the rankTopThreeByTotal function
                rankTopThreeByTotal(totalAllCountries,countryNames);
                break; 

            case 7:
                readFromFile(argv[1],country,countryNames);
                findTotalPerCountry(country,totalAllCountries);
                printf("Top 3 teams by gold medals: \n");
                //Calling the rankTopThreeByMedal function
                rankTopThreeByMedal(country,countryNames);
                break;  

            case 8:
                readFromFile(argv[1],country,countryNames);
                findTotalPerCountry(country,totalAllCountries);
                //Promts the user to select beween Gold, Silver and Bronze 
                printf("Which medal do you want to look for in X-(Gold-1,Silver-2,Bronze-3)\n");
                scanf("%d",&indexMedal);
                //Assign the variable countries the findAllWithNoXMedals function 
                countries=findAllWithNoXMedals(country,indexMedal,indexOfCountries);
                printf("Total number of countries with no medal in X: %d \n",countries);
                for(int k=0;k<countries;k++)
                {
                printf("%s\n",countryNames[indexOfCountries[k]]); 
                }
                break;

            case 9:
                readFromFile(argv[1],country,countryNames);
                findTotalPerCountry(country,totalAllCountries);
                //Promts the user to select beween Gold, Silver and Bronze 
                printf("Which medal do you want to look for in X-(Gold-1,SIlver-2,Bronze-3)\n");
                scanf("%d",&indexMedal);
                //Assign the variable countries the findAllWithOnlyXMedals function 
                countries=findAllWithOnlyXMedals(country,indexMedal,indexOfCountries);
                printf("Total number of countries with medal only in X: %d \n",countries);
                for(int k=0;k<countries;k++)
                {
                printf("%s\n",countryNames[indexOfCountries[k]]);
                }
                break; 

            case 10:
                readFromFile(argv[1],country,countryNames);
                findTotalPerCountry(country,totalAllCountries);
                //Promts the user to enter 1 for and min and 2 for max 
                printf("Enter 1 for max or 2 for min\n");
                scanf("%d",&minOrMax);
                //Assign the variable countries the findAllWithMinOrMaxLenght function 
                indexCountry=findCountryIndexWithMinOrMaxLength(minOrMax,countryNames);
                if(minOrMax==1){
                printf("The country name with maximum length= %s",countryNames[indexCountry]);
                }
                else
                {
                printf("The country name with minimum length= %s",countryNames[indexCountry]);
                }
                break;

            case 11:

                break;

                default: printf ("That is an invalid choice\n");
                
        }
        
    } while (choice != 11);
    
    
   return 0;
}






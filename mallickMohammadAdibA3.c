/************************mallickMohammadAdibA3.c**************
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

//Creating a pointer to open the file  

void readFromFile (char fName [30], int country [COUNTRIES][MEDALCAT], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){

    FILE *file; 
        // Opening file in reading mode
        file = fopen("commonWealth.txt", "r");   
        if(file == NULL)
        printf("error in reading file");

        int k, rows=COUNTRIES;
        //for loop to go over through the common wealth file 
    
        for(k=0; k<rows; k++)
        {
        // Scanning the file
        fscanf(file, "%s%d%d%d", countryNames[k], &country[k][0],  &country[k][1],  &country[k][2]);
        }
    }

void findTotalPerCountry (int country [COUNTRIES] [MEDALCAT],

        //For loop to go through COUNTRIES and MEDALCAT
            int totalAllCountries [COUNTRIES]){
            for(int k=0;k<COUNTRIES;k++)
            {
            totalAllCountries[k]=0;
            for(int t=0;t<MEDALCAT;t++) {
        //Store the total of medals per country in totalAllCountries 
            totalAllCountries[k]+=country[k][t];

            }
        }
    }

int findTotalPerMedal (int country [COUNTRIES][MEDALCAT], int totalAllMedals [MEDALCAT], int * whichMedal){

    //Creating variables for the three medals

    int gold=0,silver=0,bronze=0;

        //for loop and assign each variable their index 

        for(int k=0;k<COUNTRIES;k++)
        {
            gold+=country[k][0];
            silver+=country[k][1];
            bronze+=country[k][2];
        }

            totalAllMedals[0]=gold;
            totalAllMedals[1]=silver;
            totalAllMedals[2]=bronze;

                int max_cat=0;
                int max_medals=0;

            //Will display the max medals for the countries 

            for(int k=0;k<MEDALCAT;k++)
            {
            if(totalAllMedals[k]>max_medals)
            {
            max_cat=k;
            max_medals=totalAllMedals[k];
            }
        }   

            *whichMedal=max_cat;
            return max_medals;     
    }

void hHistogram (char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalMedals[COUNTRIES]) {

    //Assign the astrik to a variable

    char star='*';
    int num_stars=0;

    //for loop used to go throuhg the countries and total medals per country 

    for(int k=0;k<COUNTRIES;k++){

    //Divide the astrkin number by the total of the medal per country 

        num_stars=totalMedals[k]/2 + totalMedals[k]%2;
        char int_str[20];
        sprintf(int_str,"%d",totalMedals[k]);
        printf("%s:",countryNames[k]);
        for(int t=0;t<num_stars;t++)
            {

     //Print the stars of the medals per country 

                printf("%c",star);
            }
        printf("(%s)\n",int_str);    
    }
}

int searchCountry (char countryName [MAX_LENGTH_CNAME], char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalAllCountries [COUNTRIES]){
    
    int compare;
    int found=0;
    int country_index=-1;

    for(int k=0;k<COUNTRIES;k++){

         //strcmp to compare both strings 

        compare=strcmp(countryName,countryNames[k]);
        if(compare==0)
            {
                found=1;
                country_index=k;
            }
    }

    if(!found)
        return -1;  
    else
        return totalAllCountries[country_index];    
}

void rankTopThreeByTotal (int totalMedals[COUNTRIES], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){

    int sorted_indexes[COUNTRIES];

      //For loop to print the three countres with the highest medals 

    for(int k=0;k<COUNTRIES;k++)
        sorted_indexes[k]=k;

    int temp;
        for(int k=0;k<COUNTRIES-1;k++)
        for(int t=k+1;t<COUNTRIES;t++)
        {
            if(totalMedals[t]>totalMedals[k]){
            temp=sorted_indexes[k];
            sorted_indexes[k]=sorted_indexes[t];
            sorted_indexes[t]=temp;
            }
        }        
        for(int k=0;k<3;k++) {
        printf("%s: %d \n",countryNames[sorted_indexes[k]],totalMedals[sorted_indexes[k]]);
    }           
}

void rankTopThreeByMedal (int country [COUNTRIES] [MEDALCAT], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){

    int country_golds[COUNTRIES];

        //For loop to print the three countres with the top medals 

        for(int k=0;k<COUNTRIES;k++){
            country_golds[k]=country[k][0];
        }
        rankTopThreeByTotal(country_golds,countryNames);
}

int findAllWithNoXMedals (int country [COUNTRIES] [MEDALCAT], int indexMedal, int indexOfCountries [COUNTRIES]){

    //Creating a variable total_countries

    int total_countries=0;

    for(int k=0;k<COUNTRIES;k++){
        for(int t=0;t<MEDALCAT;t++)
            {
    //Will only display the countries with no medals 

            if(country[k][t]==0 && t+1==indexMedal){
            indexOfCountries[total_countries]=k;
            total_countries++;
            }
        }
    }
    //Return total countries with no medals 

    return total_countries;
}

int findAllWithOnlyXMedals (int country [COUNTRIES][MEDALCAT], int indexMedal, int indexOfCountries [COUNTRIES]){

    //Creating a variable total_countries

    int total_countries=0;

    //for loop created to find coutnries with medals 


    for(int k=0;k<COUNTRIES;k++){
        int satisfied=1;

        if(country[k][indexMedal-1]>0){
            for(int t=0;t<MEDALCAT;t++){
                if(t!=indexMedal-1 && country[k][t]>0)
                    {
                        satisfied=0;
                        break;
                    }
            }

            if(satisfied)
            {
            //Returns the number of countries with all medals

            indexOfCountries[total_countries]=k;
            total_countries++;
            }
        }
    }

    return total_countries;
}


int findCountryIndexWithMinOrMaxLength (int minOrMax, char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){

    int location;
    //Assigning max_length to a new int variable 
    int max_length=strlen(countryNames[0]);
    int k;
    int t;
    int min_length = 0;

        if(minOrMax==1){

        //for loop to go over countries 

            for(k=0;k<COUNTRIES;k++)
            {

        //if the lenghth of countryNames is less than minimum lenght then minimum lenght would equal to lenght of country names

            if(min_length<strlen(countryNames[k])){
            min_length=strlen(countryNames[k]);
            location=k;
            }
        }
        //Would only return the minimum 
        return location;    
    }
        else if(minOrMax==2){
            
            for(t=0;t<COUNTRIES;t++)
            {

        //if the lenghth of countryNames is greater than maximum lenght then maximum lenght would equal to lenght of country names 

            if(max_length>strlen(countryNames[t]))
            {
            max_length=strlen(countryNames[t]);
            location=t;
            }
        }
        return location;
    }
    return 0;
}




/*
    A Program Implement Ticket Booking System
*/
// Header Files

#include <stdio.h>
#include "Definitions.h"
#include <stdlib.h>
#include <conio.h>

// Main Function

int main()
{
    // Execution of code starts from here
    int ch; 

    printf("\n\t__________________________________________________________\n");
	printf("\n\t\t\t RAILWAY RESERVATION SYSTEM \n");
	printf("\n\t__________________________________________________________\n\n");
	printf("\n\t\t\t Welcome to Indian Railways\n");
	printf("\n\tBy IRCTC - Indian Railway Catering and Tourism Corporation\n\n");
	printf("\n\t__________________________________________________________\n");
	printf("\n\t\t\tCopyrights reserved @ %s", __DATE__ + 7);
	printf("\n\t__________________________________________________________\n");

	printf("\n\n\n\tPress Any Key To Continue...");
	getch();

    //Display options
    do{
        main :
        system("cls");
        printf("\n\t\t___________________________");
	    printf("\n\n\t\t    Reservation System    ");
	    printf("\n\t\t___________________________");
        printf("\n\t\t------------------------");
        printf("\n\t\t 0) Exit");
	    printf("\n\t\t------------------------");
	    printf("\n\t\t 1) Train Availability");
	    printf("\n\t\t------------------------");
	    printf("\n\t\t 2) Booking");
	    printf("\n\t\t------------------------");
	    printf("\n\t\t 3) Cancellation");
	    printf("\n\t\t------------------------");
	    printf("\n\t\t 4) View Chart");
	    printf("\n\t\t------------------------");
	    printf("\n\t\t 5) Clear All Reserved Data");
	    printf("\n\t\t------------------------");
	    printf("\n\nPlease Enter Your Option [0/1/2/3/4/5] : ");
	    scanf("%d",&ch);

        // To exit out of program
        if (ch == 0)
            return 0;

        switch(ch)
        {
            case 1:
                //Booking New Ticket
                AvailabilityCheck();
                break;
            
            case 2:
                //Checking For availability
                Book();
                break;

            case 3:
                //Cancelling Ticket
                Cancellation();
                break;
            
            case 4:
                //Preparing Chart
                PrepareChart();
                break;
            case 5:
                ClearData();
                break;
            default:
                printf("Wrong Choice!!");
                break;
        }
        printf("\n\n\nPress Any Key to Go to Main Menu...");
		getch();
        goto main;
    }
    while (ch > 5);
}
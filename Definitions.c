/*
	A helper c file for Reservation.c 
*/

//Implementation Part 

#include "Definitions.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int counter = 0;
ticket t;

// Implementation of Booking Ticket
int Book()
{
	int i, ch, charges, no_of_passengers, train_class_type, fc_count = 0;
	char confirm;
	FILE *fb;
	
	system("cls");
	fb = fopen("ReservationList.txt","a");

	SeaterDetails :

	system("cls");
	printf("\n\tClasses Available:\n\n\t0) Exit\t1)Seater A/C\n\t2)Seater Non A/C\n\t3)Sleeper A/C\n\t4)Sleeper Non A/C\n\nPlease Select Your Class [0/1/2/3/4]: ");
	scanf("%d",&train_class_type);
	system("cls");

	if (train_class_type == 0)
		return 0;

	switch(train_class_type)
	{
		case 1:
			t.td.train_class = "Seater A/C";
			printf("\nEnter Number of Seats : ");
			scanf("%d",&no_of_passengers);
			break;
		case 2:
			t.td.train_class = "Seater N.A/C";
			printf("\nEnter Number of Seats : ");
			scanf("%d",&no_of_passengers);
			break;
		case 3:
			t.td.train_class = "Sleeper A/C";
			printf("\nEnter Number of Berths : ");
			scanf("%d",&no_of_passengers);
			break;
		case 4:
			t.td.train_class = "SleeperN.A/C";
			printf("\nEnter Number of Berths : ");
			scanf("%d",&no_of_passengers);
			break;
		default:
			printf("\nSorry, Invalid Choice\tPlease Enter Correct option...");
			getch();
			goto SeaterDetails;
			break;
	}

	Details :

	for( i = 0; i < no_of_passengers; i++)
	{
		system("cls");
		printf("\n\nPlease Enter the Details of Passenger %d : \n", i+1);
		printf("\nFirst Name\t: ");
		scanf("%s",t.pd[i].passenger_fname);
		printf("Last Name\t: ");
		scanf("%s",t.pd[i].passenger_lname);
		printf("Gender [M/F]\t: ");
		scanf("%s",t.pd[i].passenger_gender);
		printf("Age\t\t: ");
		scanf("%d",&t.pd[i].passenger_age);
		printf("\nFee Concession for..\n 1) Senior Citizen\n 2) Age Below 5 Years\n");
		if(t.pd[i].passenger_age <= 5 || t.pd[i].passenger_age >= 60)
			fc_count++;
	}

	printf("\n\nEnter a Common Phone Number(Mandatory): ");
	scanf("%lld", &t.PhoneNumber);
	printf("\n\nPlease Enter the Details : \n");

	Id:

	system("cls");
	AvailabilityCheck();
	printf("\n\n Select Your Train ID From Above: ");
	scanf("%d",&t.td.train_id);
	
	switch(t.td.train_id)
	{
		case 1:
			t.td.train_no = 10001;
			t.td.train_time = "09:00";
			t.td.train_name ="Vaigai SF Express";
			t.td.origin = "Madurai Junction";
			t.td.destination = "Chennai Egmore";
			break;
		case 2:
			t.td.train_no = 10002;
			t.td.train_time = "13:00";
			t.td.train_name ="Coimbatore Express";
			t.td.origin = "Chennai Central";
			t.td.destination = "Coimbatore Junction";
			break;
		case 3:
			t.td.train_no = 10003;
			t.td.train_time = "08:00";
			t.td.train_name ="Coimbatore Express";
			t.td.origin = "Rameswaran Junction";
			t.td.destination = "Coimbatore Junction";
			break;
		case 4:
			t.td.train_no = 10004;
			t.td.train_time = "23:00";
			t.td.train_name ="Coimbatore Express";
			t.td.origin = "Nagercoil Junction";
			t.td.destination = "Coimbatore Juntion";
			break;
		case 5:
			t.td.train_no = 10005;
			t.td.train_time = "18:00";
			t.td.train_name ="Vaigai SF Express";
			t.td.origin = "Chennai Egmore";
			t.td.destination = "Madurai Junction";
			break;
		case 6:
			t.td.train_no = 10006;
			t.td.train_time = "09:30";
			t.td.train_name ="Pune Indore Express";
			t.td.origin = "Pune Junction";
			t.td.destination = "Indore Junction Bg";
			break;
		case 7:
			t.td.train_no = 10007;
			t.td.train_time = "13:00";
			t.td.train_name ="Bangalore Express";
			t.td.origin = "Chennai Central";
			t.td.destination = "Bangalore Junction";
			break;
		case 8:
			t.td.train_no = 10008;
			t.td.train_time = "16:00";
			t.td.train_name ="Rajdhani Express";
			t.td.origin = "Bangalore Junction";
			t.td.destination = "New Delhi Junction";
			break;
		default:
			printf("\nSorry, Invalid Train Id\tPlease Enter Correct Train Id...");
			getch();
			goto Id;
	}
	printf("\nEnter Date of Journey [DD/MM/YYYY]: ");
	scanf("%d/%d/%d", &t.td.dd, &t.td.mm, &t.td.yyyy);
	printf("\n\nTickets Need to be Confirmed...\nPress Any Key to Continue...");
	getch();
	system("cls");
	
	charges = (no_of_passengers-fc_count) * 1000 + (fc_count*concession_fees);

	printf("\n\nCharges per Ticket : Rs.1000 \t\t Fee Concession [If Applicable] : Rs.500\n");
	printf("Train No \t: %d \t\t Train Name \t : %s\n", t.td.train_no, t.td.train_name);
	printf("Class \t\t: %s \t\t Date of Journey : %d/%d/%d\n", t.td.train_class, t.td.dd, t.td.mm, t.td.yyyy);
	printf("Origin \t\t: %s \t Destination \t : %s\n", t.td.origin, t.td.destination);
	printf("Total Charges \t: %d \t\t\t Arrival Time  \t : %s", charges,t.td.train_time);
	printf("\n\t\t________________________________________________\n");
	printf("\n\t\t\tName\t\tAge\tGender");
	printf("\n\t\t________________________________________________\n");
	for( i = 0; i < no_of_passengers; i++) {

		printf("\n\t\t\t%s %s\t\t%d\t%s", t.pd[i].passenger_fname, t.pd[i].passenger_lname, t.pd[i].passenger_age, t.pd[i].passenger_gender);
	}
	printf("\n\t\t________________________________________________\n");
	printf("\n\t\tCommon Phone Number: %lld\n", t.PhoneNumber);
	printf("\n\t\t________________________________________________\n");
	printf("\n Do you want to Confirm Your Ticker [y/n]\t: ");
	scanf(" %c", &confirm);
	printf(" %c", confirm);
	if(confirm == 'y')
	{
		system("cls");	
		for( i = 0; i < no_of_passengers; i++){
			fprintf(fb,"%d\t%s %s\t%d\t %s\t%d/%d/%d\t%lld\n", t.td.train_no, t.pd[i].passenger_fname, t.pd[i].passenger_lname, t.pd[i].passenger_age, t.pd[i].passenger_gender, t.td.dd, t.td.mm, t.td.yyyy, t.PhoneNumber);
		}
		printf("\n\t\t________________________________________________\n");
		printf("\n\t\t\tName\t\tAge\tGender\n");
		printf("\t\t________________________________________________\n");
		for( i = 0; i < no_of_passengers; i++) {

			printf("\n\t\t\t%s %s\t\t%d\t%s", t.pd[i].passenger_fname, t.pd[i].passenger_lname, t.pd[i].passenger_age, t.pd[i].passenger_gender);
		}
		printf("\n\t\t________________________________________________\n");
		printf("\n\t\tCommon Phone Number: %lld\n", t.PhoneNumber);
		printf("\n\t\t________________________________________________\n");
		printf("\n\t\t\tYour Tickets are Confirmed!\n\t\t\tThank You for Travelling with us!");
		
	}
    else
    {
		system("cls");
		printf("\n\nWhat Do You Want to Edit? :\n");
		printf("\n\t1)Details of Passengers\n\t2)Train Id & Date of Journey\n\t3)Cancel Ticket\n\t0) None\n\n\tEnter Your Choice [0/1/2/3] : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				break;
			case 1:
				goto Details;
			case 2:
				goto Id;
			case 3:
				Cancellation();
				break;
		}
    	fclose(fb);
		PrepareChart();
		printf("\n\n\nPress Any Key to Go to Main Menu...");
		getch();
    	fc_count = 0;
    }
}

// Implementation of Checking Availability

void AvailabilityCheck()
{
	system("cls");
    printf("\n--------------------------------AVAILABLE TRAINS--------------------------------\n");
	printf("________________________________________________________________________________");
	printf("\n\n Tr.Id\tTr.No\tTrain Name\t\tOrigin     Destination\tTime\tCharges\n");
	printf("________________________________________________________________________________\n");
	printf("\n  1  \t10001\tVaigai SF Express\tMadurai     Chennai\t09:00\t1000");
	printf("\n  2  \t10002\tCoimbatore Express\tChennai     Coimbatore\t13:00\t1000");
	printf("\n  3  \t10003\tCoimbatore Express\tRameswaram  Coimbatore\t08:00\t1000");
	printf("\n  4  \t10004\tCoimbatore Express\tNagercoil   Coimbatore\t23:00\t1000");
	printf("\n  5  \t10005\tVaigai SF Express\tChennai     Madurai\t18:00\t1000");
	printf("\n  6  \t10006\tPune Indore Express\tPune        Indore\t09:30\t1000");
	printf("\n  7  \t10007\tBangalore Express\tChennai     Bangalore\t13:00\t1000");
	printf("\n  8  \t10008\tRajdhani Express\tBanglore    New Delhi\t16:00\t1000");
	printf("\n________________________________________________________________________________\n");
}

// Implementation of Cancelling ticket

int Cancellation()
{
	int ch, size, done = 0;
	long long int phono;
	ticket dt;
	char fname[15], lname[10], gender[2];
	int age;
	
	cancel :

	system("cls");
	printf("Do you want to delete...\n0) Exit\n1) All of Your Reservation\n2) Specific Passanger Reservation\n");
	printf("Enter Your chioce [0/1/2]: ");
	scanf("%d", &ch);
	
	if (ch == 0)
		return 0;

	FILE * fp = fopen("ReservationList.txt", "r");
	if (fp == NULL)
	{
		printf("Source File NULL While cancelling");
		return 1;
	}
	FILE * fp1 = fopen("copy.txt", "a");
	if (fp1 == NULL)
	{
		printf("Temp File Not found while cancelling");
		return 1;
	}
	switch(ch)
	{
		// To Remove bunch of Passengers data
		case 1:
			rewind(fp);
			printf("Enter Your Common Phone Number: ");
			scanf("%lld", &phono);
			while (!feof(fp))
			{
				fscanf(fp, "%d\t%s %s\t%d\t %s\t%d/%d/%d\t%lld\n", &dt.td.train_no, dt.pd[0].passenger_fname, dt.pd[0].passenger_lname, &dt.pd[0].passenger_age, dt.pd[0].passenger_gender, &dt.td.dd, &dt.td.mm, &dt.td.yyyy, &dt.PhoneNumber);
				if (dt.PhoneNumber != phono)
				{
					fprintf(fp1,"%d\t%s %s\t%d\t %s\t%d/%d/%d\t%lld\n", dt.td.train_no, dt.pd[0].passenger_fname, dt.pd[0].passenger_lname, dt.pd[0].passenger_age, dt.pd[0].passenger_gender, dt.td.dd, dt.td.mm, dt.td.yyyy, dt.PhoneNumber);
					done = 1;
				}
			}
			break;
		
		// To Remove a Particular Passengers Data
		case 2:
			rewind(fp);
			printf("\nFirst Name\t: ");
			scanf("%s",fname);
			printf("Last Name\t: ");
			scanf("%s",lname);
			while (!feof(fp))
			{
				fscanf(fp, "%d\t%s %s\t%d\t %s\t%d/%d/%d\t%lld\n", &dt.td.train_no, dt.pd[0].passenger_fname, dt.pd[0].passenger_lname, &dt.pd[0].passenger_age, dt.pd[0].passenger_gender, &dt.td.dd, &dt.td.mm, &dt.td.yyyy, &dt.PhoneNumber);
				if (strcmp(dt.pd[0].passenger_lname, lname) != 0){
					if (strcmp(dt.pd[0].passenger_fname, fname) != 0){
							fprintf(fp1,"%d\t%s %s\t%d\t %s\t%d/%d/%d\t%lld\n", dt.td.train_no, dt.pd[0].passenger_fname, dt.pd[0].passenger_lname, dt.pd[0].passenger_age, dt.pd[0].passenger_gender, dt.td.dd, dt.td.mm, dt.td.yyyy, dt.PhoneNumber);
							done = 1;
					}
				}
			}
			printf("\n\n\n\n\t\t The Ticket Named %s %s with Phone Number %lld was Cancelled",fname, lname, dt.PhoneNumber);
			break;
		default:
			printf("Invalid Choice, \nPlese Select a valid choice...\n");
			getch();
			goto cancel;
			break;
	}

	fclose(fp);
	fclose(fp1);
	
	remove("ReservationList.txt");
	rename("copy.txt", "ReservationList.txt");
	if (done == 1){	
		printf("Cancellation Done.");
		printf("\n\n\n\t\tPlease Reload the Program and Run");
		done = 0;
	}
	return 0;
}

//Impementation of Preparing chat (Displaying information)

void PrepareChart()
{
    system("cls");
	FILE *fb;
	long long int phono;
	int train_no, age, dd, mm, yyyy;
	char fname[10], lname[10], gender[2];
	

	fb = fopen("ReservationList.txt","r");
	rewind(fb);
	printf("\n\t__________________________________________________________________________________________________________\n");
	printf("\n\t Train No.\tName\t\tAge\tGender\tDate of Journey\tPhone Number\n");
	printf("\t_____________________________________________________________________________________________________________\n\n");
	while (!feof(fb))
	{	
		if (feof(fb))
			printf("\n\t\tNo Tickets Booked or Reserved");
		else
		{
			fscanf(fb, "%d\t%s %s\t%d\t %s\t%d/%d/%d\t%lld", &train_no, fname, lname, &age, gender, &dd, &mm, &yyyy, &phono);
			if (!feof(fb))
				printf("\t %d\t\t%s %s\t%d\t %s\t%d/%d/%d\t%lld\n", train_no, fname, lname, age, gender, dd, mm, yyyy, phono);
		}
	}
	printf("\t_____________________________________________________________________________________________________________\n");
	fclose(fb);
}

// To Create an Empty Chart

void ClearData()
{
	FILE * fp = fopen("ReservationList.txt", "w");
	fprintf(fp, "");
	fclose(fp);
}
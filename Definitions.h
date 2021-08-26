/*
------------------------
Header file for Definition.c which deals with Definition Part
------------------------
*/

/*
---------------------
Constant Definition
---------------------
*/
#define concession_fees 500
#define total_seats_sleeper 72
#define total_seats_seater 110

/*
------------------------
Structure Definition
------------------------
*/

// Required Details about Passenger
typedef struct {

	char passenger_fname[15], passenger_lname[10];
	char passenger_gender[2];
	int passenger_age;

}pass_details;

// Required Details about Trains
typedef struct {

		int train_id, train_no;
		int dd, mm, yyyy;
		char *train_class, *train_name, *train_time;
		char *origin, *destination;
}train_details;


typedef struct {
    pass_details pd[10];
    train_details td;
    long long int PhoneNumber;
}ticket;

/*
------------------------
Function Definition
------------------------
*/

int Book();

void AvailabilityCheck();

int Cancellation();

void PrepareChart();

void ClearData();

void getinfo(int);
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 6031)
#pragma warning (disable : 6289)

void displayRandomJobs(int ws);
const char* chooseDay(int ws);
void manageJob(int c, int ws);
void login();

int isJobAvailable = 0;

char finaljobname[100];
char finaljobday[100];
int finaljobprice;
int finaljobtimestart;
int finaljobtimeend;

struct AddJob {
	char jobname[100];
	int jobpayment;
	int timestart;
	int timeend;
	char day[10];
};

int main() {

	srand(time(NULL));

	int cs = 0;
	int ws;

	printf(" ______________________________\n");
	printf("|        Get Employed!         |\n");
	printf("|                              |\n");
	printf("|    Various different jobs    |\n");
	printf("|      for you to choose!      |\n");
	printf("|                              |\n");
	printf("|   To get started, Enter \"1\"  |\n");
	printf("|                              |\n");
	printf("|  If you want to manage jobs, |\n");
	printf("|           Enter \"2\"          |\n");
	printf("|______________________________|\n");

	scanf_s("%d", &cs);
	while (cs != 1 && cs != 2) {

		printf("Sorry! This input is not accepted! Please try again.\n");
		scanf_s("%d", &cs);
	}

	if (cs == 1)
	{
		printf("Do you want to work on Saturdays and Sundays? If so, please enter \"1\", if not, then enter \"0\".\n");
		scanf_s("%d", &ws);
		printf("\n\nLoading Jobs...\n\n");
		Sleep(3000);
		displayRandomJobs(ws);
	}
	else if (cs == 2) {
		login();
		puts("If you want to load the job manager, enter \"1\". If you want to print your jobs, enter \"2\".\n");
		int jb = 0;
		scanf_s("%d", &jb);

		while (jb != 1 && jb != 2) {
			puts("Input not accepted, please try again\n");
			scanf_s("%d", &jb);
		}

		if (jb == 1) {
			printf("\n\nLoading Job Manager...\n\n");
			Sleep(3000);
			manageJob(0, 0);
			main();
		}
		else if (jb == 2) {
			printf("\n\nPrinting Jobs...\n\n");
			Sleep(3000);
			manageJob(2, 0);
			main();
		}
	}


	return 0;
}

void displayRandomJobs(int ws) {

	int timeranAM = 0, timeranPM = 0, pricean;
	char rc;
	rc = getchar();
	const char* day;
	static int remove1, remove2, remove3, remove4, remove5;
	srand(time(NULL));

	static int jobprice1 = 0;
	static int jobtimestart1 = 0;
	static int jobtimeend1 = 0;
	static char jobday1[10] = { 0 };
	static int jobprice2 = 0;
	static int jobtimestart2 = 0;
	static int jobtimeend2 = 0;
	static char jobday2[10] = { 0 };
	static int jobprice3 = 0;
	static int jobtimestart3 = 0;
	static int jobtimeend3 = 0;
	static char jobday3[10] = { 0 };
	static int jobprice4 = 0;
	static int jobtimestart4 = 0;
	static int jobtimeend4 = 0;
	static char jobday4[10] = { 0 };
	static int jobprice5 = 0;
	static int jobtimestart5 = 0;
	static int jobtimeend5 = 0;
	static char jobday5[10] = { 0 };

	int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0;

	printf("AVAILABLE JOBS:\n\n");

	for (int i = 0; i < 3; i++)
	{

		int ran = 1 + rand() % 6;


		switch (ran)
		{
		case 1: {
			if (r1 == 0) {
				day = chooseDay(ws);
				pricean = 5 + rand() % 15;
				printf("\nJOB NAME: Cleaning Windows\n\tJOB PAYMENT: $%d/hr", pricean);
				timeranAM = 4 + rand() % 12;
				timeranPM = timeranAM + (1 + rand() % 6);
				printf("\n\tTIME: %d:00 --> %d:00 on %s\n", timeranAM, timeranPM, day);
				printf("\tTOTAL PAYMENT = $%d\n", (timeranPM - timeranAM) * pricean);
				jobprice1 = pricean;
				jobtimestart1 = timeranAM;
				jobtimeend1 = timeranPM;
				strcpy(jobday1, day);
				printf("TO SELECT THIS JOB, TYPE \"1\"\n");
				r1++;
				break;
			}
			else
			{
				printf("\nJOB CURRENTLY UNAVAILABLE\n");
				break;
			}
		}
		case 2: {
			if (r2 == 0) {
				day = chooseDay(ws);
				pricean = 5 + rand() % 10;
				printf("\nJOB NAME: Babysitting\n\tJOB PAYMENT: $%d/hr", pricean);
				timeranAM = 4 + rand() % 12;
				timeranPM = timeranAM + (1 + rand() % 6);
				printf("\n\tTIME: %d:00 --> %d:00 on %s\n", timeranAM, timeranPM, day);
				printf("\tTOTAL PAYMENT = $%d\n", (timeranPM - timeranAM) * pricean);
				jobprice2 = pricean;
				jobtimestart2 = timeranAM;
				jobtimeend2 = timeranPM;
				strcpy(jobday2, day);
				printf("TO SELECT THIS JOB, TYPE \"2\"\n");
				r2++;
				break;
			}
			else {
				printf("\nJOB CURRENTLY UNAVAILABLE\n");
				break;
			}
		}
		case 3: {
			if (r3 == 0) {
				day = chooseDay(ws);
				pricean = 5 + rand() % 15;
				printf("\nJOB NAME: Gardening\n\tJOB PAYMENT: $%d/hr", pricean);
				timeranAM = 4 + rand() % 12;
				timeranPM = timeranAM + (1 + rand() % 6);
				printf("\n\tTIME: %d:00 --> %d:00 on %s\n", timeranAM, timeranPM, day);
				printf("\tTOTAL PAYMENT = $%d\n", (timeranPM - timeranAM) * pricean);
				jobprice3 = pricean;
				jobtimestart3 = timeranAM;
				jobtimeend3 = timeranPM;
				strcpy(jobday3, day);
				printf("TO SELECT THIS JOB, TYPE \"3\"\n");
				r3++;
				break;
			}
			else {
				printf("\nJOB CURRENTLY UNAVAILABLE\n");
				break;
			}
		}
		case 4: {
			if (r4 == 0) {
				day = chooseDay(ws);
				pricean = 5 + rand() % 15;
				printf("\nJOB NAME: Video Editor\n\tJOB PAYMENT: $%d/hr", pricean);
				timeranAM = 4 + rand() % 12;
				timeranPM = timeranAM + (1 + rand() % 6);
				printf("\n\tTIME: %d:00 --> %d:00 on %s\n", timeranAM, timeranPM, day);
				printf("\tTOTAL PAYMENT = $%d\n", (timeranPM - timeranAM) * pricean);
				jobprice4 = pricean;
				jobtimestart4 = timeranAM;
				jobtimeend4 = timeranPM;
				strcpy(jobday4, day);
				printf("TO SELECT THIS JOB, TYPE \"4\"\n");
				r4++;
				break;
			}
			else {
				printf("\nJOB CURRENTLY UNAVAILABLE\n");
				break;
			}
		}
		case 5: {
			if (r5 == 0) {
				day = chooseDay(ws);
				pricean = 5 + rand() % 15;
				printf("\nJOB NAME: Music Editor\n\tJOB PAYMENT: $%d/hr", pricean);
				timeranAM = 4 + rand() % 12;
				timeranPM = timeranAM + (1 + rand() % 6);
				printf("\n\tTIME: %d:00 --> %d:00 on %s\n", timeranAM, timeranPM, day);
				printf("\tTOTAL PAYMENT = $%d\n", (timeranPM - timeranAM) * pricean);
				jobprice5 = pricean;
				jobtimestart5 = timeranAM;
				jobtimeend5 = timeranPM;
				strcpy(jobday5, day);
				printf("TO SELECT THIS JOB, TYPE \"5\"\n");
				r5++;
				break;
			}
			else {
				printf("\nJOB CURRENTLY UNAVAILABLE\n");
				break;
			}
		}
		case 6:
			if (r6 == 0) {
				if (isJobAvailable == 0)
					printf("\nJOB CURRENTLY UNAVAILABLE\n");
				else
					manageJob(1, ws);
				r6++;
				break;
			}
			else {
				printf("\nJOB CURRENTLY UNAVAILABLE\n");
				break;
			}
		}
	}

	printf("\n\nTo refresh the list, type \"R\" or \"r\".\nIf you wish to go back to the menu, type \"M\" or \"m\".\n");
	rc = getchar();

	if (rc == 'R' || rc == 'r') {
		printf("\n\n\nRefreshing...\n\n\n\n\n\n");
		Sleep(1000);
		displayRandomJobs(ws);
	}
	else if (rc == 'M' || rc == 'm') {
		printf("\n\n\nLoading Menu...\n\n\n\n\n\n");
		Sleep(3000);
		main();
	}
	else if (isdigit(rc)) {

		switch (rc)
		{
		case '1': {
			printf("\n\nContacting Job Employer...");
			Sleep(3000);
			printf("\nRequest recieved, awaiting confirmation...\n");
			Sleep(2000);
			int declineornot = rand() % 3;
			if (declineornot != 0) {
				printf("\nSELECTED JOB: Cleaning Windows\n");
				printf("TIME: %d:00 --> %d:00 on %s\n", jobtimestart1, jobtimeend1, jobday1);
				printf("PAYMENT: $%d/hr\n", jobprice1);
				printf("\nCongratulations! You got the job!\n\n");
				break;
			}
			else {
				printf("\nSorry, you are inexperienced for this job.\n");
				break;
			}
		}
		case '2': {
			printf("\n\nContacting Job Employer...");
			Sleep(3000);
			printf("\nRequest recieved, awaiting confirmation...\n");
			Sleep(2000);
			int declineornot = rand() % 3;
			if (declineornot != 0) {
				printf("\nSELECTED JOB: Babysitting\n");
				printf("TIME: %d:00 --> %d:00 on %s\n", jobtimestart2, jobtimeend2, jobday2);
				printf("PAYMENT: $%d/hr\n", jobprice2);
				printf("\nCongratulations! You got the job!\n\n");
				break;
			}
			else {
				printf("\nSorry, you are inexperienced for this job.\n");
				break;
			}
		}
		case '3': {
			printf("\n\nContacting Job Employer...");
			Sleep(3000);
			printf("\nRequest recieved, awaiting confirmation...\n");
			Sleep(2000);
			int declineornot = rand() % 3;
			if (declineornot != 0) {
				printf("\nSELECTED JOB: Gardening\n");
				printf("TIME: %d:00 --> %d:00 on %s\n", jobtimestart3, jobtimeend3, jobday3);
				printf("PAYMENT: $%d/hr\n", jobprice3);
				printf("\nCongratulations! You got the job!\n\n");
				break;
			}
			else {
				printf("\nSorry, you are inexperienced for this job.\n");
				break;
			}
		}
		case '4': {
			printf("\n\nContacting Job Employer...");
			Sleep(3000);
			printf("\nRequest recieved, awaiting confirmation...\n");
			Sleep(2000);
			int declineornot = rand() % 3;
			if (declineornot != 0) {
				printf("\nSELECTED JOB: Video Editor\n");
				printf("TIME: %d:00 --> %d:00 on %s\n", jobtimestart4, jobtimeend4, jobday4);
				printf("PAYMENT: $%d/hr\n", jobprice4);
				printf("\nCongratulations! You got the job!\n\n");
				break;
			}
			else {
				printf("\nSorry, you are inexperienced for this job.\n");
				break;
			}
		}
		case '5': {
			printf("\n\nContacting Job Employer...");
			Sleep(3000);
			printf("\nRequest recieved, awaiting confirmation...\n");
			Sleep(2000);
			int declineornot = rand() % 3;
			if (declineornot != 0) {
				printf("\nSELECTED JOB: Music Editor\n");
				printf("TIME: %d:00 --> %d:00 on %s\n", jobtimestart5, jobtimeend5, jobday5);
				printf("PAYMENT: $%d/hr\n", jobprice5);
				printf("\nCongratulations! You got the job!\n\n");
				break;
			}
			else {
				printf("\nSorry, you are inexperienced for this job.\n");
				break;
			}
		}
		case '6': {
			printf("\n\nContacting Job Employer...");
			Sleep(3000);
			printf("\nRequest recieved, awaiting confirmation...\n");
			Sleep(2000);
			printf("\nSELECTED JOB: %s\n", finaljobname);
			printf("TIME: %d:00 --> %d:00 on %s\n", finaljobtimestart, finaljobtimeend, finaljobday);
			printf("PAYMENT: $%d/hr\n", finaljobprice);
			printf("\nCongratulations! You got the job!\n\n");

			FILE* filePointer;
			filePointer = fopen("jobs.txt", "a");
			fprintf(filePointer, "\n(JOB TAKEN)\n");
			fclose(filePointer);

			isJobAvailable = 0;
			break;
		}
		}
	}

	char mc;
	mc = getchar();
	printf("Enter 'm' or 'M' to go back to the menu.\n");
	mc = getchar();
	if (mc == 'm' || mc == 'M')
		main();
	else
	{
		while ((mc != 'm') || (mc != 'M'))
		{
			mc = getchar();
			printf("Sorry! This input is not accepted! Please try again.\n");
			mc = getchar();
			if (mc == 'm' || mc == 'M') {
				main();
			}
		}
	}
}

const char* chooseDay(int ws) {



	if (ws == 0) {

		int chday = rand() % 5;

		switch (chday)
		{
		case 0:
			return "Monday";
			break;
		case 1:
			return "Tuesday";
			break;
		case 2:
			return "Wednesday";
			break;
		case 3:
			return "Thursday";
			break;
		case 4:
			return "Friday";
			break;
		}
	}
	else if (ws == 1) {
		int chday = rand() % 7;

		switch (chday)
		{
		case 0:
			return "Monday";
			break;
		case 1:
			return "Tuesday";
			break;
		case 2:
			return "Wednesday";
			break;
		case 3:
			return "Thursday";
			break;
		case 4:
			return "Friday";
			break;
		case 5:
			return "Saturday";
			break;
		case 6:
			return "Sunday";
			break;
		}
	}

}

void manageJob(int c, int ws) {

	static struct AddJob Job = { "", 0, 0, 0, "" };

	static int w = NULL;

	FILE* filePointer;

	static int j = 0;

	if (c == 2) {

		if (j == 0)
			puts("\nYou have not added any jobs to print yet.\n");
		else {
			FILE* fptr;
			fptr = fopen("jobs.txt", "r");
			c = fgetc(fptr);
			while (c != EOF)
			{
				printf("%c", c);
				c = fgetc(fptr);
			}
			fclose(fptr);
			puts("\n");
		}

	}
	else if (c == 0 && isJobAvailable == 0) {


		if (j == 0) {
			filePointer = fopen("jobs.txt", "w");
		}
		else {
			filePointer = fopen("jobs.txt", "a");
		}

		char jobname[100] = { '\0' }, jobday[10] = { '\0' };


		gets_s(jobname);


		printf("What is the name of your job? ");
		gets_s(jobname);
		printf("What day? (Please type the first 3 letters for the day you want) ");
		gets_s(jobday);

		int chooseday = 0;
		while (chooseday != 1) {
			if (strcmp(jobday, "Mon") == 0 || strcmp(jobday, "mon") == 0)
			{
				strcpy(Job.day, "Monday");
				w = 0;
				chooseday = 1;
			}
			else if (strcmp(jobday, "Tue") == 0 || strcmp(jobday, "tue") == 0)
			{
				strcpy(Job.day, "Tuesday");
				w = 0;
				chooseday = 1;
			}
			else if (strcmp(jobday, "Wed") == 0 || strcmp(jobday, "wed") == 0)
			{
				strcpy(Job.day, "Wednesday");
				w = 0;
				chooseday = 1;
			}
			else if (strcmp(jobday, "Thu") == 0 || strcmp(jobday, "thu") == 0)
			{
				strcpy(Job.day, "Thursday");
				w = 0;
				chooseday = 1;
			}
			else if (strcmp(jobday, "Fri") == 0 || strcmp(jobday, "fri") == 0)
			{
				strcpy(Job.day, "Friday");
				w = 0;
				chooseday = 1;
			}
			else if (strcmp(jobday, "Sat") == 0 || strcmp(jobday, "sat") == 0)
			{
				strcpy(Job.day, "Saturday");
				w = 1;
				chooseday = 1;
			}
			else if (strcmp(jobday, "Sun") == 0 || strcmp(jobday, "sun") == 0)
			{
				strcpy(Job.day, "Sunday");
				w = 1;
				chooseday = 1;
			}
			else
			{
				puts("Input not accepted, please try again.");
				gets_s(jobday);
			}
		}

		strncpy(Job.jobname, jobname, 100);
		printf("How much is the payment per hour? ");
		scanf_s("%d", &Job.jobpayment);
		printf("When does it start? (24hr format) ");
		scanf_s("%d", &Job.timestart);
		printf("When does it end? (24hr format) ");
		scanf_s("%d", &Job.timeend);

		printf("Adding Job...\n");
		Sleep(2500);
		printf("JOB ADDED SUCCESSFULLY!\n");
		isJobAvailable = 1;

		strcpy(finaljobname, Job.jobname);
		strcpy(finaljobday, Job.day);
		finaljobprice = Job.jobpayment;
		finaljobtimestart = Job.timestart;
		finaljobtimeend = Job.timeend;


		fprintf(filePointer, "%d: %s on %s from %d:00 -> %d:00. Payment: $%d/hr.", (j + 1), Job.jobname, Job.day, Job.timestart, Job.timeend, Job.jobpayment);



		j++;
		fclose(filePointer);
	}
	else if (c == 1)
	{
		if (ws == 1) {
			printf("\nJOB NAME: %s\n\tJOB PAYMENT: $%d/hr", Job.jobname, Job.jobpayment);
			printf("\n\tTIME: %d:00 --> %d:00 on %s\n", Job.timestart, Job.timeend, Job.day);
			printf("\tTOTAL PAYMENT = $%d\n", (Job.timeend - Job.timestart) * Job.jobpayment);
			printf("TO SELECT THIS JOB, TYPE \"6\"\n");
		}
		else if (ws == 0)
		{
			if (w == 0)
			{
				printf("\nJOB NAME: %s\n\tJOB PAYMENT: $%d/hr", Job.jobname, Job.jobpayment);
				printf("\n\tTIME: %d:00 --> %d:00 on %s\n", Job.timestart, Job.timeend, Job.day);
				printf("\tTOTAL PAYMENT = $%d\n", (Job.timeend - Job.timestart) * Job.jobpayment);
				printf("TO SELECT THIS JOB, TYPE \"6\"\n");
			}
			else if (w == 1)
			{
				printf("\nJOB CURRENTLY UNAVAILABLE\n");
			}
		}
	}
	else if (c == 0 && isJobAvailable == 1) {

		int input;

		printf("A job offer has already been added, enter \"1\" to replace it with a new offer, or \"0\" to keep it and go back to the menu: ");
		scanf_s("%d", &input);

		int notinput = 0;
		while (notinput != 1)
		{
			if (input == 1)
			{

				FILE* inputfile = fopen("jobs.txt", "r");
				FILE* outputfile = fopen("jobsdel.txt", "w");
				char line1[1000], line2[1000];
				fgets(line1, sizeof line1, inputfile);

				while (fgets(line2, sizeof line2, inputfile)) {
					fprintf(outputfile, "%s", line1);
					strcpy(line1, line2);
				}

				fclose(outputfile);
				fclose(inputfile);

				remove("jobs.txt");
				rename("jobsdel.txt", "jobs.txt");

				j--;

				isJobAvailable = 0;
				manageJob(0, 0);
				main();
			}
			else if (input == 0)
			{
				puts("\nJob offer kept.\n");
				main();
			}
			else {
				puts("Input not accepted, please try again.\n");
				scanf_s("%d", &input);
			}
		}

	}


}

void login() {

	static int i = 0;

	char username[100] = "";
	char password[100] = "";

	static char regusername[100] = "";
	static char regpassword[100] = "";
	char regpassword2[100] = "";
	int x = 1;

	fgets(username, sizeof(username), stdin);

	if (i == 0) {

		printf("\nRegister account:\n");
		printf("\nUsername: ");
		fgets(regusername, sizeof(regusername), stdin);
		printf("Password: ");
		fgets(regpassword, sizeof(regpassword), stdin);
		printf("Re-enter Password: ");
		fgets(regpassword2, sizeof(regpassword2), stdin);

		if ((strcmp(regpassword, regpassword2) == 0))
		{
			puts("\nRegistration successful!\n");
			i = 1;
		}
		else
		{
			while (i != 1)
			{
				puts("\nError! Passwords are incorrect. Please try again.\n");
				printf("\nUsername: ");
				fgets(regusername, sizeof(regusername), stdin);
				printf("Password: ");
				fgets(regpassword, sizeof(regpassword), stdin);
				printf("Re-enter Password: ");
				fgets(regpassword2, sizeof(regpassword2), stdin);
				if ((strcmp(regpassword, regpassword2) == 0))
				{
					puts("\nRegistration successful!\n");
					i = 1;
				}
			}

		}
	}
	else if (i == 1) {

		printf("\nLogin account:\n");

		while (x != 0) {
			printf("\nUsername: ");
			fgets(username, sizeof(username), stdin);
			printf("Password: ");
			fgets(password, sizeof(password), stdin);

			if ((username[0] == 'm' || username[0] == 'M') && (password[0] == 'm' || password[0] == 'M')) {
				main();
			}
			else if (strcmp(username, regusername) == 0 && strcmp(password, regpassword) == 0)
			{
				printf("\nLogin successful!\n\n");
				x = 0;
			}
			else
			{
				printf("\nIncorrect username or password. Please try again.\nIf you want to go back to the menu, enter \"m\" or \"M\" in both fields.\n");
			}
		}
	}
}

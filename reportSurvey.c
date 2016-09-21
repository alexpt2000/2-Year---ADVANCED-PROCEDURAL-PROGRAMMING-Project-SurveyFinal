/**
@desc reportSurvey - print statistics information to the file
@param struct listElement** head
@return void - Don't have return
*/

#include "functions.h"

void reportSurvey(struct listElement* head) {

	printf("\nReport Saved...\n");

	int i, j, sentinel, op;

	FILE* myReport; // Pointer to file

	// Open up the file with the Survey
	myReport = fopen("ReportSurveys.txt", "w");

	struct listElement *temp;

	int count = 1;
	temp = head;


	int countGender[2] = { 0, 0 };
	int countAge[5] = { 0, 0, 0, 0, 0 };
	int countIncome[7] = { 0, 0, 0, 0, 0, 0, 0 };

	int resultGender[2] = { 0, 0 };
	int resultAge[5] = { 0, 0, 0, 0, 0 };
	int resultIncome[7] = { 0, 0, 0, 0, 0, 0, 0 };

	sentinel = 0;
	count = 1;

	// print header file 
	fprintf(myReport, "=============================================================================================\n");
	fprintf(myReport, "                                      Survey - Records\n");
	fprintf(myReport, "=============================================================================================\n");

	fprintf(myReport, "\n         PPS Name            Surname         Address              Email                Gender\n");
	fprintf(myReport, "=============================================================================================\n");

	// loo into the memory print all details into the file
	while (temp != NULL)
	{
		fprintf(myReport, "n. %3d %5d %-15s %-15s %-20s %-20s %-20s\n", count, temp->pps, temp->firstName, temp->secondName, temp->address, temp->email, &genderArray[temp->Gender - 1][0]);
		fprintf(myReport, "Age........: %s\n", &ageArray[temp->age.age - 1][0]);
		fprintf(myReport, "Income.....: %s\n", &incomeArray[temp->income.income - 1][0]);
		fprintf(myReport, "Exercise...: %s\n", &exerciseArray[temp->exercise.exercise - 1][0]);
		fprintf(myReport, "Alcohol....: %s\n", &alcoholArray[temp->alcohol.alcohol - 1][0]);
		fprintf(myReport, "Cigarettes.: %s\n", &cigarettesArray[temp->cigarettes.cigarettes - 1][0]);

		fprintf(myReport, "----------------------------------------------------------------------------------------------\n");

		count++; // count records
		temp = temp->next; // next record

	}


	// print header statistics
	fprintf(myReport, "\n=============================================================================================\n");
	fprintf(myReport, "                                      Survey - Statistics\n");
	fprintf(myReport, "=============================================================================================");


	temp = NULL;
	temp = head;


	// loop for each option 1 to 12, the same option exist Menu for Statistics
	for (op = 1; op <= 12; op++)
	{
		count = 0;
		sentinel = 0;
		int countAge[5] = { 0, 0, 0, 0, 0 };
		int countIncome[7] = { 0, 0, 0, 0, 0, 0, 0 };
		int countGender[2] = { 0, 0 };

		// loop all records into the memory temp
		while (temp != NULL)
		{

			// this state condition will takes diferents criterias, kind of people smoke and value takes from option
			// each line represents one condition

			if ((op == 1 && (temp->cigarettes.cigarettes >= 2 && temp->cigarettes.cigarettes <= 4)) ||
				(op == 2 && (temp->cigarettes.cigarettes == 2)) ||
				(op == 3 && (temp->cigarettes.cigarettes == 3)) ||
				(op == 4 && (temp->cigarettes.cigarettes == 4)) ||
				(op == 5 && (temp->exercise.exercise == 1)) ||
				(op == 6 && (temp->exercise.exercise == 2)) ||
				(op == 7 && (temp->exercise.exercise == 3)) ||
				(op == 8 && (temp->exercise.exercise == 4)) ||
				(op == 9 && (temp->alcohol.alcohol == 1)) ||
				(op == 10 && (temp->alcohol.alcohol == 2)) ||
				(op == 11 && (temp->alcohol.alcohol == 3)) ||
				(op == 12 && (temp->alcohol.alcohol == 4)))	{ // finsh if statemnt


				int age = temp->age.age;
				int income = temp->income.income;
				int gender = temp->Gender;
				countAge[age - 1] += 1;
				countIncome[income - 1] += 1;
				countGender[gender - 1] += 1;
				count++;
				sentinel = 1;
			}
			temp = temp->next;
		}


		// if the value exist will take this condition
		if (sentinel == 1) {

			// loop count and get % Age
			for (i = 0; i < 5; i++)
			{
				resultAge[i] = (countAge[i] * 100) / count;
			}

			// loop count and get % Income
			for (i = 0; i < 7; i++)
			{
				resultIncome[i] = (countIncome[i] * 100) / count;
			}

			// loop count and get % Gender
			for (i = 0; i < 2; i++)
			{
				resultGender[i] = (countGender[i] * 100) / count;
			}


			//printing all results
			fprintf(myReport, "\n------------------------------------------------------------------\n");
			fprintf(myReport, " Total %d %s\n", count, descStatistics[op - 1]);
			fprintf(myReport, "------------------------------------------------------------------\n");
			for (i = 0; i < 5; i++)
			{
				fprintf(myReport, " Total %3d %% -%4d people - %s\n", resultAge[i], countAge[i], ageArray[i]);
			}

			fprintf(myReport, "---------------------------------------------------\n");
			for (i = 0; i < 7; i++)
			{
				fprintf(myReport, " Total %3d %% -%4d income - %s \n", resultIncome[i], countIncome[i], incomeArray[i]);
			}

			fprintf(myReport, "---------------------------------------------------\n");
			for (i = 0; i < 2; i++)
			{
				fprintf(myReport, " Total %3d %% -%4d gender - %s \n", resultGender[i], countGender[i], genderArray[i]);
			}
		}


		//if don't exist records for this statistics
		else
		{
			fprintf(myReport, "\n------------------------------------------------------------------\n");
			fprintf(myReport, " No records for statistics for \n %s\n", descStatistics[op - 1]);
			fprintf(myReport, "------------------------------------------------------------------\n");
		}


		// for each option the report will be separete
		if (op % 4 == 0) {
			fprintf(myReport, "\n====================================================================================\n");
		}

		temp = NULL;
		temp = head;
	}

	//close the file
	fclose(myReport);

}

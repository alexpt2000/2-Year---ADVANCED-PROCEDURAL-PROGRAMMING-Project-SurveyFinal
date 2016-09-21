#include "functions.h"

void updateElements(struct listElement** head) {
	char *search[40];;
	int sentinel = 0;
	struct listElement *temp;
	int count = 0;

	int choice;

	//temp = (struct listElement*)malloc(sizeof(struct listElement));
	temp = *head;

	printf("Please enter the PPS or First Name..: ");
	scanf("%s", search);

	while (temp != NULL)
	{
		count++;
		// I used atoi to convert strinto to int my search
		if (strcmp(temp->firstName, search) == 0 || temp->pps == atoi(search))
		{
			printf("---------------- Personal Data ---------------------------------\n");
			printf("PPS Number..: %d\n", temp->pps);
			printf("First Name..: %s\n", temp->firstName);
			printf("Second Name.: %s\n", temp->secondName);
			printf("Address.....: %s\n", temp->address);
			printf("Email.......: %s\n", temp->email);
			printf("Gender.......: %s\n", &genderArray[temp->Gender - 1][0]);

			printf("---------------- Survey Data ----------------\n");

			/*
			temp->pps = temp->pps;
			strcpy(temp->firstName, temp->firstName);
			strcpy(temp->secondName, temp->secondName);
			strcpy(temp->address, temp->address);
			strcpy(temp->email, temp->email);
			temp->Gender = temp->Gender;
			*/

			///Loop to get user choice for age.
			do
			{
				// Print Menu
				printf("\n--- Age Bracket ---\n");
				printf("1.  18-20 yrs\n");
				printf("2.  20-30 yrs\n");
				printf("3.  30-50 yrs\n");
				printf("4.  50-65 yrs\n");
				printf("5.  65 +  yrs\n");
				printf("==> ");
				scanf("%d", &choice);

				if (choice <= 0 || choice > 5) { // check numbers between 0 t0 5
					choice = 0;
					printf("Invalid choice - Just choice between 1 to 5.\n");
				}

				if (choice == 1)
					temp->age.age = 1;
				else if (choice == 2)
					temp->age.age = 2;
				else if (choice == 3)
					temp->age.age = 3;
				else if (choice == 4)
					temp->age.age = 4;
				else if (choice == 5)
					temp->age.age = 5;

			} while (choice <= 0 || choice > 5);


			///Loop to get user choice for Income.
			do
			{
				// Print Menu
				printf("\n--- Income Bracket ---\n");
				printf("1.  No Income\n");
				printf("2.  Less than €20,000\n");
				printf("3.  Less than €40,000\n");
				printf("4.  Less than €60,000\n");
				printf("5.  Less than €80,000\n");
				printf("6.  Less than €100,000\n");
				printf("7.  Greater than €100,000\n");
				printf("==> ");
				scanf("%d", &choice);

				if (choice <= 0 || choice > 7) { // check numbers between 0 t0 7
					choice = 0;
					printf("Invalid choice - Just choice between 1 to 7.\n");
				}

				if (choice == 1)
					temp->income.income = 1;
				else if (choice == 2)
					temp->income.income = 2;
				else if (choice == 3)
					temp->income.income = 3;
				else if (choice == 4)
					temp->income.income = 4;
				else if (choice == 5)
					temp->income.income = 5;
				else if (choice == 6)
					temp->income.income = 6;
				else if (choice == 7)
					temp->income.income = 7;

			} while (choice <= 0 || choice > 7);



			///Loop to get user choice for How often do you exercise?.
			do
			{
				// Print Menu
				printf("\n--- How often do you exercise? ---\n");
				printf("1.  Never\n");
				printf("2.  Less than three times per week\n");
				printf("3.  Less than five times per week\n");
				printf("4.  More than five times per week\n");
				printf("==> ");
				scanf("%d", &choice);

				if (choice <= 0 || choice > 4) { // check numbers between 0 t0 4
					choice = 0;
					printf("Invalid choice - Just choice between 1 to 4.\n");
				}

				if (choice == 1)
					temp->exercise.exercise = 1;
				else if (choice == 2)
					temp->exercise.exercise = 2;
				else if (choice == 3)
					temp->exercise.exercise = 3;
				else if (choice == 4)
					temp->exercise.exercise = 4;


			} while (choice <= 0 || choice > 4);



			///Loop to get user choice for How much alcohol do you consume per week?.
			do
			{
				// Print Menu
				printf("\n--- How much alcohol do you consume per week? ---\n");
				printf("1.  None\n");
				printf("2.  Less than 2 units\n");
				printf("3.  Less than 4 units\n");
				printf("4.  More than 4 units\n");
				printf("==> ");
				scanf("%d", &choice);

				if (choice <= 0 || choice > 4) { // check numbers between 0 t0 4
					choice = 0;
					printf("Invalid choice - Just choice between 1 to 4.\n");
				}

				if (choice == 1)
					temp->alcohol.alcohol = 1;
				else if (choice == 2)
					temp->alcohol.alcohol = 2;
				else if (choice == 3)
					temp->alcohol.alcohol = 3;
				else if (choice == 4)
					temp->alcohol.alcohol = 4;

			} while (choice <= 0 || choice > 4);


			///Loop to get user choice for How much cigarettes do you consume per week?.
			do
			{
				// Print Menu
				printf("\n--- How much cigarettes do you consume per week? ---\n");
				printf("1.  None\n");
				printf("2.  Less than 20 cigarettes\n");
				printf("3.  Less than 40 cigarettes\n");
				printf("4.  More than 40 cigarettes\n");
				printf("==> ");
				scanf("%d", &choice);

				if (choice <= 0 || choice > 4) { // check numbers between 0 t0 4
					choice = 0;
					printf("Invalid choice - Just choice between 1 to 4.\n");
				}

				if (choice == 1)
					temp->cigarettes.cigarettes = 1;
				else if (choice == 2)
					temp->cigarettes.cigarettes = 2;
				else if (choice == 3)
					temp->cigarettes.cigarettes = 3;
				else if (choice == 4)
					temp->cigarettes.cigarettes = 4;

			} while (choice <= 0 || choice > 4);

			sentinel = 1;
			*head = temp;
		}
		temp = temp->next;
	}

	if (sentinel == 0) {
		printf("\n The record %s is not the list.\n", search);
	}
}
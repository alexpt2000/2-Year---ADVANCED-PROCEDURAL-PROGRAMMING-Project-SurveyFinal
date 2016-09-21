#include "functions.h"

//Adding books for test
void addTemplatesSurveys(struct listElement** head)
{
	int ppsArray[5] = { 101000, 101001, 101002, 101003, 101004 };
	char *firstNameArray[5] = { "Alex", "Mary", "Kevin", "Sandra", "Vanessa" };
	char *secondNameArray[5] = { "Souza", "Fortes", "Pereira", "Silva", "Peres" };
	char *addressArray[5] = { "15RiverWalk", "35MainStreet", "90GalwayRoad", "8RiverSide", "7CuirtBrheac" };
	char *emailArray[5] = { "alex@gmail.com", "mary@gmit.ie", "kevin@vodafone.ie", "sandra@hotmail.com", "vanessa@gmail.com" };
	int genderArray[5] = { 1, 2, 1, 2, 2 };

	int ageArray[5] = { 1, 3, 2, 4, 5 };
	int incomeArray[5] = { 7, 4, 5, 6, 1 };
	int exerciseArray[5] = { 4, 1, 3, 3, 2 };
	int alcoholArray[5] = { 1, 2, 1, 3, 2 };
	int cigarettelArray[5] = { 1, 4, 1, 1, 1 };

	int sentinel;
	int PPSVerify = 0;
	int choice;
	int i = 0;
	struct listElement *temp;
	struct listElement *newNode;



	temp = *head;
	newNode = (struct listElement*)malloc(sizeof(struct listElement));

	newNode->pps = ppsArray[i];
	strcpy(newNode->firstName, firstNameArray[i]);
	strcpy(newNode->secondName, secondNameArray[i]);
	strcpy(newNode->address, addressArray[i]);
	strcpy(newNode->email, emailArray[i]);
	newNode->Gender = genderArray[i];

	newNode->age.age = ageArray[i];
	newNode->income.income = incomeArray[i];
	newNode->exercise.exercise = exerciseArray[i];
	newNode->alcohol.alcohol = alcoholArray[i];
	newNode->cigarettes.cigarettes = cigarettelArray[i];



	newNode->next = *head;
	*head = newNode; // transfer the address of newNode' to	'head'




	for (i = 1; i < 5; i++) {
		temp = *head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		newNode = (struct listElement*)malloc(sizeof(struct listElement));


		newNode->pps = ppsArray[i];
		strcpy(newNode->firstName, firstNameArray[i]);
		strcpy(newNode->secondName, secondNameArray[i]);
		strcpy(newNode->address, addressArray[i]);
		strcpy(newNode->email, emailArray[i]);
		newNode->Gender = genderArray[i];

		newNode->age.age = ageArray[i];
		newNode->income.income = incomeArray[i];
		newNode->exercise.exercise = exerciseArray[i];
		newNode->alcohol.alcohol = alcoholArray[i];
		newNode->cigarettes.cigarettes = cigarettelArray[i];




		newNode->next = NULL;
		temp->next = newNode;
	}





}
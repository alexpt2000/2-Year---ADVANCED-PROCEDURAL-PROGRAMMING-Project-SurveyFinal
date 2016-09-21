
/**
@desc addElement - function To add an element - Surveys and sort into memory
@param struct listElement** head
@return void - Don't have return
*/

#include "functions.h"


void addElement(struct listElement** head)
{
	int sentinel, i;
	int PPSVerify = 0;
	int choice;
	int position;

	struct listElement *temp;
	struct listElement *newNode;
	struct listElement *old_temp;

	// set temp
	temp = *head;

	// creating memory for old_temp
	old_temp = (struct listElement*)malloc(sizeof(struct listElement));

	// if *head is empty will create the firt survey, passing to addElement_AtStart(head, PPSVerify)
	if (*head == NULL) {
		addElement_AtStart(head, PPSVerify);
	}
	// if not empty
	else {
		do
		{
			sentinel = 0;
			printf("Please enter the PPS number:.: ");
			scanf("%d", &PPSVerify); // takes the PPS
			sentinel = verifyId(*head, PPSVerify); //verify if this PPS exist into memory - get return 1
			position = verifyPosition(*head, PPSVerify); // verify position into memory - return value represents position

			//printf("Position:.: %d \n", position);

		} while (!(sentinel == 0));

		// if *head is empty will create the firt survey, passing to addElement_AtStart(head, PPSVerify)
		if (position == 1)
		{
			addElement_AtStart(head, PPSVerify);
		}
		else
		{
			// loop node to get position to sort a new element
			for (i = 0; i < position; i++)
			{
				old_temp = temp;
				temp = temp->next;
			}

			// creating memory
			newNode = (struct listElement*)malloc(sizeof(struct listElement));

			// call function fillData - pass newNode and PPS number
			// this is the form with all imputs to be populate newNode
			fillData(newNode, PPSVerify); // the newNode will return 

			
			old_temp->next = newNode; //old_temt takes values from newNode 
			newNode->next = temp;  // now newNode->next receive values from temp
		}
	}
}




/**
@desc addElement_AtStart - function To add an element to the top of the list, 
	  this function will be used wend is use for the first time 
@param struct listElement** head, int pps
@return void - Don't have return
*/

void addElement_AtStart(struct listElement** head, int pps)
{
	struct listElement *newNode, *temp;
	int PPSVerify = pps;
	int sentinel = 0;

	temp = *head;

	// creating memory for old_temp
	newNode = (struct listElement*)malloc(sizeof(struct listElement));

	// memory is empty, then request the PPS
	if (*head == NULL) {
		printf("Please enter the PPS number:.: ");
		scanf("%d", &PPSVerify);
	}


	// call function fillData - pass newNode and PPS number
	// this is the form with all imputs to be populate newNode
	fillData(newNode, PPSVerify); // the newNode will return 


	newNode->next = *head;
	*head = newNode; // transfer the address of newNode' to	'head'
}








/**
@desc verifyId - check if PPS exist into the memory, avoid duplicate PPS
@param struct listElement* head, int PPSVerify
@return int - return 0 - if the PPS don't exist memory
			  return 1 - if the PPS exist memory
*/

int verifyId(struct listElement* head, int PPSVerify) {
	struct listElement *temp;
	int sentinel = 0;
	temp = head;

	// loop all records into the memory temp
	while (temp != NULL)
	{
		// if PPS exist, set sentinel=1 and print the msg
		if (temp->pps == PPSVerify) {
			sentinel = 1;
			printf("\nThis PPS aread exist in this survey.\n\n");
		}

		temp = temp->next; // set temp to take the  next value
	}
	return sentinel; // return value sentinel, 0 or 1
}









/**
@desc verifyPosition - verify with position PPS can fit into the memory
@param struct listElement* head, int pps
@return int - return Num - Position, where value PPS can fit 
*/
int verifyPosition(struct listElement* head, int pps) {
	struct listElement *temp;
	int position = 1;
	int count = 0;
	int checkPPS = pps;
	temp = head;

	// loop all records into the memory temp
	while (temp != NULL)
	{
		count++; // count lines

		// if the imput PPS is grater than temp->pps
		// that position will be storage
		if (checkPPS > (temp->pps)) {
			position = count; //set position
		}

		temp = temp->next; // set temp to the next value
	}
	return position;
}







/**
@desc fillData - all imputs for add new survey
@param struct listElement* node, int PPS
@return void - return values for the node
*/
void fillData(struct listElement* node, int PPS)
{
	struct listElement *newNode;
	int PPSVerify = PPS;
	int choice;

	newNode = node;

	newNode->pps = PPSVerify; // storage the PPS


	// gets values
	printf("Please enter the First Name..: ");
	scanf("%s", newNode->firstName);

	printf("Please enter the Second Name.: ");
	scanf("%s", newNode->secondName);

	printf("Please enter the Address.....: ");
	scanf("%s", newNode->address);

	do
	{
		printf("Please enter the Email.......: ");
		scanf("%s", newNode->email);

		if (!(strchr(newNode->email, '.') && strchr(newNode->email, '@')))
		{
			printf("\n It is not a valid mail address.\n");
		}

	} while (!(strchr(newNode->email, '.') && strchr(newNode->email, '@')));

	//Loop to get user choice for age.
	do
	{
		// Print Menu
		printf("\n--- Gender ---\n");
		printf("1.  Male\n");
		printf("2.  Female\n");
		printf("==> ");
		scanf("%d", &choice);

		if (choice <= 0 || choice > 5) { // check numbers between 0 t0 5
			choice = 0;
			printf("Invalid choice - Just choice between 1 to 2.\n");
		}

		if (choice == 1)
			newNode->Gender = 1;
		else if (choice == 2)
			newNode->Gender = 2;

	} while (choice <= 0 || choice > 2);

	//Loop to get user choice for age.
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
			newNode->age.age = 1;
		else if (choice == 2)
			newNode->age.age = 2;
		else if (choice == 3)
			newNode->age.age = 3;
		else if (choice == 4)
			newNode->age.age = 4;
		else if (choice == 5)
			newNode->age.age = 5;

	} while (choice <= 0 || choice > 5);


	//Loop to get user choice for Income.
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
			newNode->income.income = 1;
		else if (choice == 2)
			newNode->income.income = 2;
		else if (choice == 3)
			newNode->income.income = 3;
		else if (choice == 4)
			newNode->income.income = 4;
		else if (choice == 5)
			newNode->income.income = 5;
		else if (choice == 6)
			newNode->income.income = 6;
		else if (choice == 7)
			newNode->income.income = 7;

	} while (choice <= 0 || choice > 7);



	//Loop to get user choice for How often do you exercise?.
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
			newNode->exercise.exercise = 1;
		else if (choice == 2)
			newNode->exercise.exercise = 2;
		else if (choice == 3)
			newNode->exercise.exercise = 3;
		else if (choice == 4)
			newNode->exercise.exercise = 4;


	} while (choice <= 0 || choice > 4);



	//Loop to get user choice for How much alcohol do you consume per week?.
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
			newNode->alcohol.alcohol = 1;
		else if (choice == 2)
			newNode->alcohol.alcohol = 2;
		else if (choice == 3)
			newNode->alcohol.alcohol = 3;
		else if (choice == 4)
			newNode->alcohol.alcohol = 4;

	} while (choice <= 0 || choice > 4);


	//Loop to get user choice for How much cigarettes do you consume per week?.
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
			newNode->cigarettes.cigarettes = 1;
		else if (choice == 2)
			newNode->cigarettes.cigarettes = 2;
		else if (choice == 3)
			newNode->cigarettes.cigarettes = 3;
		else if (choice == 4)
			newNode->cigarettes.cigarettes = 4;

	} while (choice <= 0 || choice > 4);
}
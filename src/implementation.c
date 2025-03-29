#include "definition.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Il est important de faire l'implementation de vos fonctions dans un fichier .c
// Si vous le faites dans le fichier "header", chaque fichier qui l'include va compiler l`implementation
// et cela causeras des definitions de symboles multiples.


//int monprojet_add(int a, int b){
//    return a+b;
//}
//
//void monprojet_ditbonjour(void){
//    printf("Hello Sailor !\n");
//}

void InventoryMain(void) {
	Inventory original = { "Name", "ItemName", "Value", 0};
	Inventory template = { "Name", "", "Value", 0};
	FILE* new_tp1_data = NULL;
	int option;
	char ItemName[32];

	//option: 1 = Add an item, 2 = Remove an item, 3 = Search item by item name, 

	printf("Chose what you want to do:\n1: Add an item manually;\n2: Remove an item;\n3: Search for an item by it's name\n4: Do nothing and close the whole program\n\n");
	printf("What is your choice ? \nEnter your choice here: ");
	scanf("%d", &option);
	fopen_s(&new_tp1_data, "new_tp1_data", "r+");

	while (option != 4) {
	if (option == 1) {			//Add custom item

		//Get the data fot the item
		printf("Name: ");
		scanf("%s", &template.ItemName);
		printf("Item Value: ");
		scanf("%d", &template.ItemValue);

		//Add the item to the list
		fseek(new_tp1_data, 0, SEEK_END);
		fwrite(&template, sizeof(Inventory), 1, new_tp1_data);
		break;
	}
	else if (option == 2) {		//Remove item
		//Get the item to delete
		printf("Please enter the name of the item you wish to delete: ");
		scanf("%s", &ItemName);

		//Get the data in the file
		fseek(new_tp1_data, 0, SEEK_SET);
		long pos;
		bool foundItem = false;
		while (!feof(new_tp1_data)) {
			ftell(new_tp1_data);
			pos = ftell(new_tp1_data);
			fread(&template, sizeof(Inventory), 1, new_tp1_data);
			if (template.ItemName == ItemName) {
				printf("This item no longer exist");
				foundItem = true;
				break;
			}
		}
		//The cake is a lie
		if (!foundItem) {
			printf("Are you sure you typed the item name correctly?\n");
		}
		else {
			strcpy(template.Name, "");
			strcpy(template.ItemName, "");
			strcpy(template.Value, "");
			template.ItemValue = 0;

			fseek(new_tp1_data, pos, SEEK_SET);
			fwrite(&template, sizeof(Inventory), 1, new_tp1_data);
		}
		break;
	}
	else if (option == 3) {		//Find item by name

		//get account num
		printf("Please enter the name of the item you wish to see the info of: ");
		scanf("%s", ItemName);

		//get data in file
		fseek(new_tp1_data, 0, SEEK_SET);
		long pos;
		bool FoundItem = false;
		while (!feof(new_tp1_data)) {
			ftell(new_tp1_data);
			pos = ftell(new_tp1_data);
			fread(&template, sizeof(Inventory), 1, new_tp1_data);
			if (template.ItemName == ItemName) {
				printf("Name, %s, Value, %d\n", template.ItemName, template.ItemValue);
				FoundItem = true;
				break;
			}
		}
		//The Client is a Lie!
		if (!FoundItem) {
			printf("Are you sure you typed the item name correctly?\n");
		}
		
		break;
	}
	else if (option == 4) {		//Quit
		break;
	}
	printf("\nEnter your choice here: ");
	scanf("%d", &option);
	}
	fclose(new_tp1_data);
	return 0;
}
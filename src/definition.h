// Vous devez ajouter ce #pragma a tous vos fichiers .h de votre projet.
// Il garantit que le fichier "header" n'est inclus qu'une seule fois par compilation,
// ce qui evite les erreurs de redefinition et les conflits de symboles.
#pragma once

typedef struct {
	char* Name;
	char ItemName[32];
	char* Value;
	int ItemValue;
} Inventory;

// Vous devez definir les structures et fonctions que vous voulez exposer dans les "headers"
// Si jamais vous avez des fonctions avec des noms commun, vous devez les prefixer pour eviter des conflits de symboles
// Le prefix peut etre le nom de votre projet, exemple: forhonor_nom_de_fonction
int monprojet_add(int a, int b);

// Lorsqu'une fonction n'a pas de parametre, mettre void entre les parentheses.
void monprojet_ditbonjour(void);

//void InventoryMain(Inventory);

void inventory_add(inventory);

void inventory_sort(inventory);

void inventory_remove(inventory);

void inventory_search_by_name(inventory);

void inventory_search_by_position(inventory);

void inventory_search_by_quantity(inventory);
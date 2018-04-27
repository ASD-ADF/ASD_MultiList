#include <iostream>
#include <conio.h>

#include "manufacturer_list.h"
#include "weapon_list.h"

//manufacturer variable
manufacturer mnfc;
manufacturer_list mnfc_list;
parent_addr parent;

//weapon variable
weapon weap;
weapon_list weap_list;
child_addr child;

//relation variable
relation_addr relation;

//miscellanous variable
std::string search_name;

//functions and procedures
void mainMenu(bool &exit, bool &debug) {
	system("cls");
	std::cout << "WEAPON CATALOGUE SYSTEM - BETA 1.0\n" << "BY PERTIWANG SISMANANDA & HAFIZ ABDUL HAKIM\n" << std::endl;
	std::cout << "Choose Menu : \n"
		<< "1. Show list of available weapons\n"
		<< "2. Show list of registered manufacturers\n"
		<< "3. Show list of weapons made by specific manufacturer\n"
		<< "0. Exit\n"
		<< "\nPress 'Shift + ~' to enter debug menu.\n" << std::endl;

	char key = _getche();
	system("cls");
	switch (key) {
	case '1':
		printList(weap_list);
		std::cout << "Press any key to continue . . ." << std::endl;
		std::cin.ignore();
		break;
	case '2':
		printList(mnfc_list);
		std::cout << "Press any key to continue . . ." << std::endl;
		std::cin.ignore();
		break;
	case '3':
		std::cout << "Enter the name of the manufcaturer : ";
		std::getline(std::cin, search_name);
		parent = searchByName(mnfc_list, search_name);
		if (parent != NULL) {
			std::cout << "\nShowing the weapons made by " << parent->info.name << " from " << parent->info.country << "\n" << std::endl;
			printList(parent->child);
		}
		else {
			std::cout << "\nManufacturer not found." << std::endl;
		}
		std::cout << "Press any key to continue . . ." << std::endl;
		std::cin.ignore();
		break;
	case '0':
		exit = true;
		break;
	case '~':
		debug = true;
		break;
	}
}

bool debugWeaponMenu() {
	system("cls");
	std::cout << "WEAPON CATALOGUE SYSTEM - BETA 1.0 - DEBUG MODE\n" << "BY PERTIWANG SISMANANDA & HAFIZ ABDUL HAKIM\n" << std::endl;
	std::cout << "Weapon menu : \n"
		<< "1. Insert\n"
		<< "2. Delete\n"
		<< "3. Print List\n"
		<< "0. Return\n" << std::endl;

	char key = _getche();
	system("cls");
	switch (key) {
	case '1':
		std::cout << "WEAPON INSERT\n" << std::endl;
		std::cout << "Name : ";
		std::getline(std::cin, weap.name);
		std::cout << "Caliber : ";
		std::cin >> weap.caliber;
		std::cout << "Price : ";
		std::cin >> weap.price;
		child = allocate(weap);
		if (weap_list.first == NULL) {
			insertFirst(weap_list, child);
		}
		else {
			insertLast(weap_list, child);
		}
		std::cout << "Successfully inserted." << std::endl;
		std::cout << "Press any key to continue . . ." << std::endl;
		std::cin.ignore();
		break;
	case '2':
		std::cout << "WEAPON DELETE\n" << std::endl;
		std::cout << "Name : ";
		std::getline(std::cin, search_name);
		child = searchByName(weap_list, search_name);
		if (child != NULL) {
			std::cout << "Deleting " << child->info.name << " from the list . . .\n";
			if (child == weap_list.first) {
				deleteFirst(weap_list, child);
			}
			else if (child == weap_list.last) {
				deleteLast(weap_list, child);
			}
			else {
				deleteAfter(weap_list, child->prev, child);
			}
			std::cout << "Successfully deleted." << std::endl;
		}
		else {
			std::cout << "Not found.\n";
		}
		std::cout << "Press any key to continue . . ." << std::endl;
		std::cin.ignore();
		break;
	case '3':
		printList(weap_list);
		std::cout << "Press any key to continue . . ." << std::endl;
		std::cin.ignore();
		break;
	case '0':
		return false;
		break;
	}
	return true;
}

bool debugManufacturerMenu() {
	system("cls");
	std::cout << "WEAPON CATALOGUE SYSTEM - BETA 1.0 - DEBUG MODE\n" << "BY PERTIWANG SISMANANDA & HAFIZ ABDUL HAKIM\n" << std::endl;
	std::cout << "Manufacturer menu : \n"
		<< "1. Insert\n"
		<< "2. Delete\n"
		<< "3. Print List\n"
		<< "0. Return\n" << std::endl;

	char key = _getche();
	system("cls");
	switch (key) {
	case '1':
		std::cout << "MANUFACTURER INSERT\n" << std::endl;
		std::cout << "Name : ";
		std::getline(std::cin, mnfc.name);
		std::cout << "Country : ";
		std::cin >> mnfc.country;
		parent = allocate(mnfc);
		if (mnfc_list.first == NULL) {
			insertFirst(mnfc_list, parent);
		}
		else {
			insertLast(mnfc_list, parent);
		}
		std::cout << "Successfully inserted." << std::endl;
		std::cout << "Press any key to continue . . ." << std::endl;
		std::cin.ignore();
		break;
	case '2':
		std::cout << "MANUFACTURER DELETE\n" << std::endl;
		std::cout << "Name : ";
		std::getline(std::cin, search_name);
		parent = searchByName(mnfc_list, search_name);
		if (parent != NULL) {
			std::cout << "Deleting " << parent->info.name << " from the list . . .\n";
			if (parent == mnfc_list.first) {
				deleteFirst(mnfc_list, parent);
			}
			else if (parent->next == mnfc_list.first) {
				deleteLast(mnfc_list, parent);
			}
			else {
				parent_addr itr = mnfc_list.first;
				while (itr->next != parent) {
					itr = itr->next;
				}
				deleteAfter(mnfc_list, itr, parent);
			}
			std::cout << "Successfully deleted." << std::endl;
		}
		else {
			std::cout << "Not found.\n";
		}
		std::cout << "Press any key to continue . . ." << std::endl;
		std::cin.ignore();
		break;
	case '3':
		printList(mnfc_list);
		std::cout << "Press any key to continue . . ." << std::endl;
		std::cin.ignore();
		break;
	case '0':
		return false;
		break;
	}
	return true;
}

bool debugRelationMenu() {
	system("cls");
	std::cout << "WEAPON CATALOGUE SYSTEM - BETA 1.0 - DEBUG MODE\n" << "BY PERTIWANG SISMANANDA & HAFIZ ABDUL HAKIM\n" << std::endl;
	std::cout << "Relation menu : \n"
		<< "1. Connect weapon to manufacturer\n"
		<< "2. Disconnect weapon from manufacturer\n"
		<< "3. Print List\n"
		<< "0. Return\n" << std::endl;

	char key = _getche();
	system("cls");
	switch (key) {
	case '1':
		std::cout << "RELATION CONNECT WEAPON TO MANUFACTURER\n" << std::endl;
		std::cout << "Weapon name : ";
		std::getline(std::cin, search_name);
		child = searchByName(weap_list, search_name);
		std::cout << "Manufacturer name : ";
		std::getline(std::cin, search_name);
		parent = searchByName(mnfc_list, search_name);
		if (child != NULL && parent != NULL) {
			std::cout << "Connecting " << child->info.name << " to " << parent->info.name << " . . ." << std::endl;
			if (parent->child.first == NULL) {
				insertFirst(parent->child, allocate(child));
			}
			else {
				insertLast(parent->child, allocate(child));
			}
			std::cout << "Successfully connected." << std::endl;
		}
		else {
			if (child == NULL && parent != NULL) {
				std::cout << "Manufacturer found but weapon not found." << std::endl;
			}
			else if (child != NULL && parent == NULL) {
				std::cout << "Weapon found but manufacturer not found" << std::endl;
			}
			else {
				std::cout << "Weapon and manufacturer not found" << std::endl;
			}
		}
		std::cout << "Press any key to continue . . ." << std::endl;
		std::cin.ignore();
		break;
	case '2':
		std::cout << "RELATION DISCONNECT WEAPON FROM MANUFACTURER\n" << std::endl;
		std::cout << "Weapon Name : ";
		std::getline(std::cin, search_name);
		child = searchByName(weap_list, search_name);
		if (child != NULL) {
			parent = mnfc_list.first;
			while (parent->next != mnfc_list.first) {
				relation = searchChildinRelation(parent->child, child);
				if (relation != NULL) {
					if (relation == parent->child.first) {
						deleteFirst(parent->child, relation);
					}
					else if (relation->next == parent->child.first) {
						deleteLast(parent->child, relation);
					}
					else {
						relation_addr itr = parent->child.first;
						while (itr->next != relation) {
							itr = itr->next;
						}
						deleteAfter(parent->child, itr, relation);
					}
				}
				parent = parent->next;
			}
			std::cout << "Successfully disconnected." << std::endl;
		}
		else {
			std::cout << "Not found.\n";
		}
		std::cout << "Press any key to continue . . ." << std::endl;
		std::cin.ignore();
		break;
	case '3':
		std::cout << "PRINT LIST\n" << std::endl;
		std::cout << "Manufacturer name : ";
		std::getline(std::cin, search_name);
		parent = searchByName(mnfc_list, search_name);
		if (parent == NULL) {
			std::cout << "Not found." << std::endl;
		}
		else {
			std::cout << "List of weapon made by " << parent->info.name << " :\n" << std::endl;
			relation_addr itr = parent->child.first;
			while (itr != NULL) {
				std::cout << "Name : " << itr->info->info.name
					<< "\nCaliber : " << itr->info->info.caliber
					<< "\nPrice : $" << itr->info->info.price
					<< "\n" << std::endl;
				itr = itr->next;
			}
		}
		std::cout << "Press any key to continue . . ." << std::endl;
		std::cin.ignore();
		break;
	case '0':
		return false;
		break;
	}
	return true;
}

void debugMenu(bool &exit, bool &debug) {
	bool weapon_menu = false;
	bool manufacturer_menu = false;
	bool relation_menu = false;
	system("cls");
	std::cout << "WEAPON CATALOGUE SYSTEM - BETA 1.0 - DEBUG MODE\n" << "BY PERTIWANG SISMANANDA & HAFIZ ABDUL HAKIM\n" << std::endl;
	std::cout << "Choose Menu : \n"
		<< "1. Weapon menu\n"
		<< "2. Manufacturer menu\n"
		<< "3. Relation menu\n"
		<< "0. Exit\n" 
		<< "\nPress 'Shift + ~' to return to main menu.\n" << std::endl;

	char key = _getche();
	system("cls");
	switch (key) {
	case '1':
		weapon_menu = true;
		while (weapon_menu) {
			weapon_menu = debugWeaponMenu();
		}
		break;
	case '2':
		manufacturer_menu = true;
		while (manufacturer_menu) {
			manufacturer_menu = debugManufacturerMenu();
		}
		break;
	case '3':
		relation_menu = true;
		while (relation_menu) {
			relation_menu = debugRelationMenu();
		}
		break;
	case '0':
		exit = true;
		break;
	case '~':
		debug = false;
		break;
	}
}

void seedList() {
	//Making manufacturer entity
	createList(mnfc_list);

	mnfc.name = "IZMASH";
	mnfc.country = "Russia";
	parent = allocate(mnfc);
	insertFirst(mnfc_list, parent);

	mnfc.name = "Heckler & Koch";
	mnfc.country = "Germany";
	parent = allocate(mnfc);
	insertLast(mnfc_list, parent);

	mnfc.name = "ARMALITE";
	mnfc.country = "United States";
	parent = allocate(mnfc);
	insertAfter(mnfc_list, mnfc_list.first, parent);


	//Making weapon entities
	createList(weap_list);

	weap.name = "AK47";
	weap.caliber = "7.62x39mm";
	weap.price = 700;
	child = allocate(weap);
	insertFirst(weap_list, child);

	weap.name = "AKM";
	weap.caliber = "7.62x39mm";
	weap.price = 1000;
	child = allocate(weap);
	insertLast(weap_list, child);

	weap.name = "AK74";
	weap.caliber = "5.45x39mm";
	weap.price = 900;
	child = allocate(weap);
	insertAfter(weap_list, weap_list.first, child);

	weap.name = "AK74M";
	weap.caliber = "5.45x39mm";
	weap.price = 1400;
	child = allocate(weap);
	insertLast(weap_list, child);

	weap.name = "AK103";
	weap.caliber = "7.62x39mm";
	weap.price = 2000;
	child = allocate(weap);
	insertLast(weap_list, child);

	weap.name = "M16A4";
	weap.caliber = "5.56x45mm";
	weap.price = 2000;
	child = allocate(weap);
	insertLast(weap_list, child);

	weap.name = "M4A1";
	weap.caliber = "5.56x45mm";
	weap.price = 3000;
	child = allocate(weap);
	insertLast(weap_list, child);

	weap.name = "HK416";
	weap.caliber = "5.56x45mm";
	weap.price = 3500;
	child = allocate(weap);
	insertLast(weap_list, child);

	weap.name = "HK417";
	weap.caliber = "7.62x51mm";
	weap.price = 3800;
	child = allocate(weap);
	insertLast(weap_list, child);


	//Assigning weapon to manufacturer
	relation = allocate(searchByName(weap_list, "AK47"));
	insertFirst(searchByName(mnfc_list, "IZMASH")->child, relation);

	relation = allocate(searchByName(weap_list, "AK74"));
	insertLast(searchByName(mnfc_list, "IZMASH")->child, relation);

	relation = allocate(searchByName(weap_list, "AKM"));
	insertLast(searchByName(mnfc_list, "IZMASH")->child, relation);

	relation = allocate(searchByName(weap_list, "AK74M"));
	insertLast(searchByName(mnfc_list, "IZMASH")->child, relation);

	relation = allocate(searchByName(weap_list, "AK103"));
	insertLast(searchByName(mnfc_list, "IZMASH")->child, relation);

	relation = allocate(searchByName(weap_list, "M16A4"));
	insertFirst(searchByName(mnfc_list, "ARMALITE")->child, relation);

	relation = allocate(searchByName(weap_list, "M4A1"));
	insertLast(searchByName(mnfc_list, "ARMALITE")->child, relation);

	relation = allocate(searchByName(weap_list, "HK416"));
	insertFirst(searchByName(mnfc_list, "Heckler & Koch")->child, relation);

	relation = allocate(searchByName(weap_list, "HK417"));
	insertLast(searchByName(mnfc_list, "Heckler & Koch")->child, relation);

}

//main function
int main() {

	seedList();

	//Running the Main Menu
	bool exit = false;
	bool debug = false;
	while (!exit) {
		if (!debug) {
			mainMenu(exit, debug);
		}
		else {
			debugMenu(exit, debug);
		}
	}

	return 0;
}
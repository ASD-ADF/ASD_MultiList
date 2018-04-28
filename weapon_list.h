#pragma once
#include <iostream>
#include <string>

/*
    Functions made by : Pertiwang Sismananda - 1301153614
*/

struct weapon {
	std::string name;
	std::string caliber;
	double price;
};

typedef struct weapon_elm *child_addr;

struct weapon_elm {
	weapon info;
	child_addr next;
	child_addr prev;
};

struct weapon_list {
	child_addr first;
	child_addr last;
};

//functions
void createListWeapon(weapon_list &list);
child_addr allocateWeapon(weapon data);
void deallocateWeapon(child_addr addr);
void insertFirstWeapon(weapon_list &list, child_addr addr);
void insertLastWeapon(weapon_list &list, child_addr addr);
void insertAfterWeapon(weapon_list &list, child_addr prev, child_addr addr);
void deleteFirstWeapon(weapon_list &list, child_addr &addr);
void deleteLastWeapon(weapon_list &list, child_addr &addr);
void deleteAfterWeapon(weapon_list &list, child_addr prev, child_addr &addr);
void printListWeapon(weapon_list list);
child_addr searchWeaponByName(weapon_list list, std::string name);

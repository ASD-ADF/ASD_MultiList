#pragma once
#include <iostream>
#include <string>

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
void createList(weapon_list &list);
child_addr allocate(weapon data);
void deallocate(child_addr addr);
void insertFirst(weapon_list &list, child_addr addr);
void insertLast(weapon_list &list, child_addr addr);
void insertAfter(weapon_list &list, child_addr prev, child_addr addr);
void deleteFirst(weapon_list &list, child_addr &addr);
void deleteLast(weapon_list &list, child_addr &addr);
void deleteAfter(weapon_list &list, child_addr prev, child_addr &addr);
void printList(weapon_list list);
child_addr searchByName(weapon_list list, std::string name);
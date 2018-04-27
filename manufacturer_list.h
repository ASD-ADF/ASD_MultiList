#pragma once
#include <iostream>
#include <string>

#include "relation_list.h"

struct manufacturer {
	std::string name;
	std::string country;
};

typedef struct manufacturer_elm *parent_addr;

struct manufacturer_elm {
	manufacturer info;
	relation_list child;
	parent_addr next;
};

struct manufacturer_list {
	parent_addr first;
};

//functions
void createList(manufacturer_list &list);
parent_addr allocate(manufacturer data);
void deallocate(parent_addr addr);
void insertFirst(manufacturer_list &list, parent_addr addr);
void insertLast(manufacturer_list &list, parent_addr addr);
void insertAfter(manufacturer_list &list, parent_addr &prev, parent_addr addr);
void deleteFirst(manufacturer_list &list, parent_addr &addr);
void deleteLast(manufacturer_list &list, parent_addr &addr);
void deleteAfter(manufacturer_list &list, parent_addr prev, parent_addr &addr);
parent_addr searchByName(manufacturer_list &list, std::string name);
void printList(manufacturer_list list);
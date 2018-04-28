#pragma once
#include <iostream>
#include <string>

#include "relation_list.h"

/*
    Functions made by : Pertiwang Sismananda - 1301153614
*/

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
void createListManufacturer(manufacturer_list &list);
parent_addr allocateManufacturer(manufacturer data);
void deallocateManufacturer(parent_addr addr);
void insertFirstManufacturer(manufacturer_list &list, parent_addr addr);
void insertLastManufacturer(manufacturer_list &list, parent_addr addr);
void insertAfterManufacturer(manufacturer_list &list, parent_addr &prev, parent_addr addr);
void deleteFirstManufacturer(manufacturer_list &list, parent_addr &addr);
void deleteLastManufacturer(manufacturer_list &list, parent_addr &addr);
void deleteAfterManufacturer(manufacturer_list &list, parent_addr prev, parent_addr &addr);
parent_addr searchManufacturerByName(manufacturer_list &list, std::string name);
void printListManufacturer(manufacturer_list list);

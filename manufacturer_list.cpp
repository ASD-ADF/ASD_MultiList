#include "manufacturer_list.h"
#include "relation_list.h"

/*
    Functions made by : Pertiwang Sismananda - 1301153614
*/

void createListManufacturer(manufacturer_list &list) {
	list.first = NULL;
}

parent_addr allocateManufacturer(manufacturer data) {
	parent_addr addr = new manufacturer_elm;
	addr->info = data;
	addr->next = NULL;
	createListRelation(addr->child);
	return addr;
}

void deallocateManufacturer(parent_addr addr) {
	delete(addr);
}

void insertFirstManufacturer(manufacturer_list &list, parent_addr addr) {
	if (list.first == NULL) {
		list.first = addr;
		addr->next = list.first;
	}
	else {
		addr->next = list.first;
		parent_addr itr = list.first;
		while (itr->next != list.first) {
			itr = itr->next;
		}
		itr->next = addr;
		list.first = addr;
	}
}

void insertLastManufacturer(manufacturer_list &list, parent_addr addr) {
	if (list.first != NULL) {
		parent_addr itr = list.first;
		while (itr->next != list.first) {
			itr = itr->next;
		}
		itr->next = addr;
		addr->next = list.first;
	}
}

void insertAfterManufacturer(manufacturer_list &list, parent_addr &prev, parent_addr addr) {
	if (prev != NULL) {
		addr->next = prev->next;
		prev->next = addr;
	}
}

void deleteFirstManufacturer(manufacturer_list &list, parent_addr &addr) {
	if (list.first != NULL) {
		addr = list.first;
		parent_addr itr = list.first;
		while (itr->next != list.first) {
			itr = itr->next;
		}
		list.first = list.first->next;
		itr->next = list.first;
		deallocateManufacturer(addr);
	}
}

void deleteLastManufacturer(manufacturer_list &list, parent_addr &addr) {
	if (list.first != NULL) {
		parent_addr itr = list.first;
		while (itr->next->next != list.first) {
			itr = itr->next;
		}
		addr = itr->next;
		itr->next = list.first;
		deallocateManufacturer(addr);
	}
}

void deleteAfterManufacturer(manufacturer_list &list, parent_addr prev, parent_addr &addr) {
	if (prev != NULL) {
		addr = prev->next;
		prev->next = prev->next->next;
		deallocateManufacturer(addr);
	}
}

parent_addr searchManufacturerByName(manufacturer_list &list, std::string name) {
	parent_addr itr = list.first;
	while (itr->next != list.first) {
		if (itr->info.name == name)
			return itr;
		itr = itr->next;
	}
	if (itr->info.name == name)
		return itr;
	else
		return NULL;
}

void printListManufacturer(manufacturer_list list) {
	parent_addr itr = list.first;
	while (itr->next != list.first) {
		std::cout << "Name : " << itr->info.name
			<< "\nCountry : " << itr->info.country
			<< "\n" << std::endl;
		itr = itr->next;
	}
	std::cout << "Name : " << itr->info.name
		<< "\nCountry : " << itr->info.country
		<< "\n" << std::endl;
}

#include "manufacturer_list.h"

void createList(manufacturer_list &list) {
	list.first = NULL;
}

parent_addr allocate(manufacturer data) {
	parent_addr addr = new manufacturer_elm;
	addr->info = data;
	addr->next = NULL;
	createList(addr->child);
	return addr;
}

void deallocate(parent_addr addr) {
	delete(addr);
}

void insertFirst(manufacturer_list &list, parent_addr addr) {
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

void insertLast(manufacturer_list &list, parent_addr addr) {
	if (list.first != NULL) {
		parent_addr itr = list.first;
		while (itr->next != list.first) {
			itr = itr->next;
		}
		itr->next = addr;
		addr->next = list.first;
	}
}

void insertAfter(manufacturer_list &list, parent_addr &prev, parent_addr addr) {
	if (prev != NULL) {
		addr->next = prev->next;
		prev->next = addr;
	}
}

void deleteFirst(manufacturer_list &list, parent_addr &addr) {
	if (list.first != NULL) {
		addr = list.first;
		parent_addr itr = list.first;
		while (itr->next != list.first) {
			itr = itr->next;
		}
		list.first = list.first->next;
		itr->next = list.first;
		deallocate(addr);
	}
}

void deleteLast(manufacturer_list &list, parent_addr &addr) {
	if (list.first != NULL) {
		parent_addr itr = list.first;
		while (itr->next->next != list.first) {
			itr = itr->next;
		}
		addr = itr->next;
		itr->next = list.first;
		deallocate(addr);
	}
}

void deleteAfter(manufacturer_list &list, parent_addr prev, parent_addr &addr) {
	if (prev != NULL) {
		addr = prev->next;
		prev->next = prev->next->next;
		deallocate(addr);
	}
}

parent_addr searchByName(manufacturer_list &list, std::string name) {
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

void printList(manufacturer_list list) {
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
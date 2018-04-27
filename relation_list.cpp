#include "relation_list.h"

void createList(relation_list &list) {
	list.first = NULL;
}

relation_addr allocate(child_addr data) {
	relation_addr addr = new relation_elm;
	addr->info = data;
	addr->next = NULL;
	return addr;
}

void deallocate(relation_addr addr) {
	delete(addr);
}

void insertFirst(relation_list &list, relation_addr addr) {
	if (list.first == NULL) {
		list.first = addr;
	}
	else {
		addr->next = list.first;
		list.first = addr;
	}
}

void insertLast(relation_list &list, relation_addr addr) {
	if (list.first != NULL) {
		relation_addr itr = list.first;
		while (itr->next != NULL) {
			itr = itr->next;
		}
		itr->next = addr;
	}
}

void insertAfter(relation_list &list, relation_addr &prev, relation_addr addr) {
	if (prev != NULL) {
		addr->next = prev->next;
		prev->next = addr;
	}
}

void deleteFirst(relation_list &list, relation_addr &addr) {
	if (list.first != NULL) {
		addr = list.first;
		list.first = list.first->next;
		deallocate(addr);
	}
}

void deleteLast(relation_list &list, relation_addr &addr) {
	if (list.first != NULL) {
		relation_addr itr = list.first;
		while (itr->next->next != NULL) {
			itr = itr->next;
		}
		addr = itr->next;
		itr->next = NULL;
		deallocate(addr);
	}
}

void deleteAfter(relation_list &list, relation_addr prev, relation_addr &addr) {
	if (prev != NULL) {
		addr = prev->next;
		prev->next = prev->next->next;
		deallocate(addr);
	}
}

relation_addr searchChildinRelation(relation_list list, child_addr addr) {
	if (list.first != NULL) {
		relation_addr itr = list.first;
		while (itr != NULL && itr->info != addr) {
			itr = itr->next;
		}
		return itr;
	}
}

void printList(relation_list list) {
	relation_addr itr = list.first;
	while (itr != NULL) {
		std::cout << "Name : " << itr->info->info.name
			<< "\nCaliber : " << itr->info->info.caliber
			<< "\nPrice : $" << itr->info->info.price 
			<< "\n" << std::endl;
		itr = itr->next;
	}
}
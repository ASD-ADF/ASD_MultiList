#include "relation_list.h"

/*
    Functions made by : Pertiwang Sismananda - 1301153614
*/

void createListRelation(relation_list &list) {
	list.first = NULL;
}

relation_addr allocateRelation(child_addr data) {
	relation_addr addr = new relation_elm;
	addr->info = data;
	addr->next = NULL;
	return addr;
}

void deallocateRelation(relation_addr addr) {
	delete(addr);
}

void insertFirstRelation(relation_list &list, relation_addr addr) {
	if (list.first == NULL) {
		list.first = addr;
	}
	else {
		addr->next = list.first;
		list.first = addr;
	}
}

void insertLastRelation(relation_list &list, relation_addr addr) {
	if (list.first != NULL) {
		relation_addr itr = list.first;
		while (itr->next != NULL) {
			itr = itr->next;
		}
		itr->next = addr;
	}
}

void insertAfterRelation(relation_list &list, relation_addr &prev, relation_addr addr) {
	if (prev != NULL) {
		addr->next = prev->next;
		prev->next = addr;
	}
}

void deleteFirstRelation(relation_list &list, relation_addr &addr) {
	if (list.first != NULL) {
		addr = list.first;
		list.first = list.first->next;
		deallocateRelation(addr);
	}
}

void deleteLastRelation(relation_list &list, relation_addr &addr) {
	if (list.first != NULL) {
		relation_addr itr = list.first;
		while (itr->next->next != NULL) {
			itr = itr->next;
		}
		addr = itr->next;
		itr->next = NULL;
		deallocateRelation(addr);
	}
}

void deleteAfterRelation(relation_list &list, relation_addr prev, relation_addr &addr) {
	if (prev != NULL) {
		addr = prev->next;
		prev->next = prev->next->next;
		deallocateRelation(addr);
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

void printListRelation(relation_list list) {
	relation_addr itr = list.first;
	while (itr != NULL) {
		std::cout << "Name : " << itr->info->info.name
			<< "\nCaliber : " << itr->info->info.caliber
			<< "\nPrice : $" << itr->info->info.price
			<< "\n" << std::endl;
		itr = itr->next;
	}
}

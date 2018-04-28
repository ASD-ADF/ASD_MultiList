#include "weapon_list.h

/*
    Functions made by : Pertiwang Sismananda - 1301153614
*/

void createListWeapon(weapon_list &list) {
	list.first = NULL;
	list.last = NULL;
}

child_addr allocateWeapon(weapon data) {
	child_addr addr = new weapon_elm;
	addr->info = data;
	addr->next = NULL;
	addr->prev = NULL;
	return addr;
}

void deallocateWeapon(child_addr addr) {
	delete(addr);
}

void insertFirstWeapon(weapon_list &list, child_addr addr) {
	if (list.first == NULL) {
		list.first = addr;
		list.last = addr;
	}
	else {
		addr->next = list.first;
		list.first->prev = addr;
		list.first = addr;
	}

}

void insertLastWeapon(weapon_list &list, child_addr addr) {
	if (list.first != NULL) {
		addr->prev = list.last;
		list.last->next = addr;
		list.last = addr;
	}
}

void insertAfterWeapon(weapon_list &list, child_addr prev, child_addr addr) {
	if (prev != NULL) {
		if (prev == list.last) {
			list.last = addr;
		}
		addr->next = prev->next;
		addr->prev = prev;
		prev->next->prev = addr;
		prev->next = addr;
	}
}

void deleteFirstWeapon(weapon_list &list, child_addr &addr) {
	if (list.first != NULL) {
		addr = list.first;
		list.first = list.first->next;
		deallocateWeapon(addr);
	}
}

void deleteLastWeapon(weapon_list &list, child_addr &addr) {
	if (list.last != NULL) {
		addr = list.last;
		list.last = list.last->prev;
		list.last->next = NULL;
		deallocateWeapon(addr);
	}
}

void deleteAfterWeapon(weapon_list &list, child_addr prev, child_addr &addr) {
	if (prev != NULL) {
		addr = prev->next;
		prev->next = prev->next->next;
		prev->next->prev = prev;
		deallocateWeapon(addr);
	}
}

void printListWeapon(weapon_list list) {
	child_addr itr = list.first;
	while (itr != NULL) {
		std::cout << "Name : " << itr->info.name
			<< "\nCaliber : " << itr->info.caliber
			<< "\nPrice : $" << itr->info.price
			<< "\n" << std::endl;
		itr = itr->next;
	}
}

child_addr searchWeaponByName(weapon_list list, std::string name) {
	if (list.first != NULL) {
		child_addr addr = list.first;
		while (addr != NULL) {
			if (addr->info.name == name)
				return addr;
			addr = addr->next;
		}
	}
	return NULL;
}

#pragma once
#include <iostream>
#include <string>

#include "weapon_list.h"

typedef struct relation_elm *relation_addr;

struct relation_elm {
	relation_addr next;
	child_addr info;
};

struct relation_list {
	relation_addr first;
	
};

//function
void createList(relation_list &list);
relation_addr allocate(child_addr data);
void deallocate(relation_addr addr);
void insertFirst(relation_list &list, relation_addr addr);
void insertLast(relation_list &list, relation_addr addr);
void insertAfter(relation_list &list, relation_addr &prev, relation_addr addr);
void deleteFirst(relation_list &list, relation_addr &addr);
void deleteLast(relation_list &list, relation_addr &addr);
void deleteAfter(relation_list &list, relation_addr prev, relation_addr &addr);
relation_addr searchChildinRelation(relation_list list, child_addr addr);
void printList(relation_list list);
#pragma once
#include <iostream>
#include <string>

#include "weapon_list.h"

/*
    Functions made by : Pertiwang Sismananda - 1301153614
*/

typedef struct relation_elm *relation_addr;

struct relation_elm {
	relation_addr next;
	child_addr info;
};

struct relation_list {
	relation_addr first;

};

//function
void createListRelation(relation_list &list);
relation_addr allocateRelation(child_addr data);
void deallocateRelation(relation_addr addr);
void insertFirstRelation(relation_list &list, relation_addr addr);
void insertLastRelation(relation_list &list, relation_addr addr);
void insertAfterRelation(relation_list &list, relation_addr &prev, relation_addr addr);
void deleteFirstRelation(relation_list &list, relation_addr &addr);
void deleteLastRelation(relation_list &list, relation_addr &addr);
void deleteAfterRelation(relation_list &list, relation_addr prev, relation_addr &addr);
relation_addr searchChildinRelation(relation_list list, child_addr addr);
void printListRelation(relation_list list);

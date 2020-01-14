#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED
#include <iostream>
#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"

using namespace std;

void addArtist(List_parent LP);
void addSong(List_parent &LP, List_child &LC, List_relasi &LR);


#endif // CONTROL_H_INCLUDED

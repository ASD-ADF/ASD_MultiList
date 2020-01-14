#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"
#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<windows.h>
#include <ctime>

using namespace std;

void insertParent(List_parent &L);
void DisplayParent(List_parent &L);
void insertChild(List_child &L);
void displayChild(List_child &L);
void connectList(List_parent LP, List_child LC);
void checkConnection(List_parent LP, List_child LC);
void disconnect(List_parent &LP, List_child LC);
void printALL(List_parent L);
void printChildOfParent(List_parent L);
void deleteChild(List_parent &LP, List_child &LC);
void deleteParent(List_parent &L);
void MusicPlayer(address_child C);
void PlayArtist(List_parent LP);
void MusicById(List_child LC);

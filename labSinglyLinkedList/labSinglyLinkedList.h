#pragma once
#include <iostream>
#include <cctype> 
#include <string>
#include <limits>
using namespace std;

struct List {
	int data;
	List* pNext;
};

void InitList(List* list, int data = 0);
void addElEnd(List* head, int data);
void addElBegin(List*& head, int data);
void printList(List* list);
void removeList(List*& head);
void addAfterSpecificElement(List* head, int specificElement, int elem);
void deleteAfterSpecificElement(List* head, int specificElement);
void removeHead(List*& head);
void removeLastEl(List* head);
void deleteAllOccurrences(List*& head, int el);
List* searchTheList(List* head, int data);
bool emptyList(List* list);
void fillingListMultipleValues(List* list, int count);
void sortAscending(List* head);
void sortFinalList(List* headFirst, List* headSecond, List*& finalList);
void FuncNum1(List* listFirst, List* listSecond, List* finalList);
void caseFirst(List*& list);
void start(List* list);
void program();


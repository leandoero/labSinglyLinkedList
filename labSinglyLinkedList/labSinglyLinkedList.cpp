#include "labSinglyLinkedList.h";

void InitList(List* list, int data) {
	list->data = data;
	list->pNext = nullptr;
}

void addElEnd(List* head, int data) {
	if (head == nullptr) {
		cout << "Список пустой" << endl;
		return;
	}
	List* temp = head;
	while (temp->pNext != nullptr) {
		temp = temp->pNext;
	}
	List* lastEl = new List;
	lastEl->data = data;
	lastEl->pNext = nullptr;
	temp->pNext = lastEl;
}

void addElBegin(List*& head, int data) {
	if (head == nullptr) {
		cout << "Список пустой" << endl;
		return;
	}
	List* temp = head;
	List* beginEl = new List;
	beginEl->data = data;
	beginEl->pNext = temp;
	head = beginEl;
}

void printList(List* list) {
	if (list == nullptr) {
		cout << "Список пустой" << endl;
		return;
	}
	List* temp = list;
	while (temp != nullptr) {
		cout << " " << temp->data << " ";
		temp = temp->pNext;
	}
}

void removeList(List*& head) {
	if (head == nullptr) {
		cout << "Список пустой" << endl;
		return;
	}
	List* temp = head;
	while (temp != nullptr) {
		List* temp2 = temp->pNext;
		delete temp;
		temp = nullptr;
		temp = temp2;
	}
	head = nullptr;
}

void addAfterSpecificElement(List* head, int specificElement, int elem) {
	if (head == nullptr) {
		cout << "Список пустой" << endl;
		return;
	}
	List* temp = head;
	while (temp->data != specificElement) {
		temp = temp->pNext;
	}
	List* newEl = new List;
	newEl->pNext = temp->pNext;
	temp->pNext = newEl;
	newEl->data = elem;
}

void deleteAfterSpecificElement(List* head, int specificElement) {
	if (head == nullptr) {
		cout << "Список пустой" << endl;
		return;
	}

	List* temp = head;
	while (temp->data != specificElement) {
		temp = temp->pNext;
	}
	List* newTemp = temp->pNext;
	temp->pNext = nullptr;
	temp->pNext = newTemp->pNext;
	delete newTemp;
}

void removeHead(List*& head) {
	if (head == nullptr) {
		cout << "Список пустой" << endl;
		return;
	}

	List* list = head;
	head = head->pNext;
	delete list;
}

void removeLastEl(List* head) {
	if (head == nullptr) {
		cout << "Список пустой" << endl;
		return;
	}
	List* temp = head;
	List* previous = temp;
	while (temp->pNext != nullptr) {
		previous = temp;
		temp = temp->pNext;
	}
	delete temp;
	temp = nullptr;
	previous->pNext = nullptr;
}

void deleteAllOccurrences(List*& head, int el) {
	if (head == nullptr) {
		cout << "Список пустой" << endl;
		return;
	}
	List* temp = head;
	List* previus = temp;
	int count = 0;

	do {
		if (temp->data != el) {
			previus = temp;
			temp = temp->pNext;
		}
		else if (temp->data == el) {
			List* temp2 = temp->pNext;
			previus->pNext = temp2;
			head = temp2;
			delete temp;
			temp = nullptr;
			temp = temp2;
		}
	} while (temp->pNext != nullptr);

	if (temp->pNext == nullptr && temp->data == el) {
		List* temp3 = temp->pNext;
		previus->pNext = temp3;
		delete temp;
		temp = nullptr;
		temp = temp3;
	}
}

List* searchTheList(List* head, int data) {
	//сделать возвращение адреса и написать нашел или нет
	List* temp = head;
	int count = 0;
	while (temp != nullptr) {
		++count;
		if (temp->data == data) {
			cout << "элемент " << temp->data << " найден на " << count << " позиции списка" << endl;
			return temp;
		}
		temp = temp->pNext;
	}
	return nullptr;
}

bool emptyList(List* list) {
	if (list == nullptr) {
		return true;
	}
	else return false;
}

void fillingListMultipleValues(List* list, int count) {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	for (int i = 0; i < count; i++)
	{
		int input = 0;
		cin >> input;
		addElEnd(list, input);
	}
}

void sortAscending(List* head) {
	List* temp = head;
	bool swapped = false;
	while (temp->pNext != nullptr) {

		if (temp->data <= temp->pNext->data) {
			temp = temp->pNext;
			continue;
		}
		else if (temp->data > temp->pNext->data) {
			int tempForHelp = temp->data;
			temp->data = temp->pNext->data;
			temp->pNext->data = tempForHelp;

			temp = head;
		}
	}
}

void sortFinalList(List* headFirst, List* headSecond, List*& finalList) {
	finalList = headFirst;
	while (finalList->pNext) {
		finalList->data = finalList->data;
		finalList = finalList->pNext;
	}
	finalList->pNext = headSecond;
	while (finalList->pNext) {
		finalList->data = finalList->data;
		finalList = finalList->pNext;
	}
	headSecond = nullptr;
	finalList = headFirst;
	sortAscending(finalList);
}


void FuncNum1(List* listFirst, List* listSecond, List* finalList) {
	InitList(listFirst);
	InitList(listSecond);
	InitList(finalList);
	int firstCount = 0;
	int secondCount = 0;
	cout << "Введите количество элементов первого списка : ";
	cin >> firstCount;
	cout << "Введите количество элементов второго списка : ";
	cin >> secondCount;

	cout << "Заполнение первого списка : ";
	fillingListMultipleValues(listFirst, firstCount);
	sortAscending(listFirst);
	printList(listFirst);
	cout << endl;
	cout << "Заполнение второго списка : ";
	fillingListMultipleValues(listSecond, secondCount);
	sortAscending(listSecond);
	printList(listSecond);
	cout << endl;
	cout << "Упорядоченный по неубыванию список : " << endl;
	sortFinalList(listFirst, listSecond, finalList);
	printList(finalList);
	cout << endl;
	system("pause");
}

void caseFirst(List*& list) {
	int choice = 0;
	int num = 0;
	char choiceForCheck{};

	system("cls");
	cout << "1. Добавление в начало\n" <<
		"2. Добавление в конец\n" <<
		"3. Добавление после определенного элемента\n" <<
		"4. Удаление всего списка\n" <<
		"5. Удаление головы\n" <<
		"6. Удаление элемента после заданного элемента\n" <<
		"7. Удаление последнего элемента\n" <<
		"8. Удаление всех вхождений\n" <<
		"9. Вернуться в меню\n" << endl;
	cout << "Ввод : ";
	cin >> choice;
	switch (choice)
	{
	case 1: {
		system("cls");
		cout << "Введите число для добавления : ";
		cin >> num;
		addElBegin(list, num);
		cout << "Элемент добавлен!" << endl;
		system("pause");
		break;
	}
	case 2: {
		system("cls");
		cout << "Введите число для добавления : ";
		cin >> num;
		addElEnd(list, num);
		cout << "Элемент добавлен!" << endl;
		system("pause");
		break;
	}
	case 3: {
		int el = 0;
		system("cls");
		cout << "Введите элемент после которого добавить число : ";
		cin >> el;
		cout << endl;
		cout << "Введите число для добавления : ";
		cin >> num;
		addAfterSpecificElement(list, el, num);
		system("pause");
		break;
	}
	case 4: {
		system("cls");
		removeList(list);
		cout << "Список удален!" << endl;
		system("pause");
		break;
	}
	case 5: {
		system("cls");
		removeHead(list);
		cout << "Голова списка удалена!" << endl;
		system("pause");
		break;
	}
	case 6: {
		int el = 0;
		system("cls");
		cout << "Введите элемент после которого удалить : ";
		cin >> el;
		deleteAfterSpecificElement(list, el);
		cout << "Элемент удален!" << endl;
		system("pause");
		break;
	}
	case 7: {
		system("cls");
		removeLastEl(list);
		cout << "Последний элемент удален!" << endl;
		system("pause");
		break;
	}
	case 8: {
		system("cls");
		cout << "Введите число вхождения которого будут удалены : ";
		cin >> num;
		deleteAllOccurrences(list, num);
		cout << endl;
		cout << "Вхождения успешно удалены! " << endl;
		system("pause");
		break;
	}
	case 9: {
		system("cls");
	}
	}
}

void start(List* list) {
	unsigned int choiceForSwitch = 0;
	do {
		system("cls");
		cout << "Выберите операцию:\n\n" <<
			"1. Добавления и удаления\n" <<
			"2. Поиск по списку\n" <<
			"3. Вывод на экран\n" <<
			"4. Проверка на пустоту\n" <<
			"5. Индивидуальная функция\n" <<
			"6. Выйти из программы\n" << endl;
		while (true) {
			cout << "Ввод : ";
			cin >> choiceForSwitch;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else {
				break;
			}
		}
		switch (choiceForSwitch)
		{
		case 1: {
			system("cls");
			caseFirst(list);
			break;
		}
		case 2: {
			unsigned int data = 0;
			system("cls");
			cout << "Введите число которое надо найти : ";
			cin >> data;
			searchTheList(list, data);
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			printList(list);
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			if (emptyList(list) == 1) {
				cout << "Список пустой" << endl;
			}
			else {
				cout << "Список не пустой" << endl;
			}
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			List* node = new List;
			List* nodeSecond = new List;
			List* finalList = new List;
			FuncNum1(node, nodeSecond, finalList);

			break;
		}
		case 6: {
			system("cls");
			break;
		}
		}
	} while (choiceForSwitch != 6);
}

void program() {
	setlocale(LC_ALL, "Russian");
	string input;
	do {
		cout << "Создать список? y/n  :  ";
		cin >> input;
	} while (input != "Y" && input != "N" && input != "y" && input != "n");

	if (input == "y" || input == "Y") {
		system("cls");
		int data = 0;
		bool flag = true;
		while (flag) {
			cout << "Введите первое число для создания списка  :  ";
			cin >> data;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else {
				break;
			}
		}
		List* list = new List;
		InitList(list, data);
		start(list);
	}
	else if (input == "n" || input == "N") {
		cout << "Выход...";
	}
}
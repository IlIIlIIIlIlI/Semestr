#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::string;

int const MAX_MATRIX = 10;

struct town {
	string name = "nullius";
	unsigned long long pop = 0;
};

/*
	\brief Функция для добавления точки типа town в граф.
	\param list указатель на список, в который желаем добавить новую точку
	\param name Название новой точки
	\param pop Числовое значение населения новой точки
	\return Void функция меняет значения внутри списка, на который указывает указатель
	\see town
*/
void add_town(town* list, string name, long long pop) {
	int i = 0;
	while (i < MAX_MATRIX)
		if (list[i].name != "nullius") i++;
		else break;
	if (i < MAX_MATRIX) {
		list[i].name = name;
		list[i].pop = pop;
		cout << "Done! Town " << name << " has been added!\nThe Identificator for " << name << " is: " << i << ".\n";
	}
	else {
		cout << "Maximum number of towns reached [" << MAX_MATRIX << "]! Free some space.\n";
	}
}

void del_town(bool(*mat)[MAX_MATRIX], town* list, string name) {
	int i = 0;
	while (i < MAX_MATRIX)
		if (list[i].name != name) i++;
		else break;
	if (i < MAX_MATRIX) {
		for (int j = 0; j < MAX_MATRIX; j++) {
			mat[i][j] = 0;
			mat[j][i] = 0;
		}
		town nt;
		list[i] = nt;
		cout << "Done! Town " << name << " has been deleted!\n";
	}
	else {
		cout << "There is no such town!\n";
	}
}

void del_town(bool(*mat)[MAX_MATRIX], town* list, int ID) {
	if (list[ID].name != "nullius") {
		for (int j = 0; j < MAX_MATRIX; j++) {
			mat[ID][j] = 0;
			mat[j][ID] = 0;
		}
		cout << "Town " << list[ID].name << " has been deleted";
		town nt;
		list[ID] = nt;
		cout << " successufully!\n";
	}
	else {
		cout << "There is no such town!\n";
	}
}

void add_vert(bool(*mat)[MAX_MATRIX], town* list, string from, string to) {
	int i = 0, a = -1, b = -1;
	while (i < MAX_MATRIX && (a == -1 || b == -1)) {
		if (list[i].name == from) a = i;
		if (list[i].name == to) b = i;
		i++;
	}
	if (i < MAX_MATRIX) {
		if (mat[a][b]) {
			cout << "The path already exist from " << from << " to " << to << "!\n";
		}
		else {
			mat[a][b] = 1;
			cout << "The path from " << from << " to " << to << " has been added!\n";
		}
	}
	else if (a == -1 && b != -1) {
		cout << "There is no such town as " << from << "!\n";
	}
	else if (a != -1 && b == -1) {
		cout << "There is no such town as " << to << "!\n";
	}
	else {
		cout << "There are no such towns as " << from << " and " << to << ".\n";
	}
}

void add_vert(bool(*mat)[MAX_MATRIX], town* list, int from, int to) {
	if (list[from].name != "nullius" && list[to].name != "nullius") {
		if (mat[from][to]) {
			cout << "The path already exist from " << list[from].name << " to " << list[to].name << "!\n";
		}
		else {
			mat[from][to] = 1;
			cout << "The path from " << list[from].name << " to " << list[to].name << " has been added!\n";
		}
	}
	else if (list[from].name == "nullius" && list[to].name != "nullius") {
		cout << "There is no such town as " << list[from].name << "!\n";
	}
	else if (list[from].name != "nullius" && list[to].name == "nullius") {
		cout << "There is no such town as " << list[to].name << "!\n";
	}
	else {
		cout << "There are no such towns as " << list[from].name << " and " << list[to].name << ".\n";
	}
}
void add_vert(bool(*mat)[MAX_MATRIX], town* list, string from, int to) {
	int i = 0, a = -1;
	while (i < MAX_MATRIX && (a == -1)) {
		if (list[i].name == from) a = i;
		i++;
	}
	if (a != -1 && list[to].name != "nullius") {
		if (mat[a][to]) {
			cout << "The path already exist from " << from << " to " << list[to].name << "!\n";
		}
		else {
			mat[a][to] = 1;
			cout << "The path from " << from << " to " << list[to].name << " has been added!\n";
		}
	}
	else if (a == -1 && list[to].name != "nullius") {
		cout << "There is no such town as " << from << "!\n";
	}
	else if (a != -1 && list[to].name == "nullius") {
		cout << "There is no such town as " << list[to].name << "!\n";
	}
	else {
		cout << "There are no such towns as " << from << " and " << list[to].name << ".\n";
	}
}		
void add_vert(bool(*mat)[MAX_MATRIX], town* list, int from, string to) {
	int i = 0, b = -1;
	while (i < MAX_MATRIX && (b == -1)) {
		if (list[i].name == to) b = i;
		i++;
	}
	if (b != -1 && list[from].name != "nullius") {
		if (mat[from][b]) {
			cout << "The path already exist from " << list[from].name << " to " << to << "!\n";
		}
		else {
			mat[from][b] = 1;
			cout << "The path from " << list[from].name << " to " << to << " has been added!\n";
		}
	}
	else if (b == -1 && list[from].name != "nullius") {
		cout << "There is no such town as " << list[from].name << "!\n";
	}
	else if (b != -1 && list[from].name == "nullius") {
		cout << "There is no such town as " << to << "!\n";
	}
	else {
		cout << "There are no such towns as " << list[from].name << " and " << to << ".\n";
	}
}

void del_vert(bool(*mat)[MAX_MATRIX], town* list, string from, string to) {
	int i = 0, a = -1, b = -1;
	while (i < MAX_MATRIX && (a == -1 || b == -1)) {
		if (list[i].name == from) a = i;
		if (list[i].name == to) b = i;
		i++;
	}
	if (i < MAX_MATRIX) {
		if (mat[a][b]) {
			mat[a][b] = 0;
			cout << "The path from " << from << " to " << to << " has been deleted!\n";
		}
		else {
			cout << "There is no path from " << from << " to " << to << "!\n";
		}
	}
	else if (a == -1 && b != -1) {
		cout << "There is no such town as " << from << "!\n";
	}
	else if (a != -1 && b == -1) {
		cout << "There is no such town as " << to << "!\n";
	}
	else {
		cout << "There are no such towns as " << from << " and " << to << ".\n";
	}
}

void del_vert(bool(*mat)[MAX_MATRIX], town* list, int from, int to) {
	if (list[from].name != "nullius" && list[to].name != "nullius") {
		if (mat[from][to]) {
			mat[from][to] = 0;
			cout << "The path from " << list[from].name << " to " << list[to].name << " has been deleted!\n";
		}
		else {
			cout << "There is no path from " << list[from].name << " to " << list[to].name << "!\n";
		}
	}
	else if (list[from].name == "nullius" && list[to].name != "nullius") {
		cout << "There is no such town as " << list[from].name << "!\n";
	}
	else if (list[from].name != "nullius" && list[to].name == "nullius") {
		cout << "There is no such town as " << list[to].name << "!\n";
	}
	else {
		cout << "There are no such towns as " << list[from].name << " and " << list[to].name << ".\n";
	}
}
void del_vert(bool(*mat)[MAX_MATRIX], town* list, string from, int to) {
	int i = 0, a = -1;
	while (i < MAX_MATRIX && (a == -1)) {
		if (list[i].name == from) a = i;
		i++;
	}
	if (a != -1 && list[to].name != "nullius") {
		if (mat[a][to]) {
			mat[a][to] = 0;
			cout << "The path from " << from << " to " << list[to].name << " has been deleted!\n";
		}
		else {
			cout << "There is no path from " << from << " to " << list[to].name << "!\n";
		}
	}
	else if (a == -1 && list[to].name != "nullius") {
		cout << "There is no such town as " << from << "!\n";
	}
	else if (a != -1 && list[to].name == "nullius") {
		cout << "There is no such town as " << list[to].name << "!\n";
	}
	else {
		cout << "There are no such towns as " << from << " and " << list[to].name << ".\n";
	}
}
void del_vert(bool(*mat)[MAX_MATRIX], town* list, int from, string to) {
	int i = 0, b = -1;
	while (i < MAX_MATRIX && (b == -1)) {
		if (list[i].name == to) b = i;
		i++;
	}
	if (b != -1 && list[from].name != "nullius") {
		if (mat[from][b]) {
			mat[from][b] = 0;
			cout << "The path from " << list[from].name << " to " << to << " has been deleted!\n";
		}
		else {
			cout << "There is no path from " << list[from].name << " to " << to << "!\n";
		}
	}
	else if (b == -1 && list[from].name != "nullius") {
		cout << "There is no such town as " << list[from].name << "!\n";
	}
	else if (b != -1 && list[from].name == "nullius") {
		cout << "There is no such town as " << to << "!\n";
	}
	else {
		cout << "There are no such towns as " << list[from].name << " and " << to << ".\n";
	}
}

void showgraph(bool (*mat)[MAX_MATRIX], town* list) {
	for (int i = 0; i < MAX_MATRIX; i++) {
		if (list[i].name != "nullius")
			cout << list[i].name << '[' << i << ']' << ": ";
		else
			continue;
		for (int j = 0; j < MAX_MATRIX; j++) {
			if (mat[i][j]) cout << list[j].name << '[' << j << ']' << ", ";
		}
		cout << std::endl;
	}
}

unsigned long long fromWhereNPop(bool(*mat)[MAX_MATRIX], town* list, string name) {
	int i = 0;
	while (i < MAX_MATRIX)
		if (list[i].name != name) i++;
		else break;
	if (i < MAX_MATRIX) {
		cout << name << '[' << i << ']' << "...";
		unsigned long long count = 0;
		for (int j = 0; j < MAX_MATRIX; j++) {
			if (mat[j][i]) {
				cout << list[j].name << " - population: " << list[j].pop << std::endl;
				count += list[j].pop;
			}
		}
		if (count == 0) {
			cout << "No towns have a path to " << name << "!\n";
			return 0;
		}
		else {
			cout << "Total population: " << count << ".\n";
			return count;
		}
	}
	else {
		cout << "There is no such town!\n";
	}
	return 0;
}

unsigned long long fromWhereNPop(bool(*mat)[MAX_MATRIX], town* list, int ID) {
	if (list[ID].name != "nullius") {
		cout << list[ID].name << '[' << ID << ']' << std::endl;
		unsigned long long count = 0;
		for (int j = 0; j < MAX_MATRIX; j++) {
			if (mat[j][ID]) {
				cout << list[j].name << " - population: " << list[j].pop << std::endl;
				count += list[j].pop;
			}
		}
		if (count == 0) {
			cout << "No towns have a path to " << list[ID].name << "!\n";
			return 0;
		}
		else {
			cout << "Total population: " << count << ".\n";
			return count;
		}
	}
	else {
		cout << "There is no such town!\n";
	}
	return 0;
}

void main() {
	bool matrix[MAX_MATRIX][MAX_MATRIX]{ 0 };
	town list[MAX_MATRIX];

	{
		list[0].name = "Khabarovsk"; list[0].pop = 300000;
		list[1].name = "Moscow"; list[1].pop = 5000000;
		list[2].name = "St. Peterburg"; list[2].pop = 1000000;
		list[3].name = "Krasnoyarsk"; list[3].pop = 300000;
		matrix[0][1] = 1; matrix[0][2] = 1;
		matrix[1][0] = 1; matrix[1][2] = 1; matrix[1][3] = 1;
		matrix[2][0] = 1; matrix[2][1] = 1; matrix[2][3] = 1;
		matrix[3][0] = 1; matrix[3][1] = 1;
	}
	int cmd; string comm;
	cout << "Commands:\n1. Add town\n2. Delete town\n3. Add path\n4. Delete path\n5. Paths\n6. Show\n";
	while (true) {
		cout << "\nCommand: ";
		cin >> comm;
		try
		{
			cmd = stoi(comm);
		}
		catch (const std::exception&)
		{
			cmd = 0;
		}
		if (cmd >= 7) break;
		switch (cmd)
		{
		case 1:
		{
			string name;
			unsigned long long pop;
			cout << "Enter the name of the town: "; cin >> name;
			cout << "Enter the population of " << name << ": "; cin >> pop;
			add_town(list, name, pop);
			break;
		}
		case 2:
		{
			string name;
			int id;
			cout << "Enter the name/identificator of the town: "; cin >> name;
			try
			{
				id = std::stoi(name);
			}
			catch (const std::exception&)
			{
				del_town(matrix, list, name);
				break;
			}
			del_town(matrix, list, id);
			break;
		}
		case 3:
		{
			string from, to;
			int fid, tid;
			cout << "Enter from where to create the path (name/identificator): "; cin >> from;
			cout << "Enter to where the path leads (name/identificator): "; cin >> to;
			try
			{
				fid = std::stoi(from);
				tid = std::stoi(to);
			}
			catch (const std::exception&)
			{
				add_vert(matrix, list, from, to);
				break;
			}
			add_vert(matrix, list, fid, tid);
			break;
		}
		case 4:
		{
			string from, to;
			int fid, tid;
			cout << "Enter from where to delete the path (name/identificator): "; cin >> from;
			cout << "Enter to where the path leads (name/identificator): "; cin >> to;
			try
			{
				fid = std::stoi(from);
				tid = std::stoi(to);
			}
			catch (const std::exception&)
			{
				del_vert(matrix, list, from, to);
				break;
			}
			del_vert(matrix, list, fid, tid);
			break;
		}
		case 5:
		{
			string name;
			int id;
			cout << "Enter the name/identificator of the town: "; cin >> name;
			try
			{
				id = stoi(name);
			}
			catch (const std::exception&)
			{
				fromWhereNPop(matrix, list, name);
				break;
			}
			fromWhereNPop(matrix, list, id);
			break;
		}
		case 6:
		{
			showgraph(matrix, list);
			break;
		}
		default:
			cout << "Invalid command input! The only available command is a NUMBER is range [1-7]\n\n";
			break;
		}
	}
	cout << "\nThanks for using me!";
}
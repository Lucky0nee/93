#include <iostream>
#include <map>

std::map<int, int> count() {
	std::map<int, int> temp;

	for (int i = 4; i < 4096; i++) {
		int Sum = 0;
		int Num = 0;

		for (int j = 1; j < 4096; j++) {
			if (i % j == 0 && j < i) {
				Sum += j;
			}
		}

		for (int j = 1; j < 4096; j++) {
			if (Sum % j == 0 && j < Sum) {
				Num += j;
			}
		}

		if (Num == i && Sum != Num)
			temp[Sum] = Num;
	}

	return temp;
}

void print(std::map<int, int> mp) {
	for (std::pair<int, int>  str : mp) {
		std::cout << str.first << " - " << str.second << " \n";
	}
}

int main() {
	print(count());

	return EXIT_SUCCESS;
}

/*
Знайти такі пари чисел в діапазоні від 4 до 1024, для яких виконується умова:
всі можливі цілі дільники одного числа з такої пари(крім його самого) в сумі
дорівнюють іншому числу з пари.

Наприклад — всі дільники числа 284, які менші його самого: 1, 2, 4, 71 і 142. Їх сума дорівнює 220.
Всі дільники 220, без самого числа: 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 і 110.
Їх сума дорівнює 284. Отже 284 і 220 — числа
дружні.
*/

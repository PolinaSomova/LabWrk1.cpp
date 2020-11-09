#include <iostream>

using namespace std;

const int BIT = 8; // константа: 1 байт = 8 бит

void SizeOf (); // Прототип метода: Количество памяти (в байтах) выделяемое под различные типы
void BinaryInt (); // Прототип метода: Двоичное представление в памяти целого (int) числа
int RankValueInt (int); // Прототип функции: Количесво значащих разрядов в int числе
void BinaryFloat (); // Прототип метода: Двоичное представление в памяти типа float
void BinaryDouble (); // Прототип метода: Двоичное представление в памяти тип double
int MenuTasks (); // Прототип функции: Меню (перечисление задач)
void DoTasks (int); // Прототип метода: Выполнение задач по выбору
void DoLabWork1 (); // Прототип метода: Выполнение лабораторной работы номер 1

int main() {

    setlocale( LC_ALL, "Russian");

    DoLabWork1();

    return 0;
}

/*
 * Метод: Определяет количество памяти (в байтах) выделяемое под различные типы
 */
void SizeOf () {

    cout << "int: " << sizeof(int) << "\n";
    cout << "short int: " << sizeof(short int) << "\n";
    cout << "long int: " << sizeof(long int) << "\n";

    cout << "float: " << sizeof(float) << "\n";
    cout << "double: " << sizeof(double) << "\n";
    cout << "long double: " << sizeof(long double) << "\n";

    cout << "char: " << sizeof(char) << "\n";

    cout << "bool: " << sizeof(bool) << "\n";

}

/*
 * Метод: Двоичное представление в памяти int числа
 * 1. Ввод int числа с клавиатуры
 * 2. Подсчет значащих разрядов, разрядность маски и самой маски
 * 3. С помощью сдвига влево произсводится двоичное представление в памяти int числа
 */
void BinaryInt () {

    int valueInt;
    cout << "Введите целое число: ";
    cin >> valueInt;

    int rank = RankValueInt(valueInt);
    unsigned int order = sizeof(int)*BIT; //разрядность для маски
    unsigned int mask = 1 << order - 1;

    for (int i = 1; i <= order; i++) {
        putchar(valueInt & mask ? '1' : '0');
        valueInt <<= 1;

        if ( (i == 1) || (i == order - rank) ) {
            putchar(' ');
        }
    }

}

/*
 * Функция: Подсчет количества разрядов в int числе
 * Назначение: В двоичном представении int числа отделить от значащих разрядов
 */
int RankValueInt(int rValueInt) {

    int rankCopy = 0;
    int valueIntCopy = rValueInt;
    while (valueIntCopy) {
        rankCopy++;
        valueIntCopy=valueIntCopy/2;
    }
    return rankCopy;
}

/*
 * Метод: Двоичное представление в памяти float числа
 * 1. Ввод float числа с клавиатуры
 * 2. Подсчет разрядность маски и самой маски
 * 3. Двоичное представление в памяти float числа
 */
void BinaryFloat () {

    union {
        float valueFloat;
        int tool;
    };

    cout << "Введите float число: ";
    cin >> valueFloat;

    unsigned int orderFloat = sizeof(float)*BIT; //разрядность для маски
    unsigned int maskFloat = 1 << orderFloat - 1;

    for (int i = 1; i <= orderFloat; i++) {

        putchar( tool & maskFloat ? '1' : '0');

        if ( (i == 1) || (i == 9) ) {
            putchar(' ');
        }

        tool <<= 1;
    }

}

/*
 * Метод: Двоичное представление в памяти double числа
 * 1. Ввод double числа с клавиатуры
 * 2. Подсчет разрядность маски и самой маски
 * 3. Двоичное представление в памяти double числа через массив из 2 int
 */
void BinaryDouble () {

    union {
        double valueDouble;
        int toolDouble[2];
    };

    cout << "Введите double число: ";
    cin >> valueDouble;

    unsigned int orderDouble = sizeof(double) * BIT; //разрядность для маски
    unsigned int orderDoubleHalf = orderDouble / 2;
    unsigned int maskDouble = 1 << (orderDoubleHalf - 1);

    for (int i = 1; i <= orderDoubleHalf; i++) {

        putchar(toolDouble[1] & maskDouble ? '1' : '0');

        if ((i == 1) || (i == 12)) {
            putchar(' ');
        }

        toolDouble[1] <<= 1;
    }

    for (int i = orderDoubleHalf + 1; i <= orderDouble; i++) {

        putchar(toolDouble[0] & maskDouble ? '1' : '0');
        toolDouble[0] <<= 1;
    }

}

/*
 * Функция: Меню. Перечисление задач
 * Назначение: Выбор необходимой задачи
 */
int MenuTasks () {

    int numberTask;
    cout << "\n\n";
    cout << "***\n";
    cout << "Введите номер задачи: \n";
    cout << "1) Вывести количество памяти (в байтах) выделяемое под различные её типы \n";
    cout << "2) Вывести двоичное представление в памяти целого (int) числа \n";
    cout << "3) Вывести двоичное представление в памяти типа float \n";
    cout << "4) Вывести двоичное представление в памяти типа double \n";

    while (1) {

        cin >> numberTask;
        if ( (numberTask > 0) && (numberTask < 5) )
            break;
        else
            cout << "Error: Неверно введены данные \n";
    }
    cout << "\n";
    return numberTask;
}

/*
 * Выполнение необходимой задачи
 */
void DoTasks (int option) {

        switch (option) {
            case 1: {
                SizeOf();
                break;
            }
            case 2: {
                BinaryInt();
                break;
            }
            case 3: {
                BinaryFloat();
                break;
            }
            case 4: {
                BinaryDouble();
                break;
            }
        }
}

/*
 * Выполнение лабораторной работы номер 1
 */
void DoLabWork1 () {

    while (1) {
        DoTasks(MenuTasks());
    }
}



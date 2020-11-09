#include <iostream>

using namespace std;

const int BIT = 8; // ���������: 1 ���� = 8 ���

void SizeOf (); // �������� ������: ���������� ������ (� ������) ���������� ��� ��������� ����
void BinaryInt (); // �������� ������: �������� ������������� � ������ ������ (int) �����
int RankValueInt (int); // �������� �������: ��������� �������� �������� � int �����
void BinaryFloat (); // �������� ������: �������� ������������� � ������ ���� float
void BinaryDouble (); // �������� ������: �������� ������������� � ������ ��� double
int MenuTasks (); // �������� �������: ���� (������������ �����)
void DoTasks (int); // �������� ������: ���������� ����� �� ������
void DoLabWork1 (); // �������� ������: ���������� ������������ ������ ����� 1

int main() {

    setlocale( LC_ALL, "Russian");

    DoLabWork1();

    return 0;
}

/*
 * �����: ���������� ���������� ������ (� ������) ���������� ��� ��������� ����
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
 * �����: �������� ������������� � ������ int �����
 * 1. ���� int ����� � ����������
 * 2. ������� �������� ��������, ����������� ����� � ����� �����
 * 3. � ������� ������ ����� ������������� �������� ������������� � ������ int �����
 */
void BinaryInt () {

    int valueInt;
    cout << "������� ����� �����: ";
    cin >> valueInt;

    int rank = RankValueInt(valueInt);
    unsigned int order = sizeof(int)*BIT; //����������� ��� �����
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
 * �������: ������� ���������� �������� � int �����
 * ����������: � �������� ������������ int ����� �������� �� �������� ��������
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
 * �����: �������� ������������� � ������ float �����
 * 1. ���� float ����� � ����������
 * 2. ������� ����������� ����� � ����� �����
 * 3. �������� ������������� � ������ float �����
 */
void BinaryFloat () {

    union {
        float valueFloat;
        int tool;
    };

    cout << "������� float �����: ";
    cin >> valueFloat;

    unsigned int orderFloat = sizeof(float)*BIT; //����������� ��� �����
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
 * �����: �������� ������������� � ������ double �����
 * 1. ���� double ����� � ����������
 * 2. ������� ����������� ����� � ����� �����
 * 3. �������� ������������� � ������ double ����� ����� ������ �� 2 int
 */
void BinaryDouble () {

    union {
        double valueDouble;
        int toolDouble[2];
    };

    cout << "������� double �����: ";
    cin >> valueDouble;

    unsigned int orderDouble = sizeof(double) * BIT; //����������� ��� �����
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
 * �������: ����. ������������ �����
 * ����������: ����� ����������� ������
 */
int MenuTasks () {

    int numberTask;
    cout << "\n\n";
    cout << "***\n";
    cout << "������� ����� ������: \n";
    cout << "1) ������� ���������� ������ (� ������) ���������� ��� ��������� � ���� \n";
    cout << "2) ������� �������� ������������� � ������ ������ (int) ����� \n";
    cout << "3) ������� �������� ������������� � ������ ���� float \n";
    cout << "4) ������� �������� ������������� � ������ ���� double \n";

    while (1) {

        cin >> numberTask;
        if ( (numberTask > 0) && (numberTask < 5) )
            break;
        else
            cout << "Error: ������� ������� ������ \n";
    }
    cout << "\n";
    return numberTask;
}

/*
 * ���������� ����������� ������
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
 * ���������� ������������ ������ ����� 1
 */
void DoLabWork1 () {

    while (1) {
        DoTasks(MenuTasks());
    }
}



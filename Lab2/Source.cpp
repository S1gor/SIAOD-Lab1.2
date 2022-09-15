#include <iostream>
#include <string>

/*������� ���� � ������� �� ������� �����.���� �������� �������� ���� ����.������� �������� �� ��������� �������� :
1) ����������� ���� �������� � ����� ������ �� ����� ���� ��������;
2) ���������� ������� ����� ������� '�' � '�';
3) ����� ������ ����� �� ����� ���� ������;
4) � ���������� � ����������� ������ ����� ������ ���� ������� �����.*/

char SOUNDS[] = "��";
char VOWELS[] = "���������";	

void ReadFile(const char* filename, char* str)
{
	FILE* file;
	if (fopen_s(&file, filename, "r") != NULL)
	{
		printf("�� ������� ������� ���� %s", filename);
		exit(1);
	}
	fgets(str, 100, file);
	printf("�������� ������:\n%s\n", str);

	fclose(file);
}

bool isVowels(char* mas)
{
	int len = strlen(mas);
	for (int i = 0; i <= len; i++)
		for (int j = 0; j <= 9; j++)
			return (mas[i] == VOWELS[j]) ? false : true;
}


void HyphenationWord(char* str)
{
	char mas[20];

	int number = 0;
	int len = strlen(str);
	for (int i = 0; i <= len; i++)
	{
		mas[number] = str[i];
		if ((str[i] == ' ' || str[i] == ',' || str[i] == '.') && (str[i + 1] == ' ' || str[i + 1] == ',' || str[i + 1] == '.' || str[i + 1] == '\0'))
			continue;
		if (str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '\0')
		{
			mas[number] = '\0';

			printf("%s\n", mas);





			for (int j = 0; j < number; j++)
				mas[j] = ' ';
			number = 0;
			continue;
		}
		number++;
	}
}

int main()
{
	system("chcp 1251"); system("cls");

	const int amountEl = 256;
	char str[amountEl];
	char filename[] = "1.txt";

	ReadFile(filename, str);
	HyphenationWord(str);
	 

	return 0;
}
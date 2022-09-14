#include <iostream>

void ReadFile(const char* filename, char* str)
{
	FILE* file;
	if (fopen_s(&file, filename, "r") != NULL)
	{
		printf("Не удалось открыть файл %s", filename);
		exit(1);
	}
	fgets(str, 100, file);
	printf("Введённая строка:\n%s\n", str);

	fclose(file);
}

void TransferWord(char* str)
{
	char mas[20];
	//char* s1 = str;
	//char* s2 = strchr(str, ' ');
	//// Знак + точка
	//while (s1 != NULL && s2 != NULL)
	//{
	//	if (s2 - s1 <= 0)
	//	{
	//		s1 = s2 + 1;
	//		s2 = strchr(s2 + 1, ' ');
	//		continue;
	//	}

	//	strncpy_s(mas, s1, s2 - s1);
	//	printf("%s\n", mas);	


	//	s1 = s2 + 1;
	//	s2 = strchr(s2 + 1, ' ');
	//}
	//if (s2 == NULL)
	//{
	//	strncpy_s(mas, s1, s2 - s1);
	//	printf("%s\n", mas);
	//}
	int n = 0;
	int len = strlen(str);
	for (int i = 0; i <= len; i++)
	{
		mas[n] = str[i];
		if ((str[i] == ' ' || str[i] == ',') && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			continue;
		if (str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '\0')
		{
			mas[n] = '\0';

			printf("%s\n", mas);



			for (int j = 0; j < n; j++)
				mas[j] = ' ';
			n = 0;
			continue;
		}
		n++;
	}
}

int main()
{
	system("chcp 1251"); system("cls");

	const int amountEl = 100;
	char str[amountEl];
	char filename[] = "1.txt";

	ReadFile(filename, str);
	TransferWord(str);
	 

	return 0;
}
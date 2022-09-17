#include <iostream>

/*Имеется файл с текстом на русском языке.Дать варианты переноса всех слов.Перенос возможен по следующим правилам:
1) переносятся либо остаются в конце строки не менее двух символов;
2) невозможен перенос перед буквами 'ь' и 'ъ';
3) слово должно иметь не менее двух слогов;
4) в оставшейся и переносимой частях слова должны быть гласные буквы.*/

char SOUNDS[] = "ъьй";
char VOWELS[] = "аеёиоуыэюя";
char CONSONANTS[] = "бвгджзклмнпрстфхцчшщ";

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

bool isVowels(char symbol)
{
	bool flag = false;
	for (int i = 0; i < 10; i++)
		if (symbol == VOWELS[i])
			flag = true;
	return flag ? true : false;
}

bool isConsonants(char symbol)
{
	bool flag = false;
	for (int i = 0; i < 20; i++)
		if (symbol == CONSONANTS[i])
			flag = true;
	return flag ? true : false;
}

bool isSounds(char symbol)
{
	bool flag = false;
	for (int i = 0; i < 3; i++)
		if (symbol == SOUNDS[i])
			flag = true;
	return flag ? true : false;
}

void HyphenationWord(char* str)
{
	printf("Слова со знаками переноса:\n");

	char word[20];
	int number = 0;
	int len = strlen(str);
	for (int i = 0; i <= len; i++)
	{
		word[number] = str[i];
		if ((str[i] == ' ' || str[i] == ',' || str[i] == '.') && (str[i + 1] == ' ' || str[i + 1] == ',' || str[i + 1] == '.' || str[i + 1] == '\0'))
			continue;
		if (str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '\0')
		{
			word[number] = '\0';

			int n = 0, l = 0, counter = 0;
			for (int i = 0; i < number; i++)
				if (isVowels(word[i]))
					counter++;
			if (counter >= 2)
			{
				while (word[n] != '\0')
				{
					if (isVowels(word[n]))
					{
						if (isConsonants(word[n + 1]) && isVowels(word[n + 2]))
						{
							l = strlen(word) + 1;
							for (l; l >= n + 1; l--)
								word[l] = word[l - 1];
							word[n + 1] = '-';
							n = n + 2;
							continue;
						}
						if (isConsonants(word[n + 1]) && isConsonants(word[n + 2]))
						{
							l = strlen(word) + 1;
							for (l; l >= n + 2; l--)
								word[l] = word[l - 1];
							word[n + 2] = '-';
							n = n + 2;
							continue;
						}
						if (isConsonants(word[n + 1]) && isSounds(word[n + 2]) && word[n + 3] != '\0')
						{
							l = strlen(word) + 1;
							for (l; l >= n + 3; l--)
								word[l] = word[l - 1];
							word[n + 3] = '-';
							n = n + 3;
							continue;
						}
						if (isSounds(word[n + 1]) && word[n + 2] != '\0')
						{
							l = strlen(word) + 1;
							for (l; l >= n + 2; l--)
								word[l] = word[l - 1];
							word[n + 2] = '-';
							n = n + 2;
							continue;
						}
					}
					n++;
				}
				printf("%s\n", word);
			}

			for (int j = 0; j < number; j++)
				word[j] = ' ';
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
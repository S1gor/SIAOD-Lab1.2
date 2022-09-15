#include <iostream>
#include <string>

/*»меетс€ файл с текстом на русском €зыке.ƒать варианты переноса всех слов.ѕеренос возможен по следующим правилам:
1) перенос€тс€ либо остаютс€ в конце строки не менее двух символов;
2) невозможен перенос перед буквами 'ь' и 'ъ';
3) слово должно иметь не менее двух слогов;
4) в оставшейс€ и переносимой част€х слова должны быть гласные буквы.*/

char SOUNDS[] = "ъь";
char VOWELS[] = "аеЄиоуыэю€";
char CONSONANTS[] = "бвгджзйклмнпрстфхцчшщ";

void ReadFile(const char* filename, char* str)
{
	FILE* file;
	if (fopen_s(&file, filename, "r") != NULL)
	{
		printf("Ќе удалось открыть файл %s", filename);
		exit(1);
	}
	fgets(str, 100, file);
	printf("¬ведЄнна€ строка:\n%s\n", str);

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
	for (int i = 0; i < 21; i++)
		if (symbol == CONSONANTS[i])
			flag = true;
	return flag ? true : false;
}

bool isSound(char symbol)
{
	bool flag = false;
	for (int i = 0; i < 2; i++)
		if (symbol == SOUNDS[i])
			flag = true;
	return flag ? true : false;
}

void HyphenationWord(char* str)
{
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

			printf("%s\n", word);

			for (int k = 0; k < number; k++)
			{
				if (isVowels(word[k]))		printf("%c - √Ћј—Ќјя\n",	word[k]);
				if (isConsonants(word[k]))	printf("%c - —ќ√Ћј—Ќјя\n",	word[k]);
				if (isSound(word[k]))		printf("%c - ћя√ јя\n",		word[k]);
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
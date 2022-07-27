/*
U10810015地生三許惟智
還有BUG還未修復 但時間問題先繳交
編寫一個程式統計每一個英文單字出現的次數
英文單字是指連續的英文字母，有區分大小寫，所以This與this是不同的英文單字，標點符號及空白字元跳過不處理。
假設英文單字的長度最長為80個字元，不同的英文單字最多有100個。
程式先提示使用者輸入要統計的英文資料，然後處理使用者輸入的英文資料，直到EOF為止。
輸出的結果有兩欄，第一欄為各個英文單字出現的次數，第二欄為英文單字，每個英文單字輸出一行，
出現次數多的英文單字先輸出，次數相同時則依strcmp的順序排列。
*/
#include <stdio.h>
#include <string.h>
#define Stringlength 80
#define Stringnumber 100

int main() {
	char inputS[Stringlength][Stringnumber];
	char* string[Stringlength];
	char* temp;
	int count = 0;
	int i;
	int j;
	int stringCount[Stringlength] = { 0 };
	int maxStringCount = 0;

	while (scanf("%s", inputS[count]) != EOF && count < Stringlength) {
		string[count] = inputS[count];
		count++;
	}
	for (i = 0; i < count - 1; i++) {
		for (j = i; j < count; j++) {
			if (strcmp(string[i], string[j]) > 0) {
				temp = string[i];
				string[i] = string[j];
				string[j] = temp;
			}
		}
	}

	for (i = 0; i < count;) {
		for (j = i + 1; j < count && strcmp(string[i], string[j]) == 0; j++);
			stringCount[i] = j - i;
			maxStringCount = (maxStringCount > stringCount[i]) ? maxStringCount : stringCount[i];
			i = j;
	}

	for (int i = 1; i <= maxStringCount; i++)
		for (int j = 0; j < count; j++)
			if (stringCount[j] == i) {
				printf("%d %s\n", i, string[j]);
			}




	return 0;
}
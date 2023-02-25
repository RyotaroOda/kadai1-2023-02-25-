#include <stdio.h>

#define maxWord 20 //右辺または左辺の文字数の許容量
#define maxLine 10 //入力行数の許容量

int main(void) {
	FILE *fp; 
	char fname[] = "input.conf";//入力ファイル
	int c;//入力文字
	char result[2][maxLine][maxWord];
	int index = 0;
	int line = 0;
	int isValue = 0;
	int equalFlg = 0;


	fp = fopen(fname, "r");
	if(fp == NULL) 
	{
		printf("error file open");
		return -1;
	} 
	while((c = fgetc(fp)) != EOF) 
	{
		putchar(c);

		if (c == '\n')
		{
			index = 0;
			isValue = 0;
			line++;
			if (line > maxLine)
			{
				printf("error: over maxLine");
				return -1;
			}
		}
		
		else if (c == ' ')
		{
			if (equalFlg == 2)
			{
				isValue = 1;
				index = 0;
			}else{
				equalFlg = 1;
			}
		}
		
		else if (c == '=')
		{
			equalFlg = (equalFlg == 1) ? 2 : 0;
		}
		
		else
		{
			if (index > maxWord)
			{
				printf("error: over maxWord");
				return -1;
			}
			result[isValue][line][index++] = c;
		}
	}

	printf("\nResult----------------------------------\n");

	for (int i = 0; i < line + 1; i++)
	{
		printf("Key: %s, Value: %s\n", result[0][i], result[1][i]);
	}
	printf("\n");

	fclose(fp);
	return 0;
}
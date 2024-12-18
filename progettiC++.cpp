#include<iostream>
#include<Windows.h>
#include<ctime>
using namespace std;
void printGame(char colri[7][6]);
int provaFinita(char colri[7][6]);
bool checkwin(char colri[7][6],char m)
{
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (colri[k][i] == m&& colri[k+1][i] == m&& colri[k+2][i] == m && colri[k+3][i] == m)
			{	
				return true;
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i < 7; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (colri[i][k] == m && colri[i][k + 1] == m && colri[i][k + 2] == m && colri[i][k + 3] == m)
			{
				return true;
			}
			else {
				continue;
			}
		}
	}
	for (int i=0;i<4;i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (colri[i][5 - k] == m && colri[i + 1][4 - k] == m && colri[i + 2][3 - k] == m && colri[i + 3][2 - k] == m)
			{
				return true;
			}
			else if (colri[i][k] == m && colri[i + 1][k + 1] == m && colri[i + 2][k + 2] == m && colri[i + 3][k + 3] == m)
			{
				return true;
			}
			else {
				continue;
			}
		}
	}
	
	return false;
}
void printGame(char colri[7][6])
{
	system("cls");
	cout << "     1 2 3 4 5 6 7" << endl;
	cout << "    ---------------" << endl;
	cout << "    |" << colri[0][5] << "|" << colri[1][5] << "|" << colri[2][5] << "|" << colri[3][5] << "|" << colri[4][5] << "|" << colri[5][5] << "|" << colri[6][5] << "|" << endl;
	cout << "    ---------------" << endl;
	cout << "    |" << colri[0][4] << "|" << colri[1][4] << "|" << colri[2][4] << "|" << colri[3][4] << "|" << colri[4][4] << "|" << colri[5][4] << "|" << colri[6][4] << "|" << endl;
	cout << "    ---------------" << endl;
	cout << "    |" << colri[0][3] << "|" << colri[1][3] << "|" << colri[2][3] << "|" << colri[3][3] << "|" << colri[4][3] << "|" << colri[5][3] << "|" << colri[6][3] << "|" << endl;
	cout << "    ---------------" << endl;
	cout << "    |" << colri[0][2] << "|" << colri[1][2] << "|" << colri[2][2] << "|" << colri[3][2] << "|" << colri[4][2] << "|" << colri[5][2] << "|" << colri[6][2] << "|" << endl;
	cout << "    ---------------" << endl;
	cout << "    |" << colri[0][1] << "|" << colri[1][1] << "|" << colri[2][1] << "|" << colri[3][1] << "|" << colri[4][1] << "|" << colri[5][1] << "|" << colri[6][1] << "|" << endl;
	cout << "    ---------------" << endl;
	cout << "    |" << colri[0][0] << "|" << colri[1][0] << "|" << colri[2][0] << "|" << colri[3][0] << "|" << colri[4][0] << "|" << colri[5][0] << "|" << colri[6][0] << "|" << endl;
	cout << "    ---------------" << endl;
}
void filltable(int input,char colri[][6],int *level, char k,char id)
{
	if (level[input-1] <= 5)
	{
	colri[input - 1][level[input-1]] = k;
	printGame(colri);
	}
	else
	{
		if (id=='p')
		{
		l:	
			srand(time(NULL));
			input = rand() % 7 + 1;
			if (level[input - 1] <= 5)
			{
				colri[input - 1][level[input - 1]] = k;
				printGame(colri);
				level[input - 1]++;
			}
			else {
				goto l;
			}
		}
		else {
		k:
		cout << "this colon is full renter again: ";
		cin >> input;
		if (level[input - 1] <= 5)
		{
			colri[input - 1][level[input - 1]] = k;
			printGame(colri);
			level[input - 1]++;
		}
		else {
			goto k;
		}
		}
	}
}
int strategia1(char colri[7][6],int level[7])
{
	char m = 'x';
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (colri[k][i] == m && colri[k + 1][i] == m && colri[k + 2][i] == m)
			{ 
				return k + 4;
			}
			else if (colri[k+1][i] == m && colri[k + 2][i] == m && colri[k + 3][i] == m&&colri[k][i] == ' ')
			{
				return k + 1;
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i < 7; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (colri[i][k] == m && colri[i][k + 1] == m && colri[i][k + 2] == m)
			{
				return i+1;
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (colri[i][5 - k] == m && colri[i + 1][4 - k] == m && colri[i + 2][3 - k] == m)
			{
				return i+3;
			}
			else if (colri[i][k] == m && colri[i + 1][k + 1] == m && colri[i + 2][k + 2] == m)
			{
				return i+3;
			}
			else {
				continue;
			}
		}
	}
	m = 'o';
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (colri[k][i] == m && colri[k + 1][i] == m && colri[k + 2][i] == m)
			{
				return k + 4;
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i < 7; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (colri[i][k] == m && colri[i][k + 1] == m && colri[i][k + 2] == m)
			{
				return i + 1;
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (colri[i][5 - k] == m && colri[i + 1][4 - k] == m && colri[i + 2][3 - k] == m)
			{
				return i + 3;
			}
			else if (colri[i][k] == m && colri[i + 1][k + 1] == m && colri[i + 2][k + 2] == m)
			{
				return i + 3;
			}
			else {
				continue;
			}
		}
		if (i == 3)
		{
			return 10;
		}
	}
}
int strategia2(char colri[7][6], int level[7])
{
	char m = 'x';
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (colri[k][i] == m && colri[k + 1][i] == m && colri[k + 2][i] == m&& colri[k + 3][i] == ' ')
			{
				return k + 4;
				
			}
			else if (colri[k + 1][i] == m && colri[k + 2][i] == m && colri[k + 3][i] == m&& colri[k][i] == ' ')
			{
				return k + 1;
			}
			else if (colri[k][i] == m && colri[k + 1][i] == m && colri[k + 3][i] == m&& colri[k + 2][i] == ' ')
			{
				return k + 3;
			}
			else if (colri[k][i] == m && colri[k + 3][i] == m && colri[k + 2][i] == m&& colri[k + 1][i] == ' ')
			{
				return k + 2;
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i < 7; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (colri[i][k] == m && colri[i][k + 1] == m && colri[i][k + 2] == m&&colri[i][k+3]==' ')
			{
				return i + 1;
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (colri[i][5 - k] == m && colri[i + 1][4 - k] == m && colri[i + 2][3 - k] == m&&colri[i+3][2-k]==' '&&colri[i+3][1-k]!=' ')
			{
				return i + 4;
			}
			else if (colri[i+3][2 - k] == m && colri[i + 1][4 - k] == m && colri[i + 2][3 - k] == m&& colri[i][5 - k] == ' '&&colri[i][4-k]!=' ')
			{
				return i + 1;
			}
			else if (colri[i + 3][2 - k] == m && colri[i + 1][4 - k] == m && colri[i][5 - k] == m && colri[i + 2][3 - k] == ' '&& colri[i + 2][2 - k] != ' ')
			{
				return i + 3;
			}
			else if (colri[i + 3][2 - k] == m && colri[i][5 - k] == m && colri[i + 2][3 - k] == m && colri[i + 1][4 - k] == ' '&& colri[i + 1][3 - k] != ' ')
			{
				return i + 2;
			}
			else if (colri[i][k] == m && colri[i + 1][k + 1] == m && colri[i + 2][k + 2] == m&& colri[i+3][k+3] == ' ' && colri[i + 3][k + 2] != ' ')
			{
				return i + 4;
			}
			else if (colri[i][k] == m && colri[i + 1][k + 1] == m && colri[i + 3][k + 3] == m && colri[i + 2][k + 2] == ' ' && colri[i + 2][k + 1] != ' ')
			{
				return i + 3;
			}
			else if (colri[i+3][k+3] == m && colri[i + 1][k + 1] == m && colri[i + 2][k + 2] == m&& colri[i][k] == ' ')
			{
				return i + 1;
			}
			else if (colri[i][k] == m && colri[i + 3][k + 3] == m && colri[i + 2][k + 2] == m&& colri[i + 1][k + 1] == ' ' && colri[i + 1][k] != ' ')
			{
				return i + 2;
			}
			else {
				continue;
			}
		}
	}
	m = 'o';
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (colri[k][i] == m && colri[k + 1][i] == m && colri[k + 2][i] == m&& colri[k+3][i] == ' ')
			{
				return k + 4;
			}
			else if (colri[k][i] == m && colri[k + 1][i] == m && colri[k + 3][i] == m&& colri[k+2][i] == ' ')
			{
				return k + 3;
			}
			else if (colri[k][i] == m && colri[k + 3][i] == m && colri[k + 2][i] == m&& colri[k+1][i] == ' ')
			{
				return k + 2;
			}
			else if (colri[k+3][i] == m && colri[k + 1][i] == m && colri[k + 2][i] == m&& colri[k][i] == ' ')
			{
				return k + 1;
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i < 7; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (colri[i][k] == m && colri[i][k + 1] == m && colri[i][k + 2] == m&&colri[i][k+3]==' ')
			{
				return i + 1;
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (colri[i][5 - k] == m && colri[i + 1][4 - k] == m && colri[i + 2][3 - k] == m&&colri[i+3][2-k]==' ')
			{
				return i + 4;
			}
			else if (colri[i + 3][2 - k] == m && colri[i + 1][4 - k] == m && colri[i + 2][3 - k] == m)
			{
				return i + 1;
			}
			else if (colri[i + 3][2 - k] == m && colri[i + 1][4 - k] == m && colri[i][5 - k] == m)
			{
				return i + 3;
			}
			else if (colri[i + 3][2 - k] == m && colri[i][5 - k] == m && colri[i + 2][3 - k] == m)
			{
				return i + 2;
			}
			else if (colri[i][k] == m && colri[i + 1][k + 1] == m && colri[i + 2][k + 2] == m)
			{
				return i + 4;
			}
			else if (colri[i][k] == m && colri[i + 1][k + 1] == m && colri[i + 3][k + 3] == m)
			{
				return i + 3;
			}
			else if (colri[i + 3][k + 3] == m && colri[i + 1][k + 1] == m && colri[i + 2][k + 2] == m)
			{
				return i + 1;
			}
			else if (colri[i][k] == m && colri[i + 3][k + 3] == m && colri[i + 2][k + 2] == m)
			{
				return i + 2;
			}
			else {
				continue;
			}
		}
		if (i == 3)
		{
			return 10;
		}
	}
	
}
int provaFinita(char colri[7][6])
{
	int count = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			if (colri[k][i] == 'x' || colri[k][i] == 'o')
			{
				count++;
			}
			else {
				continue;
			}
		}
	}
	if (count == 42)
	{
		return 1;
	}
	else {
		return 2;
	}
}
void ControPc(char colRi[7][6], int count, int level[7],int dif)
{
	int input,x=1;
	printGame(colRi);
	while (x == 1)
	{
		if (count % 2 == 0)
		{
			system("color a");
			m:
			cout << "il giocatore x dovrebbe inserire un numero: ";
			cin >> input;
			if (input > 7 || input < 1)
			{
				cout << "devi inserire un numero compreso fra 1&7\n";
				goto m;
			}
			else {
				char k = 'x';
				count++;
				char id = 't';
				filltable(input, colRi, level, k, id);
				if (provaFinita(colRi) == 1)
				{
					cout << "\nnessuno vice il gioco :(";
					return;
				}
				else {
					level[input - 1] += 1;
					if (checkwin(colRi, k) == true)
					{
						cout << "giocatore x vince";
						return;
					}
				}
			}
		}
		else
		{
			if(dif==1)
			{
			system("color c");
			cout << "il PC sta pensando...";
			char k = 'o';
			input = strategia1(colRi, level);
				if (input == 10)
				{
					srand(time(NULL));
					input = rand() % 7 + 1;
				}
				else {
					input = input;
				}
			count++;
			char id = 'p';
			filltable(input, colRi, level, k,id);
			if (provaFinita(colRi) == 1)
			{
				cout << "\nnessuno vice il gioco :(";
				return;
			}
			level[input - 1] += 1;
			if (checkwin(colRi, k) == true)
			{
				cout << "il giocatore o vince";
				return;
			}
			}
			else {
				system("color c");
				cout << "il PC sta pensando...";
				char k = 'o';
				input = strategia2(colRi, level);
				if (input == 10)
				{
					srand(time(NULL));
					input = rand() % 5 + 3;
				}
				else {
					input = input;
				}
				count++;
				char id = 'p';
				filltable(input, colRi, level, k, id);
				if (provaFinita(colRi) == 1)
				{
					cout << "\nnessuno vice il gioco :(";
					return;
				}
				level[input - 1] += 1;
				if (checkwin(colRi, k) == true)
				{
					cout << "il giocatore o vince";
					return;
				}
			}
		}
	}
}
void ControAmico(char colRi[7][6],int count,int level[7])
{
	int input,x=1;
	printGame(colRi);
	while (x == 1)
	{
		if (count % 2 == 0)
		{
			system("color a");
			l:
			cout << "il giocatore x dovrebbe inserire un numero: ";
			cin >> input;
			if (input < 1 || input>7)
			{
				cout << "devi inserire numeri compresi fra 1&7\n";
				goto l;
			}
			else {
			
				char k = 'x';
				char id = 't';
				count++;
				filltable(input, colRi, level, k, id);
				if (provaFinita(colRi) == 1)
				{
					cout << "\nnessuno vice il gioco :(";
					return;
				}
					level[input - 1] += 1;
					if (checkwin(colRi, k) == true)
					{
						cout << "giocatore x vince";
						return;
					}
			}
		}
		else
		{
			system("color c");
			h:
			cout << "il giocatore o dovrebbe inserire un numero: ";
			cin >> input;
			if (input > 7 || input < 1)
			{
				cout << "devi inserire un numero compreso fra 1&7\n";
				goto h;
			}
			else {
			
				char k = 'o';
				count++;
				char id = 't';
				filltable(input, colRi, level, k, id);
				if (provaFinita(colRi) == 1)
				{
					cout << "\nnessuno vice il gioco :(";
					return;
				}
				level[input - 1] += 1;
				if (checkwin(colRi, k) == true)
				{
					cout << "giocatore o vince";
					return;
				}
			}
		}
	}
}
void livello(char colri[7][6], int count, int level[7])
{
	int in;
	system("cls");
	cout << "scegli il livello(1 per scegliere quello facile, 2 per scegliere quello difficile):";
	cin >> in;
	if (in == 1)
	{
		ControPc(colri,count,level,in);
	}
	else {
		ControPc(colri, count, level, in);
	}
}
int main()
{
	int modalita;
	char i[] = { 'x','o' };
	int count=0;
	int level[7]={0,0,0,0,0,0,0};
	char colRi[7][6]={{' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' '} };
	cout << "Scegli 1 per giocare contro il PC" << endl;
	cout << "Scegli 2 per giocare contro un'amcio:";
	cin >> modalita;
	if (modalita == 1)
	{
		livello(colRi, count, level);
	}
	else {
		ControAmico(colRi,count,level);
		return 0;
	}
}

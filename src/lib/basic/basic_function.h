#pragma once
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string.h>
#include "../struct.h" // cac caaus truc du lieu
#include "../view/console_function.h"

enum status
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	ENTER,
	BACK,
	EXIT,
	MUSIC,
	NHAP_VAN_BAN,
	XOA_VAN_BAN
};

int charToInt(char *a);
std::string getKeyType(int z);
void stringToChar(std::string a, char *b, int size_b);
std::string charToString(char *a);
std::vector<int> customSplit(std::string a, char delim);
void intToChar(int a, char *b, int size_b);
char *loaiBoDauXuongDong(char *a);
std::string DeleteCharacter(std::string text, int index);
char ToLower(char a);
char ToUpper(char a);
bool IsAlphabet(char a);
bool IsFloatDigit(char a);
bool IsIntNumber(std::string num);
bool IsFloatNumber(std::string num);
std::string getStandardizedName(std::string text);
std::string getStandardizedStudentID(std::string text);
std::string getCapitalized(std::string text);

std::string getKeyType(int z)
{
	if (z == 224)
	{
		char c = getch();
		if (c == 72)
			return "UP";
		if (c == 80)
			return "DOWN";
		if (c == 77)
			return "RIGHT";
		if (c == 75)
			return "LEFT";
	}
	else
	{
		if (z >= 32 && z <= 126 && z != 13 && z != 27)
			return "NHAP_VAN_BAN";
		else if (z == 27)
			return "EXIT";
		else if (z == 13)
			return "ENTER";
		else if (z == 8)
			return "XOA_VAN_BAN";
		else if (z == 27)
			return "BACK";
	}
}
int charToInt(char *a)
{
	int res = 0;
	int a_length = strlen(a);

	for (int i = 0; i < a_length; i++)
		if (isdigit(a[i]))
			res = res * 10 + int(a[i] - '0');

	return res;
}

void stringToChar(std::string a, char *b, int size_b)
{
	int copyLength = a.copy(b, size_b);
	for (int i = copyLength; i < size_b; i++)
	{
		b[i] = '\0';
	}
}

std::string charToString(char *a)
{
	return std::string(a);
}

std::vector<int> customSplit(std::string a, char delim)
{
	std::vector<int> res;
	std::string temp = "";
	for (int i = 0; i < a.size(); i++)
	{
		if(a[i]!=',') {
			temp.push_back(a[i]);
		}
		else {
			res.push_back(std::stoi(temp));
			temp = "";
		}
	}
	return res;
}

void intToChar(int a, char *b, int size_b)
{
	std::string c = std::to_string(a);
	stringToChar(c, b, size_b);
}
char *loaiBoDauXuongDong(char *a)
{
	int size = strlen(a);
	if (a[size - 1] == '\n')
		a[size - 1] = '\0';

	return a;
}
std::string DeleteCharacter(std::string text, int index)
{

	int string_size = text.length();

	for (int i = index; i < string_size; i++)
		text[i] = text[i + 1];

	text.pop_back();

	return text;
}
char ToUpper(char a)
{
	if (a >= 'a' && a <= 'z')
		a -= 32;

	return a;
}
char ToLower(char a)
{
	if (a >= 'A' && a <= 'Z')
		a += 32;
	return a;
}

bool IsAlphabet(char a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return true;
	return false;
}

bool IsFloatDigit(char a)
{
	if (a >= '0' && a <= '9')
		return true;
	if (a == '.')
		return true;
	return false;
}

bool IsIntNumber(std::string num)
{
	for (int i = 0; i < num.length(); i++)
		if (isdigit(num[i]) == false)
			return false;
	return true;
}

bool IsFloatNumber(std::string num)
{
	int sodaucham = 0; // neu so dau cham lon hon 1 thif khong phai la so thuc

	for (int i = 0; i < num.length(); i++)
		if (num[0] == '.' || num[num.length() - 1] == '.')
			return false;
		else if (isdigit(num[i]) == false && num[i] != '.')
			return false;
		else if (sodaucham > 1)
			return false;
		else if (num[i] == '.')
			sodaucham++;

	return true;
}

std::string getStandardizedName(std::string text)
{
	if (text.length() == 0)
	{
		return text;
	}
	int string_size = text.length();

	// xoa trang dau chuoi
	while (text[string_size - 1] == ' ')
	{
		text.pop_back();
		string_size--;
	}

	// xoa trang cuoi chuoi
	while (text[0] == ' ')
	{
		text = DeleteCharacter(text, 0);
		string_size--;
	}

	// loai bo mot trong hai khhoang trang canh nhau
	for (int i = 0; i < string_size; i++)
	{

		// xoa ky tu dac biet va number
		if (IsAlphabet(text[i]) == false && text[i] != ' ')
		{
			text = DeleteCharacter(text, i);
			i--;
			string_size--;
		}

		// hai dau cach lien nhau hoac ky tu khac chu cai lien sau dau cach
		else if (text[i] == ' ' && IsAlphabet(text[i + 1]) == false)
		{
			text = DeleteCharacter(text, i + 1);
			i--;
			string_size--;
		}

		else if (i > 0 && IsAlphabet(text[i]) == true && text[i - 1] == ' ')
			text[i] = ToUpper(text[i]);

		// viet hoa chu cai bat dau cua tu moi
		else if (i == 0)
			text[i] = ToUpper(text[i]);

		else
			text[i] = ToLower(text[i]);
	}

	return text;
}

std::string getCapitalized(std::string text = "")
{
	int string_size = text.length();
	if (text.length() == 0)
	{
		return text;
	}
	// xoa dau cach dau chuoi
	while (text[string_size - 1] == ' ')
	{
		text.pop_back();
		string_size--;
	}

	// xoa dau cach cuoi chuoi
	while (text[0] == ' ')
	{
		text = DeleteCharacter(text, 0);
		string_size--;
	}

	// loai bo mot trong hai khhoang trang canh nhau
	for (int i = 0; i < string_size; i++)
	{

		// hai dau cach lien nhau hoac ky tu khac chu cai lien sau dau cach
		if (text[i] == ' ' && text[i + 1] == ' ')
		{
			text = DeleteCharacter(text, i + 1);
			i--;
			string_size--;
		}

		// viet hoa chu cai bat dau cua tu moi
		else if (i == 0)
			text[i] = ToUpper(text[i]);

		else if (i > 0 && text[i - 1] == ' ')
			text[i] = ToUpper(text[i]);

		else
			text[i] = ToLower(text[i]);
	}

	return text;
}

std::string getStandardizedStudentID(std::string text)
{

	if (text.length() == 0)
	{
		return text;
	}
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] >= 'a' && text[i] <= 'z')
			text[i] = text[i] - 32;
		if (text[i] == ' ')
		{ // xoa nhung ki tu sau ma sinh vien
			int count = text.length() - i;
			while (count--)
				text.pop_back();
		}
	}

	return text;
}

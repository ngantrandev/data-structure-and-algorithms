#pragma once
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <string.h>
#include "struct.h" // cac caaus truc du lieu
#include "console_function.h"

// chieu dai toi da cua mot chuoi ky tu
const int maxLengthString = 128;

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

int stringTo_Int(std::string num_a);
int charToInt(char a[maxLengthString]);
status GetKey(int z);
int CompareSourseCode(char a[maxLengthString], char b[maxLengthString]);
void ConvertStringToChar(std::string a, char b[maxLengthString]);
void ConvertCharToString(char a[maxLengthString], std::string &b);
void loaiBoDauXuongDong(char a[maxLengthString]);
void DeleteCharacter(std::string &text, int index);
void ToLower(char &a);
void ToUpper(char &a);
bool IsAlphabet(char a);
bool IsFloatDigit(char a);
bool IsIntNumber(std::string num);
bool IsFloatNumber(std::string num);
std::string getStandardizedName(std::string text);
std::string getStandardizedStudentID(std::string text);
std::string getCapitalized(std::string text);
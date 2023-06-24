#pragma once
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <algorithm>
#include <math.h>
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

int stringTo_Int(std::string num_a);
int charToInt(char *a);
status GetKey(int z);
int CompareSourseCode(char *a, char *b);
char *ConvertStringToChar(std::string a);
std::string convertCharToString(char *a);
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
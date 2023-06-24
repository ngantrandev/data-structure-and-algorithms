#pragma once
#include<iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <string.h>
#include "./console_function.h"

void ShowProgramName(int x_program_name, int y_program_name, int sleep_time);
void Show_Loading_Time(int x = 59, int y = 8);
void ShowMessage(int x_origin, int y_origin, std::string message, int duration);
void Show_Error(int error_code);

void showCourceList(int tabx, int taby, int tabw, int tabh);
void showStudentList(int tabx, int taby, int tabh);
void showCreditClassList(int tabx, int taby, int tabw, int tabh);
void showCreditClassStatus(int tabx, int taby, int tabw, int tabh);
void showPointList(int tabx, int taby, int tabw, int tabh);
void drawBox(int x, int y, int w, int h);
void drawScoreBoard(int tabx, int taby, int tabw, int tabh);
void vebangtongketdiem(int x, int y, int step, int soSV, int so_mon_hoc, std::string maMH[1000]);

void clearScreen(int x_origin, int y_origin, int width, int height);

int XacNhan(int x_origin, int y_origin, std::string title, std::string luachon_1, std::string luachon_2);

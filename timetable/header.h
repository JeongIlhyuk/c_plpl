#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

const int hoursNum = 10;
const int daysNum = 5;

const string dayNames[daysNum] = {"MON", "TUE", "WED", "THU", "FRI"};

bool showCurriculum();
bool showGrade();

#endif
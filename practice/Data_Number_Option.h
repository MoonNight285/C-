#pragma once
#include<list>
#include<vector>
using std::list;
using std::vector;

void data_New_Save(list<vector<char>>* data, vector<char>* temp, vector<int>* data_count);
int data_Number_Count(list<vector<char>>* data, vector<char>* temp);
void data_Number_Count_Plus(list<vector<char>>* data, vector<char>* temp, vector<int>* data_count, int* max);
/*
Benjamin Stanton
CSCI 2421-001 Thomas Augustine Phd
1/25/2018
*/
#ifndef RANDOMINTARRAY_H
#define RANDOMINTARRAY_H

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class RandomIntArray
{
public:
	RandomIntArray();
	
	RandomIntArray(int range, int size);

	int compare_vectors(vector<int> user_vector);

	void set_values(int range, int size);

	vector<int> get_values();

	int get_size();

	friend ostream& operator << (ostream& out, RandomIntArray& in);

private:

	vector<int> int_array;

};

#endif // !RANDOMINTARRAY_H

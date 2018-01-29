/*
Benjamin Stanton
CSCI 2421-001 Thomas Augustine Phd
1/25/2018
*/
#include "RandomIntArray.h"


//default constructor
RandomIntArray::RandomIntArray()
{
	
	srand(time(NULL));

}

//parameterized constructor
RandomIntArray::RandomIntArray(int range, int size)
{
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		int_array.push_back((rand() % range)+1);
	}
}

//comparison function
int RandomIntArray::compare_vectors(vector<int> user_vector)
{
	int matches = 0;

	for (int i = 0; i < user_vector.size(); i++)
	{
		for (int j = 0; j < int_array.size(); j++)
		{
			if (int_array[i] == user_vector[j])
			{
				matches++;

				continue;
			}
		}

	}

	return matches;
}

//explicit mutator
void RandomIntArray::set_values(int range, int size)
{
	for (int i = 0; i > size; i++)
	{
		int_array.push_back((rand() % (range + 1)));
	}
}

//assesor
vector<int> RandomIntArray::get_values()
{
	return int_array;
}

//assesor for the private data field metadata
int RandomIntArray::get_size()
{
	return int_array.size();
}

/*------------------------------------Friends---------------------------------------*/

//output stream operator

ostream& operator << (ostream& out, RandomIntArray& in)
{
	for (int i = 0; i < in.get_size(); i++)
	{
		out << in.int_array[i] << " ";
	}

	return out;
}
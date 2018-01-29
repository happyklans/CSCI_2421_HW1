/*
Benjamin Stanton
CSCI 2421-001 Thomas Augustine Phd
1/25/2018
*/

#include <iostream>
#include <vector>
#include <string>
#include "RandomIntArray.h"

using namespace std;


int main()
{

	string size_input_check;
	
	string range_input_check;

	string user_input;

	string play_again;

	int size = 0;

	int range = 0;

	int matches = 0;

	bool kill_loop = false;

	bool is_good_input = false;

	bool bad_input = false;

	vector<int> user_guesses;

	
	

	while (kill_loop == false)
	{

		while (is_good_input == false)
		{
			cout << "Enter the number of integers you would like to guess: ";

			cin >> size_input_check;

			for (int i = 0; i < size_input_check.size(); i++)
			{
				if (isdigit(size_input_check[i]))
				{
					is_good_input = true;
				}
				else
				{
					cout << "That is not a valid number. Please try again." << endl;

					is_good_input = false;

					break;
				}
			}

			if (is_good_input)
			{
				size = stoi(size_input_check);
			}
		}

		is_good_input = false;

		while (is_good_input == false)
		{
			cout << "Enter the upper bound of the integers: ";

			cin >> range_input_check;

			for (int i = 0; i < range_input_check.size(); i++)
			{
				if (isdigit(range_input_check[i]))
				{
					is_good_input = true;
				}
				else
				{
					cout << "That is not a valid number. Please try again." << endl;

					is_good_input = false;

					break;
				}
			}

			if (is_good_input)
			{
				range = stoi(range_input_check);
			}

		}

		is_good_input = false;

		RandomIntArray guess_target(range, size);

		cout << "Enter your guesses for the " << size << " integers in the range from 1 to " << range << ":" << endl;

		while (true)
		{

			while (is_good_input == false)
			{
				for (int i = 0; i < size; i++)
				{
					cin >> user_input;

					for (int i = 0; i < user_input.size(); i++)
					{
						if (isdigit(user_input[i]) == false)
						{
							bad_input = true;
						}
						else
						{
							user_guesses.push_back(stoi(user_input));
						}

						if (bad_input)
						{
							user_guesses.clear();

							cout << "One or more of the numbers you entered is not an integer. Please try again:" << endl;

							cin.ignore(numeric_limits<streamsize>::max(), '\n');

							break;
						}
					}

					if (bad_input)
					{
						i = -1;

						bad_input = false;
					}
				}

				if (bad_input == false)
				{
					is_good_input = true;
				}
				else
				{
					bad_input = false;
				}
			}

			matches = guess_target.compare_vectors(user_guesses);
			
			if (matches == size)
			{
				cout << "You are correct! Play again? ";

				cin >> play_again;

				if (play_again == "No" || play_again == "NO" || play_again == "no")
				{
					kill_loop = true;

					break;
				}
				else if (play_again == "yes" || play_again == "YES" || play_again == "Yes")
				{
					kill_loop = false;

					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					is_good_input = false;

					break;
				}

			}
			
			else
			{
				cout << matches << " of your guesses are correct. Guess again" << endl;

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			
		}
		
	}
	
	

	return 0;

}
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctype.h>




using namespace std;
int main() {
	char DFA[100];

	string DFA_Result[100];

	int i = 0;
	int k = 0;
	int State = 0;
	string name;
	bool error = false;
	bool error2 = false;


	ofstream myfile2;
	ifstream myfile;


	//asking user for file name
	cout << "What is the name of the file you wish to open?" << endl;
	cin >> name;

	myfile.open(name);
	myfile2.open("DFA_Output.txt");

	if (myfile.is_open())
	{


		//scanning information from file into the DFA[i]
		while (myfile.get(DFA[i])) {
			i++;
		}



		myfile.close();
	}







	

	else myfile2 << "Unable to open file"; {

	}


	//loop for the DFA
	for (int j = 0; j < i; j++ ) {

		if (DFA[j] == ' ' || DFA[j] == '\t' || DFA[j] == '\n') {
			State = 1;
		}

		//if there is a / then we peak at the next member of the array, if its a * or an / then we ignore everything untill the end of the comment
		if (DFA[j] == '/') {

			if (DFA[j + 1] == '*') {
				while (DFA[j] != '*' || DFA[j + 1] != '/') {
					j++;
					State = 4;

				}
				j++;



			}
			 else if (DFA[j + 1] == '/') {
				while (DFA[j] != '\n') {
					j++;
					State = 3;
				}

			}
			else {
				DFA_Result[k] = "Div";
				State = 2;

				k++;
			}

		}
		//checks for ( 
		if (DFA[j] == '(') {
			State = 6;
			DFA_Result[k] = "Lparen";
			k++;

		}
		//checks for )
		if (DFA[j] == ')') {
			State = 7;
			DFA_Result[k] = "Rparen";
			k++;
		}
		// checks for +
		if (DFA[j] == '+') {
			State = 8;
			DFA_Result[k] = "Plus";
			k++;
		}

		//checks for -
		if (DFA[j] == '-') {
			State = 9;
			DFA_Result[k] = "Minus";
			k++;
		}

		//checks for *
		if (DFA[j] == '*') {
			State = 10;
			DFA_Result[k] = "Times";
			k++;
		}
		
		// checks for any number and also '.' ex 4.3, 3.1, .77
		// will also peak at the next item in the array untill the next value is not a number
		if ( isdigit(DFA[j]) || DFA[j] == '.') {
			

			if (j < i) {
				while (DFA[j] == '.' || isdigit(DFA[j] ) ) {

					j++;
					if (j >= i) {
						break;
					}


				}
			}
			
			DFA_Result[k] = "number";
			State = 14;
			k++;
		}
		if (DFA[j] == '.') {
			State = 13;
		}

		// checks for any letter and peaks to see if the next value is a letter or a number and stops when there isnt one
		if (j < i && isalpha(DFA[j])) {

			while (isdigit(DFA[j+1]) || isalpha(DFA[j + 1])) {
				State = 16;
				j++;
				if (j >= i) {
					break;
				}
			}
			if (DFA[j - 3] == 'r' &&  DFA[j - 2] == 'e' && DFA[j - 1] == 'a' && DFA[j] == 'd') {
				DFA_Result[k] = "read";
				k++;
			}
			else if (DFA[j - 4] == 'w' &&  DFA[j - 3] == 'r' && DFA[j - 2] == 'i' && DFA[j - 1] == 't' && DFA[j] == 'e') {
				DFA_Result[k] = "write";
				k++;
			}

			else {
				DFA_Result[k] = "Id";
				k++;

			}



		}
		//checks for : and peaks to see if the next value is =
		if (DFA[j] == ':' && DFA[j + 1] == '=') {
			State = 11;
			DFA_Result[k] = "Assign";
			k++;

		}
		if (DFA[j] == ' ' || DFA[j] == '\n') {

		}


		//checks to see if other tokens are in the file outside of the ones above. 
		//if there is one then it will return an error msg
		if (j < i) {
			if (DFA[j] != '.' && !isdigit(DFA[j]) && !isalpha(DFA[j]) && DFA[j] != '*' && DFA[j] != '/' && DFA[j] != '-' && DFA[j] != '+' && DFA[j] != '(' && DFA[j] != ')' && DFA[j] != ':' && DFA[j] != '=' && DFA[j] != ' ' && DFA[j] != '\n' && DFA[j] != '\t' && DFA[j] != '\r') {
				myfile2 << "ERROR Token in text file not allowed." << endl;
				error2 = true;
				break;
			}
		}

		
		



		







	}
	if (error2 == false) {


		myfile2 << "(";
		// prints the items 
		for (int h = 0; h < k; h++) {

			myfile2 << DFA_Result[h];
			if (h + 1 < k) {
				myfile2 << ", ";
			}
		}
		myfile2 << " )";
		myfile2 << endl << "the final state was " << State << endl;
	}
	


	
	return 0;
	
}
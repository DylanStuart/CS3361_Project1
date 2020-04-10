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
	bool error = false;
	bool error2 = false;


	ofstream myfile2;
	ifstream myfile;

	myfile.open("DFA.txt");
	myfile2.open("DFA_Output.txt");

	if (myfile.is_open())
	{



		while (myfile.get(DFA[i])) {
			i++;
		}



		myfile.close();
	}









	else myfile2 << "Unable to open file"; {

	}

	for (int j = 0; j < i; j++) {

		if (DFA[j] == ' ') {
			State = 1;
		}
		if (DFA[j] == '/') {

			if (DFA[j + 1] == '*') {
				while (DFA[j] != '*' || DFA[j + 1] != '/') {
					j++;

				}
				j++;



			}
			else if (DFA[j + 1] == '/') {
				while (DFA[j] != '\n') {
					j++;
				}

			}
			else {
				DFA_Result[k] = "Div";

				k++;
			}

		}
		if (DFA[j] == '(') {
			DFA_Result[k] = "Lparen";
			k++;

		}
		if (DFA[j] == ')') {
			DFA_Result[k] = "Rparen";
			k++;
		}
		if (DFA[j] == '+') {
			DFA_Result[k] = "Plus";
			k++;
		}

		if (DFA[j] == '-') {
			DFA_Result[k] = "Minus";
			k++;
		}

		if (DFA[j] == '*') {
			DFA_Result[k] = "Times";
			k++;
		}
		
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
			k++;
		}
		if (DFA[j] == '.') {
			
		}

		if (j < i && isalpha(DFA[j])) {
			while (j < i && isalpha(DFA[j + 1])) {
				j++;
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
		if (DFA[j] == ':' && DFA[j + 1] == '=') {
			DFA_Result[k] = "Assign";
			k++;

		}
		if (DFA[j] == ' ' || DFA[j] == '\n') {

		}

		if (j < i) {
			if (DFA[j] != '.' && !isdigit(DFA[j]) && !isalpha(DFA[j]) && DFA[j] != '*' && DFA[j] != '/' && DFA[j] != '-' && DFA[j] != '+' && DFA[j] != '(' && DFA[j] != ')' && DFA[j] != ':' && DFA[j] != '=' && DFA[j] != ' ' && DFA[j] != '\n' && DFA[j] != '\t') {
				myfile2 << "ERROR Token in text file not allowed." << endl;
				error2 = true;
				break;
			}
		}

		
		



		







	}
	if (error2 == false) {


		myfile2 << "(";

		for (int h = 0; h < k; h++) {

			myfile2 << DFA_Result[h];
			if (h + 1 < k) {
				myfile2 << ", ";
			}
		}
		myfile2 << " )";
	}
	


	
	return 0;
	
}
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctype.h>






using namespace std;
int main() {
	char DFA[100];
	string hold[50];
	char holdd[50];
	int Q = 0;


	string DFA_Result[100];
	string holder = "bob";
	string counter = "";

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
	myfile2.open("Parser_output.txt");

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
	for (int j = 0; j < i; j++) {

		if (DFA[j] == ' ' || DFA[j] == '\t' || DFA[j] == '\n') {
			State = 1;


		}

		//if there is a / then we peak at the next member of the array, if its a * or an / then we ignore everything untill the end of the comment
		if (DFA[j] == '/') {


			DFA_Result[k] = "mult_op";
			State = 2;
			hold[Q] = DFA[j];

			Q++;

			k++;
		}


		//checks for ( 
		if (DFA[j] == '(') {
			State = 6;
			DFA_Result[k] = "Lparen";
			hold[Q] = DFA[j];
			Q++;

			k++;

		}
		//checks for )
		if (DFA[j] == ')') {
			State = 7;
			DFA_Result[k] = "Rparen";
			hold[Q] = DFA[j];
			Q++;
			k++;
		}
		// checks for +
		if (DFA[j] == '+') {
			State = 8;
			DFA_Result[k] = "add_op";
			hold[Q] = DFA[j];
			Q++;
			k++;
		}

		//checks for -
		if (DFA[j] == '-') {
			State = 9;
			DFA_Result[k] = "add_op";
			hold[Q] = DFA[j];
			Q++;
			k++;
		}

		//checks for *
		if (DFA[j] == '*') {
			State = 10;
			DFA_Result[k] = "mult_op";
			hold[Q] = DFA[j];
			Q++;
			k++;
		}

		// checks for any number and also '.' ex 4.3, 3.1, .77
		// will also peak at the next item in the array untill the next value is not a number
		if (isdigit(DFA[j]) || DFA[j] == '.') {


			

			DFA_Result[k] = "number";
			State = 14;
			stringstream ss;
		
			hold[Q] = DFA[j];
		
		
		
			Q++;
			k++;
		}
		if (DFA[j] == '.') {
			State = 13;
		}

		// checks for any letter and peaks to see if the next value is a letter or a number and stops when there isnt one
		if (j < i && isalpha(DFA[j])) {

			while (isdigit(DFA[j + 1]) || isalpha(DFA[j + 1])) {
				State = 16;
				j++;
				if (j >= i) {
					break;
				}
			}
			if (DFA[j - 3] == 'r' && DFA[j - 2] == 'e' && DFA[j - 1] == 'a' && DFA[j] == 'd') {
				DFA_Result[k] = "read";
				hold[Q] = "read";
				Q++;
				k++;
			}
			else if (DFA[j - 4] == 'w' && DFA[j - 3] == 'r' && DFA[j - 2] == 'i' && DFA[j - 1] == 't' && DFA[j] == 'e') {
				DFA_Result[k] = "write";
				hold[Q] = "write";
				Q++;
				k++;
			}

			else {
				DFA_Result[k] = "Id";
				hold[Q] = DFA[j];
				
				Q++;
				k++;

			}



		}
		//checks for : and peaks to see if the next value is =
		if (DFA[j] == ':' && DFA[j + 1] == '=') {
			State = 11;
			DFA_Result[k] = "Assign";
			hold[Q] = ":=";
			Q++;
			k++;

		}
		if (DFA[j] == ' ' || DFA[j] == '\n') {

		}


		//checks to see if other tokens are in the file outside of the ones above. 
		//if there is one then it will return an error msg
		if (j < i) {
			if (DFA[j] != '.' && !isdigit(DFA[j]) && !isalpha(DFA[j]) && DFA[j] != '*' && DFA[j] != '/' && DFA[j] != '-' && DFA[j] != '+' && DFA[j] != '(' && DFA[j] != ')' && DFA[j] != ':' && DFA[j] != '=' && DFA[j] != ' ' && DFA[j] != '\n' && DFA[j] != '\t' && DFA[j] != '\r') {
				myfile2 << "ERROR Token in text file not allowed." << endl;
				cout << "TEST" << endl;
				error2 = true;
				break;
			}
		}














	}










	myfile2 << "\t <Program> " << endl;
	myfile2 << " \t \t <stmt_list>" << endl;
	myfile2 << " \t \t \t <stmt>" << endl;

	int j = 0;

	// this is the loop that does the parsing. its kinda janky. i wasnt sure how to do the indents so i just did it manually 
	if (DFA_Result[j] == "read" || DFA_Result[j] == "Id" || DFA_Result[j] == "write") {
		for ( j = 0; j < i; j++) {

			if (DFA_Result[j] == "read") {
				myfile2 << "\t \t \t \t <read>" << endl;
				myfile2 << "\t \t \t \t \t " << hold[j] << endl;
				myfile2 << "\t \t \t \t </read>" << endl;
				
				

			}
			if (DFA_Result[j] == "Id" && DFA_Result[j + 1] == "Assign") {
				myfile2 << "\t \t \t \t <id>" << endl;
				myfile2 << "\t \t \t \t \t " << hold[j] << endl;
				myfile2 << "\t \t \t \t </id>" << endl;
				j++;
				myfile2 << "\t \t \t \t <Assign>" << endl;
				myfile2 << "\t \t \t \t \t " << hold[j] << endl;
				myfile2 << "\t \t \t \t </Assign>" << endl;




			}
			if (DFA_Result[j] == "write") {
				myfile2 << "\t \t \t \t <read>" << endl;
				myfile2 << "\t \t \t \t \t " << hold[j] << endl;
				myfile2 << "\t \t \t \t </read>" << endl;

			}
			if (DFA_Result[j] == "Lparen") {
				myfile2 << "\t \t \t \t <Lparen>" << endl;
				myfile2 << "\t \t \t \t \t " << hold[j] << endl;
				myfile2 << "\t \t \t \t </Lparen>" << endl;
				j++;
				myfile2 << "\t \t \t \t <Number>" << endl;
				myfile2 << "\t \t \t \t \t " << hold[j] << endl;;
				myfile2 << "\t \t \t \t </Number>" << endl;
				j++;
				myfile2 << "\t \t \t \t <rparen>" << endl;
				myfile2 << "\t \t \t \t \t " << hold[j] << endl;
				myfile2 << "\t \t \t \t </rparen>" << endl;


			}
			if (DFA_Result[j] == "Id" && DFA_Result[j + 1] != "Assign") {
				myfile2 << "\t \t \t \t <id>" << endl;
				myfile2 << "\t \t \t \t \t " << hold[j] << endl;
				myfile2 << "\t \t \t \t </id>" << endl;

			}
			if (DFA_Result[j] == "add_op") {
				myfile2 << "\t \t \t \t <add_op>" << endl;
				myfile2 << "\t \t \t \t \t " << hold[j] << endl;
				myfile2 << "\t \t \t \t </add_op>" << endl;
			}

			if (DFA_Result[j] == "number") {
				myfile2 << "\t \t \t \t <Number>" << endl;
				myfile2 << "\t \t \t \t \t " << hold[j] << endl;;
				myfile2 << "\t \t \t \t </Number>" << endl;


			}


			if (DFA_Result[j] == "mult_op") {
				myfile2 << "\t \t \t \t <add_op>" << endl;
				myfile2 << "\t \t \t \t \t " << hold[j] << endl;
				myfile2 << "\t \t \t \t </add_op>" << endl;
			}


			

	
		



		}
	}
		myfile2 << " \t \t \t </stmt>" << endl;
		myfile2 << " \t \t </stmt_list>" << endl;
		myfile2 << "\t </Program> " << endl;


		return 0;

	}


	




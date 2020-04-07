#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctype.h>
// was trying to add the extra options to isdigit and was getting errors.
//its working for the exact data set that was provided in the project, however i'm pretty sure it will break if you change the DFA.txt file
//will try and file tune it.
// wasn't sure how to add spaces/newlines
//not sure if we should add what states is on?



using namespace std;
int main() {
	char DFA[60];
	
	string DFA_Result[30];
	
	int i = 0;
	int k = 0;
	int State = 0;
	 
	
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
		
		if (DFA[j] == '/') {
			
			if (DFA[j + 1] == '*') {
				while (DFA[j] != '*' || DFA[j + 1] != '/') {
					j++;
					
				}
				j++;
			
				
				
			}
			else if (DFA[j + 1] == '/') {
				while (DFA[j] != ' ') {
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
		if (j < i  && isdigit(DFA[j])) {
			while (j < i && isdigit(DFA[j]) ) {
				j++;
				
			}
		
			DFA_Result[k] = "Digit";
			k++;
		}

		if (j < i && isalpha(DFA[j])) {
			while (j < i && isalpha(DFA[j+1])) {
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
				DFA_Result[k] = "Letter";
				k++;

			}

			 
			
		}
		if (DFA[j] == ':' && DFA[j + 1] == '=') {
			DFA_Result[k] = "Assign";
			k++;
		}
		



		
		

	}
	myfile2 << "(";
	for (int h = 0; h < k; h++) {
		
		myfile2 << DFA_Result[h];
		if (h + 1 < k) {
			myfile2 << ", ";
		}
	}
	myfile2 << " )"; 

	


	
	return 0;
	
}
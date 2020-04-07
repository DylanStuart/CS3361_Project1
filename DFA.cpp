#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctype.h>

using namespace std;
int main() {
	char DFA[20];
	int count = 1;
	string DFA_Result[20];
	
	int i = 0;
	int k = 0;
	 
	
	ofstream myfile2;
	ifstream myfile;
	
	myfile.open("DFA.txt");
	myfile2.open("example.txt");
	
	if (myfile.is_open())
	{
		for(i=0; i<50; i++){
		
			
			myfile >> DFA[i];
		
		
		}
		myfile.close();
	}

	else myfile2 << "Unable to open file"; {

	}

	for (int j = 0; j < 20; j++) {
		
		if (DFA[j] == '/') {
			if (DFA[j + 1] == '*') {
				while (DFA[j] != '*' && DFA[j + 1] != '/') {
					j++;
					
				}
				j++;
				
				
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

		

		
		

	}

	for (int h = 0; h < k; h++) {
		myfile2 << DFA_Result[h] << endl;
	}


	
	return 0;
	
}

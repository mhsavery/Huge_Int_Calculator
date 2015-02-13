
#include "integer.h"

int main(){

	bool TrFalse;
	char response='y';
	int Length, space1, space2;
	string op1String, op2String, operation, equation;
	int op1Array[ARRAY] = {0};
	int op2Array[ARRAY] = {0};
	void test(bool TrFalse);
	void separateEquation(string oprString, int oprArray[]);

	cout << "------- Welcome to the huge integer calculator -------" << endl<< endl;
	
	do{

		cout << "\nEnter an equation" << endl;
		cout << "-----------------" << endl;
		
		// Commands to separate the equation into operands / operator
		getline(cin, equation);

		// length() returns the number of characters in a string
		Length = equation.length();
		space1 = equation.find(" ");
		space2 = equation.find(" ", space1+1);
		
		// substr returns a newly constructed string object with its value 
		// initialized to a copy of a substring of this object
		operation = equation.substr(space1+1, (space2-(space1+1)));
		
		// Number 1
		op1String = equation.substr(0,space1);
		separateEquation(op1String, op1Array);
		HugeInteger op1 = op1Array;
		
		// Number 2
		op2String = equation.substr(space2+1, Length-(space2+1));
		separateEquation(op2String, op2Array);
		HugeInteger op2 = op2Array;		
				

		if(operation == "+"){
			HugeInteger sum = op1.addition(op2);
			sum.output();
		}else
		if(operation == "*"){
			HugeInteger product = op1.multiply(op2);
			product.output();
		}else
		if(operation == "<="){
			TrFalse = op1.lessEqual(op2);
			test(TrFalse);
		}else
		if(operation == ">="){
			TrFalse = op1.greatEqual(op2);
			test(TrFalse);
		}else
		if(operation == "!="){
			TrFalse = op1.notEqual(op2);
			test(TrFalse);
		}else
		if(operation == "=="){
			TrFalse = op1.isEqual(op2);
			test(TrFalse);
		}	

	}while(response == 'Y'|| response == 'y');
}

// Function to test if equality operators are true or false
void test(bool TrFalse){

	if(TrFalse == true){
		cout << "True." << endl;
	}else{
		cout << "False." << endl;
	}
}

// Function to separate equation into op1 op op2 form
void separateEquation(string oprString, int oprArray[]){

	int length = oprString.length();

	// c_str returns a pointer to an array that contains a sequence of characters
	// atoi converts the string to ints	
	for(int i=(length-1), j=(ARRAY-1); i>=0; i--, j--){
		string entry = oprString.substr(i,1);
		const char *oprCharArray = entry.c_str();
		oprArray[j] = atoi(oprCharArray);
	}
}

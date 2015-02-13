#include "integer.h"

//******* Constructors *******
HugeInteger::HugeInteger(){

	for(int i=0; i <ARRAY; ++i){
		number[i]=0;
	}
}

HugeInteger::HugeInteger(int operand[]){

	for(int i=0; i<ARRAY; ++i){
		number[i]=operand[i];
	}
}


//****** Input / Output Functions ******
void HugeInteger::input(int operand[]){

	for(int i=0; i<ARRAY; i++){
		number[i] = operand[i];
	}	
}
		
void HugeInteger::output(){

	int i=0;

	while(number[i] == 0 && i<(ARRAY-1)){
		i++;
	}

	while(i<ARRAY){
		cout << number[i];
		i++;
	}
	cout << endl;
}

//****** Addition / Subtraction Operator Overloaded Functions *******
HugeInteger HugeInteger::operator+(HugeInteger op2){

	int result;
	HugeInteger addition;

	for(int i=ARRAY-1; i>=0; i--){
		result = number[i] + op2.number[i];		
		addition.number[i] = result %10;
	}
	return addition;
}

HugeInteger HugeInteger::operator*(HugeInteger op2){

	int result;
	int carry[ARRAY] = {0};
	HugeInteger product;

	for(int i=ARRAY-1; i>=0; i--){
		int k=i;
		int carry[ARRAY] = {0};
		for(int j=ARRAY-1; j>=0; j--){
			result = (number[j] * op2.number[i]) + carry[j];
			product.number[k] += result %10;
			carry[(j-1)] = result /10;
			k--;
		}
	}
	return product;
}


//******* Ostream / istream Operators *******
ostream operator<<(ostream& out, const HugeInteger& a){

	int i=0;

	while(a.number[i] == 0 && i<(ARRAY-1)){
		i++;
	}

	while(i<ARRAY){
		out << a.number[i];
		i++;
	}
	out << endl;
}
	
istream operator>>(istream& in, HugeInteger& a){

	for(int i=0; i<ARRAY; i++){
		a.number[i];
	}
}


//******* Normal Member Functions *******
HugeInteger HugeInteger::addition(HugeInteger op2){

	int result;
	int carry[ARRAY] = {0};
	HugeInteger addition;

	for(int i=ARRAY-1; i>0; i--){
		int j=i-1;
		result = number[i] + op2.number[i] + carry[i];
		carry[j] = result /10;
		addition.number[i] = result %10;
	}
	return addition;
}

HugeInteger HugeInteger::multiply(HugeInteger op2){

	int result;
	int carry[ARRAY] = {0};
	HugeInteger product;

	for(int i=ARRAY-1; i>=0; i--){
		int k=i;
		int carry[ARRAY] = {0};
		for(int j=ARRAY-1; j>=0; j--){
			result = (number[j]*op2.number[i]) + carry[j];
			product.number[k] += result %10;
			carry[(j-1)] = result /10;
			k--;
		}
	}
	return product;
}

bool HugeInteger::isEqual(HugeInteger op2){

	int i=0;

	while(number[i] == op2.number[i]){
		i++;
	}
	if(i>=ARRAY){
		return true;
	}else{
		return false;
	}
}

bool HugeInteger::notEqual(HugeInteger op2){

	int i=0;
	int oper1=0;
	int oper2=0;

	while(number[oper1]==0){
		oper1++;
	}

	while(op2.number[oper2]==0){
		oper2++;
	}

	if(oper1 != oper2){
		return true;
	}else{
		while(number[i]==op2.number[i] && i<ARRAY){
			i++;
		}

		if(i>=ARRAY){
			return false;
		}else{
			return true;
		}
	}
}

bool HugeInteger::greatEqual(HugeInteger op2){

	int i=0;
	int oper1=0;
	int oper2=0;

	while(number[oper1]==0){
		oper1++;
	}

	while(op2.number[oper2]==0){
		oper2++;
	}

	if(oper1 < oper2){
		return true;
	}else
	if(oper1 > oper2){
		return false;
	}else{
		while(number[i]==op2.number[i] && i<ARRAY){
			i++;
		}

		if(number[i] > op2.number[i] || i>=ARRAY){
			return true;
		}else{
			return false;
		}
	}
}

bool HugeInteger::lessEqual(HugeInteger op2){

	int i=0;
	int oper1=0;
	int oper2=0;

	while(number[oper1]==0){
		oper1++;
	}

	while(op2.number[oper2]==0){
		oper2++;
	}

	if(oper1 > oper2){
		return true;
	}else
	if(oper1 < oper2){
		return false;
	}else{
		while(number[i]==op2.number[i] && i<ARRAY){
			i++;
		}

		if(number[i] < op2.number[i] || i>=ARRAY){
			return true;
		}else{
			return false;
		}
	}	
}

bool HugeInteger::isZero(){

	int i=0;

	while(number[i] == 0 && i<ARRAY){
		i++;
	}

	if(i==ARRAY){
		return true;
	}else{
		return false;
	}
}

// ******* Operator Overloaded Bool Functions *******
bool HugeInteger::operator==(HugeInteger op2){

	int i=0;

	while(number[1] == op2.number[i]){
		i++;
	}
	if(i>=ARRAY){
		return true;
	}else{
		return false;
	}
}

bool HugeInteger::operator!=(HugeInteger op2){

	int i=0;
	int oper1=0;
	int oper2=0;

	while(number[oper1]==0){
		oper1++;
	}

	while(op2.number[oper2]==0){
		oper2++;
	}

	if(oper1 != oper2){
		return true;
	}else{
		while(number[i]==op2.number[i] && i<ARRAY){
			i++;
		}

		if(i>=ARRAY){
			return false;
		}else{
			return true;
		}
	}
}

bool HugeInteger::operator>=(HugeInteger op2){

	int i=0;
	int oper1=0;
	int oper2=0;

	while(number[oper1]==0){
		oper1++;
	}

	while(op2.number[oper2]==0){
		oper2++;
	}

	if(oper1 < oper2){
		return true;
	}else
	if(oper1 > oper2){
		return false;
	}else{
		while(number[i]==op2.number[i] && i<ARRAY){
			i++;
		}

		if(number[i] > op2.number[i] || i>=ARRAY){
			return true;
		}else{
			return false;
		}
	}
}

bool HugeInteger::operator<=(HugeInteger op2){

	int i=0;
	int oper1=0;
	int oper2=0;

	while(number[oper1]==0){
		oper1++;
	}

	while(op2.number[oper2]==0){
		oper2++;
	}

	if(oper1 > oper2){
		return true;
	}else
	if(oper1 < oper2){
		return false;
	}else{
		while(number[i]==op2.number[i] && i<ARRAY){
			i++;
		}
		if(number[i] < op2.number[i] || i>=ARRAY){
			return true;
		}else{
			return false;
		}
	}
}

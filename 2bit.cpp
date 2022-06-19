#include <iostream>
#include <cstring>

using namespace std;

char calc_sum(char, char, char);
char calc_carry(char, char, char);
uint input_and_verify_int();
string input_and_verify_str(string, uint);
bool check_if_binary(string);

int main(){
	cout << "Hint: e.g. \"01\" is a 2-bit string" << endl;
	cout << "-------------------------------------" << endl;

	uint bit_num = input_and_verify_int();	
	string str_A = input_and_verify_str("A", bit_num);
	string str_B = input_and_verify_str("B", bit_num);

	char arr_A[bit_num+1], arr_B[bit_num+1];
	strcpy(arr_A, str_A.c_str());
	strcpy(arr_B, str_B.c_str());

	char arr_sum[bit_num+1];
	char arr_carry[bit_num+1+1];
	arr_sum[bit_num] = arr_carry[bit_num+1] = '\0';
	arr_carry[bit_num] = '0';

	for(uint i = bit_num; i > 0; i--){
		arr_sum[i-1] = calc_sum(arr_A[i-1], arr_B[i-1], arr_carry[i]);
		arr_carry[i-1] = calc_carry(arr_A[i-1], arr_B[i-1], arr_carry[i]);
	}

	cout << "\n********** TABLE **********" << endl;
	cout << ' ' << str_A << " (";
	for(uint i=1; i<= bit_num; i++) cout << 'A'+to_string(i)+'_';
	cout << ")\n";
	cout << '+' << str_B << " (";
	for(uint i=1; i<= bit_num; i++) cout << 'B'+to_string(i)+'_';
	cout << ")\n";
	for(uint i=0; i< bit_num+1; i++) cout << '-';
	cout << "\n " << string(arr_sum) + " (Sum)\n";
	cout << string(arr_carry) + " (Carry_IN)\n\n";

	return 0;
}


char calc_sum(char a, char b, char carry_in){
	int val_a = atoi(&a);
	int val_b = atoi(&b);
	int val_carry_in = atoi(&carry_in);

	int a_b_or = ((!val_a)&val_b) | ((!val_b)&val_a);
	int sum = ((!a_b_or) & val_carry_in) | ((!val_carry_in) & a_b_or);

	return '0'+sum;
}


char calc_carry(char a, char b, char carry_in){
	int val_a = atoi(&a);
	int val_b = atoi(&b);
	int val_carry_in = atoi(&carry_in);

	int a_b_or = ((!val_a)&val_b) | ((!val_b)&val_a);
	int val_carry_out = (val_a&val_b) | (val_carry_in&a_b_or);

	return '0'+val_carry_out;
}


uint input_and_verify_int(){
	uint val;
	while(1){
		cout << "How many bits: ";
		cin >> val;
		if (val < 1){
			cout << "Invalid input, try again.." << endl;
		}else{
			return val;
		}
	}
}

string input_and_verify_str(string port, uint bits){
	string str;
	while(1){
		cout << "Please enter " << bits << "-bit string " << port << ": ";
		cin >> str;
		if (str.length() != bits){
			cout << "The length is incorrect.." << endl;
		}else{
			if(check_if_binary(str)){
				return str;
			}else{
				cout << "Binary must be 0 or 1.." << endl;
			}
		}
	}
}

bool check_if_binary(string str){
	for(uint i=0; i<str.length(); i++){
		if(str[i] != '0' && str[i] != '1'){
			return false;
		}
	}
	return true;
}


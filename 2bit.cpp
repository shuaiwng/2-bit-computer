#include <iostream>

using namespace std;

unsigned int bit_num;
string str_A;
string str_B;

char calc_sum(char, char, char);
char calc_carry(char, char, char);

int main(){
	cout << "Hint: e.g. \"01\" is a 2-bit string" << endl;
	cout << "-------------------------------------" << endl;
	cout << "How many bits: ";
	cin >> bit_num;
	cout << "Please enter " << bit_num << "-bit string A: ";
	cin >> str_A;
	cout << "Please enter " << bit_num << "-bit string B: ";
	cin >> str_B;

	char sum_arr[bit_num];
	char carry_arr[bit_num+1];
	carry_arr[bit_num] = '0';

	for(int i = bit_num-1; i >= 0; i--){
		sum_arr[i] = calc_sum(str_A.c_str()[i], str_B.c_str()[i], carry_arr[i+1]);
		carry_arr[i] = calc_carry(str_A[i], str_B[i], carry_arr[i+1]);
	}

	string str_sum(sum_arr);
	string str_carry(carry_arr);

	cout << ' ' << str_sum << "=> Sum" <<endl;
	cout << str_carry << "=> Carry" <<endl;

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




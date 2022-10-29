/*
Author: Anita Prova
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 2
The program fixes the formatting of a file. It makes it so that each line only accepts a certain amount of characters. 
*/

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

string add_spaces(int c, int w) {
	string str;
	for(int i = c; i < w; i++) {
		str += " ";
	}
	return str;
}

void set_width(string input_name) {
	ifstream in_file;
	in_file.open(input_name);
	
	string int_line;
	getline(in_file, int_line, ';');
	int width = stoi(int_line);

	string output_name;
	getline(in_file, output_name, ';');
	
	ofstream out_file;
	out_file.open(output_name);

	string junk;
	getline(in_file, junk);
	
	int count = 0;
	string line;
	while(getline(in_file, line)) { //getting each line 
		stringstream s(line);
		string word;
		string arr[line.length()];
		int j = 0;
		while (s >> word) {
			arr[j] = word; //put each word into array
			j++;
			cout << word << " ";
		}
		
		for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {	
			if(arr[i].length() + count + 1 < width) {
				out_file << arr[i] << " ";
				count += arr[i].length() + 1;
			}
			else {
				out_file << add_spaces(count, width) << "\n" << arr[i] << " ";
				count = 0;
				count += arr[i].length() + 1;
			}
			
			if (i == sizeof(arr)/sizeof(arr[0]) - 1 && count + arr[i].length() < width){
				out_file << add_spaces(count, width) << "\n";
				count = 0;
			}
		}
	}

}

int main() {
	string file_name;
	cout << "Enter the input filename: ";
	cin >> file_name;
	set_width(file_name);	

	return 0;
}

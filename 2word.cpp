/*
Author: Anita Prova
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 2
The program fixes the formatting of a file. It makes it so that each line only accepts a certain amount of characters. 
*/

#include <iostream>
#include <sstream>
#include<string>
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
		while(s >> word) { //getting each word
			if(word.length() + count + 1 < width) {
				out_file << word << " ";
				count += word.length() + 1;
			}
			else {
				out_file << add_spaces(count, width) << "\n" << word << " ";
				count = 0;
				count += word.length() + 1;
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

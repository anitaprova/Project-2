/*
Author: Anita Prova
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 2
The program fixes the formatting of a file. It makes it so that each line only accepts a certain amount of characters. 
*/

#include <iostream>
#include <string> 
#include <fstream>
#include <cctype>

using namespace std;

string add_spaces(int c, int w) {
	string str;
	for(int i = c; i < w - 1; i++) {
		str += " ";
	}
	return str;
}

void set_width(string input_name){
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
	bool new_line = false;
	while(getline(in_file, line)) {
		string word = "";
		for (int i = 0; i < line.length(); i++) {
			if (line[line.length() - 1] == ' ') { //no space at the end = new line
				new_line = false;
			}
			else {new_line = true;}

			if (!isspace(line[i])) { //makes the word
				word += line[i];
				if (i == line.length() - 1) { //contains last word in a line
					if ((count + word.length() ) < width) {
						out_file << word << " ";
						count += word.length() + 1;
					}
					else {
						out_file << add_spaces(count, width) << "\n" << word << " ";
						count = 0;
						count += word.length() + 1;
					}
					if (new_line == true) {
						out_file << add_spaces(count, width) << "\n";
						count = 0;
					}
				}
			}
			else {
				if ((count + word.length() + 1 ) < width) {
					out_file << word << " ";
					count += word.length() + 1;
				}
				else if ((count + word.length() ) < width) {
					out_file << word;
					count += word.length();	
				}
				else { 
					out_file << add_spaces(count, width) << "\n" << word << " ";
					count = 0;
					count += word.length() + 1;	
				}
				word = "";
			}
		}	
		if (line.length() == 0) {
			count = 0;
			out_file << "\n";
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

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

int num_line(string filename) { //total lines in a file
	ifstream in_file;
	in_file.open(filename);
	
	int count = 0;
	string line;
	while (getline(in_file, line)) {
		count++;
	}
	return count - 1;
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
	int line_count = 0;
	string line;
	string leftover;
	string output;
	while(getline(in_file, line)) { //getting each line 
		line_count++;
		if (line.length() == 0) {
				output += "\n\n";
				count = 0;
		} 
		else { 
			
		stringstream s(line);
		string word;
		while (s >> word) {
			if (leftover.length() + count + word.length() + 1 < width) {
				output += word + " ";
				count += word.length() + 1;
			}
			else if (leftover.length() + count + word.length() < width) {
				output += word;
				count += word.length();
			}
			else { // too big
				leftover += word + " ";
			}
		}

		if (line_count != num_line(input_name) && count + leftover.length() < width && leftover.length() == 0) { //if nothing else on the line, new line
			output += "\n";
			count = 0;
		}
		
		if (count + leftover.length() > width) { //if it overflows then new line
			output += "\n";
			count = 0;
		}

		if (leftover.length() < width) {
			output += leftover;
			count += leftover.length();
			leftover = "";
		}
		else { //if leftover becomes too big
			stringstream s2(leftover);
			string str;
			while (s2 >> str) {
				if(count + str.length() + 1 < width) {
					output += str + " ";
					count += str.length() + 1;
				}
				else if (count + str.length() < width) {
					output += str;
					count += str.length();
				}
				else {
					output += "\n";
					count = 0;
					output += str + " ";
					count += str.length() + 1;
				}
			}
			leftover = "";
		}
		}
	} //end of getline
	out_file << output;
}

bool isCap(string str) {
	bool bol =  true;
	for (int i = 0; i < str.length(); i++) {
		if(str[i] >= 'A' && str[i] <= 'Z') {
			bol = false;
		}	
	}
	
	return bol;
} 

void justify(string input_file) {
	ifstream in_file;
	in_file.open(input_file);

	string width;
	getline(in_file, width, ';');

	string body;
	getline(in_file, width, ';');

	string header;
	getline(in_file, width, ';');
	
	string output_name;
	getline(in_file, output_name, ';');
	
	//if()


}

int main() {
	string file_name;
	cout << "Enter the input filename: ";
	cin >> file_name;
	set_width(file_name);
	//set_width("input.txt");
	//set_width("input3.txt");

	return 0;
}

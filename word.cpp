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

void set_width(string input_name) {
	ifstream in_file;
        in_file.open(input_name);

        ofstream out_file;
        out_file.open("output.txt");

	string int_line;
        getline(in_file, int_line, ';');
        int width = stoi(int_line);

        string output_name;
        getline(in_file, output_name, ';');
	
	string junk;
        getline(in_file, junk);
	
	string line;
	string array[100];
	int index = 0;
	int capacity = 0;
	while(getline(in_file, line)) { //puts all the words into an array
		string word;
		for (int i = 0; i < line.length(); i++) {
			if (isspace(line[i])) {
				array[index] = word;
				index++;
				capacity++;
				word = "";
			}
			else {
				word += line[i];
			}	
		}
		if (line.length() == 0) {
			array[index] = "NEW LINE";
			index++;
			capacity++;
		}
		array[index] = word;
		index++;
		capacity++;
	}

	int count = 0;
	for(int i = 0; i < capacity; i++) { //putting it all together
		string str = array[i];
		if (str == "NEW LINE") {
			out_file << "\n\n";
			count = 0;
			i++;	
		}
		str = array[i];
		if (str == "") {
                        i++;
                }
		str = array[i];
		
		if ( (count + str.length() + 1) < width) {
			out_file << str << " ";
			count += str.length() + 1;
		}
		else {
                        out_file << "\n" << str << " ";
                        count = str.length() + 1;
                }
		
                if (str[str.length() - 1] == '?') {
                	count = 0;
                	out_file << "\n";
                }
	}
}

int main() {
	set_width("input.txt");

	return 0;
}

/*void set_width(string input_name){
	ifstream in_file;
        in_file.open(input_name);
	
	ofstream out_file;
	out_file.open("output.txt");
	
	string int_line;
	getline(in_file, int_line, ';');
	int width = stoi(int_line);

	string output_name;
	getline(in_file, output_name, ';');

	string junk;
	getline(in_file, junk);

	int count = 0;
	string line;
	while(getline(in_file, line)) {
		string word;
		for (int i = 0; i < line.length(); i++) {
			if (isspace(line[i])) {
				if ((count + word.length() ) < width) {
					out_file << word << " ";
					count += word.length() + 1;
				}
				else {
					count = 0;
					out_file << "\n" << word << " ";
					count += word.length() + 1;
				}

				if (word[word.length() - 1] == '?') {
                        		count = 0;
					out_file << "\n";
                		}
				word = "";
			}
			else {
				word += line[i];
			}
		}

		out_file << word << " "; //end word

		if (word[word.length() - 1] == '?') {
			count = 0;
			out_file << "\n";
		}
		
		if (line.length() == 0) { //paragraphs
			count = 0;
			out_file << "\n\n";
		}
	}
}

int main() {
	string file_name;
	cout << "Enter the input filename: ";
	cin >> file_name;
	set_width(file_name);

	return 0;
}*/

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

long mystoi(const char s)
{
    long i;
    i = 0;
    if(s >= '0' && s <= '9')
    {
        i = i * 10 + (s - '0');
    }
    return i;
}

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
	
	string int_line; //check if each part is an int 
	getline(in_file, int_line, ';');
	int width = 0;
	int tens = 0;
	int ones = 0;
	for (int i = 0; i < int_line.length(); i++) {
		if (isdigit(int_line[i]) == true) {
			ones = mystoi(int_line[i]);
		}
	}
	tens = mystoi(int_line[0]);
	width = tens * 10 + ones;
	//cout << width;
	
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
	bool prev = false;
	while(getline(in_file, line)) { //getting each line 
		line_count++;
		if (line.length() == 0) {
				if (prev == false) {
					output += "\n\n";
					count = 0;
				}
				else {
					output += "\n";
					count = 0;
					prev = false;
				}
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
			prev = true;
		}
		
		if (count + leftover.length() > width) { //if it overflows then new line
			output += "\n";
			count = 0;
			prev = false;
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

void set_width(string input_name, string temp, int width) {
        ifstream in_file;
        in_file.open(input_name);

        ofstream out_file;
        out_file.open(temp);

	string junk;
	getline(in_file, junk);

        int count = 0;
        int line_count = 0;
        string line;
        string leftover;
        string output;
        bool prev = false;
        while(getline(in_file, line)) { //getting each line
                line_count++;
                if (line.length() == 0) {
                                if (prev == false) {
                                        output += "\n\n";
                                        count = 0;
                                }
                                else {
                                        output += "\n";
                                        count = 0;
                                        prev = false;
                                }
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
                        prev = true;
                }

                if (count + leftover.length() > width) { //if it overflows then new line
                        output += "\n";
                        count = 0;
                        prev = false;
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

bool isCap(string str) { //checks if string is all caps
	for (int i = 0; i < str.length(); i++) {
		if(str[i] < 'A' || str[i] > 'Z') {
			return false;
		}	
	}

	return true;
}

string right(string line, int w){
        string s = "";
        for(int i = 0; i < w-line.length(); i++) {
                s += " ";
        }
        s += line;
        
	return s;
}

string left(string line, int w) {
        return line;
}

string center(string line, int w) { //need to fix
        string s = "";
        for(int i = 0; i < (w-line.length())/2; i++) {
                s += " ";
        }
        s += line;

        return s;
}

void justify(string input_file) {
	ifstream in_file;
	in_file.open(input_file);
	
	string int_line;
	getline(in_file, int_line, ';');
	int width;
	int tens = 0;
        int ones = 0;
        for (int i = 0; i < int_line.length(); i++) {
                if (isdigit(int_line[i]) == true) {
                        ones = mystoi(int_line[i]);
                }
        }
        tens = mystoi(int_line[0]);
        width = tens * 10 + ones;
	
	string body;
	getline(in_file, body, ';');

	string header;
	getline(in_file, header, ';');

	string output_name;
        getline(in_file, output_name, ';');

	set_width(input_file, "tempfile", width);
	ifstream temp;
	temp.open("tempfile"); //should contain the set_width stuff now
	
	ofstream out_file;
	out_file.open(output_name);
	string output;

	string line;
	while(getline(temp, line)) {
		if(isCap(line) == true) { //header alert
			if(header == "left") {
				output += left(line, width);
			}
			else if(header == "right") {
				output += right(line, width);
			}
			else if(header == "center") {
				output += center(line, width);
			}
		}
		else { //body
			if(body == "left") {
                                output += left(line, width);
                        }
                        else if(body == "right") {
                                output += right(line, width);
                        }
                        else if(body == "center") {
                                output += center(line, width);
                        }
		}
		output += "\n";
	}
	out_file << output;
}

int main() {
	string file_name;
	cout << "Enter the input filename: ";
	cin >> file_name;
	//set_width(file_name);
	//justify("input.txt");
	justify(file_name);

	return 0;
}

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <optional>
#include "argparse.hpp"

using namespace std;

class WordGenerator {
private:

	char* m_filename;
	void test_vector(vector<string> vec) {
		cout << "[";
		for(auto &i: vec) {
			cout << i << " ";
		} cout << "]\n";
	}

	char* parse_file_name_from_arg(int argc, char** argv) {
		argparse::ArgumentParser program("tty-type-test");
		program.add_argument("-w", "wordlist")
			.help("Path to file containing the words")
			.required();
		return nullptr;
	}

public:
 		vector<string> read_words(char* filename) {

		ifstream infile;
		infile.open(this -> m_filename, ios::in);

		string word;
		vector<string> words;

		while(!infile.eof()) {
			getline(infile, word);
			if(word.size() > 0) {
				words.push_back(word);
			}
		}
		// test_vector(words);
		return words;
	}
};

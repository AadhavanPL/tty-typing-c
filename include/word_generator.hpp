#pragma once
#include <random>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "argparse.hpp"

using namespace std;
using uint = unsigned int;

class TypeTest{
private:

	
	string wordlist_path;
	
	void print_vector(const vector<string>& str_vec) const {
		for(auto &i: str_vec) {
			cout << i << endl;
		}
	}
	
	string parse_file_path_from_arg(int argc, char** argv) {
		argparse::ArgumentParser options("tty-typing");
		options.add_argument("-w", "--wordlist")
			.help("Path to wordlist")
			.required();
		try {
			options.parse_args(argc, argv);
		} 
		catch (const std::runtime_error& err) {
			cerr << "Error: " << err.what() << endl;
			exit(1);
		}
		string word_list_path = options.get<string>("--wordlist");
		return word_list_path;
	}

	vector<string> read_words_from_list() {
		string word;
		ifstream wordlist_file;
		wordlist_file.open(this -> wordlist_path);
		vector<string> words;

		while(wordlist_file >> word) {
			words.push_back(word);
		}
		cout << "ALL WORDS" << endl;
		print_vector(words);
		return words;
	}

	vector<string> generate_random_words(vector<string> all_words, uint num_words) {
		random_device rnd;
		mt19937 rng(rnd());
		uniform_int_distribution<uint> rnums(0, all_words.size()-1);
		vector<string> random_words;
		for(uint i = 0; i < num_words; ++i) {
			random_words.push_back(all_words[rnums(rng)]);
		}
		cout << "RANDOM WORDS" << endl;
		print_vector(random_words);
		return random_words;
	}

public:
	void initialize(int argc, char** argv) {
		this -> wordlist_path = parse_file_path_from_arg(argc, argv);
		vector<string> all_words = read_words_from_list();
		generate_random_words(all_words, 25);
	}
};

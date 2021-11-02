#pragma once
#include "argparse.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>

using namespace std;
using uint = unsigned int;

class word_generator{
private:

	string m_wordlist_path;
	vector<string> m_wordlist_words;
	uint m_wordcount;

	void print_vector(const vector<string>& str_vec) const {
		for(auto &i: str_vec) {
			cout << i << endl;
		}
	}

	void parse_cli_args(int argc, char** argv) {
		argparse::ArgumentParser options("tty-typing");
		options.add_argument("-w", "--wordlist")
			.help("Path to wordlist")
			.required();
		options.add_argument("-c", "--wordcount")
			.help("Mention the number of words to be used (default 25)")
			.default_value(25);
		try {
			options.parse_args(argc, argv);
		}
		catch (const std::runtime_error& err) {
			cerr << "Error: " << err.what() << endl;
			exit(1);
		}
		string word_list_path = options.get<string>("--wordlist");
		uint wordcount = options.get<int>("--wordcount");
		this -> m_wordlist_path = word_list_path;
		this -> m_wordcount = wordcount;
	}

	void read_words_from_wordlist() {
		string word;
		ifstream wordlist_file;
		wordlist_file.open(this -> m_wordlist_path);
		vector<string> words;

		while(wordlist_file >> word) {
			words.push_back(word);
		}
		this -> m_wordlist_words = words;
	}


public:
	void initialize(int argc, char** argv) {
		parse_cli_args(argc, argv);
		read_words_from_wordlist();
		parse_cli_args(argc, argv);
		// print_vector(this -> m_wordlist_words);
	}

	uint get_num_words() {
		return this -> m_wordcount;
	}

	vector<string> get_all_words() {
		return this -> m_wordlist_words;
	}

	vector<string> generate_random_words() {
		random_device rnd;
		mt19937 rng(rnd());
		uniform_int_distribution<uint> rnums(0, (this -> m_wordlist_words).size()-1);
		vector<string> random_words;
		for(uint i = 0; i < m_wordcount; ++i) {
			random_words.push_back((this -> m_wordlist_words)[rnums(rng)]);
		}
		// print_vector(random_words);
		return random_words;
	}
};

#pragma once

#include "word_generator.hpp"
#include <curses.h>
#include <iostream>

class display {
public:
    void run(int argc, char** argv) {
        word_generator wg;
        wg.initialize(argc, argv);
        vector<string> randwords = wg.generate_random_words();

        initscr();
        noecho();
        for(auto &i: randwords) {
            printw("%s ", i.data());
        }
        getch();
        getch();
        endwin();
    }
};

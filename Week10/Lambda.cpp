#define _CRT_SECURE_NO_WARNINGS


// the CommandManager class should implement a mini terminal that receive commands and dispatches them.
// example: copy a.jpg b.jpg
// this will search the map for a "copy" command, and if it finds it, it will invoke its callback with a vector made of {"a.jpg", "b.jpg"}
// no global variables allowed

#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <vector>
#include <fstream>
#include <algorithm>
#include <filesystem>

using namespace std;

class CommandManager {
private:
    map<string, function <void(vector<string>)>> commands;
    int timess = 0;
public:
    void add(string name, function<void(vector<string>)> fn);

    // run shall read a line from stdin in a loop, split it by whitespaces.
    // the first word will be the command name. if no word has been found, it will do nothing
    // then it will search the map for the name, and it will invoke the callback if it founds it
    // or it will show a message if it can't find it
    // the args for the callback will not contain the command name
    // if the `stop` command is found, the function will return
    // try doing this yourself; if you spent too much time on this, look at https://gist.github.com/rzaharia/0e155df56a3a81d5383f00d838c97a99
    void run();
    int getTimes() { return timess; };
};

void CommandManager::add(string name, function<void(vector<string>)> fn) {
    commands[name] = fn;
}

void CommandManager::run() {
    string tmp;
    vector<string> args;

    while (true) {
        printf("Enter command: ");
        std::getline(std::cin, tmp);
        if (tmp == "stop") {
            return;
        }

        args.clear();
        auto ptr = strtok(&tmp[0], " ");
        while (ptr) {
            args.push_back(ptr);
            ptr = strtok(nullptr, " ");
        }

        if (args.empty()) {
            // empty command, doing nothing
            continue;
        }

        auto it = commands.find(args[0]);
        if (args[0] == "times")
            timess++;
        if (it == commands.end()) {
            printf("no command with that name!\n");
            continue;
        }

        // remove the command name
        args.erase(args.begin());

        it->second(args);
    }
}

int main() {
    CommandManager manager;
    // number_of_errors represents the number of IO errors (eg. file errors) that happened in the commands
    // this is only relevant for the append and copy commands
    unsigned number_of_errors = 0;

    // prints pong!
    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);

    // prints the number of arguments it received
    // `count a b c` -> will print `counted 3 args`

    auto count = [](vector<string> args) {  printf("counted %d args \n", args.size() ); };
    manager.add("count", count);

    // the first argument will be treated as a file name
    // the rest of the arguments will be appended to that file with a space as delimiter
    // remember to count the errors, if any
    auto append = [](vector<string> args) { ofstream f(args[0]); for (int i = 1; i < args.size(); i++) { f << args[i]; f << " "; } f.close(); };
    manager.add("append", append);
    
    // will print the number of times the command was called
    // do not capture any reference for this lambda
    auto times = [&manager](vector<string> args) { printf("The command was called %d times\n", manager.getTimes() ); };
    manager.add("times", times);

    // copy a file; args[0] will provide the source, and args[1] the destination
    // make sure it works with binary files (test it with an image)
    // remember to count the errors, if any
    auto copy = [](vector<string> args) { filesystem::copy_file(args[0], args[1]); };
    manager.add("copy", copy);

    // will sort the arguments by size
    // `sort_size abc a 1234` -> will print `a abc 1234`
    // use std::sort with a lambda comparator to sort
    // and std::for_each with a lambda to print afterwards

    auto sort_size = [](vector<string> args) { sort(args.begin(), args.end(), [](const string& a, const string& b) {return a.size() < b.size(); }); for_each(args.begin(), args.end(), [](const string& var) { cout << var << ' '; }); cout << endl;  };
    manager.add("sort_size", sort_size);

    // add one more command of anything you'd like

    auto count_even_words = [](vector<string> args) {int c = 0; for_each(args.begin(), args.end(), [&c](const string& var) { if (var.size() % 2 == 0) c++;  }); cout << c << endl; };
    manager.add("count_even_words", count_even_words);
   
    manager.run();

    printf("number of errors: %u\ndone!\n", number_of_errors);
    return 0;
}
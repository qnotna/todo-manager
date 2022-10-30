#include <vector>

#include "../Command/Command.hpp"
#include "../Todo/Todo.hpp"

#ifndef MANAGER_H
#define MANAGER

class Manager {
public: 
    Manager(std::vector<Command> commands);
    ~Manager();

    bool get_is_running();
    bool get_needs_clean();

    void run();

    void print_todos();
    void print_title();
private:
    std::vector<Command> commands;
    std::vector<Todo> todos;
    bool is_running;
    bool needs_clean;

    bool add_todo();
    bool toggle_todo();
    void print_commands();
    void retry();
};

#endif
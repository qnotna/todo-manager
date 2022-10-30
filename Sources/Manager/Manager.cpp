#include <iostream>
#include <vector>

#include "Manager.hpp"
#include "../Command/Command.hpp"
#include "../Todo/Todo.hpp"

Manager::Manager(std::vector<Command> commands): commands(commands), todos(), is_running(true) {}

Manager::~Manager() = default;

bool Manager::get_is_running() {
    return this->is_running;
}

bool Manager::get_needs_clean() {
    return this->needs_clean;
}

void Manager::run() {
    char input;
    std::cin >> input;
    std::cin.clear();
    std::cin.ignore();

    this->needs_clean = true;

    for (Command command: this->commands) {
        if (command.get_invocation_character() == input) {
            switch (command.get_type()) {
            case Command::ADD_WITH_DESCRIPTION:
                add_todo();
                return;
            case Command::TOGGLE_BY_ID:
                toggle_todo();
                return;
            // case Command::REMOVE_COMPLETED:
            //     return;
            case Command::QUIT:
                this->is_running = false;
                return;
            }
        }
    }
    print_commands();
    this->needs_clean = false;
}

// MARK: - Actions

bool Manager::add_todo() { 
    std::string description_input;
    std::cout << "> " << "Add todo with description:" << " ";
    std::getline(std::cin, description_input);
    todos.push_back(Todo(description_input));
    // TODO: Check for existing duplicate descriptions
    return true;
}

bool Manager::toggle_todo() {
    int id_input;
    std::cout << "> " << "Mark todo as completed by id:" << " ";
    std::cin >> id_input;
    for (Todo &todo: todos) {
        if (id_input == todo.get_id().get_raw_value()) {
            todo.toggle_is_completed();
            return true;
        }
    }
    std::cout << "> " << "No todo with id" << " " << id_input << std::endl;
    return false;
}

void Manager::print_commands() {
    std::cout << "> " << "Available commands:" << std::endl;
    for (Command command: this->commands) {
        std::cout << " " << command.get_description() << std::endl;
    }
}

void Manager::retry() {
    std::cout << "> " << "Received unrecognized command, try again:" << " ";
}

void Manager::print_todos() {
    if (this->todos.empty()) {
        std::cout << "> " << "No todos yet." << std::endl;
    } else {
        for (Todo todo: this->todos) {
            std::cout 
                << " "
                << todo.get_id().get_raw_value() << " | " 
                << todo.get_description() << " | " 
                << todo.get_is_completed_description() << std::endl; // TODO: Format table
        }
    }
}

void Manager::print_title() {
    std::string welcome_text = "Todo Manager";
    std::string version_number_string = "v0.0.1"; // TODO: Use arguments from make file to create version number
    std::cout  << welcome_text << " " << version_number_string << std::endl;
}

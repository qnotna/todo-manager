#include <string>
#include "Command.hpp"

Command::Command(Command::Type type): type(type) {}

Command::~Command() = default;

char Command::get_invocation_character() {
    switch (this->type) {
    case Command::ADD_WITH_DESCRIPTION:
        return 'a';
    case Command::TOGGLE_BY_ID:
        return 'c';
    case Command::REMOVE_COMPLETED:
        return 'r';
    case Command::PRINT_HELP:
        return 'h';
    case Command::QUIT:
        return 'q';
    }
}

std::string Command::get_description() {
    switch (this->type) {
    case Command::ADD_WITH_DESCRIPTION:
        return "[a]dd todo.";
    case Command::TOGGLE_BY_ID:
        return "toggle [c]ompleted status.";
    case Command::REMOVE_COMPLETED:
        return "[r]emove completed todos.";
    case Command::PRINT_HELP:
        return "show [h]elp.";
    case Command::QUIT:
        return "[q]uit todo manager.";
    }
}

Command::Type Command::get_type() {
    return this->type;
}
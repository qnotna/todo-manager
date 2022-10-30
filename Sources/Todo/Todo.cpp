#include <string>

#include "Todo.hpp"
#include "../ID/ID.hpp"

Todo::Todo(std::string description) {
    this->id = ID();
    this->description = description;
    this->is_completed = false;
}

Todo::~Todo() = default;

ID Todo::get_id() {
    return id;
}

std::string Todo::get_description() {
    return description;
}

bool Todo::get_is_completed() {
    return is_completed;
}

void Todo::toggle_is_completed() {
    this->is_completed = !this->is_completed;
}

std::string Todo::get_is_completed_description() {
    return is_completed ? "Completed." : "Not completed.";
}

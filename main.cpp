// TODO: Add serialization to persistent storage

#include <iostream>
#include <string>
#include <list>
#include <ctime>

/// A item that is created by the user as a reminder to complete it.
class Todo { // TODO: Separate files for different types
private: 
    /// The id of the item.
    int id; // TODO: ID-Type for Todo
    /// The description of the item that is set by the user.
    std::string description;
    /// Whether the item has been completed.
    bool is_completed;
public:
    Todo(std::string description) {
        this->id = rand() % 100 + 1;
        this->description = description;
        this->is_completed = false;
    }
    ~Todo() = default;

    int get_id() {
        return id;
    }

    std::string get_description() {
        return description;
    }

    bool get_is_completed() {
        return is_completed;
    }

    void toggle_is_completed() {
        this->is_completed = this->is_completed ? false : true;
    }

    std::string get_is_completed_description() {
        return is_completed ? "Completed." : "Not completed.";
    }
};

void print_greeting() {
    std::string welcome_text = "Todo Manager";
    std::string version_number_string = "v0.0.1"; // TODO: Use arguments from make file to create version number
    std::cout  << welcome_text << " " << version_number_string << std::endl;
}

void print_todos(std::list<Todo> todos) {
    if (todos.empty()) {
        std::cout << "> " << "No todos yet." << std::endl;
    } else {
        for (Todo todo: todos) {
            std::cout 
                << " "
                << todo.get_id() << " | " 
                << todo.get_description() << " | " 
                << todo.get_is_completed_description() << std::endl; // TODO: Format table
        }
    }
}

void add_todo(std::list<Todo> &todos) { // TODO: Check for existing duplicate descriptions
    // std::cin.clear();
    // std::cin.ignore();
    std::string description_input;
    std::cout << "> " << "Add todo with description:" << " ";
    std::getline(std::cin, description_input);
    todos.push_back(Todo(description_input));
}

void toggle_todo(std::list<Todo> &todos) {
    int id_input;
    std::cout << "> " << "Mark todo as completed by id:" << " ";
    std::cin >> id_input;
    for (Todo &todo: todos) {
        if (id_input == todo.get_id()) {
            todo.toggle_is_completed();
            return;
        }
    }
    std::cout << "> " << "No todo with id" << " " << id_input << std::endl;
}

void print_commands() { // TODO: Create enum type for commands
    std::cout 
        << "> " << "Available commands:" << std::endl
        << " " << "[a]dd todo" << std::endl
        << " " << "[t]oggle todo completed status" << std::endl
        // << " " << "[r]emove completed" << std::endl
        // << " " << "[h]elp" << std::endl
        << " " << "[q]uit" << std::endl;
}

void quit() {
    std::cout << "> " << "Going to sleep." << std::endl;
}

void retry() {
    std::cout << "> " << "Received unrecognized command, try again:" << " ";
}

int main() {
    // Reset seed for random id generation.
    srand(time(NULL)); // TODO: Make this part of Todo::ID

    std::list<Todo> todos;

    while(true) {
        // Reset console content
        system("clear");
        print_greeting();
        print_todos(todos);

        char input;
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore();

        switch (input) {
            case 'a':
                add_todo(todos);
                break;
            case 't':
                toggle_todo(todos);
                break;
            // case 'h':
            //     print_commands();
            //     break;
            case 'q':
                quit();
                return 0;
            default: 
                // retry();
                break;
        }
        // TODO: Allow holding the loop to await new input.
    }
    return 0;
}
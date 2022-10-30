#include <string>

#ifndef COMMAND_H
#define COMMAND_H

/// A command for user input.
class Command {
public:
    /// Enumeration of all kinds of commands.
    enum Type {
        ADD_WITH_DESCRIPTION,
        TOGGLE_BY_ID,
        REMOVE_COMPLETED,
        PRINT_HELP,
        QUIT
    };

    Command(Type type);
    ~Command();

    /// Get the character that was used to invoke the command.
    char get_invocation_character();

    /// Get the human readable command description.
    std::string get_description();

    Type get_type();

private:
    /// The command type.
    Type type;
};

#endif
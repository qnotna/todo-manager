#include "../ID/ID.hpp"

#ifndef TODO_H
#define TODO_H

/// An item that is created by the user as a reminder to complete it.
class Todo {
public:
    Todo(std::string description);
    ~Todo();

    ID get_id();
    std::string get_description();
    bool get_is_completed();

    /// Negates the current completion status.
    void toggle_is_completed();

    /// The string representation of the todo's completion status.
    std::string get_is_completed_description();

private: 
    /// The id of the item.
    ID id;
    /// The description of the item that is set by the user.
    std::string description;
    /// Whether the item has been completed.
    bool is_completed;
};

#endif

// TODO: Make equatable
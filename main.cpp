// TODO: Add serialization to persistent storage

#include <vector>

#include "Sources/Command/Command.hpp"
#include "Sources/Manager/Manager.hpp"
#include "Sources/ID/ID.hpp"

int main() {
    ID::seed();

    Manager manager = Manager({
        Command(Command::Type::ADD_WITH_DESCRIPTION),
        Command(Command::Type::TOGGLE_BY_ID),
        Command(Command::Type::REMOVE_COMPLETED),
        Command(Command::Type::PRINT_HELP),
        Command(Command::Type::QUIT)
    });

    system("clear");
    while(manager.get_is_running()) {
        if (manager.get_needs_clean()) {
            system("clear");
            manager.print_title();
            manager.print_todos();
        }
        manager.run();
    }
    return 0;
}

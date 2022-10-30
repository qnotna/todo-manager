# MARK: - Run

output: main.o Todo.o ID.o Command.o Manager.o
	g++ -std=c++11 main.o Todo.o ID.o Command.o Manager.o -o todo

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

# MARK: - Sources

Todo.o: Sources/Todo/Todo.cpp
	g++ -std=c++11 -c Sources/Todo/Todo.cpp

ID.o: Sources/ID/ID.cpp
	g++ -std=c++11 -c Sources/ID/ID.cpp

Command.o: Sources/Command/Command.cpp
	g++ -std=c++11 -c Sources/Command/Command.cpp

Manager.o: Sources/Manager/Manager.cpp
	g++ -std=c++11 -c Sources/Manager/Manager.cpp

# MARK: - Other commands

clean:
	rm *.o todo
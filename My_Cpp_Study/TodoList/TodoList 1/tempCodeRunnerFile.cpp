#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct Task {
    std::string text;
    bool done;
};

void viewTasks(const std::vector<Task> &todos);
void printInvalidMessage();
void saveTasks(const std::vector<Task> &todos);
void loadTasks(std::vector<Task> &todos);

int main(){

    std::vector<Task> todos;
    loadTasks(todos);
    int choice;
    int inputNumber;

    do{
        std::cout << "\n===TODO list===\n";
        std::cout << "1. Add task\n";
        std::cout << "2. View task\n";
        std::cout << "3. Mark task as done\n";
        std::cout << "4. Delete task\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose: ";
        std::cin >> choice;
        std::cin.ignore();

        if(choice == 1){
            Task task;
            std::cout << "===Add Task===\n";
            std::getline(std::cin, task.text);
            task.done = false;

            todos.push_back(task);
            saveTasks(todos);
        }
        else if(choice == 2){
            if(todos.empty()){
                printInvalidMessage();
            }
            else{
                viewTasks(todos);
            }
        }
        else if(choice == 3){
            if(todos.empty()){
                printInvalidMessage();
            }
            else{
                std::cout << "Enter the number that you want to mark as done: ";
                std::cin >> inputNumber;
                if(inputNumber >= 1 && inputNumber <= todos.size()){
                    todos[inputNumber - 1].done = true;
                    std::cout << "===Updated Tasks===\n";
                    viewTasks(todos);
                    saveTasks(todos);
                }
                else{
                    printInvalidMessage();
                }

            }
        }
        else if(choice == 4){
            if(todos.empty()){
                printInvalidMessage();
            }
            else{
                std::cout << "Enter the number that you want to delete: ";
                std::cin >> inputNumber;
                if(inputNumber >= 1 && inputNumber <= todos.size()){
                    todos.erase(todos.begin() + inputNumber - 1);
                    std::cout << "===Updated List===\n";
                    viewTasks(todos);
                    saveTasks(todos);
                }
                else{
                    printInvalidMessage();
                }
            }
        }

    }while(choice != 5);

    std::cout << "===Thank you for using===\n";

    return 0;
}

void viewTasks(const std::vector<Task> &todos){
    for(int i = 0; i < todos.size(); i++){
        std::cout << i + 1 << ". " << todos[i].text << "[" << todos[i].done << "]\n";
    }
}
void printInvalidMessage(){
    std::cout << "Invalid\n";
}
void saveTasks(const std::vector<Task> &todos){
    std::ofstream file("todo.txt");

    for(const Task &task : todos){
        file << task.text << "|" << task.done << "\n";
    }
}
void loadTasks(std::vector<Task> &todos){
    std::ifstream file("todo.txt");
    std::string line;

    while(std::getline(file, line)){
        size_t pos = line.find('|');

        if(pos != std::string::npos){
            Task task;
            task.text = line.substr(0, pos);
            task.done = (line.substr(pos + 1) == "1");
            todos.push_back(task);
        }
    }
}
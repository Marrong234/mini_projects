#include <iostream>
#include <string>

int main(){

    std::string todos[100];
    bool done[100] = {false};
    int count = 0;
    int size = sizeof(todos)/sizeof(todos[0]);
    int choice;

    do{
        std::cout << "===TODO list===\n";
        std::cout << "1. Add task\n";
        std::cout << "2. View task\n";
        std::cout << "3. Mark task as done\n";
        std::cout << "4. Exit\n";
        std::cin >> choice;
        std::cin.ignore();

        if(choice == 1){
            if(count >= size){
                std::cout << "Task is full.\n";
                continue;
            }

            std::cout << "===Add Things===\n";
            std::getline(std::cin, todos[count]);
            count++;
        }
        else if(choice == 2){
            if(count == 0){
                std::cout << "No tasks yet.\n";
            }
            else{
                std::cout << "--------\n";
                for(int i = 0; i < count; i++){
                std::cout << i + 1 << ". " << todos[i] << " [" << done[i] << "]\n";
                }
            }
        }
        else if(choice == 3){
            if(count == 0){
                std::cout << "No tasks yet.\n";
                continue;
            }
            else{
                std::cout << "===Your current list===\n";

                for(int i = 0; i < count; i++){
                    std::cout << i + 1 << ". " << todos[i] << "\n";
                }

                std::cout << "What are you done?: ";
                int doneNumber;
                std::cin >> doneNumber;

                if(doneNumber >= 1 && doneNumber <= count){
                    done[doneNumber - 1] = true;
                    std::cout << "===Updated list===\n";
                    std::cout << "===1 means done, 0 means not done===\n";
                    for(int i = 0; i < count; i++){
                        std::cout << todos[i] << " " << done[i] << "\n";
                    }
                }
                else{
                    std::cout << "Invalid task number\n";
                }
            }
        }

        
    }while(choice != 4);

    std::cout << "===Thank you for using===\n";

    return 0;
}
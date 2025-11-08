#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void loadTasks(vector<string>& tasks) {
    ifstream file("tasks.txt");
    string task;
    while (getline(file, task)) {
        if (!task.empty()) {
            tasks.push_back(task);
        }
    }
    file.close();
}

void saveTasks(const vector<string>& tasks) {
    ofstream file("tasks.txt");
    for (const string& task : tasks) {
        file << task << endl;
    }
    file.close();
}

void displayTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks! Add one to get started." << endl;
        return;
    }
    cout << "\n===== YOUR TO-DO LIST =====" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

int main() {
    vector<string> tasks;
    int choice;
    string task;
    int taskNum;
    
    loadTasks(tasks);
    
    while (true) {
        cout << "\n1. View Tasks" << endl;
        cout << "2. Add Task" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                displayTasks(tasks);
                break;
                
            case 2:
                cout << "Enter task: ";
                getline(cin, task);
                if (!task.empty()) {
                    tasks.push_back(task);
                    saveTasks(tasks);
                    cout << "Task added successfully!" << endl;
                }
                break;
                
            case 3:
                displayTasks(tasks);
                if (!tasks.empty()) {
                    cout << "Enter task number to delete: ";
                    cin >> taskNum;
                    if (taskNum > 0 && taskNum <= tasks.size()) {
                        tasks.erase(tasks.begin() + taskNum - 1);
                        saveTasks(tasks);
                        cout << "Task deleted successfully!" << endl;
                    } else {
                        cout << "Invalid task number!" << endl;
                    }
                }
                break;
                
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
                
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}

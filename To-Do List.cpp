#include <iostream>
#include <string>

using namespace std;

class Task
{
public:
    string description;
    bool completed;

    Task(const string &desc) : description(desc), completed(false) {}

    void markCompleted()
    {
        completed = true;
    }
};

class TodoList
{
private:
    static const int maxTasks = 100;
    Task *tasks[maxTasks];
    int size;

public:
    TodoList() : size(0) {}

    void addTask(const string &description)
    {
        if (size < maxTasks)
        {
            tasks[size] = new Task(description);
            size++;
            cout << "Task added: " << description << endl;
        }
        else
        {
            cout << "Todo list is full. Cannot add more tasks." << endl;
        }
    }

    void viewTasks()
    {
        cout << "Tasks:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << (i + 1) << ". ";
            if (tasks[i]->completed)
            {
                cout << "[X] ";
            }
            else
            {
                cout << "[ ] ";
            }
            cout << tasks[i]->description << endl;
        }
    }

    void markTaskAsCompleted(int taskIndex)
    {
        if (taskIndex >= 0 && taskIndex < size)
        {
            tasks[taskIndex]->markCompleted();
            cout << "Task marked as completed: " << tasks[taskIndex]->description << endl;
        }
        else
        {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(int taskIndex)
    {
        if (taskIndex >= 0 && taskIndex < size)
        {
            delete tasks[taskIndex];
            for (int i = taskIndex; i < size - 1; i++)
            {
                tasks[i] = tasks[i + 1];
            }
            size--;
            cout << "Task removed." << endl;
        }
        else
        {
            cout << "Invalid task index." << endl;
        }
    }

    ~TodoList()
    {
        for (int i = 0; i < size; i++)
        {
            delete tasks[i];
        }
    }
};

int main()
{
    TodoList todoList;

    while (true)
    {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore(); // Clear newline from the buffer

        switch (choice)
        {
        case 1:
        {
            cout << "Enter task description: ";
            string description;
            getline(cin, description);
            todoList.addTask(description);
            break;
        }
        case 2:
        {
            todoList.viewTasks();
            break;
        }
        case 3:
        {
            cout << "Enter the task index to mark as completed: ";
            int taskIndex;
            cin >> taskIndex;
            todoList.markTaskAsCompleted(taskIndex - 1); // Subtract 1 to match array index
            break;
        }
        case 4:
        {
            cout << "Enter the task index to remove: ";
            int taskIndex;
            cin >> taskIndex;
            todoList.removeTask(taskIndex - 1); // Subtract 1 to match array index
            break;
        }
        case 5:
        {
            cout << "Exiting the program." << endl;
            return 0;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

    return 0;
}

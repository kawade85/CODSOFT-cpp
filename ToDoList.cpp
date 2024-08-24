#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task                                  //In C++, we use a structure called Task to represent each task,
                                        //with a string for the task description and a boolean to indicate if it's done.
{
    string task;
    bool done;
};

void addTask(vector<Task> & tasks)      //vector<Task> is used to manage the list of tasks.
{
    int n_tasks;
    cout << "How many tasks do you want to add: ";
    cin >> n_tasks;
    cin.ignore();      // To ignore the newline character left in the buffer

    for (int i = 0; i < n_tasks; ++i)
    {
        Task newTask;
        cout << "Enter the task: ";
        getline(cin, newTask.task);
        newTask.done = false;
        tasks.push_back(newTask);
        cout << "Task added!" << endl;
    }
}

void showTasks(const vector<Task>& tasks)
{
    cout << "\nTasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        string status = tasks[i].done ? "Done" : "Not Done";
        cout << (i + 1) << ". " << tasks[i].task << " - " << status << endl;
    }
}

void markTaskAsDone(vector<Task>& tasks)
{
    int task_index;
    cout << "Enter the task number to mark as done: ";
    cin >> task_index;
    cin.ignore();         // To ignore the newline character left in the buffer

    if (task_index > 0 && task_index <= tasks.size())
    {
        tasks[task_index - 1].done = true;
        cout << "Task marked as done!" << endl;
    }
    else
    {
        cout << "Invalid task number." << endl;
    }
}

void removeTask(vector<Task>& tasks)
{
    int task_index;
    cout << "Enter the task number to remove: ";
    cin >> task_index;
    cin.ignore();         // To ignore the newline character left in the buffer

    if (task_index > 0 && task_index <= tasks.size())
    {
        tasks.erase(tasks.begin() + task_index - 1);
        cout << "Task removed!" << endl;
    }
    else
    {
        cout << "Invalid task number!" << endl;
    }
}


int main()
{
    vector<Task> tasks;
    string choice;

    while (true)
    {
        cout << "\n===== To-Do List =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Show Tasks" << endl;
        cout << "3. Mark Task as Done" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        cout << "\n\nEnter your choice: ";
        getline(cin, choice);

        if (choice == "1")
        {
            addTask(tasks);
        }
        else if (choice == "2")
        {
            showTasks(tasks);
        }
        else if (choice == "3")
        {
            markTaskAsDone(tasks);
        }
        else if (choice == "4")
        {
            removeTask(tasks);
        }
        else if (choice == "5")
        {
            cout << "Exiting the To-Do List." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

//The code is divided into functions() to handle different operations: addTask, showTasks, and markTaskAsDone.

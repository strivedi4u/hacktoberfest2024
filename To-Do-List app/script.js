// Get elements from the DOM
const taskInput = document.getElementById('task-input');
const addTaskButton = document.getElementById('add-task-button');
const taskList = document.getElementById('task-list');

// Function to add a new task
function addTask() {
    const taskText = taskInput.value.trim();

    // If the input is not empty
    if (taskText !== '') {
        const taskItem = document.createElement('li');
        taskItem.innerText = taskText;

        // Create complete and delete buttons
        const completeButton = document.createElement('button');
        completeButton.innerText = 'Complete';
        completeButton.classList.add('complete-button');
        completeButton.onclick = function () {
            taskItem.classList.toggle('completed');
        };

        const deleteButton = document.createElement('button');
        deleteButton.innerText = 'Delete';
        deleteButton.classList.add('delete-button');
        deleteButton.onclick = function () {
            taskItem.remove();
        };

        // Append buttons to task item
        taskItem.appendChild(completeButton);
        taskItem.appendChild(deleteButton);

        // Add task to the task list
        taskList.appendChild(taskItem);

        // Clear the input
        taskInput.value = '';
    }
}

// Add event listener to the button
addTaskButton.addEventListener('click', addTask);

// Optionally, add a keypress event to add task with "Enter" key
taskInput.addEventListener('keypress', function (e) {
    if (e.key === 'Enter') {
        addTask();
    }
});

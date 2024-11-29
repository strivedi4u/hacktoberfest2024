import datetime
import json
import re
import os

# Global Data Stores
tasks = []
notes = {}
flashcards = {}

# Constants
DATA_FILE = 'data.json'

# Utility Functions
def save_data():
    """Saves tasks, notes, and flashcards to a JSON file."""
    with open(DATA_FILE, 'w') as f:
        json.dump({'tasks': tasks, 'notes': notes, 'flashcards': flashcards}, f)

def load_data():
    """Loads tasks, notes, and flashcards from a JSON file, handling file corruption."""
    global tasks, notes, flashcards
    try:
        if os.path.exists(DATA_FILE):
            with open(DATA_FILE, 'r') as f:
                data = json.load(f)
                tasks = data.get('tasks', [])
                notes = data.get('notes', {})
                flashcards = data.get('flashcards', {})
    except json.JSONDecodeError:
        print("Error: Corrupted data file.")

# Task Management
def add_task():
    task_name = input("Enter task name: ")
    due_date_str = input("Enter due date (YYYY-MM-DD): ")
    try:
        due_date = datetime.datetime.strptime(due_date_str, '%Y-%m-%d')
        tasks.append({"task": task_name, "due_date": due_date_str})
        print(f"Task '{task_name}' added with due date {due_date_str}.")
    except ValueError:
        print("Invalid date format. Please use YYYY-MM-DD.")

def display_tasks():
    print("\nTasks List:")
    if not tasks:
        print("No tasks available.")
    for i, task in enumerate(tasks):
        print(f"{i + 1}. {task['task']} - Due: {task['due_date']}")
    print()

def remove_task():
    display_tasks()
    try:
        task_number = int(input("Enter task number to remove: ")) - 1
        if 0 <= task_number < len(tasks):
            removed_task = tasks.pop(task_number)
            print(f"Removed task: {removed_task['task']}")
        else:
            print("Invalid task number.")
    except ValueError:
        print("Invalid input. Please enter a number.")

# Notes Management
def add_note():
    title = input("Enter note title: ")
    content = input("Enter note content: ")
    notes[title] = content
    print(f"Note '{title}' added.")

def display_notes():
    print("\nNotes List:")
    if not notes:
        print("No notes available.")
    for title in notes:
        print(f"Title: {title}")
        print(f"Content: {notes[title]}\n")
    print()

def remove_note():
    display_notes()
    title = input("Enter the title of the note to remove: ")
    if title in notes:
        del notes[title]
        print(f"Note '{title}' removed.")
    else:
        print("Note not found.")

def search_notes():
    query = input("Enter search term: ").lower()
    print("\nSearch Results:")
    for title, content in notes.items():
        if query in title.lower() or query in content.lower():
            print(f"Title: {title}")
            print(f"Content: {content}\n")
    print()

# Flashcards
def create_flashcards_from_notes():
    for title, content in notes.items():
        words = re.findall(r'\b\w+\b', content)
        for word in words:
            if word not in flashcards:
                flashcards[word] = []
            if (title, content) not in flashcards[word]:
                flashcards[word].append((title, content))
    print("Flashcards created from notes.")

def display_flashcards():
    print("\nFlashcards List:")
    if not flashcards:
        print("No flashcards available.")
    for term, entries in flashcards.items():
        print(f"Term: {term}")
        for title, content in entries:
            print(f"  From Note: {title}")
            print(f"  Content: {content}\n")
    print()

def quiz_with_flashcards():
    for term, entries in flashcards.items():
        print(f"Term: {term}")
        answer = input("Your answer: ").strip()
        if not answer:
            print("Skipping...")
            continue
        print("Entries containing the term:")
        for title, content in entries:
            print(f"  Note Title: {title}")
            print(f"  Content: {content}\n")
    print()

# Text Summarization
def summarize_text():
    title = input("Enter the title of the note to summarize: ")
    if title in notes:
        content = notes[title]
        summary = ' '.join(content.split()[:20]) + '...'
        print(f"Summary: {summary}")
    else:
        print("Note not found.")

# Study Material Recommendations
study_materials = {
    "Python": ["https://docs.python.org/3/", "https://www.learnpython.org/"],
    "Data Science": ["https://www.datacamp.com/", "https://www.kaggle.com/"],
    "Machine Learning": ["https://www.coursera.org/learn/machine-learning", "https://www.deeplearning.ai/"],
    "Cyber Security": ["https://www.udemy.com/topic/cyber-security/", "https://www.pluralsight.com/courses/cyber-security-awareness"],
}

def recommend_study_material():
    topic = input("Enter the topic you want resources for: ")
    if topic in study_materials:
        print(f"Recommended resources for {topic}:")
        for resource in study_materials[topic]:
            print(resource)
    else:
        print("No recommendations available for this topic.")

# Main Menu
def main_menu():
    load_data()
    try:
        while True:
            print("\nSmart Study Assistant")
            print("1. Task Management")
            print("2. Notes Management")
            print("3. Flashcards")
            print("4. Text Summarization")
            print("5. Study Material Recommendations")
            print("6. Exit")
            choice = input("Enter your choice: ")

            if choice == "1":
                print("\nTask Management")
                print("1. Add Task")
                print("2. Display Tasks")
                print("3. Remove Task")
                task_choice = input("Enter your choice: ")
                if task_choice == "1":
                    add_task()
                elif task_choice == "2":
                    display_tasks()
                elif task_choice == "3":
                    remove_task()
                save_data()

            elif choice == "2":
                print("\nNotes Management")
                print("1. Add Note")
                print("2. Display Notes")
                print("3. Remove Note")
                print("4. Search Notes")
                note_choice = input("Enter your choice: ")
                if note_choice == "1":
                    add_note()
                elif note_choice == "2":
                    display_notes()
                elif note_choice == "3":
                    remove_note()
                elif note_choice == "4":
                    search_notes()
                save_data()

            elif choice == "3":
                print("\nFlashcards")
                print("1. Create Flashcards from Notes")
                print("2. Display Flashcards")
                print("3. Quiz with Flashcards")
                flashcard_choice = input("Enter your choice: ")
                if flashcard_choice == "1":
                    create_flashcards_from_notes()
                elif flashcard_choice == "2":
                    display_flashcards()
                elif flashcard_choice == "3":
                    quiz_with_flashcards()
                save_data()

            elif choice == "4":
                summarize_text()

            elif choice == "5":
                recommend_study_material()

            elif choice == "6":
                print("Exiting... Have a productive day!")
                save_data()
                break

            else:
                print("Invalid choice. Please try again.")
    except KeyboardInterrupt:
        print("\nExiting and saving data...")
        save_data()
        exit()

# Run the main menu
if __name__ == "__main__":
    main_menu()

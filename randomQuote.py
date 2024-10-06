import random

subjects = ["The cat", "A programmer", "My teacher", "The universe", "The AI", "An artist", "A dreamer"]
verbs = ["writes", "paints", "sings", "analyzes", "creates", "contemplates", "dreams about"]
objects = ["endless code", "a masterpiece", "the stars", "life's mysteries", "the unknown", "infinity", "their purpose"]

def generate_quote():
    subject = random.choice(subjects)
    verb = random.choice(verbs)
    obj = random.choice(objects)
    return f"{subject} {verb} {obj}."

def main():
    print("Welcome to the Random Quote Generator!\n")
    while True:
        print(f"\nGenerated Quote: {generate_quote()}")
        user_input = input("\nDo you want another quote? (y/n): ").lower()
        if user_input == 'n':
            print("Thanks for using the Random Quote Generator!")
            break

if __name__ == "__main__":
    main()

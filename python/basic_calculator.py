def calculator():
    try:
        expression = input("Input: ")
        result = eval(expression)
        print("Output:", result)
    except Exception as e:
        print("Error:", e)

if __name__ == "__main__":
    calculator()

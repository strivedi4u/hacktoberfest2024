def calculator():
    # The try block contains code that might raise an exception.
    try:
        # Prompt the user to enter an expression.
        expression = input("Input: ")
        
        # Evaluate the expression using the eval() function.
        # This can be a security risk if user input is not trusted.
        result = eval(expression)
        
        # Print the result of the expression.
        print("Output:", result)
        
    # The except block catches any exceptions raised in the try block.
    except Exception as e:
        # Print the error message.
        print("Error:", e)

# The if __name__ == "__main__": block checks if the script is being run directly.
if __name__ == "__main__":
    # Call the calculator function.
    calculator()

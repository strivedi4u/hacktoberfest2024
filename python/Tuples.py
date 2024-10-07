def create_tuple_and_hash():
    # Read an integer input for the number of elements
    try:
        n = int(input("Enter the number of elements: "))
        
        # Read the space-separated integers and convert to a tuple
        integer_list = tuple(map(int, input(f"Enter {n} integers: ").split()))
        
        # Check if the number of inputs matches n
        if len(integer_list) != n:
            raise ValueError(f"Expected {n} integers but got {len(integer_list)}")
        
        # Print the hash of the tuple
        print("Hash:", hash(integer_list))

    except ValueError as e:
        print(f"Error: {e}")


if __name__ == '__main__':
    create_tuple_and_hash()

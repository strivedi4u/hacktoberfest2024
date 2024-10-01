def find_largest_element(arr):
    if len(arr) == 0:
        raise ValueError("Array is empty.")

    largest = arr[0]  # Assume the first element is the largest

    # Iterate through the array to find the largest element
    for num in arr:
        if num > largest:
            largest = num  # Update largest if current element is greater

    return largest  # Return the largest element found

# Example usage
if __name__ == "__main__":
    arr = [10, 5, 20, 8]
    largest_element = find_largest_element(arr)
    print("The largest element in the array is:", largest_element)

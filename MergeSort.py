def merge_sort(arr):
    if len(arr) > 1:
        # Finding the middle of the array
        mid = len(arr) // 2
        
        # Dividing the array into two halves
        left_half = arr[:mid]
        right_half = arr[mid:]
        
        # Recursively sorting the two halves
        merge_sort(left_half)
        merge_sort(right_half)
        
        i = j = k = 0
        
        # Merging the sorted halves
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1
        
        # Checking if any elements were left in the left half
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1
        
        # Checking if any elements were left in the right half
        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

# Sample Input
arr = [12, 11, 13, 5, 6, 7]
print("Given array is:", arr)
merge_sort(arr)
print("Sorted array is:", arr)

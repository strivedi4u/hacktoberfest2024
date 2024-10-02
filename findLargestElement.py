input_arr = [int(x) for x in input("Enter the element of Array (seperated by space): ").split()]
print(input_arr)
#using built-in function
print(f"max element in the array is: {max(input_arr)}")
#using loop
for i in range(1,len(input_arr)):
    if input_arr[0] < input_arr[i]:
        input_arr[0] = input_arr[i]
print(f"max element in the array is: {input_arr[0]}")
#Time Conplexity is O(n)
#using sort built in function
print(f"max element in the array is: {sorted(input_arr)[-1]}")

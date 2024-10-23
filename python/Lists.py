my_list = [] # creates an empty list for the values to be stored in 
if __name__ == '__main__':
    N = int(input()) 
   
for _ in range(N): # loops through range of N to carry out the commands 
        command = input().strip().split() # reads the command, splits it into parts 
        
        if command[0] == 'insert': # checks to see if the command is asking to insert a value 
            
            index = int(command[1]) # get the index for when in the list value will be inserted
            value = int(command[2]) # gets the value/the thing that will be inserted into the list 
            my_list.insert(index, value) # inserts the value at a specific point in the list 
               
        elif command[0] == 'print': # checks to see if the command is to print the list at the current state
            print(my_list) # prints the list 
        elif command[0] == 'remove': # checks if command is to remove a value 
        
             value = int(command[1]) # gets the value of the thing to be removed 
             my_list.remove(value) # removes first occurrence of that value 
        elif command[0] == 'append': 
        
             value = int(command[1]) # gets value to be appended - value to be added to list 
             my_list.append(value) # appends that value to the list 
        elif command[0] == 'sort':
        
             my_list.sort() # sorts list in ascending order 
        elif command[0] == 'pop':
        
             my_list.pop() # removes the last item of the list 
        elif command[0] == 'reverse':
        
             my_list.reverse() # reverses the list 

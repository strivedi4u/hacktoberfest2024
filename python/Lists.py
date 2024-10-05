my_list = []
if __name__ == '__main__':
    N = int(input())
   
for _ in range(N):
        command = input().strip().split()
        
        if command[0] == 'insert':
            
            index = int(command[1])
            value = int(command[2])
            my_list.insert(index, value)
               
        elif command[0] == 'print':
            print(my_list)
        elif command[0] == 'remove':
        
             value = int(command[1])
             my_list.remove(value)
        elif command[0] == 'append':
        
             value = int(command[1])
             my_list.append(value)
        elif command[0] == 'sort':
        
             my_list.sort()
        elif command[0] == 'pop':
        
             my_list.pop()
        elif command[0] == 'reverse':
        
             my_list.reverse()
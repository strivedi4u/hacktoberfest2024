tup=[1,4,9,16,25,36,49,64,81,100]
num=int(input("Choose a number"))
i=1
j=1
count=0
while(i<=10):
     j=i*i
     if(j==num):
        print("Your number is there:",num)
     else:
         count+=1
     i+=1
if(count==10):
  print("Your number is not there in the list")

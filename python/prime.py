#To check the number is prime or not
n=int(input("Enter the number:"))
lim=int(n/2)+1
for i in range(2,lim):
    rem=n%i
    if rem==0:
        print(n,"is a prime number")
        break
else:
    print(n,"is not a prime number")


    

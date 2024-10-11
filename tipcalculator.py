bill = int(input("Enter bill amt"))
tip = float(input("Enter tip percent"))
n = int(input("Enter number of people"))

tip_amt = bill*tip/100

tot_amt = bill + tip_amt

per_person = tot_amt / n

print("Total amount: ", tot_amt)
print("Tip amount: ", tip_amt)
print("To Pay per person: ", per_person)

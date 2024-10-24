import random
import string

pass_len = 8

# password value exist in these character
passValue = string.ascii_letters + string.digits + string.punctuation

password = ""
for i in range(pass_len):
    password += random.choice(passValue)  # Use random.choice() to select a character


print("Your password is :", password)
# Enter your code here. Read input from STDIN. Print output to STDOUT
import math
AB= int(input())
AC=int(input())


theta=math.degrees(math.atan(AB/AC))



print(f"{round (theta)}\u00B0")
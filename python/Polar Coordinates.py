# Enter your code here. Read input from STDIN. Print output to STDOUT
import cmath
z= complex(input().strip())
r=abs(z)
theta=cmath.phase(z)

print(f"{r:.3f}")
print(f"{theta:.3f}")
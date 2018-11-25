import math

number = math.factorial(100)

strnumber = str(number)

solution = 0

for c in strnumber:

	solution = solution + int(c)

print(solution)

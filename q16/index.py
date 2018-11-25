print("Hello World!")

number = pow(2, 1000)

strnumber = str(number)

solution = 0

for c in strnumber:

	solution = solution + int(c)

print(solution)

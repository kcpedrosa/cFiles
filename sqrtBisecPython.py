y = float(input('Enter the number that you want to find the square root of: '))
num = y
x = 0
ans = 0

while abs(ans**2 - abs(num)) > 0.0001 and ans <= y:
    ans = (x + y) / 2.0
    if ans**2 < num:
        x = ans
    else:
        y = ans

print('The square root of', num, 'is', ans)
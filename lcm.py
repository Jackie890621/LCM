import math

def gcd(x, y):
    if (x == 0):
        return y
    return gcd(y % x, x)

def find_b(a, c):
    b = list()
    for i in range(len(a)):
        if (a[i] > c[i] or c[i] % a[i] != 0):
            b.append(-1)
            continue
        temp = c[i] // a[i]
        temp2 = gcd(a[i], temp)
        while (temp2 != 1):
            temp = temp2
            a[i] //= temp
            temp2 = gcd(a[i], temp)
            
        b.append(c[i] // a[i])
        
    return b


if __name__ == '__main__':
    n = int(input())
    a = list()
    c = list()
    for i in range(n):
        temp1, temp2 = input().split()
        a.append(int(temp1))
        c.append(int(temp2))
    b = find_b(a, c)
    for number in b:
        print(number)

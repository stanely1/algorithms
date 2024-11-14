t = int(input())
for _ in range(t):
    n, b, c = map(int, input().split())
    if b == 0:
        if c >= n:
            print(n)
        elif c >= n - 2:
            print(n - 1)
        else:
            print(-1)
    else:
        print((n * (b - 1) + min(c, n)) // b)

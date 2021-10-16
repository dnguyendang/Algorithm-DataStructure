#BigO là thgian chạy của thuật toán khi trường hợp tệ nhất

#   O(C)
a = 1
b = 2

i = 0
while i < 100:
    i += 1

print(i)

#   O(N), linear
n = 100
while i < n:
    i += 5

#   O(N^2)
for i in range(n):
    for j in range(n):
        # f(n) = n * n -> O(f(n)) = O(n^2)
        i += 1

for i in range(n):
    for j in range(i):
        i += 1
        # f(n) = 1 + 2 + .. + n = n*(n + 1)/2 = n^2/2 + n/2 
        # -> O(f(n)) = O(n^2)

#   O(log(N))
arr = []
value = 100
for i in range(n):
    if arr[i] == value:
        arr[i] += 1
    # f(n) = cn -> O(f(n)) = O(n)

low = 0 
high = n - 1
while low <= high:
    mid = (high + low)/2
    if(arr[mid] == value):
        arr[mid] += 1
    elif arr[mid] < value:
        low = mid + 1
    else: 
        high = mid + 1  
    #tat ca nhung cai cu chia 2 chia 2 la log
    #trong lap trinh log la log2 chu kop log10
    # f(n) = log(n) -> O(f(n)) = O(log(n))

#   O(N^a) 
for i in range(n):
    for j in range(2*n):
        value += 1
    for j in range(3*n):
        value +=1
    #f(n) = n*(2n + 3n) = n*5n -> O(f(n)) = O(n^2)

for i in range(n):
    for j in range(40, 80):
        value += 1
    for j in range(0,n*n, 2):
        value += 1
    #f(n) = n*(40 + n*n/2) = n^3/2 + n*40 -> O(f(n)) = O(n^3)
    
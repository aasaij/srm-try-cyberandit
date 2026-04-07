l1 = list(map(int, input().split()))
n = len(l1)
#implementing selection sort algorithm
for i in range(n):
    minIndex = i
    for j in range(i+1, n):
        if l1[minIndex]>l1[j]:
            minIndex = j
    if i!=minIndex:
        l1[i], l1[minIndex] = l1[minIndex], l1[i]
print(l1)

    
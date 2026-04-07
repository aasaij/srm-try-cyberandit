amt = int(input())
numDenoms = int(input())
denoms = list(map(int,input().split()))[:numDenoms]
denoms.sort(reverse=True)
i = 0
totalCoins = 0
while i<numDenoms and amt!=0:
    if amt >=denoms[i]:        
        curCoins = amt // denoms[i]
        totalCoins += curCoins
        amt -= curCoins * denoms[i]
    i+=1
# print(totalCoins) if amt == 0 else print (-1)
if amt == 0:
    print(totalCoins)
else:
    print(-1)
    
    

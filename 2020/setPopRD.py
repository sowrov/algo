# Enter your code here. Read input from STDIN. Print output to STDOUT
n=int(input())

nums = [int(v) for v in input().split()]
numSet = set(nums)
cn = int(input())

for i in range(cn):
    command = input().split()
    if command[0]=='pop':
        numSet.pop()
    else:
        v = int(command[1])
        if command[0]=='remove':
            numSet.remove(v)
        else:
            numSet.discard(v)

sumv=0
for r in numSet :
    sumv+= r

print (sumv)

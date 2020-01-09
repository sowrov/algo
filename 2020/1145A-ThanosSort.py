def isSorted(aList):
    v = 0
    for x in aList :
        if x<v :
            return 0
        v=x
    return 1

def rec(aList):   
    #print (aList)
    if isSorted(aList) :
        return len(aList)
    length = len(aList)
    return max(rec(aList[0:int(length/2)]), rec(aList[int(length/2):]))

count = int(input())

listItem = [int(n) for n in input().split()]
# listItem = list()

# for x in range(count):
#     listItem.append(int(input()))

print (rec(listItem))


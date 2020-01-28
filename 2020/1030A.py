n = input()
flagList = [int(x) for x in input().split() ]

hard = 0

for x in flagList :
    if x==1 :
        hard = 1
        break

if hard == 0 :
    print ("easy")
else:
    print ("hard")


t= int(raw_input())

for i in range(0,t):
    s = raw_input()

    temp = ""
    n = len(s)
    ans = 0
    for j in range(0,n):
        temp = ""
        for k in range(j,n):
            temp = temp + s[k]
            if temp[0] == 'R' && temp[len(temp)-1]=='R':
                ans = ans+1
    print ans




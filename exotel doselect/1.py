ir = []
c = []
t = []
def calcProfit:
    for i in range(1,2010):
        ir.append(3*c[i-1]*c[i-1] - 2*t[i-1] + 2)
        c.append(4*t[i-1] - 3*ir[i-1] + 2)
        t.append(2*(ir[i-1] + c[i-1])+14)


ir.append(100)
c.append(-20)
t.append(1)

calcProfit()

n = int(raw_input())

for i in range(0,n):
    temp = raw_input()
    name, age = temp.split()

    if name == "I":
        print ir[age]
    else if name == "C":
        print c[age]
    else
        print t[age]



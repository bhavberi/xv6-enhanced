import matplotlib.pyplot as plt

in_file = input("Filename: ")

fp = open(in_file, "r")

l = fp.readlines()
d = {'4': list(), '5': list(), '6': list(), '7': list(), '8': list(),
     '9': list(), '10': list(), '11': list(), '12': list(), '13': list()}

z = 1

# print(l)
for i in l:
    if i == '\n':
        for j in d:
            if len(d[j]) != z:
                d[j].append(d[j][-1])
            # if len(d[j])==0:
            #     d[j].append(-1)
        z += 1

    x = (i.strip('\n').strip(' ')).split(' ')

    # print(x)
    if len(x) > 2:
        a, b = x[0], x[1]
        m = x[2:]
        for j in m:
            if int(j) > 3:
                d[j].append(int(b))

# print(d)
# print(d['4'])
# for j in d:
#     print(len(d[j]), end=' ')


f = plt.figure()
f.set_figwidth(len(d['10'])/20)

linestyle = ['-', '--', ':', '-.']

x = list(range(len(d['10'])))
for j in d:
    y = d[j][:len(d['10'])]
    s = "p"+j
    plt.plot(x, y, label=s, linestyle=linestyle[(int(j) % 4)])

plt.legend()
# schedulertest.txt

# plt.show()
plt.savefig(in_file+'.png')

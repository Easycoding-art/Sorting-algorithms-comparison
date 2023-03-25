import matplotlib.pyplot as plt
label1 = "$first$"
label2 = "$second$"
x1_unsorted = []
x2_unsorted = []
y1_unsorted = []
y2_unsorted = []
x1_sorted = []
x2_sorted = []
y1_sorted = []
y2_sorted = []
file = open('Lab1_graph_data_unsorted.txt', "r")
line = list(file.readline())
sort_numbers = list(line)

file2 = open('Lab1_graph_data_sorted.txt', "r")
line2 = list(file2.readline())
sort_numbers2 = list(line2)

if sort_numbers[0] == '1' :
    label1 = "$tree\ sort$"
elif sort_numbers[0] == '2' :
    label1 = "$quick\ sort$"
elif sort_numbers[0] == '3' :
    label1 = "$shaker\ sort$"
elif sort_numbers[0] == '4' :
    label1 = "$bubble\ sort$"

if sort_numbers[1] == '1' :
    label2 = "$tree\ sort$"
elif sort_numbers[1] == '2' :
    label2 = "$quick\ sort$"
elif sort_numbers[1] == '3' :
    label2 = "$shaker\ sort$"
elif sort_numbers[1] == '4' :
    label2 = "$bubble\ sort$"

while True :
    line = file.readline()
    coord = line.split()
    if len(coord) == 0 :
        break
    x1_unsorted.append(int(coord[0]))
    x2_unsorted.append(int(coord[0]))
    y1_unsorted.append(int(coord[1]))
    y2_unsorted.append(int(coord[2]))
    if not line :
        break
file.close()

while True :
    line2 = file2.readline()
    coord2 = line2.split()
    if len(coord2) == 0 :
        break
    x1_sorted.append(int(coord2[0]))
    x2_sorted.append(int(coord2[0]))
    y1_sorted.append(int(coord2[1]))
    y2_sorted.append(int(coord2[2]))
    if not line2 :
        break
file2.close()
plt.figure(100)
plt.subplot (1, 2, 1)
plt.plot(x1_unsorted, y1_unsorted, label = label1)
plt.plot(x2_unsorted, y2_unsorted, label = label2)
plt.xlabel(r'$sequence\ size$', fontsize=14)
plt.ylabel(r'$sorting\ time,\ microseconds$', fontsize=14)
plt.title(r'$Unsorted\ sequence$')
plt.legend(loc='best', fontsize=12)
plt.grid(True)

plt.subplot (1, 2, 2)
plt.plot(x1_sorted, y1_sorted, label = label1)
plt.plot(x2_sorted, y2_sorted, label = label2)
plt.xlabel(r'$sequence\ size$', fontsize=14)
plt.ylabel(r'$sorting\ time,\ microseconds$', fontsize=14)
plt.title(r'$Sorted\ sequence$')
plt.legend(loc='best', fontsize=12)
plt.grid(True)

plt.subplots_adjust(wspace= 0.5, hspace=0.5)
plt.show()
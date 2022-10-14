
import numpy as np
import matplotlib.pyplot as plt
from qbstyles import mpl_style

X = ['RR', 'FCFS', 'LBS', 'PBS', "MLFQ"]
rtime = [15, 16, 15, 15, 15]
wtime = [148, 126, 142, 120, 151]

X_axis = np.arange(len(X))

mpl_style(True)

plt.bar(X_axis - 0.2, rtime, 0.4, label='rtime')
plt.bar(X_axis + 0.2, wtime, 0.4, label='wtime')

plt.xticks(X_axis, X)
plt.xlabel("Scheduling")
plt.ylabel("Average Ticks")
plt.title("Scheduling Analysis - schedulertest")
# plt.style.use("dark_background")
plt.legend()
plt.show()

# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt

error = []

with open(r"./exp.txt", 'r') as fp:
    lines = fp.readlines()
    for i in lines:
        error.append(float(i))

x = [i for i in range(1, 11)]

plt.scatter(x, error, color="red")
plt.plot(x, error, color="black")
plt.xlabel("Order")
plt.ylabel("Error")
plt.show()

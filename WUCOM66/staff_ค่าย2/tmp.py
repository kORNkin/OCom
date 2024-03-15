import matplotlib.pyplot as plt
import numpy as np

xpoints = np.array([50, 5, 22, 37, 42, 32, 38, 27, 21, 3, 11, 14, 19, 31, 36])
ypoints = np.array([14915.208, 349.002, 2964.074, 7161.371, 10645.145, 5942.902, 7991.706, 3998.745, 2487.047, 251.037, 906.755, 1375.485, 2239.935, 5030.073, 7058.919])

plt.plot(xpoints, ypoints, 'o')
plt.show()
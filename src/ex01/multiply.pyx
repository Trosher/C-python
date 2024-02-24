cimport cython

@cython.boundscheck(False)
@cython.wraparound(False)
def mul(x, y):
  return [[sum([x[i][j] * y[j][z] for j in range(len(x[0]))]) for z in range(len(y[0]))] for i in range(len(x))]
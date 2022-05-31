from sympy.utilities.iterables import multiset_permutations

kiste = []
for i in range(0,18):
    kiste.append("blau")
for i in range(0,15):
    kiste.append("gelb")
for i in range(0,12):
    kiste.append("rot")
for i in range(0,9):
    kiste.append("schwarz")

array = list(multiset_permutations(kiste,10))
print(len(array))
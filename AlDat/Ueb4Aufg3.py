

def splitIntoSubArrays(A, numberOfSubArrays):
    Ai = []
    m = len(A) // numberOfSubArrays
    for i in range(numberOfSubArrays):
        Ai.append([])
    for i in range(len(A)):
        j = i//m
        Ai[j].append(A[i])
    return Ai

a1 = [1,2,3,4,5,6,7,8,9,10,11,12]
a2 = splitIntoSubArrays(a1,6)
for i in range(len(a2)):
    print(a2[i])
def split(C: list, a: int, b:int) -> list:
    C1 = []
    for i in range(a, b):
        C1.append(C[i])
    return C1

def getMedian(C: list, n: int) -> float:
    if (n % 2 == 0):
        return (C[n//2 - 1] + C[n//2])/2
    else:
        return C[n//2]

def median(A: list, B: list, n: int) -> float:
    k = n % 2;
    if(n == 0):
        return 0
    if(n == 1):
        return (A[0] + B[0])/2
    if(n==2):
        C = A+B
        C.sort()
        return getMedian(C,2*n)
       
    m1 = getMedian(A, n)
    m2 = getMedian(B, n)
   
    if(m1 == m2):
        return m1
    if (m1 < m2):
        return median(split(A,n//2,n), split(B,0,n//2+k), n - n//2)
    else:
        return median(split(A,0,n//2+k), split(B,n//2,n), n - n//2)

A = [-1,1,2,5,9]
B = [7,8,10,11,12]
print(median(A, B, len(A)))
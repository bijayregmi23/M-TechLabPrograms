def closest(l,n):
    x = [b for b in l if n>b]
    return max(x)
res = closest([1,6,3,9,11],8)
print(res)

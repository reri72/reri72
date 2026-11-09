# Python 3.9.25

# 튜플은 리스트와 다르게 값들을 변경할 수 없음

tuple1 = 1,2,3,4
tuple2 = (1,2,3,4)
tuple3 = (1,)
tuple4 = (1)
tuple5 = tuple(["안","녕","하","세","요"])

print(tuple1)   # (1, 2, 3, 4)
print(tuple2)   # (1, 2, 3, 4)
print(tuple3)   # (1,)
print(tuple4)   # 1
print(tuple5)   # ('안', '녕', '하', '세', '요')

print(tuple5[0])        # 안
print(tuple5[-1])       # 요
print(tuple1[:3])       # (1, 2, 3)
print(tuple2[1:])       # (2, 3, 4)
print(tuple1+tuple2)    # (1, 2, 3, 4, 1, 2, 3, 4)
print(tuple2*2)         # (1, 2, 3, 4, 1, 2, 3, 4)

# -----------------------------------------------------------------

# packing
tuple1 = 10, "월", False

# unpacking
a,b,c = tuple1

print(tuple1)   # (10, '월', False)
print(a)        # 10
print(b)        # 월
print(c)        # False

print(10 in tuple1)         # True
print("메롱" in tuple1)     # False
print(True in tuple1)       # False

# Python 3.9.25

vals = [1,2,3,4,5]
for i in vals:
    print(i, end=" ")   # 1 2 3 4 5

print()
print(len(vals))            # 5

print(vals)                 # [1, 2, 3, 4, 5]
print(vals[-1])             # 5
print(vals[0:3])            # [1, 2, 3]
print(vals[:3])             # [1, 2, 3]
print(vals[1:3])            # [2, 3]
print(vals[0] - vals[2])    # -2

vals.append(6)
print(vals)                 # [1, 2, 3, 4, 5, 6]

vals2 = vals
print(vals2)                # [1, 2, 3, 4, 5, 6]

vals3 = vals2[:6]
print(vals3)                # [1, 2, 3, 4, 5, 6]

vals4 = list((1,2,3,4,5,6)) # [1, 2, 3, 4, 5, 6]
print(vals4)

vals2.append(vals3)
print(vals2)                # [1, 2, 3, 4, 5, 6, [1, 2, 3, 4, 5, 6]]

print(vals3+vals4)          # [1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6]
print(vals3*2)              # [1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6]

vals4.append(7)
print(vals4)                # [1, 2, 3, 4, 5, 6, 7]

vals4.remove(1)
print(vals4)                # [2, 3, 4, 5, 6, 7]

vals4.insert(0,1)           # 희망 인덱스에 값을 삽입
print(vals4)                # [1, 2, 3, 4, 5, 6, 7]

vals4.pop(6)                # 희망 인덱스에 있는 값을 제거
print(vals4)                # [1, 2, 3, 4, 5, 6]

vals4.reverse()
print(vals4)                # [6, 5, 4, 3, 2, 1]

# 이건 실제로 순서를 변경하진 않음
print(sorted(vals4))        # [1, 2, 3, 4, 5, 6]

vals4.sort()
print(vals4)                # [1, 2, 3, 4, 5, 6]

double_list = [[1,2,3,4],['a','b','c','d']]
print(double_list)          # [[1, 2, 3, 4], ['a', 'b', 'c', 'd']]
print(double_list[0][0])    # 1
print(double_list[1])       # ['a', 'b', 'c', 'd']

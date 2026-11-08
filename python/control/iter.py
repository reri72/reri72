# Python 3.9.25

i = 0
for i in range(5):
    print(i, end=" ")   # 0 1 2 3 4
print()

i = 0
for i in range(5,10):
    print(i, end=" ")   # 5 6 7 8 9
print()

str = "hello world"
for ch in str:
    print(ch, end=" ")  # h e l l o   w o r l d
print()

i = 0
while i < 5:
    print(i, end=" ")   # 0 1 2 3 4
    i += 1
print()

i = 0
for i in range(1,20):
    if i%2 == 0:
        continue
    elif i > 10:
        break
    print(i, end=" ")   # 1 3 5 7 9
print()
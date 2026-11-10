# Python 3.9.25

global hello
hello = "hello"
print(hello)        # hello

# ----------------------------------------------------------------
def func1():
    print('func1 called')

def func2(a, b):
    print(a+b)
    
def func3(a, b):
    return (a+b)

def func4(a=1, b=2):
    print(a+b)

def func5(a, b):
    return (a+b), (a-b)

func1()             # func1 called
func2(3, 4)         # 7
func2(a=3, b=4)     # 7
print(func3(3, 4))  # 7

func4(2,b=3)        # 5
func4(2,3)          # 5

i, j = func5(5,1)
print(i, j)         # 6 4

# ----------------------------------------------------------------
# 가변 매개변수
def func6(*val):
    total = 0
    for v in val:
        total += v
    return total

def func7(**val):
    for i,j in val.items():
        print(i,j)

print(func6(1,2,3,4,5))
func7(일=1, 이=2, 삼=3)

# ----------------------------------------------------------------
# lambda
func2(1,2)                          # 3
print((lambda a, b : a+b)(1,2))     # 3

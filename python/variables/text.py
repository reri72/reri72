# Python 3.9.25

print("python and 'python'")    # python and 'python'
print('python and "python"')    # python and "python"
print('''python
    is
    awesome''')
print("""python
    is
    awesome""")
# ------------------------------------------------------

i = "python!"
j = 'P'
k = 123

# TypeError: can only concatenate str (not "int") to str
# print(i+k)
print(i+j)      # python!P
print(i[0])     # p
print(i[-1])    # !
print(len(i))   # 7

# ------------------------------------------------------

str="python is awesome"
print(str[0])       # p
print(str[0:6])     # python
print(str[:8])      # python i
print(str[5:])      # n is awesome

# ------------------------------------------------------

str="I like chicken, I like pizza"
# 개수 출력
print(str.count("I"))       # 2
print(str.count("like"))    # 2

# find랑 index는 처음으로 등장하는 인덱스 반환
print(str.find("l"))        # 2
print(str.find("chicken"))  # 7
print(str.find("you"))      # -1
print(str.index("l"))       # 2
print(str.index("pizza"))   # 23

#  ValueError: substring not found
# print(str.index("you"))     

# ------------------------------------------------------

str = "hello World, welcome to Korea!"
print(str.upper())  # HELLO WORLD, WELCOME TO KOREA!
print(str.lower())  # hello world, welcome to korea!
print(str.replace("World", "Python"))  # hello Python, welcome to Korea!
print(str)          # hello World, welcome to Korea!

print(str.split(' '))   # ['hello', 'World,', 'welcome', 'to', 'Korea!']
print(str.split())      # ['hello', 'World,', 'welcome', 'to', 'Korea!']
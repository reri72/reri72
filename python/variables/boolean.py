# Python 3.9.25

print(type(True))  #    <class 'bool'>
print(type(False)) #    <class 'bool'>

print(bool(1))  # True
print(bool(0))  # False

print(bool("hi"))   # True
print(bool(""))     # False

print(bool([1,2,3]))    # True
print(bool([]))         # False

print(bool(()))     # False
print(bool({}))     # False
print(bool(None))   # False

# ------------------------------------------------------
i = 10
j = 1
print(i>j)  # True
print(i<j)  # False
print(i==j) # False
print(i!=j) # True

print(i>j and i!=j)         # True
print(i<j or i!=j)          # True
print(not(i>j and i!=j))    # False
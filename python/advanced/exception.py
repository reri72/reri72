try:
    5/0
except IndexError as e:
    print("error :",e)
except ZeroDivisionError as e:
    print("error :", __file__, e)
# error : /root/git/reri72/python/advanced/exception.py division by zero

try:
    pass
except IndexError:
    print("error :",e)
except ZeroDivisionError:
    print("error :",e)
else:
    print("None error")
finally:
    print("finally context")
# None error
# finally context

'''
Traceback (most recent call last):
  File "/root/git/reri72/python/advanced/exception.py", line 24, in <module>
    raise ValueError
ValueError
'''
if True:
    raise ValueError
    
print("program exit")
fp = open('text.txt', 'r')
all_data = fp.read()
"""
hello world
bye world
"""
print(all_data)
fp.close()


fp = open('text.txt', 'r')
oneline = fp.readline()
'''
hello world

'''
print(oneline)
fp.close()


fp = open('text.txt', 'r')
'''
hello world
bye world
'''
while True:
    line = fp.readline()
    if not line:
        break
    print(line, end='')
fp.close()


fp = open('text.txt', 'r')
lines = fp.readlines()
print(lines)                # ['hello world\n', 'bye world']
fp.close()


fp = open('text.txt', 'a')
fp.write('\ngood morning')
fp.close()


# auto close
with open('text.txt', 'r') as fp:
    print(fp.read())


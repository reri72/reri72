# Python 3.9.25

# key 를 통해 각 요소에 접근할 수 있는 데이터 타입
# key 는 변경이 불가한 타입이어야 함

dict1 = {'일':1, '이':2, "삼":3, 4:'사'}
dict2 = dict({"일":1, "이":2, "삼":3})
dict3 = dict([('일',1), ('이',2), ('삼',3)])
dict4 = dict(일=1, 이='2', 삼=3)
dict5 = {('four', 4): ['five', 5.0]}

print(dict1)    # {'일': 1, '이': 2, '삼': 3, 4: '사'}
print(dict2)    # {'일': 1, '이': 2, '삼': 3}
print(dict3)    # {'일': 1, '이': 2, '삼': 3}
print(dict4)    # {'일': 1, '이': '2', '삼': 3}
print(dict5)    # {('four', 4): ['five', 5.0]}

# ------------------------------------------------------------

dict6 = dict({'하나': 1, '둘': 2, '셋': 3})
print(dict6['하나'])        # 1
# print(dict6['넷'])        # KeyError: '넷'
print(dict6.get('하나'))    # 1
print(dict6.get('넷'))      # None

dict6['넷'] = 4
dict6['다섯'] = 6
dict6['여섯'] = 6
dict6['다섯'] = 5
print(dict6)                # {'하나': 1, '둘': 2, '셋': 3, '넷': 4, '다섯': 5, '여섯': 6}

dict6.clear()
print(dict6)                # {}

print(dict1.keys())         # dict_keys(['일', '이', '삼', 4])
print(dict1.values())       # dict_values([1, 2, 3, '사'])
print(dict1.items())        # dict_items([('일', 1), ('이', 2), ('삼', 3), (4, '사')])

print(4 in dict1)           # True
print(5 in dict1)           # False

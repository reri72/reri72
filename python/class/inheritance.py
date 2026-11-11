# Python 3.9.25

class sweet:
    _name = '단거'
    def __init__(self):
        self.desc = "냠냠 혈당 상승"
    
    def favorite(self):
        print('chocolate')
        
class Shara(sweet):
    _name = '사라'      # protected
    def favorite(self):
        print('candy')
    
class Alice(sweet):
    __name = '앨리스'   # private
    def __init__(self):
        self.desc = "냠냠 혈당 정상"    # 오버라이딩
    
    
person1 = Shara()
person2 = Alice()

print(person1.desc)  # 냠냠 혈당 상승
person1.favorite()   # candy

print(person2.desc) # 냠냠 혈당 정상
person2.favorite()  # chocolate
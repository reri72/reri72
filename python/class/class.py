# Python 3.9.25

class Python:
    #attribute
    name = '파이톤'
    
    # method
    def setting(self, name):
        self.name = name
        self.desc = name + ' 입니다'
        
    def introduce(self):
        print(self.name + " 입니다")
                
py1 = Python()  # object 이자 instance

# print(py1.desc) # AttributeError: 'Python' object has no attribute 'desc'
                # __init__ 메서드 없으니까 먼저 setting 호출 해야 desc 를 쓸 수 있음

py1.setting("감자빵")
py1.introduce()

print(py1.desc)

# ------------------------------------------------------------------------------------------
class November:
    # 클래스 변수
    month = 11
    
    def __init__(self, name):
        self.name = name    # 인스턴스 변수
    def introduce(self):
        print("저는 " + self.name + " 입니다")

nov = November("11월")
print(nov.month)
nov.introduce()
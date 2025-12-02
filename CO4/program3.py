class Rectangle:
  def __init__(self, l, b):
    self.__length = l 
    self.__breadth = b 
  def getDimensions(self):
    return self.__length, self.__breadth
  def getArea(self):
    return self.__length * self.__breadth
  def __lt__ (self, other): 
    return self.getArea() < other.getArea()

length1 = int(input("Enter the 1st rectangle length: "))
breadth1 = int(input("Enter the 1st rectangle breadth: "))
ar1 = Rectangle(length1, breadth1)

length2 = int(input("Enter the 2nd rectangle length: "))
breadth2 = int(input("Enter the 2nd rectangle breadth: "))
ar2 = Rectangle(length2, breadth2)

print (f"Area of 1st rectangle = {ar1.getArea()}")
print(f"Area of 2nd rectangle = {ar2.getArea()}")
if ar1 < ar2:
   print("1st rectangle is smaller")
else:
   print("2nd rectangle is smaller or both are equal")

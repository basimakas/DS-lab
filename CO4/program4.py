class Time:
  def __init__(self, h, m, s):
    self.__hours = h
    self.__minutes = m
    self.__seconds = s
  def __add__(self, other): 
    total_seconds = self.__seconds + other.__seconds
    total_minutes = self.__minutes + other.__minutes + (total_seconds // 60)
    total_hours = self.__hours + other.__hours + (total_minutes // 60)
    seconds = total_seconds % 60
    minutes = total_minutes % 60
    hours = total_hours % 24
    return Time(hours, minutes, seconds)
  def display(self):
    print(f"{self.__hours:02d}:{self.__minutes:02d}:{self.__seconds:02d}")

print("Enter details for Time 1:")
h1 = int(input("Hours: "))
m1 = int(input("Minutes: "))
s1 = int(input("Seconds: "))
t1 = Time(h1, m1, s1)
print("\nEnter details for Time 2:")
h2 = int(input("Hours: "))
m2 = int(input("Minutes: "))
s2 = int(input("Seconds: "))
t2 = Time(h2, m2, s2)
result=t1+t2
print("\nSum of the two times: ", end="")
result.display()

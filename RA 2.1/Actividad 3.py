class Vector: 
    def __init__(self, x , y):
        self.x= x
        self.y= y 

    def __neg__(self): 
        return Vector(-self.x, -self.y)
    
    def __add__(self, other): 
        return Vector(self.x + other.x, self.y - other.y)
    
    def __mul__(self, seg_obj):
        if isinstance(seg_obj, (int, float)): 
            return Vector(self.x * seg_obj, self.y * seg_obj)
        
        return Vector(self.x * seg_obj.x, self.y * seg_obj.y )
    
    def __rmul__(self, seg_obj):
        return self.__mul__(seg_obj)
    
    def __eq__(self, otro):
        return self.x == otro.x and self.y == otro.y
    
    def __str__(self):
        return f"({self.x}, {self.y})"
    
#Prueba 
v1= Vector(3, 4)
v2= Vector(1, -2)

print("v1 =", v1)
print("v2 =", v2)
print("-v1 =", -v1)
print("v1 + v2 = ", v1 + v2)
print("v1 * 3 =", v1 * 3)
print("5 * v2 =", 5 * v2) #__rmul__ 
print("v1 == v2?", v1 == v2)
print("v1 * v2 =", v1 * v2) # NotImplemented

v3= Vector(3, 4)
print("v1 == v3?", v1 == v3)


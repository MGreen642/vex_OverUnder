

Axis3 = float(input("Axis3: "))
Axis4 = float(input("Axis4: "))


steering = (pow((Axis4),1.2)/10).real
if (Axis4 < 0):
    steering = steering*-1

speed = Axis3
left = int(speed-steering)
right = int(speed+steering)
if (left > 100):
    right = right - (left-100)
    left = 100
elif (left < -100):
    right = right - (left+100)
    left = -100

if (right > 100):
    left = left - (right-100)
    right = 100
elif (right < -100):
    left = left - (right+100)
    right = -100

print(left,right)
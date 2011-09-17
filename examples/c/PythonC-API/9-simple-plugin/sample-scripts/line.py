import math
from canvas_interface import *

def line(x1, y1, x2, y2):
    m = float(y2 - y1)/(x2 - x1)

    x = x1
    y = y1

    for i in range(x2-x1):
        set_pixel(int(x), int(y), 1)
        x += 1.0/m
        y += m

def circle(x, y, r):
    for i in range(360):
        xp = r*math.cos(math.radians(i)) + x
        yp = r*math.sin(math.radians(i)) + y
        set_pixel(int(xp), int(yp), 1)

line(0, 0, 256, 457)
circle(100, 100, 100)
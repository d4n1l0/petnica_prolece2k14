#!/usr/bin/python

import math

f = open("testset1/testset1")

H = f.read()
OP = f.read()
DH = f.read()
DOP = f.read()

height = 480

a = 21.8
d = 24.0

nuv = 2 * math.atan(a/(2*d))

print nuv

for x in f:
    print 1
    print x

    

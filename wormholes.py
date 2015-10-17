# -*- coding: utf-8 -*-
"""
Created on Fri Oct 16 22:42:58 2015

@author: s7mahaja
"""

# Generates Pairings in pairings:
a = [1,2,3,4,5,6,7,8,9,10,11,12]
pairing=[0]*(len(a)/2)
pairings=[]
    
def pair(a):
    global pairing
    level = len(a)/2 -1 
    if(len(a)==0):
        p = list(pairing)
        pairings.append(p)
        return 
    for i in range(1,len(a)):
        pairing[level] = (a[0],a[i])
        t = list(a)
        t.pop(i)
        t.pop(0)
        pair(t)
        
pair(a)

print len(pairings)*12
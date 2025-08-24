# Code Studio 0 based indexing
from os import *
from sys import *
from collections import *
from math import *

'''
    Following is the class structure of the Node class:
    
    class Node:
        def __init__(self,data):
            self.data = data
            self.next = None
            self.prev = None
'''


def deleteNode(head, pos):
    if head:
        i=0
        if head.next is None and i == pos:
            head = None
        else:
            temp = head

            if i == pos:
                head = head.next
            else:
                temp = temp.next
                while temp:
                    if i+1 == pos:
                        temp.prev.next = temp.next

                        if temp.next:
                            temp.next.prev=temp.prev
                    
                    i+=1
                    temp= temp.next
        
    return head    
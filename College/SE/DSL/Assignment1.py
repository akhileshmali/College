groupA=[]
groupB=[]
groupC=[]
groupANB=[]
groupEAOBNBO=[]
groupNANB=[]
groupUN=[]
a=int(input("Enter number of student playing cricket"))
b=int(input("Enter number of student playing badminton"))
c=int(input("Enter number of student playing football"))
def cricket():
    for i in range(0, a):
        print("Enter the roll no of students playing cricket")
        ele1 = int(input())
        groupA.append(ele1)
    return groupA
def badminton():
    for i in range(0, b):
        print("Enter the roll no of students playing badminton")
        ele2 = int(input())
        groupB.append(ele2)
    return groupB
def football():
    for i in range(0, c):
        print("Enter the roll no of students playing football")
        ele3 = int(input())
        groupC.append(ele3)
    return groupC
def dup(d):
    lst=[]
    for i in d:
        if i not in lst:
            lst.append(i)
    return lst
def anb():
    for i in range(0, a+b):
        if i in groupA and i in groupB:
            groupANB.append(i)
cricket()
badminton()
football()
groupA=dup(groupA)
print("List of roll no of students playing cricket is : "
, groupA)
groupB=dup(groupB)
print("List of roll no of students playing badminton is : "
, groupB)
groupC=dup(groupC)
print("List of roll no of students playing football is : ", groupC)
def eaobnbo():
    for i in range(0, a+b):
        if i in groupA or i in groupB :
            groupEAOBNBO.append(i)
        if i in groupEAOBNBO and i in groupANB :
            groupEAOBNBO.remove(i)
    
    return groupEAOBNBO
def nanb():
    for i in range(0, a+b+c):
       if i in groupC and i not in groupA and i not in groupB :
            groupNANB.append(i)
groupUN=groupA+groupB+groupC
groupUN=dup(groupUN) 
def abnc():
    for i in range(0, a+b+c):
       if i in groupUN and i in groupB :
            groupUN.remove(i)
while 1:
    x=int(input('''\n\nEnter your choice :
1. List of roll no of students playing both cricket and badminton
2. List of roll no of students who play either cricket or badminton but not both
3. No of students playing neither cricket nor badminton
4. No of students playing cricket and football but not badminton\n\n'''))
    if x==1:
        anb()
        groupANB=dup(groupANB)
        print('''\nList of roll no of students playing both cricket and badminton : '''
, groupANB)
    elif x==2:
        eaobnbo()
        groupEAOBNBO=dup(groupEAOBNBO)   
        print('''\nList of roll no of students who play either cricket or badminton but 
not both : ''',groupEAOBNBO) 
    elif x==3:
        nanb()
        groupNANB=dup(groupNANB)   
        print((len(groupNANB))," students play neither cricket nor badminton")
    elif x==4:
        abnc()
        print((len(groupUN))," students play cricket and football but not badminton")
    else:
        print("Invalid Input")



        














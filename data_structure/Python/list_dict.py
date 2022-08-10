List = [1, "A", "spring", 26, 0.32]
"""
print("\nList:")
print(List)
print(List[4])


print("\nWhile loop:")
i = 1
while(i < 3):
    print(i, end = " ->  ")
    print(List[i])
    i += 1

print("\nFor loop:")
for i in range(1,11):
    print(i, end = ", ")
"""

dica = {}

dicb = {
    'aaa': 10,
    'erh': 23,
    'aam': 44,
    'cjz': 56,
    'via': 81,
    'pip':{
        'MMM' : 111,
        'CCC' : 222,
        'PPP' : 333,
        'XXX' : 444,                        
    }                    
}

dica = {
    'e' : 32,
    "e" : 556,
    'f' : "Ting",
    '32' : 100,
    'Chieh' : 24,
    'g' : 24,
    '245' : "Cindy",
    '100' : "Ryan",
    'Nested':{
        'q' : 0.14,
        'w' : 0.15,
        'e' : 0.16,
        'r' : 0.17,                
    }

}

# print(dica.keys())
# print('f' in dica)

# % = 字串格式化
for i in dica:
    
    if type(dica[i])== dict:
        print("%-5s" % i)
        for j in dica[i]:
            print("\t%-5s -> %-5s" % (j, dica[i][j]))
    else:
        print("\t%-5s -> %-5s" % (i, dica[i]))

print(dicb['pip']['CCC'])


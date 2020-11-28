import pymysql
import numpy
import past_a2


try:
    base = pymysql.connect('localhost', 'root', '', 'verb')
except pymysql.OperationalError:
    print('Uknown')

try:
    cursor = base.cursor()
except pymysql.Error:
    print('cant get cursor')


try:
    cursor.execute("SELECT `code_parent` FROM `verbs`")
    code = cursor.fetchall()
except pymysql.Error:
    print('Cant Select')

code1 = numpy.msort(code) #сортировка
result = numpy.unique(code1)  #Уникальные родительские коды



x = []
n=0
for i in result[20000:30000]:
    try:
        cursor.execute("SELECT `word` FROM `verbs` WHERE `gender`='муж' AND `plural`=0 AND `code_parent`=%s",int(i))  #ед число мужского рода 1 лица "Я"
        word1 = cursor.fetchone()


        if word1!=None :
            x.append(past_a2.slovar(word1))




    except pymysql.Error:
        continue

f = open('past.txt', 'a')

for z in range(0,len(x),1):
    f.write(x[z])

f.close()

# try:
#     cursor.execute("SELECT 'word' FROM `verbs`")
# except pymysql.Error:
#     print('Cant Select')







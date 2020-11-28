import pymysql
import numpy
import a2


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
for i in result[128000:128100]:
    try:
        cursor.execute("SELECT `word` FROM `verbs` WHERE `face`='1-е' AND `plural`=0 AND `code_parent`=%s",int(i))  #ед число мужского рода 1 лица "Я"
        word1 = cursor.fetchone()

        cursor.execute("SELECT `word` FROM `verbs` WHERE `face`='1-е' AND `plural`=1 AND `code_parent`=%s",int(i))  #множ число м/ж рода 1 лица "МЫ"
        word2 = cursor.fetchone()


        cursor.execute("SELECT `word` FROM `verbs` WHERE `face`='3-е' AND `plural`=1 AND `code`=%s",int(i))  # множ число 3 лицо "ОНИ"
        word3 = cursor.fetchone()

        cursor.execute("SELECT `word` FROM `verbs` WHERE `face`='3-е' AND `plural`=0 AND `code_parent`=%s",int(i))  # ед число 3 лица "ОН"
        word4 = cursor.fetchone()



        if word1!=None :
            x.append(a2.slovar(word1, word2, word3, word4))




    except pymysql.Error:
        continue

f = open('slova2.txt', 'a')

for z in range(0,len(x),1):
    f.write(x[z])

f.close()

# try:
#     cursor.execute("SELECT 'word' FROM `verbs`")
# except pymysql.Error:
#     print('Cant Select')







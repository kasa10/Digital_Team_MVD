import string
import nltk
import pymysql
import conect


f = open('test1.txt', "r", encoding="utf-8")
text = f.read()
print(text)

t3=[]
t1 = nltk.word_tokenize(text)  #Разбиваем текст
print(t1)

for i in t1:
    n = conect.changeword(i)
    if isinstance(n, tuple):
        t3.append(n[0])
    else:
        t3.append(n)

print(t3)

t2 =  ' '.join(t3) # Соединение текста

print(t2)









#str.split



#print(string.punctuation)
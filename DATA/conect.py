import pymysql

def changeword(a1):

    S1=1

    try:
        base = pymysql.connect('localhost', 'root', '', 'verb')
    except pymysql.OperationalError:
        print('Uknown')

    try:
        cursor = base.cursor()
    except pymysql.Error:
        print('cant get cursor')


    try:
        cursor.execute("SELECT `code_parent` FROM `verbs` WHERE `word`=%s",a1)
    except pymysql.Error:
        print('Cant Select')

    code = cursor.fetchone()


    try:
        cursor.execute("SELECT `word` FROM `verbs` WHERE`plural`=0 AND `face`='3-е' AND `code_parent`=%s",code)
    except pymysql.Error:
        S1=a1


    if S1==1:
        S1=cursor.fetchone()

    cursor.close()
    base.close()
    return (S1)
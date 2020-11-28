
def slovar(word1,word2,word3,word4):
    if word1==None:
        word1=['неизвестно']
    if word2==None:
        word2=['неизвестно']
    if word3==None:
        word3=['неизвестно']
    if word4==None:
        word4=['неизвестно']

    return(
    '{'+
    '    "rule": 1,' +
    '    "first_face" :' +
    '	    {'+
    '	        "male" :'+
    '		        {'+
    '		            "single" : "'+word1[0]+'",'+
    '		            "plural" : "'+word2[0]+'"'+
    '		        },'+
    '	        "female" :'+
    '		        {'+
    '		            "single" : "'+word1[0]+'",'+
    '		            "plural" : "'+word2[0]+'"'+
    '		        }'+
    '	    },'+
    '    "third_face" :' +
    '	    {'+
    '	        "male" :'+
    '		        {'+
    '		            "single" : "'+word4[0]+'",'+
    '		            "plural" : "'+word3[0]+'"'+
    '		        },'+
    '	        "female" :'+
    '		        {'+
    '		            "single" : "'+word4[0]+'",'+
    '		            "plural" : "'+word3[0]+'"'+
    '		        }'+
    '	    }'+
    '}\n'
    )


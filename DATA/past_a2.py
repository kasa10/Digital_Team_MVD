
def slovar(word1):

    return(
    '{'+
    '    "rule": 1,' +
    '    "first_face" :' +
    '	    {'+
    '	        "male" :'+
    '		        {'+
    '		            "single" : "'+word1[0]+'",'+
    '		            "plural" : "'+word1[0]+'и'+'"'+
    '		        },'+
    '	        "female" :'+
    '		        {'+
    '		            "single" : "'+word1[0]+'а'+'",'+
    '		            "plural" : "'+word1[0]+'и'+'"'+
    '		        }'+
    '	    },'+
    '' 
    '    "third_face" :' +
    '	    {'+
    '	        "male" :'+
    '		        {'+
    '		            "single" : "'+word1[0]+'",'+
    '		            "plural" : "'+word1[0]+'и'+'"'+
    '		        },'+
    '	        "female" :'+
    '		        {'+
    '		            "single" : "'+word1[0]+'а'+'",'+
    '		            "plural" : "'+word1[0]+'и'+'"'+
    '		        }'+
    '	    }'+
    '}\n'
    )


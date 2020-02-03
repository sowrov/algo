# Import the required module for text  
# to speech conversion 
from gtts import gTTS 
  
# This module is imported so that we can  
# play the converted audio 
import os 
import time

#wordFile = open("2kWordenlijst.txt")
wordFile = open("2kWordenShortLijst.txt")

enLang = 'en'
nlLang = 'nl'

while True:
    line = wordFile.readline()

    if not line: break

    wordAndMean = list(filter(None, line.split('\t')))
    word = wordAndMean[0].split('(')[0].strip()
    wordChar = ""
    for char in word:
        if wordChar != "":
            wordChar += ", "
        wordChar += char
    
    meaning = wordAndMean[1].split('(')[0].strip()

    exampleLine = ""

    if len(wordAndMean)>2:
        exampleLine = wordAndMean[2].strip()
    
    if not word or not wordChar or not meaning:
        print("----Error----\n"+line)
        continue
    print (word + " - - "+wordChar+" -- "+meaning)

    nlWord = gTTS(text=word, lang=nlLang, slow=False) 
    nlWord.save("nlWord.mp3")

    nlWordChar = gTTS(text=wordChar, lang=nlLang, slow=True)
    nlWordChar.save("nlWordChar.mp3")

    enMeaning = gTTS(text=meaning, lang=enLang, slow=False) 
    enMeaning.save("enMeaning.mp3")

    if exampleLine:
        nlExample = gTTS(text=exampleLine, lang=nlLang, slow=True) 
        nlExample.save("nlExample.mp3")
    

    # Playing the converted file 
    os.system("mpg123 -q ./nlWord.mp3") 
    os.system("mpg123 -q ./nlWordChar.mp3")
    os.system("mpg123 -q ./nlWord.mp3")
    os.system("mpg123 -q ./enMeaning.mp3")

    if exampleLine:
        os.system("mpg123 -q ./nlExample.mp3")

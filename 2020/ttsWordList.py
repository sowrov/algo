# Import the required module for text  
# to speech conversion 
from gtts import gTTS 
  
# This module is imported so that we can  
# play the converted audio 
import os 
import time

wordFile = open("2kWordenlijst.txt")

enLang = 'en'
nlLang = 'nl'

while True:
    line = wordFile.readline()

    if not line: break

    wordAndMean = line.split('\t')
    word = wordAndMean[0].split('(')[0]
    wordChar = ""
    for char in word:
        wordChar += char + " "
    
    meaning = wordAndMean[1]
    print (word + " - - "+wordChar+" -- "+meaning)

    nlWord = gTTS(text=word, lang=nlLang, slow=False) 
    nlWord.save("nlWord.mp3")
    nlWordChar = gTTS(text=wordChar, lang=nlLang, slow=True)
    nlWordChar.save("nlWordChar.mp3")
    enMeaning = gTTS(text=meaning, lang=enLang, slow=False) 
    enMeaning.save("enMeaning.mp3")
    

    # Playing the converted file 
    os.system("mpg123 ./nlWord.mp3") 
    os.system("mpg123 ./nlWordChar.mp3")
    os.system("mpg123 ./nlWord.mp3")
    os.system("mpg123 ./enMeaning.mp3") 
    time.sleep(1)

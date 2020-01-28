# Import the required module for text  
# to speech conversion 
from gtts import gTTS 
  
# This module is imported so that we can  
# play the converted audio 
import os 
  
# The text that you want to convert to audio 
enText = 'Hello World'
nlText = 'Hallo Werld'
  
# Language in which you want to convert 
enLang = 'en'
nlLang = 'nl'
  
# Passing the text and language to the engine,  
# here we have marked slow=False. Which tells  
# the module that the converted audio should  
# have a high speed 
enObj = gTTS(text=enText, lang=enLang, slow=False) 
nlObj = gTTS(text=nlText, lang=nlLang, slow=False) 
# Saving the converted audio in a mp3 file named 
# welcome  
enObj.save("en-welcome.mp3") 
nlObj.save("nl-welcome.mp3") 

# Playing the converted file 
os.system("mpg123 ./en-welcome.mp3") 
os.system("mpg123 ./nl-welcome.mp3") 
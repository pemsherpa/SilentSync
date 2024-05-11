from gtts import gTTS
import os

# Read the entire content of the file
text = open("sstext.txt", "r").read()
language = 'en'

# Create gTTS object for the entire content
myobj = gTTS(text=text, lang=language, slow=False)

# Save the generated audio with the same filename, overwriting the existing file
filename = "trail_audio.mp3"
myobj.save(filename)

# Play the MP3 file on macOS
os.system(f"open {filename}")


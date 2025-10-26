from google import genai
import os

client = genai.Client(api_key=os.getenv("AIzaSyBCrzYyXY51JPvbVZJGRIE3W9b8IW4th5U"))

uploaded_file = client.files.upload(file="/home/kaushalhero/Documents/gemini/bot/02 Ugi Ugi Suruj Dev.mp3") #mp3,pdf , mp4 , etc

response = client.models.generate_content(
    modal="gemini-2.0-flash",
    contents=["describe this file for me",uploaded_file]
)

print(response.text)
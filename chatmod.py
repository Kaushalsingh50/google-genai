from google import genai
import os

client = genai.Client(api_key=os.getenv(""))

uploaded_file = client.files.upload(file="enter file path") #mp3,pdf , mp4 , etc

response = client.models.generate_content(
    modal="gemini-2.0-flash",
    contents=["describe this file for me",uploaded_file]
)

print(response.text)

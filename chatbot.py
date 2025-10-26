from google import genai
import os

client = genai.Client(api_key=os.getenv("AIzaSyBCrzYyXY51JPvbVZJGRIE3W9b8IW4th5U"))

chat=client.chats.create(model="gemini-2.0-flash")

while True:
    message=input("input -> ")
    if message == "exit":
        break

    res=chat.send_message(message)
    print("\n")
    print(res.text)
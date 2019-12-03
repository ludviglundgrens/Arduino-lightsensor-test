from flask import Flask, request, jsonify
from datetime import datetime
import requests

app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello, World! flask'

@app.route('/webhook', methods=['POST'])
def webhook1():
    # In case data is needed
    data = request.json
    
    # Get the time for last email as string
    with open("/home/pi/webhook/data.txt", "r") as fo:
        for i in fo.readlines():
            string = i
    # Convert string to datetime
    string = string.replace(" ", "")
    string = string.replace("\n", "")
    then = datetime.strptime(string, ("%Y/%m/%d-%H:%M:%S"))
    
    # Calculate timedelta
    now = datetime.now()
    duration = now-then
    duration = duration.total_seconds()

    # Execute if 1 hour has passed
    if duration > 3600:
        # Send email
        url = "https://maker.ifttt.com/trigger/wh_em/with/key/g-4XnmdFiCQyoqI1xntHMJZdNLd6mdJ-uLzlCkrFNFR"
        requests.post(url = url)
        # Update txt
        with open("/home/pi/webhook/data.txt", "w") as fo:
            now_str = now.strftime("%Y/%m/%d-%H:%M:%S")
            fo.write(now_str)

    return "flask function works"

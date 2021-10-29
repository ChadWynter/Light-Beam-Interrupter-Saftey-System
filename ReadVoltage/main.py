import smtplib
import serial
from datetime import datetime

'''
verizon: @vtext.com
att: @mms.att.net
tmobile: @tmomail.net
'''

email = "ece.4880.lab@gmail.com"
password = "KK5PF6qc9GKWhT"

server = smtplib.SMTP("smtp.gmail.com", 587)
server.starttls()
server.login(email, password)

def send_sms(number, message):
    server.sendmail(email, number, message)

if __name__ == "__main__":
    ser = serial.Serial("COM3", 115200, timeout=1)
    while True:
        if "indicator" in ser.readline().decode("utf-8"):
            time = datetime.now().strftime("%I:%M %p")
            msg = "Critical safety event at " + time
            print(msg)
            send_sms("6125997855@vtext.com", msg)  

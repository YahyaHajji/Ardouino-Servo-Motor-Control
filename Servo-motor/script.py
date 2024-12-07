import serial
import time

bluetooth = serial.Serial('COM6', 9600)

while True:
    angle = input("Entrez un angle (0-180) : ")

    if angle.isdigit() and 0 <= int(angle) <= 180:
        bluetooth.write(f"{angle}\n".encode())
        print(f"Angle {angle} envoyé.")
        time.sleep(1)
        response = bluetooth.readline().decode().strip()
        print(f"Arduino Response: {response}")
    else:
        print("Angle invalide, réessayez.")

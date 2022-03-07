import socket
import sys
import re
import select
import time
import random
from datetime import datetime

def main():
    ip = socket.gethostbyname('chall.knping.pl')
    server_address = (ip, 22223)
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print('connecting to %s port %s' % server_address, file=sys.stderr)
    sock.connect(server_address)
    data = socket_receive(sock)
    print(data.decode())
    socket_send(sock,b"s\n")
    print("s")
    districts = ["Altan", "Vescillo", "Burnton", "Octovalis", "Gennistora", "Lendiforma", "Wozenfield", "Fardesto"]
    countries = {
        "Kolechia" : ["Yurko City","Vedor","West Grestin"],
        "Republia" : ["True Glorian","Lesrenadi","Bostan"],
        "Antegria" : ["St. Marmero","Glorian","Outer Grouse"],
        "Arstotzka" : ["Orvech Vonor","East Grestin","Paradizna"],
        "Obristan" : ["Skal","Lorndaz","Mergerous"],
        "United Fed." : ["Great Rapid","Shingleton","Korista City"],
        "Impor" : ["Enkyo","Maihan","Tsunkeido"]
    }
    rx_name = re.compile("My name is ([A-Za-z ]{3,20})")
    rx_country = re.compile("country: ([A-Za-z. ]{3,20})")
    rx_district = re.compile("district: ([A-Za-z. ]{3,20})")
    rx_city = re.compile("city: ([A-Za-z. ]{3,20})")
    rx_real_name = re.compile("name: ([A-Za-z ]{3,20}).")
    rx_birth = re.compile("date of birth: '([0-9]{4})\-([0-9]{2})\-([0-9]{2})'")
    rx_today = re.compile("Today is  ([0-9]{4})\-([0-9]{2})\-([0-9]{2})")
    rx_age = re.compile("age: ([0-9]{1,10})")
    while True:
        data = socket_receive(sock)
        print(data.decode())
        if "Today is" in data.decode():
            today_year = int(rx_today.search(str(data)).group(1))
            today_month = int(rx_today.search(str(data)).group(2))
            today_day = int(rx_today.search(str(data)).group(3))
        if "ping{" in data.decode():
            data = socket_receive(sock)
            print(data.decode())
            break
        if "REPORT" in data.decode():
            for i in range(5):
                data = socket_receive(sock)
                print(data.decode())
            break
        try:
            name = rx_name.search(str(data)).group(1)
            country = rx_country.search(str(data)).group(1)
            district = rx_district.search(str(data)).group(1)
            city = rx_city.search(str(data)).group(1)
            real_name = rx_real_name.search(str(data)).group(1)
            born_year = int(rx_birth.search(str(data)).group(1))
            born_month = int(rx_birth.search(str(data)).group(2))
            born_day = int(rx_birth.search(str(data)).group(3))
            age = int(rx_age.search(str(data)).group(1),10)
            real_age = today_year - born_year
            if (today_month < born_month) or ((today_month == born_month) and (today_day < born_day)):
                real_age = real_age - 1

            if (district in districts) and (city not in countries[country]) and age > 17 and real_age > 17 and (age == real_age) and (name == real_name):
                socket_send(sock,b"Accept\n")
                print("Accept")
            else:
                socket_send(sock,b"Reject\n")
                print("name: ", name)
                print("real_name: ", real_name)
                print("district: ", district, district in districts)
                print("country: ", country)
                print("city: ", city, (city not in countries[country]))
                print("age: ", age)
                print("real_age: ", real_age)
                print("Reject")
        except e:
            print("Error: ",e)
            break
        



def socket_receive(sock):
    data = b''
    try:
        amount_expected = 4096
        ready = select.select([sock], [], [], 2)
        data = sock.recv(amount_expected)
    finally:
        return data

def socket_send(sock, data):
    try:
        sock.send(data)
    except:
        print("Couldn't send data")


if __name__ == "__main__":
    main()
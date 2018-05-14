#
# osc_server.py
# A test server for OSC messages from the command line
#
# Author:   Tanuj Sane
# Since:    5/3/2018
# Version:  1.0
#

import socket
from time import sleep

OSC_PORT = 1234

def osc_create(address, fmt, *data):
    pass

def osc_parse(stream):
    pass

if __name__ == "__main__":
    # Create the server and bind to the port (and NULL address)
    server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server.bind(("0.0.0.0", OSC_PORT))

    data, addr = (0, 0)

    # Spin waiting for a "connection"
    while True:
        data, addr = server.recvfrom(OSC_PORT)
        if data and addr:
            print("Got {} from {}, sending back ACK".format(data, addr))
            server.sendto("/pvc_aerophone/ack\x00,\x00".encode(), addr)
            break

    # Send 60bpm quarter notes on middle C
    while True:
        print(server.sendto("/pvc_aerophone/play\x00,ii\x00\x3C\x00\x00\x00\x7F\x00\x00\x00".encode(), addr))
        sleep(1.0)

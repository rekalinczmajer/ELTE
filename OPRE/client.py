from ast import operator
from asyncio.windows_events import NULL
import math
from socket import socket, AF_INET, SOCK_STREAM
import sys
import struct

def send_guess(client, min, max):
    op ='<' if min!=max else '='
    num=math.floor((min+max)/2)
    values=(op.encode(), num)
    packer =struct.Struct('1s I')
    packed_data=packer.pack(*values)
    client.sendall(packed_data)

if len(sys.argv) != 3:
    raise Exception("Missing argument")

server_addr = (sys.argv[1],int(sys.argv[2]))
client = socket(AF_INET, SOCK_STREAM)
client.connect(server_addr)
response=NULL
min=1
max=100
while(response!='Y' or response!='K' or response!='V'):
    print("min, max: ",min, max)
    send_guess(client, min, max)
    data = client.recv(32)
    if data:
        unpacker=struct.Struct('1s I')
        unpacked_data=unpacker.unpack(data)
        print("Kaptam:",unpacked_data)
        response=unpacked_data[0].decode()
        if response=='I':
            max=math.floor((min+max)/2)
        else:
            min=min=math.floor((min+max)/2)

client.close()
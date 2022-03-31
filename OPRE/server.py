from asyncio.windows_events import NULL
import socket
import random
import struct
import sys

def init_socket():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # ipv4, TCP
    server_addr = (sys.argv[1], int(sys.argv[2]))
    sock.bind(server_addr)
    sock.listen(1)
    sock.settimeout(1.0)	# windowson kell
    return sock

def response_msg(g_op, g_num, n):
	if g_op=='<':
		r='I'if n < g_num else 'N'
	elif g_op=='>':
		r='I'if n > g_num else 'N'
	else:
		r='Y' if n == g_num else 'K'
	return r

if len(sys.argv) != 3:
    raise Exception("Missing argument")


sock = init_socket()
num=random.randint(1,100)
print(num)
over=False

while not over:
	try:
		client_socket, client_addr = sock.accept()
		data = client_socket.recv(32)
		if data:
			unpacker=struct.Struct('1s I')
			unpacked_data=unpacker.unpack(data)
			print(unpacked_data)
			ch= response_msg(unpacked_data[0].decode(),unpacked_data[1],num)
			print(ch)
			values=(ch.encode(),0)
			packer=struct.Struct('1s I')
			packed_d=packer.pack(*values)
			client_socket.sendall(packed_d)
			over= ch =='Y'
		else:
			print("Kilepett")
			client_socket.close()
		
	
	except socket.timeout:
		pass
	except KeyboardInterrupt:
		sock.close()
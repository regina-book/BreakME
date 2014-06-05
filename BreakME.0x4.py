#! /usr/bin/python
import sys
import base64
secret = "RE9OJ1QgRE8gJ2NhdCBzZWNyZXQnClNvLCB5b3UgbXVzdCBleHBsb2l0IFB5dGhvbiBpbnB1dCgpCkluIG9yZGVyIHRvIHJlYWQgdGhpcyBmaWxlIGNvbnRhaW4gcGFzc3dvcmQKMTIzNDU2Nzg5"

with open("secret", "wr+") as hFile:
    hFile.write(base64.b64decode(secret).strip())
    hFile.seek(0)
    if input("enter id : ") == int(hFile.read().split('\n')[-1]):
        print "good job :)"
    else:
        print "bad job :("
    hFile.close()

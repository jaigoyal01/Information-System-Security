from PIL import Image
import stepic

def encp(imgname,msg):
    im = Image.open(imgname)
    im1 = stepic.encode(im, b'hello')
    im1.save(imgname, 'PNG')
    im1 = Image.open(imgname)
    #im1.show()


def decode(imgname):
    im2 = Image.open(imgname)
    stegoImage = stepic.decode(im2)
    print(stegoImage)

name=input("Enter Image name\n")

print("Enter \n1) To Encrypt\n2)To Decrypt\n3)To Exit\n")
opt=int(input())
if opt==1:
    message=input("data to hide\n")
    encp(name,message)
if opt==2:
    decode(name)
if opt==3:
    exit




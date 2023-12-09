import os
import qrcode

img = qrcode.make("https://www.instagram.com/thettouri/")

img.save("qr.png", "PNG")

os.system("open qr.png")
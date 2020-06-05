import subprocess
from pathlib import Path

for x in range(12,37,1):
    subprocess.run(["mkdir", "-p","lesson"+str(x)+"Carpeta" ])

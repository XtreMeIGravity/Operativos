# Import the module
import subprocess
# Ask the user for input
print("obteniendo los datos de la tarjeta wlan")
# Set up the echo command and direct the output to a pipe
p1 = subprocess.Popen(['ifconfig', 'wlp7s0'], stdout=subprocess.PIPE)
# Run the command
output = p1.communicate()[0]
output=output.strip( '\n' )
print(output)
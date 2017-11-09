import socket
import sys

HOST = '10.109.53.11'    # server name goes in here
PORT = 8080


def put(commandName):
    socket1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socket1.connect((HOST, PORT))
    socket1.send(commandName)
    string = commandName.split(' ', 1)
    inputFile = string[1]
    with open(inputFile, 'rb') as file_to_send:
        for data in file_to_send:
            socket1.sendall(data)
    print 'PUT Successful'
    socket1.close()
    return


def get(commandName):
    socket1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socket1.connect((HOST, PORT))
    socket1.send(commandName)
    string = commandName.split(' ', 1)
    inputFile = string[1]
    with open(inputFile, 'wb') as file_to_write:
        while True:
            data = socket1.recv(1024)
            # print data
            if not data:
                break
            # print data
            file_to_write.write(data)
    file_to_write.close()
    print 'GET Successful'
    socket1.close()
    return


msg = raw_input('Enter your name: ')
while(1):
    print 'Instruction'
    print '"put [filename]" to send the file the server '
    print '"get [filename]" to download the file from the server '
    print '"ls" to list all files in this directory'
    print '"lls" to list all files in the server'
    print '"quit" to exit'
    sys.stdout.write('%s> ' % msg)
    inputCommand = sys.stdin.readline().strip()
    if (inputCommand == 'quit'):
        socket.send('quit')
        break
    # elif (inputCommand == 'ls')
    # elif (inputCommand == 'lls')
    else:
        string = inputCommand.split(' ', 1)
        if (string[0] == 'put'):
            put(inputCommand)
        elif (string[0] == 'get'):
            get(inputCommand)
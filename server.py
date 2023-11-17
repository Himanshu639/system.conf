import socket
HOST='127.0.0.1'
PORT=5555

def say_hello():
    message='Hello from server'
    client.sendall(message.encode())
    response=client.recv(1024)
    print(f'Received from client:{response.decode()}')

def rec_file(file_name):
    with open(file_name,'wb') as f:
        while True:
            data=client.recv(1024)
            if not data:
                break
            f.write(data)

if __name__=='__main__':
    server=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    server.bind((HOST,PORT))
    server.listen(1)

    print('server is listening on port{}'.format(PORT))
    client,add=server.accept()
    print('connect to client at{}'.format(add))
    say_hello()
    file_name=client.recv(1024).decode()
    print(f'client wants to send file:{file_name}')
    rec_file(file_name)
    server.close()
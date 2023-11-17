import socket
HOST='127.0.0.1'
PORT=5555

def send_file(file_name):
    with open(file_name,'rb') as f:
        while True:
            data=f.read(1024)
            if not data:
                break
            client.sendall(data)

if __name__=='__main__':
    client=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    client.connect((HOST,PORT))
    print("connected to server")

    message='Hello from client!'
    client.sendall(message.encode())
    response=client.recv(1024)
    print(f'received from server {response.decode()}')

    file_name=input('Enter file name to send: ')
    send_file(file_name)
    print(f'File {file_name} sent Successfully')
    client.close()
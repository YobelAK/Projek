import socket
import threading

def handle_client(client_socket):
    request = client_socket.recv(1024).decode()
    headers = request.split('\n')
    filename = headers[0].split()[1]

    if filename == '/':
        filename = '/index.html'

    try:
        # Tentukan path file
        filepath = '.' + filename
        # Tentukan apakah file adalah biner atau teks
        if filename.endswith(('.png', '.jpg', '.jpeg', '.gif')):
            with open(filepath, 'rb') as fin:
                content = fin.read()
            response = b'HTTP/1.1 200 OK\nContent-Type: image/png\n\n' + content
        else:
            with open(filepath, 'r', encoding='utf-8') as fin:
                content = fin.read()
            response = 'HTTP/1.1 200 OK\n\n' + content
            response = response.encode()
    except FileNotFoundError:
        response = 'HTTP/1.1 404 Not Found\n\nFile Not Found'.encode()

    client_socket.sendall(response)
    client_socket.close()

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('0.0.0.0', 12000))
    server_socket.listen(5)
    print('Server listening on port 12000')

    while True:
        client_socket, addr = server_socket.accept()
        print(f'Accepted connection from {addr}')
        client_handler = threading.Thread(target=handle_client, args=(client_socket,))
        client_handler.start()

if __name__ == "__main__":
    main()
import socket
import threading


IP = socket.gethostbyname(socket.gethostname())
PORT = 12000
ADDR = (IP, PORT)
SIZE = 1024
FORMAT = "utf-8"


def handle_client(conn, addr):
    print(f"[NEW CONNECTION] {addr} connected.")

    try:
        request = conn.recv(SIZE).decode(FORMAT)
        headers = request.split('\n')
        filename = headers[0].split()[1]

        if filename == '/':
            filename = '/index.html'

        try:
            filepath = '.' + filename
            if filename.endswith('.html'):
                content_type = 'text/html'
                with open(filepath, 'r') as f:
                    content = f.read()
                response = f'HTTP/1.1 200 OK\nContent-Type: {content_type}\n\n' + content
                conn.sendall(response.encode(FORMAT))
            elif filename.endswith(('.jpg', '.jpeg')):
                content_type = 'image/jpeg'
                with open(filepath, 'rb') as f:
                    content = f.read()
                response = f'HTTP/1.1 200 OK\nContent-Type: {content_type}\n\n'.encode(FORMAT) + content
                conn.sendall(response)
            elif filename.endswith('.png'):
                content_type = 'image/png'
                with open(filepath, 'rb') as f:
                    content = f.read()
                response = f'HTTP/1.1 200 OK\nContent-Type: {content_type}\n\n'.encode(FORMAT) + content
                conn.sendall(response)
            else:
                response = 'HTTP/1.1 415 Unsupported Media Type\n\nUnsupported Media Type'
                conn.sendall(response.encode(FORMAT))
        except FileNotFoundError:
            response = 'HTTP/1.1 404 NOT FOUND\n\nFile Not Found'
            conn.sendall(response.encode(FORMAT))
    except Exception as e:
        print(f"Error handling client {addr}: {e}")
    finally:
        conn.close()
        print(f"[DISCONNECTED] {addr} disconnected.")

def main():
    print("[STARTING] Server is starting...")
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(ADDR)
    server.listen()
    print(f"[LISTENING] Server is listening on {IP}:{PORT}")

    while True:
        conn, addr = server.accept()
        thread = threading.Thread(target=handle_client, args=(conn, addr))
        thread.start()
        print(f"[ACTIVE CONNECTIONS] {threading.active_count() - 1}")

if __name__ == "__main__":
    main()
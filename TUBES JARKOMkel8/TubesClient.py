import socket
import sys

def http_request(host, port, path):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((host, port))
    request = f"GET {path} HTTP/1.1\r\nHost: {host}\r\n\r\n"
    client_socket.send(request.encode())
    response = client_socket.recv(4096)
    print(response.decode())
    client_socket.close()

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python TubesClient.py <host> <port> <path>")
    else:
        host = sys.argv[1]
        port = int(sys.argv[2])
        path = sys.argv[3]
        http_request(host, port, path)
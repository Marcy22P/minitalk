# 🛰️ Minitalk – Client-Server Communication via UNIX Signals

Minitalk is a 42 project that demonstrates **process communication** in C using **only UNIX signals** (`SIGUSR1` and `SIGUSR2`).  
The client sends a string to the server **bit by bit**, and the server reconstructs and prints the message.

---

## 📦 Project Structure

```bash
.
├── client.c        # Sends a message to the server (bit by bit)
├── server.c        # Listens for signals and reconstructs the message
├── minitalk.h      # Shared function prototypes
├── Makefile        # Builds both client and server
```

---

## ⚙️ How It Works

- **Client** encodes each character into 8 bits:
  - `SIGUSR1` = binary `0`
  - `SIGUSR2` = binary `1`
- After each bit, the client waits for an acknowledgment signal from the server.
- **Server** reconstructs the character by collecting bits into a byte using left bit shifting.
- Once a full byte is received, it is printed to standard output.

---

## 🧠 Example

```bash
# Run server
$ ./server
Server PID: 12345

# In another terminal
$ ./client 12345 "Hello Minitalk!"
```

---

## 🛠️ Build Instructions

```bash
make
./server
./client <server_pid> "your message"
```

---

## 📈 Evaluation Result

> 🟢 **Success** – 125/100 (bonus included)

---

## 📚 Learning Points

- Mastery of **UNIX signals** and asynchronous communication
- Handling **bitwise operations** (`&`, `|`, `<<`)
- Proper use of **signal handlers** and `sigaction`
- Synchronization using **pause()** and acknowledgment signals
- Managing global state with `volatile`

---

## 👨‍🚀 Author

Made with ❤️ at 42RomaLuiss.

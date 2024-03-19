<h1 align="center">
	MINITALK
</h1>
<div align="center">
	<br>
  <img  height="130em"  width="15%" src="https://game.42sp.org.br/static/assets/achievements/minitalkm.png" />
    <br>
</div>

## 💡 About the project

MiniTalk is an inter-process communication project using signals, and a client and a server are simulated.
Signals are a way to stop a program from executing every time an event occurs. When this happens, the signal performs some action upon program execution.
In this project, the SiGURS1 and SIGURS2 signals are used.
The way a message is sent from the client to the server is done by bitwise operations. This is a fast and efficient way of sending where each character of the message is sent bit by bit to the server.

---

### Mandatory

Sending a message from the client to the server.

### Bonus part

Sending a message from the client to the server and emoji 👩🏻‍💻. The server has to send a signal back to the client every time it receives a message.

---

## 💡 Execute

Compile using the Makefile.

    make

Open 2 terminals. In the first terminal you will run the server. 
To run, just write to the end ./server.

    ./server

In the second terminal you will execute the client file along with the other 2 arguments. To execute it, you will write in the ./client terminal, 
the PID of the process that appears at the end of the ./server executable and the third is the message that will be sent to the server.

    ./client <PID PROCESS> <message>

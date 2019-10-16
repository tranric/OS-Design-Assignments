/*Assignment 3 Question 2 Richard Tran / Daniel Sacchetto*/

import java.io.*;
import java.net.*;

public class EchoServer {

private ServerSocket server;
private Socket client;
private int port = 9458;
private class ClientConnThread extends Thread {
		
	private Socket client;
	private DataOutputStream out;
	private InputStream in;
	private boolean connection = true;
	private ByteArrayOutputStream buffer;		
	
	//Connection cliean for the messages coming in and out
	ClientConnThread (Socket client) {
		
	try {
		// Connects and disconects the clients
		in = client.getInputStream();
		out = new DataOutputStream(client.getOutputStream());
		buffer = new ByteArrayOutputStream();			
		this.start();
	}
	catch (SocketException e) {
		//reseting the connection
		System.out.print("[Client connection]: Connection Reset for " + client.hashCode());
		} catch (EOFException e) {
		//closing the connection
		System.out.println("[Client connection]: Client Connection Closed." + client.hashCode());
	} catch (IOException e) {
		e.printStackTrace();
		}		
	}
//run method that will verify that the connections are running and working, if they are not they are d
public void run () {
	try {
	while (connection) {
		// Read messages from client
		connection = echoMessages(buffer, in, out) ? true : false;
	}
	//catch for when the connection has been removed
	} catch (IOException e) {
		System.out.println("[Server]: Client closed connection removed.");
	}
	}
}
public boolean echoMessages (ByteArrayOutputStream buffer, InputStream in, DataOutputStream out) throws IOException {
	int nRead;
	byte[] message = new byte[16384];	
	if ((nRead = in.read(message, 0, message.length)) != -1) {
		buffer.write(message, 0, nRead);
	} else if ((nRead = in.read(message, 0, message.length)) == -1) {
		return false;
	}

	buffer.flush();

	byte[] byteMsg = buffer.toByteArray();

	String msg = new String(byteMsg, "UTF-8");

	System.out.println("[Server]: Message received: " + msg);

	// Output nessage from the servers
	out.write(byteMsg);
	out.flush();
	buffer.reset();
	return true;
}
public EchoServer() {
	try {
		// Socket server creation
		server = new ServerSocket(port);
		System.out.println("[Server]: Started. Waiting for connections on port " + port);
		
		// while loop the will continue to look for new connections to accept
		while(true) {
			// Starting a new thread 
			new ClientConnThread(server.accept());
		}
		//catches to notifie when connections are reseted and closed
	} catch (SocketException e) {
		System.out.print("[Server]: Connection Reset");
		System.exit(1);
	} catch (EOFException e) {
		System.out.println("[Server]: Client Connection Closed.");
	} catch (IOException e) {
		e.printStackTrace();
	}
}

public static void main(String[] args) {
	//method to create the new servers 
	new EchoServer();
}
}

package com.fyj;

import android.os.ServiceManager;
import android.os.RemoteException;
import android.os.Binder;

public class Hello {
      public static void main(String args[]) {

             if (args[0].equals("--client")) {
		     IHelloService hs = IHelloService.Stub.asInterface(ServiceManager.getService("com.fyj.IHelloService"));
		     try {
			  System.out.println("Get msg from HelloService: " + hs.hello());
		     } catch (RemoteException e) {
			  System.err.println("failed to call HelloService");
		     }
             } else if (args[0].equals("--server")) {
		      ServiceManager.addService("com.fyj.IHelloService", new HelloService());

		     IHelloService hs = IHelloService.Stub.asInterface(ServiceManager.getService("com.fyj.IHelloService"));
		     try {
			  System.out.println("[Local]Get msg from HelloService: " + hs.hello());
		     } catch (RemoteException e) {
			  System.err.println("failed to call HelloService");
		     }
		    System.out.println("Waiting for a REQUEST");
		    while(true);
            }


      }
}

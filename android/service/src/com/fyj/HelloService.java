package com.fyj;

import android.os.ServiceManager;
import android.os.RemoteException; 

public class HelloService extends IHelloService.Stub {


       public String hello() throws RemoteException {
            return "Hello, From Yajun Fu";
       }

}

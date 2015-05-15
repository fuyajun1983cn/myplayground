package com.fyj;

import java.lang.String;
import android.os.RemoteException;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Binder;
import android.os.Parcel;

public interface IHelloService extends android.os.IInterface {
 
         public static abstract class Stub extends android.os.Binder implements IHelloService {
              private static final String DESCRIPTOR = "com.fyj.IHelloService";
              
              public Stub() {
                   this.attachInterface(this, DESCRIPTOR);
              }

              public static IHelloService asInterface(android.os.IBinder obj) {
                   if (obj == null)
                       return null;
                   IInterface iin = (IInterface)obj.queryLocalInterface(DESCRIPTOR);
                   if ((iin != null) && (iin instanceof IHelloService))
                         return (IHelloService)iin;

                   return new IHelloService.Stub.Proxy(obj);
             }

             public IBinder asBinder() {
                    return this;
             }

             public boolean onTransact(int code, Parcel data,
                                      Parcel reply, int flags)
                                      throws RemoteException {
                   switch(code) {
                   case TRANSACTION_hello:
                        data.enforceInterface(DESCRIPTOR);
                        String msg = hello();
                        System.out.println("IHelloService.Stub: " + msg);
                        //reply.writeNoException();
                        reply.writeString(msg);
                        return true;
                   }
                   return super.onTransact(code, data, reply, flags);
             }


             private static class Proxy implements IHelloService {

                    private IBinder mRemote;
                   
                    Proxy(IBinder remote) {
                         mRemote = remote;
                    }

                    public IBinder asBinder() {
                         return mRemote;
                    }

                    public String getInterfaceDescriptor() {
                            return DESCRIPTOR;
                    }

                    public String hello() throws RemoteException {
                          Parcel data = Parcel.obtain();
                          Parcel reply = Parcel.obtain();
                          String result = null;
                          try {
                               data.writeInterfaceToken(DESCRIPTOR);
                               mRemote.transact(Stub.TRANSACTION_hello, data, reply, 0);
                               result = reply.readString();
                               //System.out.println("IHelloService.Stub.Proxy: " + result);
                               System.out.println("IHelloService.Stub.Proxy: " + result);
                           } finally {
                               reply.recycle();
                               data.recycle();
                           }
                           return result;
                   }
               }


              static final int TRANSACTION_hello = (IBinder.FIRST_CALL_TRANSACTION + 0);
        }


        public String hello() throws RemoteException;

}


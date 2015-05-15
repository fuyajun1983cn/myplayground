package com.fyj.test;

public class VimFileObserver extends FileObserver {

    public VimFileObserver(String path, int mask) {
	super(path, mask);
    }

    public void onEvent(int event, String path) {
	switch(event) {
	    case ACCESS:
		System.out.println("ACCESS");
		break;
	    case MODIFY:
		System.out.println("MODIFY");
		break;
	    case ATTRIB:
		System.out.println("ATTRIB");
		break;
	    case CLOSE_WRITE:
		System.out.println("CLOSE_WRITE");
		break;
	    case CLOSE_NOWRITE:
		System.out.println("CLOSE_NOWRITE");
		break;
	    case OPEN:
		System.out.println("OPEN");
		break;
	    case MOVED_TO:
		System.out.println("MOVED_TO");
		break;
	    case MOVED_FROM:
		System.out.println("MOVED_FROM");
		break;
	    case CREATE:
		System.out.println("CREATE");
		break;
	    case DELETE:
		System.out.println("DELETE");
		break;
	    case DELETE_SELF:
		System.out.println("DELETE_SELF");
		break;
	    case MOVE_SELF:
		System.out.println("MOVE_SELF");
		break;
	    default:
		break;
	}

    }

    public static void main(String args[]) {
	VimFileObserver vfo = new VimFileObserver("/home/fuyajun/.vim/", ALL_EVENTS);
	vfo.startWatching();
    }

}



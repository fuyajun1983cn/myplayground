The first step in working with files is to determine the name of the file on which
to work. Python represents filenames as simple strings, but provides tools for building
them from standard, platform-independent components in `os.path` . List the contents
of a directory with `listdir()` from `os` , or use glob to build a list of filenames from
a pattern.   
The filename pattern matching used by `glob` is also exposed directly through
`fnmatch` , so it can be used in other contexts.   
`dircache` provides an efficient way to scan and process the contents of a directory
on the file system, and it is useful when processing files in situations where the names
are not known in advance.    
After the name of the file is identified, other characteristics, such as permissions
or the file size, can be checked using `os.stat()` and the constants in `stat` .
When an application needs random access to files, `linecache` makes it easy to
read lines by their line number. The contents of the file are maintained in a cache, so be
careful of memory consumption.  
`tempfile` is useful for cases that need to create scratch files to hold data tempora-
rily, or before moving it to a permanent location. It provides classes to create temporary
files and directories safely and securely. Names are guaranteed to be unique and include
random components so they are not easily guessable.   
Frequently, programs need to work on files as a whole, without regard to their
content. The `shutil` module includes high-level file operations, such as copying files
and directories, and setting permissions.   
The `filecmp` module compares files and directories by looking at the bytes they
contain, but without any special knowledge about their format.  
The `codecs` module handles the encoding and decoding automatically, so that in many
cases, a non-ASCII file can be used without any other changes.

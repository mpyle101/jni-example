# jni-example

**Install OpenJDK**  
$ brew install openjdk

**So the "built-in" java binary finds openjdk**  
$ sudo ln -sfn /opt/homebrew/opt/openjdk/libexec/openjdk.jdk /Library/Java/JavaVirtualMachines/openjdk.jdk

**So libjawt.dylib can find libjvm.dylib**  
$ sudo ln -s /opt/homebrew/Cellar/openjdk/18.0.2/libexec/openjdk.jdk/Contents/Home/lib/server/libjvm.dylib /usr/local/lib

**Create the .class from the `hello-world` directory**  
$ javac HelloWorld/Main.java

**Create the .jar from the `hello-world` directory**  
$ jar cfme Main.jar Manifest.txt HelloWorld.Main HelloWorld/Main.class

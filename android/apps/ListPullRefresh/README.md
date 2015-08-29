##构建命令  
```
gradle build -b build.gradle-simple
```

##release包需要的自签名文件   
```
keytool -genkey -v -keystore fyjcode.keystore -alias fyjcode -keyalg RSA -keysize 2048 -validity 100000

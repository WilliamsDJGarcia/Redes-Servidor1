var express = require('express')
var aplicacion = express()

const net = require('net')
const server = require('http').Server(aplicacion)
const socket = require('socket.io')(server)
const os = require('os')


var HOST = 'https://hidden-fjord-71164.herokuapp.com/'
var PORT =  process.env.PORT
var interface = os.networkInterfaces();
var ipdinamic;

 for(var k in interface){
     for(var k2 in interface[k]){
         var address = interface[k][k2]
         if(address.family == 'IPv4' && !address.internal){
             ipdinamic = address.address.toString();
         }
        
         console.log(ipdinamic);
     }
 };


server.listen(PORT, function(){
     console.log('Servidor activo ' + PORT + ' : ' + HOST)
 })

var ser = net.createServer(function(so){
    //console.log(so)
    console.log('Usuario nuevo '+ so.remoteAddress+ ' : ' + so.remotePort )
    so.on('connect', function(){
        console.log('Nuevo usuario')
    })

    so.on('data', function(data){
        console.log(Buffer.from(data, 'hex').toString('utf8'))
    })

    so.on('close', function(){
        console.log('usuario desconectado')
    })

})
 if(PORT == null || PORT == ''){
     PORT = 3000;
 }

ser.listen(HOST, PORT);

console.log('Node');
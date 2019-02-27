var express = require('express')
var aplicacion = express()

const net = require('net')
const server = require('http').Server(aplicacion)
const socket = require('socket.io')(server)
const os = require('os')


var HOST = 'redespolitecnica5.ddns.net'
var PORT =  3000
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

//var HOST = ipdinamic;
//server.listen(PORT, function(){
//     console.log('Servidor activo ' + PORT + ' : ' + HOST)
// })

var ser = net.createServer(function(so){
    //console.log(so)
    console.log('Usuario nuevo '+ so.remoteAddress+ ' : ' + so.remotePort )

    so.on('data', function(data){
        console.log(Buffer.from(data, 'hex').toString('utf8'))
    })

    so.on('close', function(){
        console.log('usuario desconectado')
    })

})
 

ser.listen(PORT, HOST);

console.log('Node');

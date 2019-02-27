var express = require('express')
var aplicacion = express()

const net = require('net')
const server = require('http').Server(aplicacion)
const socket = require('socket.io')(server)

var HOST = 'redespolitecnica5.ddns.net'
var PORT =  5100
 
//server.listen(PORT, function(){
//     console.log('Servidor activo ' + PORT + ' : ' + HOST)
// })

var ser = net.createServer(function(so){
    //console.log(so)
    console.log('Usuario nuevo '+ so.remoteAddress+ ' : ' + so.remotePort )
    so.on('connect', function(){
        console.log('Nuevo usuario')
    })

    so.on('data', function(data){
        console.log(Buffer.from(data, 'hex').toString('utf8'))
	so.write('Hola BB3')
    })

    so.on('close', function(){
        console.log('usuario desconectado')
    })

})
ser.listen(PORT,HOST);

console.log('Conectado a : ' + HOST + ' : ' + PORT )

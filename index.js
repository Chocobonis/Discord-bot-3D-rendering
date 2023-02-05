require('dotenv').config(); //initialize dotenv

const Discord = require('discord.js'); //import discord.js

const Canvas = require('canvas');

const dgram = require('dgram');

const WebSocket = require('ws');

Client = Discord.Client;
Intents = Discord.Intents;

const canvas = Canvas.createCanvas(640, 480);
const context = canvas.getContext('2d');

const client = new Discord.Client({ intents: [3276567] }); //create new client
const bridge = dgram.createSocket('udp4');

const activities = [
  "Eploding creepers!", "Using BonGL renderer!",
  "Open Source!"      , "As seen on TV!",
  "Also try Nekotina!", "Colaborative Rendering!",
  "Ask your doctor!"  ,
  "Technically good!"
];

client.on('ready', () => {
 console.log(`Logged in as ${client.user.tag}!`);
 const randomIndex = Math.floor(Math.random() * (activities.length - 1) + 1);
 const newActivity = activities[randomIndex];
 client.user.setActivity(newActivity);
});

client.on('messageCreate', message => {
  if (message.content === 'ping') {
    message.channel.send('pong');
    bridge.send('ping', 8080, 'localhost' ,async (err)=>{
     //console.log(err);
     if(err === null){

        const context = canvas.getContext('2d');

	const background = await Canvas.loadImage('./Data/VVM/buffer.png');

	// This uses the canvas dimensions to stretch the image onto the entire canvas
         context.drawImage(background, 0, 0, canvas.width, canvas.height);
	// Use the helpful Attachment class structure to process the file for you
       //	const attachment = new Attachment(await canvas.encode('png'), { name: 'profile-image.png' });

        message.channel.send({content: `${message.author.username}'s base:\n⁣`, files: [
         { attachment: canvas.toBuffer()  }
        ]});//.catch(allerrors);
     }
    });
  }
});

//make sure this line is the last line
client.login(process.env.CLIENT_TOKEN); //login bot using token

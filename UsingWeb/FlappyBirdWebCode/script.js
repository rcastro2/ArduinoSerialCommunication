/* Game 2 Tutorial 10
This tutorial demonstrates,
1) audio

*/

// Specifies resources
let resources = {images:[{id:"day", src:"images/day.png"},
                         {id:"bird", src:"images/bird.png"},
                         {id:"bar", src:"images/bar.png"},
                         {id:"ring", src:"images/ring2.png"},
                         {id:"pipetop",src:"images/pipe_top.png"},
                         {id:"pipebot",src:"images/pipe_bot.png"}, 
                         {id:"gameover", src:"images/flappybird_end.png"},
                         {id:"logo", src:"images/logo.png"}
                  ],
                 audios:[{id:"point",src:"audios/point.ogg"},
                         {id:"fly", src:"audios/wing.ogg"},
                         {id:"hit", src:"audios/hit.ogg"},
                         {id:"dead", src:"audios/die.ogg"}
                  ]
                };

let cpxInput = '', port;
const startButton = document.getElementById("start");

//Functionality required for serial communication
async function writeData(port, data) {
  const encoder = new TextEncoder();
  const writer = port.writable.getWriter();
  await writer.write(encoder.encode(data));
  writer.releaseLock();
}
async function startReadingData(port) {
  const reader = port.readable.getReader();
  try {
      while (true) {
          const { value, done } = await reader.read();
          if (done) {
              // Port disconnected
              break;
          }
          const decoder = new TextDecoder(); // Use TextDecoder with polyfill
          const data = decoder.decode(value);
          if(data == 'u' || data == 'd' || data == 'e'){
            cpxInput = data;
            
          }else{
            console.log(data + " : " + data.charCodeAt(0));
          }
      }
  } catch (error) {
      console.error('Error reading from serial port:', error);
  } finally {
      reader.releaseLock();
  }
}
async function connectCPX(){
  try {
    if(port == null || port == undefined){
      port = await navigator.serial.requestPort();
      await port.open({ baudRate: 9600 }); // Adjust baudRate if needed
      startButton.style.display = "none";
      startReadingData(port);
      preload();
    }
  } catch (error) {
      console.error('Error connecting to serial port:', error);
  }
}

// Load resources and starts the game loop
function preload(){
  game = new Game("game");
  game.preload(resources);
  game.state = init;
  gameloop();
}
//document.onload = preload();
startButton.onclick = function(){
  connectCPX();
} 

// Controls the state of the game
function gameloop(){
  game.processInput();
  if(game.ready){
    game.state();
  }
  game.update()
  setTimeout(function(){gameloop()},20);
}

// Create game objects and perform any game initialization
function init(){
  day = new Sprite(game.images.day, game)
  game.setBackground(day)
  //game.showBoundingBoxes = true

  bird = new Animation(game.images.bird, 3, game, 132 / 3, 34)

  bar = new Animation(game.images.bar,3,game,700,110)
  bar.y = game.height - 50

  ring = new Animation(game.images.ring,64,game,512/8,512/8)
  ring.framerate = 1
  ring.scale = 0.7
  ring.x = game.width + 50
  ring.y = randint(200,300)
  ring.setVector(2,90)

  scorering = new Animation(game.images.ring,64,game,512/8,512/8)
  scorering.framerate = 1
  scorering.x = 40
  scorering.y = game.height - 40

  scoreFont = new Font("30px","Comic Sans MS","brown","black")

  pipetop = new Sprite(game.images.pipetop,game)
  pipebot = new Sprite(game.images.pipebot,game)

  gameover = new Sprite(game.images.gameover,game)
  logo = new Sprite(game.images.logo,game)
  logo.scale = 2
  logo.y = 100

  startFont = new Font("30px","Impact","#F0F0F0","#333")

  dead = new Sound(game.audios.dead);
  hit = new Sound(game.audios.hit);
  fly = new Sound(game.audios.fly);
  point = new Sound(game.audios.point);

  game.state = startScreen;
}

// Game logic
function main(){
  game.scrollBackground("left",2)
  bird.draw()
  ring.move()
  pipetop.moveTo(ring.x, ring.y - 200)
  pipebot.moveTo(ring.x, ring.y + 200)
  
  if(key.pressed[key.space] || cpxInput == 'u'){
    bird.y -= 1.5
    fly.play()
  }else{
    bird.y += 1.5
  }
  bar.draw()
  scorering.draw()
  game.drawText(` X ${game.score}`, scorering.right + 5,scorering.y + 7,scoreFont)
  if(bird.collidedWith(bar)||bird.collidedWith(pipetop)||bird.collidedWith(pipebot)){
    game.state = gameoverScreen;
    hit.play()
    dead.play()
  }
  if(bird.collidedWith(ring)){
    ring.visible = false
    point.play()
    writeData(port, 'h');
    game.score += 1
  }
  if(ring.x < 0){
    ring.x = game.width + 50
    ring.y = randint(200,300)
    ring.speed += 1
    ring.visible = true
  }
}
function startScreen(){
  game.scrollBackground("left",2)
  bird.draw()
  logo.draw()
  bar.draw()
  game.drawText("Press a button to start",game.width / 2 - 145, bar.top + 80,startFont)
  
  if(key.pressed[key.space] || cpxInput == 'e'){
    game.state = main
  }
}

function gameoverScreen(){
  game.scrollBackground("left",2)
  gameover.draw()
  bar.draw()
  game.drawText("Press a button to play again",game.width / 2 - 165, bar.top + 80,startFont)
  
  if(key.pressed[key.space] || cpxInput == 'e'){
    game.score = 0;
    ring.speed = 2;
    ring.x = game.width + 50
    ring.y = randint(200,300)
    bird.y = game.height / 2;
    game.state = main;
  }
  
}

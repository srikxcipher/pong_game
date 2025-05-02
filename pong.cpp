#include<SFML/Graphics.hpp>
#include<sstream>
#include<iostream>
#include"bat.cpp"
#include"ball.cpp"

using namespace std;
using namespace sf;

int main(){
        int xr, yr;
        cout<<"Enter resolution in x and y:: ";
        cin>>xr>>yr;
        VideoMode vm(xr,yr);
        RenderWindow window(vm,"Pong Game!!!");
        int Xw=window.getSize().x;
        int Yw=window.getSize().y;
        cout<<"Support resolution: "<<Xw<<" "<<Yw<<endl;
        int score = 0;
        int lives = 3;
        Font font;
        font.loadFromFile("res/font/KOMIKAP_.ttf");
        Text hud;
        hud.setFont(font);
        hud.setCharacterSize(75);
        hud.setFillColor(Color::White);
        hud.setPosition(20,20);
        
        bool touchBottom=false;
        
        Bat bat(Xw/2,Yw-20); // Bat is initialized.
        
        Ball ball(Xw/2, Yw=0);
        
        
        Clock clock; //clock to measure time
        while(window.isOpen()){ //main game loop
        /* handle player input */
           Event event;
           while(window.pollEvent(event)){
              if(event.type==Event::Closed){
                 window.close();
              }
           }
              if(Keyboard::isKeyPressed(Keyboard::Escape)){
                window.close();
              }
              
              //Handle the Players Right Arrow Key ----- (Press & Release)
              
              if(Keyboard::isKeyPressed(Keyboard::Right)){
                   bat.moveRight();
              }
              else{
                   bat.stopRight();
              }
              
              if(Keyboard::isKeyPressed(Keyboard::Left)){
                   bat.moveLeft();
              }
              else{ 
                   bat.stopLeft();
              }

              
              //Update delta time   -  The elapsed time b/w two frames.
              Time dt = clock.restart();
              
              //Bat update
              bat.update(dt);
              
              //Ball update
              ball.update(dt);
              
              //Update text and lives - stored into Buffer
              std::stringstream ss;
              ss<<"Score: "<<score<<" Lives: "<<lives;
              
               //Display values
              hud.setString(ss.str());
              
              //Handle Ball hitting sides of Display.
              if(ball.getPosition().left<0 || (ball.getPosition().left+ball.getPosition().width)>Xw)
              {
                 ball.reboundSides();
              }
              //Handle Ball hitting to the bottom
              if(ball.getPosition().top>window.getSize().y)
              { 
                ball.reboundBottom();
                lives=lives-1;
                touchBottom=true;
                if(lives<1){
                   score=0;
                   lives=3;
                }
              }
               //Handle Ball hitting to the top
              if(ball.getPosition().top<0)
              { 
                ball.reboundBatOrTop();
                if(!touchBottom){
                   score=score+1;
                }
                else
                  touchBottom = false;
                }    
              
              //Handle ball hitting to Bat
              
              if(ball.getPosition().intersects(bat.getPosition()))
              {
                 ball.reboundBatOrTop();
              }
             
              //clear, Draw and Display
              
              window.clear();
              window.draw(hud);
              window.draw(bat.getShape()); //Bat
              window.draw(ball.getShape()); //Ball
              window.display();
              
           }// main game loop ends
        return 0;
        }//end of main

#include<SFML/Graphics.hpp>
using namespace sf;


class Bat{
      private:
         Vector2f m_Position;
      
         RectangleShape m_Shape;
         float m_Speed = 1000.0f;
         bool m_MovingRight = false;
         bool m_MovingLeft = false;
      
      public:
         Bat(float StaAX, float StaAY);
         FloatRect getPosition();
         RectangleShape getShape();
         void moveRight();
         void stopRight();
         void moveLeft();
         void stopLeft();
         void update(Time dt);
      
      };
      
      //Member defn's
      
      Bat::Bat(float StartX, float StartY)
      {
        m_Position.x = StartX;
        m_Position.y = StartY;
        m_Shape.setSize(sf::Vector2f(100,5));
        m_Shape.setPosition(m_Position);
      }
         
      FloatRect Bat::getPosition()
      {
        return m_Shape.getGlobalBounds();
      }
      
      RectangleShape Bat::getShape()
      {
        return m_Shape;
      }
      
      void Bat::moveRight()
      {
         
         m_MovingRight = true;  
         
      }    
      void Bat::moveLeft()
      {
         
         m_MovingLeft = true;
         
      }    
      void Bat::stopRight()
      {
         
         m_MovingRight = false;
         
      }  
      void Bat::stopLeft()
      {
         
         m_MovingLeft = false;
         
      } 
      
      void Bat::update(Time dt)
      {
         if(m_MovingRight){
             m_Position.x = m_Position.x + m_Speed*dt.asSeconds();
             m_Shape.setPosition(m_Position);
         }
         if(m_MovingLeft){
             m_Position.x = m_Position.x - m_Speed*dt.asSeconds();
             m_Shape.setPosition(m_Position);
         }
     }
         


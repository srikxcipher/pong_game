#include<SFML/Graphics.hpp>
using namespace sf;

class Ball{
        private:
                 Vector2f m_Position;
                 CircleShape m_Shape; // CircleShape <--- DataType
                 float m_Speed = 400.0f;
                 float m_DirectionX = 0.2f;
                 float m_DirectionY = 0.2f;
        public:
                 Ball(float StartX, float StartY);
                 
                 FloatRect getPosition();
                 CircleShape getShape(); // func returning obj... 
                 void reboundSides();
                 void reboundBatOrTop();
                 void reboundBottom();
                 void update(Time dt);
          };
          
     //Member defn's
      
      Ball::Ball(float StartX, float  StartY)
      {
        m_Position.x = StartX;
        m_Position.y = StartY;
        m_Shape.setRadius(30);
        m_Shape.setPosition(m_Position);
      }
      
      
      FloatRect Ball::getPosition()
      {
        return m_Shape.getGlobalBounds();
      }
      
      CircleShape Ball::getShape()
      {
        return m_Shape;
      }
      
      void Ball::update(Time dt)
      {
         m_Position.x = m_Position.x + m_DirectionX * m_Speed * dt.asSeconds();
         m_Position.y = m_Position.y + m_DirectionY * m_Speed * dt.asSeconds();
         m_Shape.setPosition(m_Position);
      }
      
      void Ball::reboundSides()
      {
        m_DirectionX = -m_DirectionX;
      }
      
      void Ball::reboundBatOrTop()
      {
        m_DirectionY = -m_DirectionY;
      }
      
      void Ball::reboundBottom()
      {
        m_Position.x = 500;
        m_Position.y = 0;
      //  m_DirectionY = -m_DirectionY;
      }

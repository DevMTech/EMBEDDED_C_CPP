class AbstractMotor
{
    private:
        int Speed;
    
    public:
        AbstractMotor();
        void SetSpeed(int speed);
        int GetSpeed();
        virtual void Off()=0;
        virtual void Forward()=0;
        virtual void Reverse()=0;
        virtual void Brake()=0;
};
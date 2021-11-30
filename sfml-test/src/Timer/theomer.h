
#ifndef THEOMER_H 
#define THEOMER_H 
#include <chrono> 
#include <time.h>  
class  Theomer {    
	std::chrono::system_clock::time_point _startTime;     
	//std::chrono::duration<float> _deltaTime;    
	float _deltaTime;     
	float _timeScale;    
	float _elapsedTime = 0;    
	float _framesCounter;    
	int frames;     
	float fps = 0; 
public:    
	Theomer();    
	~Theomer();     
	void reset();     
	void setTimeScale(float t);    
	float getTimeScale();    
	float getSeconds();   
	void startTime();   
	void tick();  
	float deltaTime();  
	void calculateFps();   
	float getFPS();   
	void FPS(); 
};
#endif // !THEOMER_H
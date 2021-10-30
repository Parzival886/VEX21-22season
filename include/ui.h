#ifndef UI_H
#define UI_H

  /**
   *480*272
  **/

#include "vex.h"
extern competitionSide sideFlag;


class _rect{
private:
  int x,y,width,height;
  color fillColor;
  std::string  text;
  
public:
  _rect(color _fillColor,int _x,int _y,int _width=80,int _height=80);
  ~_rect();
  bool pressed(int32_t _xPosition,int32_t _yPosition);
  void setText(std::string _str);
  std::string getText();
  void pressedFunc();
  void show();
  competitionSide enumSide;
};

class zLog
{
private:
  int x,y,width,height;
  int linesNum=0,lineIndex=0;
  std::vector<std::string> vectorLogString;
  std::string nowString;
public:
  zLog(int _x,int _y,int _w,int _h);
  void put(const char * _s);
  void show();
  void setIndex(int _index);
  int getIndex();
  void pressedFunc(int __y);
  bool pressed(int32_t _xPosition,int32_t _yPosition);
};

class ui
{
private:
  std::vector<_rect*> vectorRect4ScreenDetect;
  _rect *rectLeftLeft,*rectLeftRight,*rectRightLeft,*rectRightRight,*rectDuiYouGuaJi,*rectTest;
  task *taskPressDetect;
  void sideRectInit();
  zLog *myLog;
  
public:
  void screenPressed();
  void show();
  void put(const char * _s);

  ui();
  ~ui();
};

int _tPressDetect();
#endif
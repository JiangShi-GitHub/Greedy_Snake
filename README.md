# Greedy_Snake
一个基于Arm-6818开发板的贪吃蛇

# 项目简介
## 项目优势

> 1.完成全部基本功能且无任何bug；
>
> 
>
> 2.基于数学的颜色渐变和透明度；
>
> 
>
> 3.随机的游戏地图；
>
> 
>
> 4.食物随时间的消失设计以及随时间变化的进度条；
>
> 
>
> 5.游戏最高得分记录；
>
> 
>
> 6.界面简洁明了美观，设计创新；

## 界面展示

### 游戏界面

游戏界面样例如图所示，地图背景为随机显示：

![image](others/Sample.jpg)

还有多种界面地图，内部代码实现为遍历目录并且检测结尾为“.bmp”的文件，所以可以直接添加图片而不用改变代码：

![image](pictures/chuyin.bmp)

![image](pictures/chuyin2.bmp)

![image](pictures/chuying1.bmp)

![image](pictures/hutao.bmp)

![image](pictures/keqing.bmp)

![image](pictures/laisha.bmp)

![image](pictures/megumin.bmp)

![image](pictures/xiaogong.bmp)

![image](pictures/nanmeng.bmp)

![image](pictures/xiaomai.bmp)

### 结束界面

游戏有两个结束界面，蛇撞到边界或者自己会死亡，如果刷新最高纪录为如下界面：

![image](pictures/best_score.bmp)

其他情况为如下界面：

![image](pictures/game_over.bmp)

## 游戏内容

本游戏为一款基于Arm6818开发板的传统贪吃蛇，蛇可以通过滑屏上下左右移动，地图会随机生成食物，并随时间增加线性变浅消失，直至下一次食物投放。蛇吃到食物会增加分数并且变长。如果刷新最高记录，系统会在目录的score.txt（可自行更改）保存最佳分数并在之后的游戏中显示。


# Copyright
> 蔡宇辰
> 龚天健
> 张嘉鑫
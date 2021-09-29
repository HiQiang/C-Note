##### 数据采集卡 USB 4711A Stream采集模式

不同类分文件编写

采集到的数据储存在采集卡的Buffer上，未对数据进行处理

会引发采集卡的Overrun事件（在模拟采集卡上不会出现）

```c++
#include"DataReadyHandler.h"
#include"CacheOverflowHandler.h"
#include"OverrunHandler.h"
#include"StoppedHandler.h"
```


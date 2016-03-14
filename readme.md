# 数据生成器 - 配合LiveJournal原数据使用




## Getting Started
* 本数据生成器文件夹外应当放置 **soc-LiveJournal1.txt**
* 在make之前请使用mkdir在文件夹中生成 **data**，**bin**两个文件夹

## Compile
执行 **make bins** 来进行编译，编译后bin文件夹内出现三个binary

## Graph Creator

生成图和加密图均由Makefile里的参数进行控制  
生成后执行 **make graph**，在data文件夹内得到所需数据。  
以下介绍Makefile内前三个参数
* OVERLAP 控制两图共有的点数
* NODE 控制总图的点数
* ENCRYPT 控制匿名化方法。其中 Case 0: Naive, Case 1: Sparsify, Case 2: Switching

###Example:
两个7500点图，用Sparsify匿名化：

* OVERLAP = 5000
* NODE = 10000
* ENCRYPT = 1

解释: （NODE - OVERLAP）/ 2 + OVERLAP = 7500  
然后在主文件加下执行make graph  
## Copyright and License

--Jialin Liu, 2016/03/14

# SearchEngine
搜索引擎原型系统，数据结构课程作业

## 简介
该系统不包含爬虫和分词部分，项目目录下包含了一些作为演示实例的已经爬取的网页内容，该项目使用 **[jieba分词软件的C++版本](https://github.com/yanyiwu/cppjieba)**

## 编译和使用  
**该软件只在Linux和Mac OSX下测试过，Windows下没有进行测试，不保证可以运行**
只支持中文搜索

### 依赖软件  
* `cmake`
* `g++`

### 编译   
```sh
git clone --depth=1 --branch=master git://github.com/Duconnor/SearchEngine.git
cd SearchEngine
mkdir build
cd build
cmake ..
make
```

### 使用  
```
./SearchEngine
```  
系统初始化完成后可以键入demo运行实例，实例演示中当出现“next?:”提示时，键入n表示继续，键入b表示退出  

# 鸿钧模拟器
## 介绍
鸿钧：一个基于虚幻引擎和 AirSim 的仿真系统，让用户以简单轻松的配置方式搭建定制化的无人机作战环境。 本项目是鸿钧的 python 模拟器端，由Unreal4.27.2开发，其通过 Socket 协议与由基于虚幻引擎和 AirSim 的仿真系统——鸿钧建立通讯，并控制其中仿真的无人机，进行飞行和战斗任务。用户可以使用 Python 语言编写无人机的飞行任务程序，完成无人机的编队飞行、攻击战斗、集群对抗等任务。 本团队在 AirSim 的基础上拓展出了攻击、战斗系统，可以对无人机的作战环境进行模拟，本项目可作为集群智能的训练平台，适用于无人机集群对抗、轰炸敌方目标单位等任务的人工智能训练。

该项目已被清华大学猛狮无人驾驶实验室和南京航空航天大学无人机实验室的研究生团队采用，并于人工智能仿真训练，并发表相关科研论文 本项目与HongJun的控制器端项目是配套使用的，控制器端项目链接：
[HongJun控制器端](https://github.com/CGandGameEngineLearner/HongJun)

**如果您在使用此项目时遇到困难，可以提issue或编辑邮件并发送到`lifesize1@qq.com`进行咨询，如果你愿意向联合国儿童基金会捐款，或者您本人已有了任何合法的国际慈善项目的捐款证明，我将免费帮您解决问题。**

## 依赖环境
1. Unreal4.27.2 （在Epic下载）
2. AirSim Unreal插件 [AirSim](https://github.com/microsoft/AirSim/tree/main/Unreal/Plugins/AirSim) （可在虚幻商城下载）
3. [Socket.IO Client](https://github.com/getnamo/socketio-client-ue4) Unreal插件（可在虚幻商城下载）
4. VisualStudioTools  Unreal插件 （可在虚幻商城下载） 



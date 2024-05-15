# MySqlConnectorExamples
MySqlConnectorExamples示例项目

* The MySQL database connection plugin tool has implemented TCP persistent connections, connection pooling, multithreading, asynchronous calls, and multi-statement transaction execution. It supports both Blueprint and C++ invocations, making it more stable and powerful than other MySQL tools available on the market. It is suitable for large-scale online game development.

* MySQL数据库连接插件工具实现了TCP持久连接、连接池、多线程、异步调用和多语句事务执行。它同时支持Blueprint和c++调用，这使得它比市场上可用的其他MySQL工具更加稳定和强大。适用于大型网络游戏开发。

* When using plug-ins, All dll files under "{Project}\Plugins\MySQLConnectorTools\Source\ThirdParty\MysqlConnectorCpp\lib" need to be copied to "{Project}\Binaries\Win64" Or Unreal Engine won't run. Same thing with the package

* 使用插件时，需要将“{Project}\Plugins\MySQLConnectorTools\Source\ThirdParty\MysqlConnectorCpp\lib”下的所有dll文件拷贝到“{Project}\Binaries\Win64”下，否则虚幻引擎无法运行，打包文件同理

* If the plug-in encounters any bugs, please raise them in the issues, and we will conduct version iteration as soon as possible

* 插件如果遇到任何bug请在issues中提出，我们会第一时间进行版本迭代

* Although the sample project is a GPL3.0 license, the plug-ins purchased by Unreal Mall are available for use in a commercial environment and are not subject to any GPL3.0 license

* 示例项目虽然是GPL3.0许可证，但是虚幻商城购买的插件是可用于商业环境的，不受GPL3.0许可证的任何约束

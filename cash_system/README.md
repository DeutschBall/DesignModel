# 商场促销系统设计
## 需求描述
1.添加订单功能: 一个物品对应一个订单, 订单包括物品单价, 物品数量

2.折扣收费功能: 可以设置折扣策略
> 例如折扣收费, 满减收费等

3.结算
## 设计模式
### 工厂模式
工厂类提供一个接口,接受一个参数,返回对应的对象
> 比如文件格式分析器中,参数就是文件魔术 \
如果文件魔数为0x4d5a则返回ExeParser类对象\
发现文件魔数为.elf则返回ElfParser类对象

如果语言支持反射,那么这里可以使用一个映射表, \
键是魔数,值是一种`Parser`类   
```
dispatcher ={
    0x4d5a : ExeParser,
   ...
}
#key = 0x4d5a
parser = dispatcher[key]
parser.parse(file)  #调用ExeParser的静态方法parse
```
这样就能避免`if-else`判断 


### 策略模式
策略模式用于封装变化

策略上下文类中封装了具体的策略,对外提供统一的策略接口,屏蔽了具体策略的实现.如此可以避免使用if-else语句细分策略.

所有策略类组成一个可选策略集

策略上下文类相当于一个选中的策略集

感觉策略上下文类就是多功能步兵车, 策略类就是步兵

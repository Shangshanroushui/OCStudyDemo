//
//  UtilsMacros.h
//  OCStudyDemo
//
//  Created by wunan on 2018/4/12.
//  Copyright © 2018年 wunan. All rights reserved.
// 放一些方便使用的宏定义

#ifndef UtilsMacros_h
#define UtilsMacros_h

//-------------------获取设备大小-------------------------
//NavBar高度
#define NavigationBar_HEIGHT 44

#define _GETTER_BEGIN(__class__, __property__) \
- (__class__*)__property__ \
{\
if(!_##__property__)\
{\


#define _GETTER_END(__property__) \
}\
return _##__property__;\
}
#define _LINE_HEIGHT_1_PPI         (1/[UIScreen mainScreen].scale)
#define BLOCK_EXEC(block, ...) if (block) { block(__VA_ARGS__); }
//-------------------适配iPhoneX-------------------------
#define SERVICE_IPHONEX CGSizeEqualToSize([UIScreen mainScreen].bounds.size, CGSizeMake(375.0, 812.0))
#define FZJT_IPHONEX_OR_BEFORE_SPACE(df, latest) ({\
float space = df;\
if (SERVICE_IPHONEX)space = latest;\
(space);\
})

//状态栏高度
#define FZJT_STATUSBAE_HEIGHT FZJT_IPHONEX_OR_BEFORE_SPACE(20, 44)
//状态栏+导航栏的高度
#define FZJT_TOPBAR_HEIGHT (FZJT_STATUSBAE_HEIGHT + NavigationBar_HEIGHT)
//底部homeBar高度
#define FZJT_HOMEBAR_HEIGHT FZJT_IPHONEX_OR_BEFORE_SPACE(0, 34)

//获取屏幕 宽度、高度
//#define SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
//#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)

//-------------------获取设备大小-------------------------


//-------------------新分类适配数据-------------------------

#define kNewClassLeftWidth (kScreenWidth/375.0f * 90)
#define kNewClassRightWidth (kScreenWidth - kNewClassLeftWidth)
#define kNewClassItemsWidth (kNewClassRightWidth - 4 *10)/3
#define kNewClassItemsHeight (kNewClassItemsWidth +35)

//-------------------新分类适配数据-------------------------

//-------------------打印日志-------------------------

//重写NSLog,Debug模式下打印日志和当前行数
#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"\nfunction:%s line:%d content:%s\n", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif

//---------------------打印日志--------------------------


//----------------------系统----------------------------

// 是否iPad
#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
// 是否iPad
#define someThing (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)? ipad: iphone

//获取系统版本
#define IOS_VERSION ［[UIDevice currentDevice] systemVersion] floatValue]
#define CurrentSystemVersion ［UIDevice currentDevice] systemVersion]
#define IOS_VERSIONString [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

//获取当前语言
#define CurrentLanguage (［NSLocale preferredLanguages] objectAtIndex:0])

//判断是否 Retina屏、设备是否%fhone 5、是否是iPad
#define isRetina ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), ［UIScreen mainScreen] currentMode].size) : NO)
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), ［UIScreen mainScreen] currentMode].size) : NO)
#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//判断设备的操做系统是不是ios7
#define IOS7 (［[UIDevice currentDevice].systemVersion doubleValue] >= 7.0]

//判断当前设备是不是iphone5
#define kScreenIphone5 (([[UIScreen mainScreen] bounds].size.height)>568)

//获取当前屏幕的高度
#define kMainScreenHeight ([UIScreen mainScreen].applicationFrame.size.height)

//获取当前屏幕的宽度
#define kMainScreenWidth ([UIScreen mainScreen].applicationFrame.size.width)



//定义一个define函数
#define TT_RELEASE_CF_SAFELY(__REF) { if (nil != (__REF)) { CFRelease(__REF); __REF = nil; } }

//判断是真机还是模拟器
#if TARGET_OS_IPHONE
//iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif

//检查系统版本
#define SYSTEM_VERSION_EQUAL_TO(v) (［[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v) (［[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v) (［[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v) (［[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v) (［[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)


//----------------------系统----------------------------


//----------------------内存----------------------------

//使用ARC和不使用ARC
#if __has_feature(objc_arc)
//compiling with ARC
#else
// compiling without ARC
#endif

#pragma mark - common functions
#define RELEASE_SAFELY(__POINTER) { [__POINTER release]; __POINTER = nil; }

//释放一个对象
#define SAFE_DELETE(P) if(P) { [P release], P = nil; }

#define SAFE_RELEASE(x) [x release];x=nil



//----------------------内存----------------------------


//----------------------图片----------------------------

//读取本地图片
#define LOADIMAGE(file,ext) [UIImage imageWithContentsOfFile:［NSBundle mainBundle]pathForResource:file ofType:ext］

//定义UIImage对象
#define IMAGE(A) [UIImage imageWithContentsOfFile:［NSBundle mainBundle] pathForResource:A ofType:nil］

//定义UIImage对象
#define ImageNamed(_pointer)    [UIImage imageNamed:[UIUtil imageName:_pointer］
#define IMGNAMED(_img)          [UIImage imageNamed:_img]
//建议使用前两种宏定义,性能高于后者
//----------------------图片----------------------------

/**************************************字体***************************************/
#define FONT_TITLE(X)                   [UIFont systemFontOfSize:X]
#define BOLDFONT_TITLE(X)               [UIFont boldSystemFontOfSize:X]
#define FONT_TITLE_PF_BOLD(X)           [UIFont fontWithName:@"PingFangSC-Medium" size:X]
#define FONT_TITLE_PF(X)                 [UIFont fontWithName:@"PingFangSC-Regular" size:X]

//----------------------颜色类---------------------------
// rgb颜色转换（16进制->10进制）
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

//带有RGBA的颜色设置
#define COLOR(R, G, B, A) [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]

// 获取RGB颜色
#define RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define RGB(r,g,b) RGBA(r,g,b,1.0f)

//背景色
#define BACKGROUND_COLOR [UIColor colorWithRed:242.0/255.0 green:236.0/255.0 blue:231.0/255.0 alpha:1.0]

//清除背景色
#define CLEARCOLOR [UIColor clearColor]

#pragma mark - color functions
#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]

//----------------------颜色类--------------------------



//----------------------其他----------------------------

//方正黑体简体字体定义
#define FONT(F) [UIFont fontWithName:@"FZHTJW--GB1-0" size:F]


//定义一个API
#define APIURL @"http://xxxxx/"
//登录API
#define APILogin [APIURL stringByAppendingString:@"Login"]

//设置View的tag属性
#define VIEWWITHTAG(_OBJECT, _TAG) [_OBJECT viewWithTag : _TAG]
//程序的本地化,引用国际化的文件
#define MyLocal(x, ...) NSLocalizedString(x, nil)

//G－C－D
#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)

//NSUserDefaults 实例化
#define USER_DEFAULT [NSUserDefaults standardUserDefaults]


//由角度获取弧度 有弧度获取角度
#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)



//单例化一个类
#define SYNTHESIZE_SINGLETON_FOR_CLASS(classname) \
\
static classname *shared##classname = nil; \
\
+ (classname *)shared##classname \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [[self alloc] init]; \
} \
} \
\
return shared##classname; \
} \
\
+ (id)allocWithZone:(NSZone *)zone \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [super allocWithZone:zone]; \
return shared##classname; \
} \
} \
\
return nil; \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
return self; \
}

//#define IS_IPAD         (UI_USER_INTERFACE_IDIOM()==UIUserInterfaceIdiomPad)
#define isIPhone4       ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define isIPhone5       ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
//6,6s,7,8
#define isIPhone6       ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
//6p,6sp,7p,8p
#define isIPhone6p      ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)
//iPhone X
#define isIPhoneX      ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)

#define _LINE_HEIGHT_1_PPI         (1/[UIScreen mainScreen].scale)

#define IOS8_OR_LATER    ( [[[UIDevice currentDevice] systemVersion] compare:@"8.0"] != NSOrderedAscending )
#define IOS7_OR_LATER    ( [[[UIDevice currentDevice] systemVersion] compare:@"7.0"] != NSOrderedAscending )
#define IOS6_OR_LATER    ( [[[UIDevice currentDevice] systemVersion] compare:@"6.0"] != NSOrderedAscending )
#define IOS5_OR_LATER    ( [[[UIDevice currentDevice] systemVersion] compare:@"5.0"] != NSOrderedAscending )
#define IOS4_OR_LATER    ( [[[UIDevice currentDevice] systemVersion] compare:@"4.0"] != NSOrderedAscending )
#define IOS3_OR_LATER    ( [[[UIDevice currentDevice] systemVersion] compare:@"3.0"] != NSOrderedAscending )

//字符串是否为空
#define IsStrEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) ||([(_ref)isEqualToString:@""]))
//数组是否为空
#define IsArrEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) ||([(_ref) count] == 0))

//若字符串为空则返回@""
#define AvailableString(string) string == nil || ![string isKindOfClass:[NSString class]] ? @"":string

#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_RETINA ([[UIScreen mainScreen] scale] >= 2.0)

#define SCREEN_WIDTH ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))

#define IS_IPHONE_4_OR_LESS (IS_IPHONE && SCREEN_MAX_LENGTH < 568.0)
#define IS_IPHONE_5 (IS_IPHONE && SCREEN_MAX_LENGTH == 568.0)
#define IS_IPHONE_6 (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define IS_IPHONE_6P (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)

#define kTableViewCellHeight 43
#define kTableViewHeight 300
#define kButtomImageViewHeight 21

#define kTextColor [UIColor colorWithRed:51/255.0 green:51/255.0 blue:51/255.0 alpha:1]
#define kDetailTextColor [UIColor colorWithRed:136/255.0 green:136/255.0 blue:136/255.0 alpha:1]
#define kSeparatorColor [UIColor colorWithRed:219/255.0 green:219/255.0 blue:219/255.0 alpha:1]
#define kCellBgColor [UIColor colorWithRed:245/255.0 green:245/255.0 blue:245/255.0 alpha:1]
#define kTextSelectColor [UIColor colorWithRed:246/255.0 green:79/255.0 blue:0/255.0 alpha:1]

/* 获取当前保存在NSUserDefaults的本地语言 */
#define curretLanguage [NSString stringWithFormat:@"%@", [USER_DEFAULT objectForKey:@"appLanguage"]]

/* 获取语言文件所在路径 */
#define LanguagePath [[NSBundle mainBundle] pathForResource:curretLanguage ofType:@"lproj"]

/* 根据键值返回转换结果 */
#define localized(key) [[NSBundle bundleWithPath:LanguagePath] localizedStringForKey:(key) value:nil table:@"Localizable"]

/*自适应,以6S为标准*/
#define SYRealValue(value) ((value)/375.0f*[UIScreen mainScreen].bounds.size.width)

/**************************枚举工具*************************************/
/**
 定义一个枚举case
 */
#define ENUM_VALUE(name, assign) name assign,

/**
 展开后是一个switch语句的case，返回一个字符串
 */
#define ENUM_CASE(name, assign) case name: return @#name;

/**
 展开后通过比较字符串，返回相应枚举case
 */
#define ENUM_STRCMP(name, assign) if ([string isEqualToString:@#name]) return name;

/**
 定义枚举，声明反射函数；
 */
#define DECLARE_ENUM(EnumType, ENUM_DEF) \
typedef NS_ENUM(NSInteger, EnumType) { \
ENUM_DEF(ENUM_VALUE) \
}; \
NSString *NSStringFrom##EnumType(EnumType value); \
EnumType EnumType##FromNSString(NSString *string); \

/**
 实现实现函数；
 */
#define DEFINE_ENUM(EnumType, ENUM_DEF) \
NSString *NSStringFrom##EnumType(EnumType value) \
{ \
switch(value) \
{ \
ENUM_DEF(ENUM_CASE) \
default: return @""; \
} \
} \
EnumType EnumType##FromNSString(NSString *string) \
{ \
ENUM_DEF(ENUM_STRCMP) \
return (EnumType)0; \
}
/********************************************************************/


/* 主色调 */
#define mainColor [UIColor colorWithHexString:@"#4f8ffd"]
/* 商家主色调 */
#define shopMainColor [UIColor colorWithHexString:@"008aea"]
/* 常用色调 */
#define Color3 [UIColor colorWithHexString:@"333333"]
#define Color6 [UIColor colorWithHexString:@"666666"]
#define Color9 [UIColor colorWithHexString:@"999999"]
#define GrayColor [UIColor colorWithHexString:@"cccccc"]
#define _COLOR_RED                        [UIColor redColor]
#define _COLOR_BLUE                       [UIColor blueColor]
#define _COLOR_YELLOW                     [UIColor yellowColor]
#define _COLOR_GREEN                      [UIColor greenColor]
#define _COLOR_BLACK                      [UIColor blackColor]
#define _COLOR_WHITE                      [UIColor whiteColor]
#define _COLOR_CLEAR                      [UIColor clearColor]
#define _COLOR_DARK_GRAY                  [UIColor darkGrayColor]
#define _COLOR_GRAY                       [UIColor grayColor]
#define _COLOR_LIGHT_GRAY                 [UIColor lightGrayColor]
/* 页面背景色 */
#define pageColor [UIColor colorWithHexString:@"#f2f2f2"]

/*=====客服电话=====*/
#define ReceivablesPhone [FZJTSystemTool shareInstance].systemModel.phoneNumber

#define ValidPhone [FZJTSystemTool shareInstance].systemModel.phoneNumber

/* 比例 */
#define kAutoIPhone6Width(width)  (kScreenWidth * width/375)
#define kAutoIPhone6Height(height) (kScreenHeight * height/667)

#define kScreenScale [[UIScreen mainScreen] scale]

//首页判断是买家还是买家
#define kIsBuyerOrSeller   @"kIsBuyerOrSeller"


/**
 获取当前控制器的navigationcontroller
 */
#define kAPPDelegateNavC [(AppDelegate*)[UIApplication sharedApplication].delegate navVC]

/**
 获取当前控制器的tabbarController
 */
#define kAPPDelegateTabBarController [(AppDelegate*)[UIApplication sharedApplication].delegate tabBarController]
#endif /* UtilsMacros_h */

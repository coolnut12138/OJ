//#define _CRT_SECURE_NO_WARNINGS 1
//
////🗡指offer第二题、单例模式
////饿汉模式：
//class singleton
//{
//public:
//	static singleton* GetInstance()
//	{
//		return &_sinst;
//	}
//private:
//	singleton()
//	{};
//	singleton(singleton const&) = delete;
//	singleton& operator=(singleton const&) = delete;
//
//	static singleton _sinst;	//static保证全局只有唯一的对象
//};
//singleton singleton::_sinst;	//在程序入口之前就完成对对象的初始化
//
//
////懒汉模式
//#include <iostream>
//#include <mutex>
//#include <thread>
//using namespace std;
//class Singleton
//{
//public:
//	static Singleton *GetInstance()
//	{
//		if (m_pInstance == nullptr)
//		{
//			m_mtx.lock();
//			if (m_pInstance == nullptr)
//			{
//				m_pInstance = new Singleton();
//			}
//			m_mtx.unlock();
//		}
//	}
//	class CGarbo{
//	public:
//		~CGarbo(){
//			if (Singleton::m_pInstance){
//				delete Singleton::m_pInstance;
//			}
//		}
//	};
//	static CGarbo Garbo;
//private:
//	Singleton()
//	{};
//	Singleton(Singleton const&) = delete;
//	Singleton operator=(Singleton const&) = delete;
//	static Singleton* m_pInstance;
//	static mutex m_mtx;
//};
//Singleton *Singleton::m_pInstance = nullptr;
//mutex Singleton::m_mtx;
//Singleton::CGarbo Garbo;
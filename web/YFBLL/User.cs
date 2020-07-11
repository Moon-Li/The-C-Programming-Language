using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace YF.BLL
{
    //业务类
    public class User
    {
        public static bool add(YF.Mode.User user)//添加
        {
            return YF.DAL.User.add(user);
        }
        public static bool add(YF.Mode.Upnumber info)//添加
        {
            return YF.DAL.Upnumber.add(info);
        }
        public static bool Search(string username)//用户名查重
        {
            return YF.DAL.User.Search(username);
        }

        public static bool Login(string username, string password)//登录验证
        {
            return YF.DAL.User.Login(username, password);
        }

        public static bool LoginEmail(string username, string password)//登录验证
        {
            return YF.DAL.User.LoginEmail(username, password);
        }

        public static bool LoginRoot(string rootname, string password)//root验证
        {
            return YF.DAL.User.LoginRoot(rootname, password);
        }

        public static List<YF.Mode.User> listU()//查看所有用户信息
        {
            return YF.DAL.User.listU();
        }

        public static List<YF.Mode.Doctor> listD()//查看所有医生信息
        {
            return YF.DAL.User.listD();
        }

        public static List<YF.Mode.Upnum> listN()//查看所有挂号信息
        {
            return YF.DAL.User.listN();
        }

        public static YF.Mode.User getUser(int id)//查看某一个用户信息
        {
            return YF.DAL.User.getUser(id);
        }

        public static YF.Mode.Doctor getDoctor(int id)//查看某一个用户信息
        {
            return YF.DAL.User.getDoctor(id);
        }

        public static YF.Mode.User getUserName(string name)//查看某一个用户信息
        {
            return YF.DAL.User.getUserName(name);
        }

        public static YF.Mode.User getUserEmail(string email)//查看某一个用户信息
        {
            return YF.DAL.User.getUserEmail(email);
        }

        public static YF.Mode.Root getRoot(string name)//查看某一个用户信息
        {
            return YF.DAL.User.getRoot(name);
        }

        public static bool Del(int id)//删除用户
        {
            return YF.DAL.User.Del(id);
        }
        public static bool DelDoc(int id)//删除用户
        {
            return YF.DAL.User.DelDoc(id);
        }

        public static bool Update(YF.Mode.User user)//修改用户系信息
        {
            return YF.DAL.User.Update(user);
        }

        public static bool UpdateD(YF.Mode.Doctor user)//修改用户系信息
        {
            return YF.DAL.User.UpdateD(user);
        }

    }
}

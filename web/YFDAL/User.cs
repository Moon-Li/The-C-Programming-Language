using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;

namespace YF.DAL
{

    public class Upnumber
    {
        public static bool add(YF.Mode.Upnumber info)
        {
            bool result = false;

            string strsql = "insert into _Upnum (name,room,word) values ('" + info.Name + "','" + info.Room + "','" + info.Word + "')";

            int i = YF.MsSqlHelper.YFMsSqlHelper.ExecuteSql(strsql);//执行插入语句，失败返回0

            if (i > 0)
            {
                result = true;
            }

            return result;
        }
    }

    //用户数据访问类
    public class User
    {
        //添加用户
        public static bool add(YF.Mode.User user)
        {
            bool result = false;

            string strsql = "insert into _user (name,rename,sex,email,phone,address,password) values ('"+user.Name+"','"+user.Rename+"',"+user.Sex+",'"+user.Email+"','"+user.Phone+"','"+user.Address+"','"+user.Password+"')";

            int i = YF.MsSqlHelper.YFMsSqlHelper.ExecuteSql(strsql);//执行插入语句，失败返回0

            if(i > 0)
            {
                result = true;
            }

            return result;
        }

        public static bool Search(string username)//用户名查重
        {
            bool result = false;

            string strsql = "select * from _user where name='" + username + "'";

            DataTable dataTable = YF.MsSqlHelper.YFMsSqlHelper.Query(strsql).Tables[0];

            if(dataTable.Rows.Count == 0)
            {
                result = true;
            }

            return result;
        }

        public static bool Login(string username, string password)//登录检查
        {
            bool result = false;

            string strsql = "select * from _user where name='" + username + "' and password='" + password + "'";

            DataTable dataTable = YF.MsSqlHelper.YFMsSqlHelper.Query(strsql).Tables[0];
            
            if (dataTable.Rows.Count != 0)
            {
                result = true;
            }

            return result;
        }

        public static bool LoginEmail(string username, string password)//登录检查
        {
            bool result = false;

            string strsql = "select * from _user where email='" + username + "' and password='" + password + "'";

            DataTable dataTable = YF.MsSqlHelper.YFMsSqlHelper.Query(strsql).Tables[0];

            if (dataTable.Rows.Count != 0)
            {
                result = true;
            }

            return result;
        }

        public static bool LoginRoot(string rootname, string password)//root登录检查
        {
            bool result = false;

            string strsql = "select * from _root where rootname='" + rootname + "' and password='" + password + "'";

            DataTable dataTable = YF.MsSqlHelper.YFMsSqlHelper.Query(strsql).Tables[0];

            if (dataTable.Rows.Count != 0)
            {
                result = true;
            }

            return result;
        }

        public static List<YF.Mode.User> listU()//查询用户表所有信息
        {

            string strsql = "select * from _user order by id desc";
            DataTable dataTable = YF.MsSqlHelper.YFMsSqlHelper.Query(strsql).Tables[0];

            return DttolistU(dataTable);
        }

        

        public static List<YF.Mode.User> DttolistU(DataTable dt)//把对象构建成一个list
        {
            List<YF.Mode.User> list = new List<Mode.User>();

            for (int i = 0; i < dt.Rows.Count; i++)
            {
                YF.Mode.User user = new Mode.User();

                user.Id = int.Parse(dt.Rows[i]["Id"].ToString());
                user.Name = dt.Rows[i]["Name"].ToString();
                user.Rename = dt.Rows[i]["Rename"].ToString();
                user.Sex = int.Parse(dt.Rows[i]["Sex"].ToString());
                user.Email = dt.Rows[i]["Email"].ToString();
                user.Phone = dt.Rows[i]["Phone"].ToString();
                user.Address = dt.Rows[i]["Address"].ToString();
                //这里没有拿密码，管理员对密码无权访问

                list.Add(user);
            }

            return list;
        }

        public static List<YF.Mode.Doctor> listD()//查询用户表所有信息
        {

            string strsql = "select * from _doctor order by docnum desc";
            DataTable dataTable = YF.MsSqlHelper.YFMsSqlHelper.Query(strsql).Tables[0];

            return DttolistD(dataTable);
        }

        public static List<YF.Mode.Doctor> DttolistD(DataTable dt)//把对象构建成一个list
        {
            List<YF.Mode.Doctor> list = new List<Mode.Doctor>();

            for (int i = 0; i < dt.Rows.Count; i++)
            {
                YF.Mode.Doctor user = new Mode.Doctor();

                user.Id = int.Parse(dt.Rows[i]["docnum"].ToString());
                user.Name = dt.Rows[i]["docname"].ToString();
                user.Age = dt.Rows[i]["age"].ToString();
                user.Job = dt.Rows[i]["job"].ToString();
                user.Room = dt.Rows[i]["room"].ToString();

                list.Add(user);
            }

            return list;
        }

        public static List<YF.Mode.Upnum> listN()//查询用户表所有信息
        {

            string strsql = "select * from _Upnum order by name desc";
            DataTable dataTable = YF.MsSqlHelper.YFMsSqlHelper.Query(strsql).Tables[0];

            return DttolistN(dataTable);
        }

        public static List<YF.Mode.Upnum> DttolistN(DataTable dt)//把对象构建成一个list
        {
            List<YF.Mode.Upnum> list = new List<Mode.Upnum>();

            for (int i = 0; i < dt.Rows.Count; i++)
            {
                YF.Mode.Upnum user = new Mode.Upnum();

                user.Name = dt.Rows[i]["name"].ToString();
                user.Room = dt.Rows[i]["room"].ToString();
                user.Word = dt.Rows[i]["word"].ToString();

                list.Add(user);
            }

            return list;
        }


        public static YF.Mode.User getUser(int id)//得到一个对象
        {
            YF.Mode.User user = new Mode.User();

            string strsql = "select * from _user where id='" + id + "'";
            
            DataTable dataTable = YF.MsSqlHelper.YFMsSqlHelper.Query(strsql).Tables[0];

            if(dataTable.Rows.Count != 0)
            {

                user.Id = int.Parse(dataTable.Rows[0]["Id"].ToString());
                user.Name = dataTable.Rows[0]["Name"].ToString();
                user.Rename = dataTable.Rows[0]["Rename"].ToString();
                user.Sex = int.Parse(dataTable.Rows[0]["Sex"].ToString());
                user.Email = dataTable.Rows[0]["Email"].ToString();
                user.Phone = dataTable.Rows[0]["Phone"].ToString();
                user.Address = dataTable.Rows[0]["Address"].ToString();
                user.Password = dataTable.Rows[0]["Password"].ToString();

            }

            return user;
        }
        public static YF.Mode.Doctor getDoctor(int id)//得到一个对象
        {
            YF.Mode.Doctor user = new Mode.Doctor();

            string strsql = "select * from _doctor where docnum='" + id + "'";

            DataTable dataTable = YF.MsSqlHelper.YFMsSqlHelper.Query(strsql).Tables[0];

            if (dataTable.Rows.Count != 0)
            {
                user.Id = int.Parse(dataTable.Rows[0]["docnum"].ToString());
                user.Name = dataTable.Rows[0]["docname"].ToString();
                user.Age = dataTable.Rows[0]["age"].ToString();
                user.Job = dataTable.Rows[0]["job"].ToString();
                user.Room = dataTable.Rows[0]["room"].ToString();

            }

            return user;
        }


        public static YF.Mode.User getUserName(string name)//得到一个对象
        {
            YF.Mode.User user = new Mode.User();

            string strsql = "select * from _user where name='" + name + "'";

            DataTable dataTable = YF.MsSqlHelper.YFMsSqlHelper.Query(strsql).Tables[0];

            if (dataTable.Rows.Count != 0)
            {

                user.Id = int.Parse(dataTable.Rows[0]["Id"].ToString());
                user.Name = dataTable.Rows[0]["Name"].ToString();
                user.Rename = dataTable.Rows[0]["Rename"].ToString();
                user.Sex = int.Parse(dataTable.Rows[0]["Sex"].ToString());
                user.Email = dataTable.Rows[0]["Email"].ToString();
                user.Phone = dataTable.Rows[0]["Phone"].ToString();
                user.Address = dataTable.Rows[0]["Address"].ToString();
                user.Password = dataTable.Rows[0]["Password"].ToString();

            }

            return user;
        }

        public static YF.Mode.User getUserEmail(string email)//得到一个对象
        {
            YF.Mode.User user = new Mode.User();

            string strsql = "select * from _user where email='" + email + "'";

            DataTable dataTable = YF.MsSqlHelper.YFMsSqlHelper.Query(strsql).Tables[0];

            if (dataTable.Rows.Count != 0)
            {

                user.Id = int.Parse(dataTable.Rows[0]["Id"].ToString());
                user.Name = dataTable.Rows[0]["Name"].ToString();
                user.Rename = dataTable.Rows[0]["Rename"].ToString();
                user.Sex = int.Parse(dataTable.Rows[0]["Sex"].ToString());
                user.Email = dataTable.Rows[0]["Email"].ToString();
                user.Phone = dataTable.Rows[0]["Phone"].ToString();
                user.Address = dataTable.Rows[0]["Address"].ToString();
                user.Password = dataTable.Rows[0]["Password"].ToString();

            }

            return user;
        }

        public static YF.Mode.Root getRoot(string name)//找到一个管理员用户
        {
            YF.Mode.Root user = new Mode.Root();

            string strsql = "select * from _root where rootname='" + name + "'";

            DataTable dataTable = YF.MsSqlHelper.YFMsSqlHelper.Query(strsql).Tables[0];

            if (dataTable.Rows.Count != 0)
            {

                user.Name = dataTable.Rows[0]["rootname"].ToString();

            }

            return user;
        }

        public static bool Del(int id)
        {
            bool result = false;

            string strsql = "delete from _user where id=" + id + "";

            int i = YF.MsSqlHelper.YFMsSqlHelper.ExecuteSql(strsql);//执行删除语句，失败返回0

            if (i > 0)
            {
                result = true;
            }

            return result;
        }
        public static bool DelDoc(int id)
        {
            bool result = false;

            string strsql = "delete from _doctor where docnum=" + id + "";

            int i = YF.MsSqlHelper.YFMsSqlHelper.ExecuteSql(strsql);//执行删除语句，失败返回0

            if (i > 0)
            {
                result = true;
            }

            return result;
        }

        public static bool Update(YF.Mode.User user)
        {
            bool result = false;

            string strsql = "update _user set rename='" + user.Rename + "',sex=" + user.Sex + ",email='" + user.Email + "',phone='" + user.Phone + "',address='" + user.Address + "',password='" + user.Password + "' where id=" + user.Id + "";

            int i = YF.MsSqlHelper.YFMsSqlHelper.ExecuteSql(strsql);//执行删除语句，失败返回0

            if (i > 0)
            {
                result = true;
            }

            return result;
        }

        public static bool UpdateD(YF.Mode.Doctor user)
        {
            bool result = false;

            string strsql = "update _doctor set age='" + user.Age + "',job='" + user.Job + "',room='" + user.Room + "' where docnum=" + user.Id + "";

            int i = YF.MsSqlHelper.YFMsSqlHelper.ExecuteSql(strsql);//执行删除语句，失败返回0

            if (i > 0)
            {
                result = true;
            }

            return result;
        }
    }
}

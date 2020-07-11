using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace YF.Mode
{
    public class User
    {
        private int id;//id
        public int Id
        {
          get { return id; }
          set { id = value; }
        }

        private string name;//用户名
        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        private string rename;//昵称
        public string Rename
        {
            get { return rename; }
            set { rename = value; }
        }

        private int sex;//性别
        public int Sex
        {
            get { return sex; }
            set { sex = value; }
        }

        private string email;//邮箱
        public string Email
        {
            get { return email; }
            set { email = value; }
        }

        private string phone;//电话
        public string Phone
        {
            get { return phone; }
            set { phone = value; }
        }

        private string address;//地址
        public string Address
        {
            get { return address; }
            set { address = value; }
        }

        private string password;//密码
        public string Password
        {
            get { return password; }
            set { password = value; }
        }

    }

    public class Root
    {
        private string name;
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        
    }

    public class Upnumber
    {
        private string name;

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        private string room;

        public string Room
        {
            get { return room; }
            set { room = value; }
        }

        private string word;

        public string Word
        {
            get { return word; }
            set { word = value; }
        }

    }

    public class Doctor
    {
        private int id;

        public int Id
        {
            get { return id; }
            set { id = value; }
        }

        

        private string name;

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        private string age;

        public string Age
        {
            get { return age; }
            set { age = value; }
        }

        private string job;

        public string Job
        {
            get { return job; }
            set { job = value; }
        }

        private string room;

        public string Room
        {
            get { return room; }
            set { room = value; }
        }

    }

    public class Upnum
    {
        private string name;

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        private string room;

        public string Room
        {
            get { return room; }
            set { room = value; }
        }

        private string word;

        public string Word
        {
            get { return word; }
            set { word = value; }
        }

    }

}

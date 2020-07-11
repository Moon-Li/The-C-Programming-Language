using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class login : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void TextBox1_TextChanged(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        string user_name = this.username.Text;
        string pass_word = this.password.Text;
        string str = "index.aspx?id=";
        
        

        if(YF.BLL.User.Login(user_name, pass_word))
        {
            YF.Mode.User user = YF.BLL.User.getUserName(user_name);
            string str2 = user.Id.ToString();
            str = str.Insert (14,str2);

            YF.JsHelper.AlertAndRedirect("登陆成功！", str);
        }
        else if (YF.BLL.User.LoginEmail(user_name, pass_word))
        {
            YF.Mode.User user = YF.BLL.User.getUserEmail(user_name);
            string str2 = user.Id.ToString();
            str = str.Insert(14, str2);

            YF.JsHelper.AlertAndRedirect("登陆成功！", str);
        }
        else
        {
            YF.JsHelper.AlertAndRedirect("用户名不存在或密码错误，请重新输入", "login.aspx");
        }
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        YF.JsHelper.Redirect("wind.aspx");
    }
    protected void Button3_Click(object sender, EventArgs e)
    {
        YF.JsHelper.Redirect("helloroot.aspx");

    }
}
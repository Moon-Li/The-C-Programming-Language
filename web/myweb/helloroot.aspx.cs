using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class helloroot : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        string name = "root";
        YF.Mode.Root root = YF.BLL.User.getRoot(name);
        this.root.Text = root.Name;

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        string rootname = this.root.Text;
        string password = this.password.Text;

        if (YF.BLL.User.LoginRoot(rootname, password))
        {
            YF.JsHelper.AlertAndRedirect("登陆成功！", "rootChose.aspx");
        }
        else
        {
            YF.JsHelper.AlertAndRedirect("用户名不存在或密码错误，请重新输入", "helloroot.aspx");
        }
    }
}
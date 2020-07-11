using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using YF.BLL;
using YF.DAL;
using YF.Mode;
using YF.MsSqlHelper;


public partial class wind : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        YF.Mode.User user = new YF.Mode.User();
        user.Name = this.name.Text;
        user.Rename = this.rename.Text;
        user.Sex = int.Parse(this.sex.Text);//转整型
        user.Email = this.email.Text;
        user.Phone = this.phone.Text;
        user.Address = this.address.Text;
        user.Password = this.password.Text;

        if (YF.BLL.User.Search(this.name.Text) == false)
        {
            YF.JsHelper.AlertAndRedirect("该用户名已存在！", "wind.aspx");
        }
        else
        {
            if (YF.BLL.User.add(user) == true)//注册成功
            {
                YF.JsHelper.AlertAndRedirect("注册成功！", "login.aspx");
            }
            else//注册失败
            {
                YF.JsHelper.AlertAndRedirect("注册失败!", "wind.aspx");
            }
        }
    }
}